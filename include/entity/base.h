#ifndef TEXTMAGIC_BASE_H
#define TEXTMAGIC_BASE_H
#include <vector>
#include <map>
#include <string>
#include <json/json.h>

#include <utils.h>
#include <restclient.h>

namespace Textmagic {
	class BaseModel {
		public:
			BaseModel(const std::string& data){
				response = data;
			};

			BaseModel(){
				response = "";
			};

			std::string asString() {
				return response;
			};

			Json::Value asJsonValue();
		
			void deserialize(){
				return;
		    };

			Textmagic::Rest::RequestData serialize(){
				Textmagic::Rest::RequestData data;
            	return data;
			};

		private:
			std::string response;

	};
}

#endif /* TEXTMAGIC_BASE_H */