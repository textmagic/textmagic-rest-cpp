#ifndef TEXTMAGIC_RESTCLIENT_H
#define TEXTMAGIC_RESTCLIENT_H

namespace Textmagic {
	class Rest {
		public:
			typedef std::map<std::string, std::string> RequestData;
 			typedef struct
    			{
				  const char* data;
				  size_t length;
    			} UploadObject;
			Rest(const std::string& login, const std::string& token){
				tmlogin = login;
				tmtoken = token;
			}

		    std::string request(const std::string& path, const std::string& method, RequestData& options);
            long httpCode;
		private:
		 	static const std::string API_URL;

			std::string tmlogin;
			std::string tmtoken;
			std::string tbuffer;

			struct curl_slist* headersPrepare();
		  	std::string buildUrl(const std::string& path) const;
		  	std::string buildParams(RequestData const &params);
		  	std::string httpGet(const std::string& url,  RequestData& vars);
			std::string httpPost(const std::string& url, RequestData& vars);
			std::string httpPut(const std::string& url, RequestData& vars);
			std::string httpDelete(const std::string& url, RequestData& vars);
	};

}

#endif /* TEXTMAGIC_RESTCLIENT_H */