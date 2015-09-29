#include <json/json.h>
#include <iostream>
#include <string>
#include <map>
#include <iterator>
#include <curl/curl.h>
#include <curl/easy.h>

using namespace std;

#include <restclient.h>

using namespace Textmagic;

const string Rest::API_URL = "https://rest.textmagic.com/api/v2";

static size_t writer(char *data, size_t size, size_t nmemb, string *buffer){
	size_t result = 0;
	if (buffer != NULL){
		buffer->append(data, size * nmemb);
		result = size * nmemb;
	}
	return result;
}

static size_t reader(void *data, size_t size, size_t nmemb, void *userdata) {
	Rest::UploadObject* u;
	u = reinterpret_cast<Rest::UploadObject*>(userdata);
	size_t curl_size = size * nmemb;
	size_t copy_size = (u->length < curl_size) ? u->length : curl_size;
	memcpy(data, u->data, copy_size);
	u->length -= copy_size;
	u->data += copy_size;
	return copy_size;
}


string Rest::buildUrl(const string& path) const {
	return Rest::API_URL + path;
}

struct curl_slist* Rest::headersPrepare() {
	curl_slist *header = NULL;
	string token = "x-tm-key:" + tmtoken;
	string login = "x-tm-username:" + tmlogin;
	header = curl_slist_append(header, "accept:application/json");
	header = curl_slist_append(header, "accept-language:en;q=1");
	header = curl_slist_append(header, "content-type:application/x-www-form-urlencoded");
	header = curl_slist_append(header, "user-agent:textmagic-rest-cpp");
	header = curl_slist_append(header, login.c_str());
	header = curl_slist_append(header, token.c_str());
	return header;
}

std::string Rest::request(const string& path, const string& method, RequestData& options){
	string response = "Request error";
	if(method == "GET"){
		response = httpGet(path, options);
	}
	else if(method == "POST"){
		response = httpPost(path, options);
	}
	else if(method == "PUT"){
		response = httpPut(path, options);
	}
	else if(method == "DELETE"){
		response = httpDelete(path, options);
	}
	return response;
};

string Rest::httpGet(const string& url,  RequestData& vars){
	CURL *curl;
	CURLcode res;
	curl_slist *header;
	string u = buildUrl(url) + "?" + buildParams(vars);

	tbuffer = "HTTP get error";
	curl = curl_easy_init();
	if(curl) {
		tbuffer = "";
		header = Rest::headersPrepare();
		curl_easy_setopt(curl, CURLOPT_URL, u.c_str());
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writer);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &tbuffer);
		curl_easy_setopt(curl, CURLOPT_HTTPHEADER, header);
//		curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
		res = curl_easy_perform(curl);
        curl_easy_getinfo (curl, CURLINFO_RESPONSE_CODE, &httpCode);
        curl_easy_cleanup(curl);
		curl_slist_free_all(header);
		if (res == CURLE_OK) {
//		std::cout<<tbuffer<<std::endl;
			return tbuffer;
		}
	}
	return tbuffer;
}

string Rest::httpPost(const string& url, RequestData& vars){
	CURL *curl;
	CURLcode res;
	string u = buildUrl(url);
	struct curl_slist *header = NULL;
	string data = buildParams(vars);

	curl_global_init(CURL_GLOBAL_ALL);
	tbuffer = "HTTP post error";
	curl = curl_easy_init();

	if(curl) {
		curl_easy_setopt(curl, CURLOPT_URL, u.c_str());
		header = Rest::headersPrepare();
		curl_easy_setopt(curl, CURLOPT_HTTPHEADER, header);
		curl_easy_setopt(curl, CURLOPT_POST, 1L);
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data.c_str());

//		std::cout<< "DATA::: " << data.c_str()<<std::endl;

        curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, data.size());
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writer);
//		curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);

		tbuffer = "";
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &tbuffer);
		res = curl_easy_perform(curl);
		curl_easy_getinfo (curl, CURLINFO_RESPONSE_CODE, &httpCode);

		curl_easy_cleanup(curl);
		curl_slist_free_all (header);
		curl_global_cleanup();

	if (res == CURLE_OK)
//	  std::cout << "RESPONSE::: " <<tbuffer<<std::endl;
	  return tbuffer;
	}

	return tbuffer;
}

string Rest::httpPut(const string& url, RequestData& vars){
	CURL *curl;
	CURLcode res;
	string u = buildUrl(url);
	struct curl_slist *header = NULL;
	string data = buildParams(vars);
	Rest::UploadObject upobj;
	upobj.data = data.c_str();
	upobj.length = data.size();

	curl_global_init(CURL_GLOBAL_ALL);
	tbuffer = "HTTP post error";
	curl = curl_easy_init();

	if(curl) {
		curl_easy_setopt(curl, CURLOPT_URL, u.c_str());
		header = Rest::headersPrepare();
		curl_easy_setopt(curl, CURLOPT_HTTPHEADER, header);
		curl_easy_setopt(curl, CURLOPT_PUT, 1L);
		curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);
		curl_easy_setopt(curl, CURLOPT_READFUNCTION, reader);
		curl_easy_setopt(curl, CURLOPT_READDATA, &upobj);
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writer);

//		curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
//		std::cout<< "DATA::: " << data.c_str()<<std::endl;

		tbuffer = "";
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &tbuffer);
		res = curl_easy_perform(curl);
		curl_easy_getinfo (curl, CURLINFO_RESPONSE_CODE, &httpCode);
		curl_easy_cleanup(curl);
		curl_slist_free_all (header);
		curl_global_cleanup();
	if (res == CURLE_OK)
//		  std::cout << "RESPONSE::: " <<tbuffer<<std::endl;
	  return tbuffer;
	}
	return tbuffer;
}


string Rest::httpDelete(const string& url, RequestData& vars){
	CURL *curl;
	CURLcode res;
	string u = buildUrl(url);
	struct curl_slist *header = NULL;
	string data = buildParams(vars);

	tbuffer = "HTTP delete error";
	curl = curl_easy_init();
	if(!curl) {
		return tbuffer;
	}
	header = Rest::headersPrepare();
	curl_easy_setopt(curl, CURLOPT_URL, u.c_str());
	curl_easy_setopt(curl, CURLOPT_HTTPHEADER, header);
	curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data.c_str());
    curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, data.size());
	curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "DELETE");
//	curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);

//	std::cout<< "DATA::: " << data.c_str()<<std::endl;

	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writer);
	tbuffer = "";
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &tbuffer);
	res = curl_easy_perform(curl);
//	std::cout << "RESPONSE::: " <<tbuffer<<std::endl;
	curl_easy_getinfo (curl, CURLINFO_RESPONSE_CODE, &httpCode);
	curl_easy_cleanup(curl);
	return tbuffer;
}


string Rest::buildParams(RequestData const &params) {
	if(params.empty()) {
		return "";
	}
	RequestData::const_iterator pb = params.begin(), pe = params.end();
	string data = pb->first+ "=" + pb->second;
	++ pb;
	if(pb == pe){
		return data;
	}
	for(; pb!= pe; ++ pb){
		data+= "&" + pb->first + "=" + pb->second;
	}

	return data;
}





