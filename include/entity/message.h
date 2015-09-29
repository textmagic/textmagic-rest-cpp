#ifndef TEXTMAGIC_MESSAGE_H
#define TEXTMAGIC_MESSAGE_H

#include <entity/base.h>

namespace Textmagic {
	class MessageModel:public Textmagic::BaseModel {
		public:
			MessageModel() : Textmagic::BaseModel(){};
			MessageModel(const std::string& data) : Textmagic::BaseModel(data){};

			void deserialize();
		
			std::string id;
			std::string direction; // ??
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