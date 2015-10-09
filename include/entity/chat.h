#ifndef TEXTMAGIC_CHAT_H
#define TEXTMAGIC_CHAT_H

#include <entity/base.h>

namespace Textmagic {
	class ChatModel:public Textmagic::BaseModel {
		public:
			ChatModel() : Textmagic::BaseModel(){};
			ChatModel(const std::string& data) : Textmagic::BaseModel(data){};

			void deserialize();

			std::string phone;
			std::string contactId;
			int unread;
			std::string updatedAt;

	};
}

#endif /* TEXTMAGIC_CHAT_H */