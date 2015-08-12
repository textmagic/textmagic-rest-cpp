#ifndef TEXTMAGIC_CHAT_H
#define TEXTMAGIC_CHAT_H

namespace Textmagic {
	class ChatModel:public Textmagic::BaseModel {
		public:
			ChatModel() : Textmagic::BaseModel(){};
			ChatModel(const std::string& data) : Textmagic::BaseModel(data){};

			void deserialize() {
				Json::Value root = this->asJsonValue();
			 	id = root.get("id", "").asString();
			 	phone = root.get("phone", "").asString();
			 	contactId = root.get("contactId", "").asString();
			 	unread = root.get("unread", 0).asInt();
			 	updatedAt = root.get("updatedAt", "").asString();
			};

			Textmagic::Rest::RequestData serialize(){
				Textmagic::Rest::RequestData data;
				return data;
			};

			std::string id;
			std::string phone;
			std::string contactId;
			int unread;
			std::string updatedAt;

	};
}

#endif /* TEXTMAGIC_CHAT_H */