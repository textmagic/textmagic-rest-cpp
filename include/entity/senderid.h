#ifndef TEXTMAGIC_SENDERID_H
#define TEXTMAGIC_SENDERID_H

#include <entity/base.h>

namespace Textmagic {
	class SenderIdModel:public Textmagic::BaseModel {
		public:
			SenderIdModel() : Textmagic::BaseModel(){};
			SenderIdModel(const std::string& data) : Textmagic::BaseModel(data){};

			void deserialize();
			Textmagic::Rest::RequestData serialize() const;
		
			std::string id;
			std::string senderId;
			std::string status;
			std::string userId;
			std::string userName;
			std::string explanation;

	};
}

#endif /* TEXTMAGIC_SENDERID_H */