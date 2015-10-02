#ifndef TEXTMAGIC_REPLY_H
#define TEXTMAGIC_REPLY_H

#include <entity/base.h>

namespace Textmagic {
	class ReplyModel:public Textmagic::BaseModel {
		public:
			ReplyModel() : Textmagic::BaseModel(){};
			ReplyModel(const std::string& data) : Textmagic::BaseModel(data){};

			void deserialize();
			// the model is not used in POST/PUT requests
			//Textmagic::Rest::RequestData serialize() const;
		
			std::string id;
			std::string sender;
			std::string messageTime;
			std::string text;
			std::string receiver;

	};
}

#endif /* TEXTMAGIC_REPLY_H */