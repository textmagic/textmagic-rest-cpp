#ifndef TEXTMAGIC_SESSION_H
#define TEXTMAGIC_SESSION_H

#include <entity/base.h>

namespace Textmagic {
	class SessionModel:public Textmagic::BaseModel {
		public:
			SessionModel() : Textmagic::BaseModel(){};
			SessionModel(const std::string& data) : Textmagic::BaseModel(data){};

			void deserialize();
			// the model is not used in POST/PUT requests
			//Textmagic::Rest::RequestData serialize() const;
		
			std::string id;
			std::string startTime;
			std::string text;
			std::string source;
			std::string referenceId;
			float price;
			int numbersCount;

	};
}

#endif /* TEXTMAGIC_SESSION_H */