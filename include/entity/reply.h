#ifndef TEXTMAGIC_REPLY_H
#define TEXTMAGIC_REPLY_H

namespace Textmagic {
	class ReplyModel:public Textmagic::BaseModel {
		public:
			ReplyModel() : Textmagic::BaseModel(){};
			ReplyModel(const std::string& data) : Textmagic::BaseModel(data){};

			void deserialize() {
				Json::Value root = this->asJsonValue();
			 	id = root.get("id", "").asString();
			 	sender = root.get("sender", "").asString();
			 	messageTime = root.get("messageTime", "").asString();
			 	text = root.get("text", "").asString();
			 	receiver = root.get("receiver", "").asString();

			};

			Textmagic::Rest::RequestData serialize(){
				Textmagic::Rest::RequestData data;
				return data;
			};

			std::string id;
			std::string sender;
			std::string messageTime;
			std::string text;
			std::string receiver;

	};
}

#endif /* TEXTMAGIC_REPLY_H */