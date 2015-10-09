#ifndef TEXTMAGIC_MESSAGE_H
#define TEXTMAGIC_MESSAGE_H

#include <entity/base.h>

namespace Textmagic {
	class MessageModel:public Textmagic::BaseModel {
		public:
			MessageModel() : Textmagic::BaseModel(){};
			MessageModel(const std::string& data) : Textmagic::BaseModel(data){};

			void deserialize() {
				Json::Value root = this->asJsonValue();
			 	id = root.get("id", "").asString();
			 	direction = root.get("direction", "o").asString();
			 	receiver = root.get("receiver", "").asString();
				messageTime = root.get("messageTime", "").asString();
				status = root.get("status", "").asString();
				text = root.get("text", "").asString();
				charset = root.get("charset", "").asString();
				firstName = root.get("firstName", "").asString();
				lastName = root.get("lastName", "").asString();
				country = root.get("country", "").asString();
				sender = root.get("sender", "").asString();
				price = root.get("price", 0).asFloat();
				partsCount = root.get("partsCount", 0).asInt();

			};

			std::string direction;
			std::string receiver;
			std::string messageTime;
			std::string status;
			std::string text;
			std::string charset;
			std::string firstName;
			std::string lastName;
			std::string country;
			std::string sender;
			float price;
			int partsCount;

	};
}

#endif /* TEXTMAGIC_MESSAGE_H */