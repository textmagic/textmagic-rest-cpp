#ifndef TEXTMAGIC_BASECONTR_H
#define TEXTMAGIC_BASECONTR_H

#include <vector>
#include <map>
#include <string>
#include <json/json.h>

#include <utils.h>
#include <restclient.h>

namespace Textmagic {

	template <class TCustomEntity>
	struct Resources
		{
		  int page;
		  int limit;
		  int pageCount;
		  std::vector<TCustomEntity> resources;
		} ;

	template <class TGeneralEntity>
	class BaseController {
		public:
            typedef struct
                {
                  long code;
                  std::string message;
                  Json::Value errors;
                } Error;

			Error lastError;
			bool isError;
			std::string basePath;
			Textmagic::Rest& rest;

			BaseController(Textmagic::Rest* r, std::string path) :rest(*r) {
        		basePath = path;
        		isError = false;
        	}

			TGeneralEntity get(std::string id) {
				Rest::RequestData data;
				TGeneralEntity e(rest.request(basePath + "/" + id, "GET", data));
                if (errorHandler(e)) {
                    e.deserialize();
                }
				return e;
			};

			int create(TGeneralEntity& entity) {
				Rest::RequestData data = entity.serialize();
				TGeneralEntity e(rest.request(basePath, "POST", data));
				if (errorHandler(e)) {
					int id = e.asJsonValue().get("id", 0).asInt();
					entity.id = Textmagic::Utils::toString(id);
				    return id;
				} else {
				    return 0;
				}
			};

			int update(TGeneralEntity& entity) {
				Rest::RequestData data = entity.serialize();
				TGeneralEntity e(rest.request(basePath + "/" + entity.id, "PUT", data));
				if (errorHandler(e)) {
				    return e.asJsonValue().get("id", 0).asInt();
				 } else {
				    return 0;
				 }
			};

			bool remove(std::string id) {
				Rest::RequestData data;
				TGeneralEntity e(rest.request(basePath + "/" + id, "DELETE", data));
				return errorHandler(e);
			};

			Resources<TGeneralEntity> search(){
				Rest::RequestData options;
            	return search(options);
        	};

		    Resources<TGeneralEntity> search(Rest::RequestData& options){
		    	std::string path = basePath + "/search";
                return getResources<TGeneralEntity>(path , options);
        	};

			Resources<TGeneralEntity> list(){
				Rest::RequestData options;
	            return list(options);
			};

			Resources<TGeneralEntity> list(Rest::RequestData& options){
	            return getResources<TGeneralEntity>(basePath, options);
			};


			template <class TCustomEntity>
			Resources<TCustomEntity> getResources(std::string& path, Rest::RequestData& options){
                TCustomEntity e(rest.request(path, "GET", options));
                Json::Value json = e.asJsonValue();
                Resources<TCustomEntity> r;
                if (! errorHandler<TCustomEntity>(e)) {
                    return r;
                }

				Json::Value array;
				if (json.isArray()) {
					array = json;
				} else {
					array = json["resources"];
					r.page = json.get("page", 0).asInt();
					r.limit = json.get("limit", 0).asInt();
					r.pageCount = json.get("pageCount", 0).asInt();
				}

                for(unsigned int i = 0; i < array.size(); ++i){
                    TCustomEntity item(array[i].toStyledString());
                    item.deserialize();
                    r.resources.push_back(item);
                }
                return r;
            };

			bool errorHandler(TGeneralEntity& entity){
				return errorHandler<TGeneralEntity>(entity);
			};

			template <class TCustomEntity>
            bool errorHandler(TCustomEntity& entity){
                if (rest.httpCode >= 500) {
                    // api exception or fatal
                    isError = true;
                    lastError.code = rest.httpCode;
                    lastError.message = "Unknown TM2 API error.";
                    return false;
                } else if (rest.httpCode >= 300){
                    // wrong request/response
                    isError = true;
                    Json::Value json = entity.asJsonValue();
                    lastError.code = json.get("code", 400).asInt();
                    lastError.message = json.get("message", "Wrong parameters").asString();
                    lastError.errors = json["errors"];
                    return false;
                } else {
                    //success
                    isError = false;
                    lastError.code = 200;
                    lastError.message = "";
                    lastError.errors = Json::Value();
                    return true;
                }
            }

	};
}

#endif /* TEXTMAGIC_BASECONTR_H */