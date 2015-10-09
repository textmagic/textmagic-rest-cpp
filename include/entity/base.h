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
			std::string id;
		
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
		
			virtual void deserialize(){
				throw std::logic_error("Deserialize is not implemented");
		    };
		
			virtual Textmagic::Rest::RequestData serialize() const {
				throw std::logic_error("Serialize is not implemented");
			};

		private:
			std::string response;

	};
}

#endif /* TEXTMAGIC_BASE_H */