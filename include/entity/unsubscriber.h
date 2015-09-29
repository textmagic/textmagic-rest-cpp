#ifndef TEXTMAGIC_UNSUBSCRIBER_H
#define TEXTMAGIC_UNSUBSCRIBER_H

#include <entity/base.h>

namespace Textmagic {
	class UnsubscriberModel: public Textmagic::BaseModel {
		public:
			UnsubscriberModel() : Textmagic::BaseModel(){};
			UnsubscriberModel(const std::string& data) : Textmagic::BaseModel(data){};

			void deserialize();
			Textmagic::Rest::RequestData serialize() const;
		
			std::string id;
			std::string phone;
			std::string unsubscribeTime;
			std::string firstName;
			std::string lastName;
	};
}

#endif /* TEXTMAGIC_UNSUBSCRIBER_H */