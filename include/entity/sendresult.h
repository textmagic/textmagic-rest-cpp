#ifndef TEXTMAGIC_SENDRESULT_H
#define TEXTMAGIC_SENDRESULT_H

#include <entity/base.h>

namespace Textmagic {
	class SendResultModel:public Textmagic::BaseModel {
		public:
			SendResultModel() : Textmagic::BaseModel(){};
			SendResultModel(const std::string& data) : Textmagic::BaseModel(data){};

			void deserialize() {
				Json::Value root = this->asJsonValue();
			 	id = root.get("id", "").asString();
			 	href = root.get("href", "").asString();
				sessionId = root.get("sessionId", "").asString();
				type = root.get("type", "").asString();
				bulkId = root.get("bulkId", "").asString();
				messageId = root.get("messageId", "").asString();
				scheduleId = root.get("scheduleId", "").asString();
			};

			Textmagic::Rest::RequestData serialize(){
				Textmagic::Rest::RequestData data;
				return data;
			};

			std::string id;
			std::string href;
			std::string type;
			std::string sessionId;
			std::string bulkId;
			std::string messageId;
			std::string scheduleId;
	};
}

#endif /* TEXTMAGIC_SENDRESULT_H */