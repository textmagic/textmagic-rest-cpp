#ifndef TEXTMAGIC_SENDERID_H
#define TEXTMAGIC_SENDERID_H

namespace Textmagic {
	class SenderIdModel:public Textmagic::BaseModel {
		public:
			SenderIdModel() : Textmagic::BaseModel(){};
			SenderIdModel(const std::string& data) : Textmagic::BaseModel(data){};

			void deserialize() {
				Json::Value root = this->asJsonValue();
			 	id = root.get("id", "").asString();
			 	senderId = root.get("senderId", "").asString();
				status = root.get("status", "").asString();
				userId = root["user"].get("id", "").asString();
				userName = root["user"].get("name", "").asString();

			};

			Textmagic::Rest::RequestData serialize(){
				Textmagic::Rest::RequestData data;
				data["senderId"] = senderId;
				data["explanation"] = explanation;
				return data;
			};

			std::string id;
			std::string senderId;
			std::string status;
			std::string userId;
			std::string userName;
			std::string explanation;

	};
}

#endif /* TEXTMAGIC_SENDERID_H */