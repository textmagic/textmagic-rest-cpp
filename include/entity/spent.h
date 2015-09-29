#ifndef TEXTMAGIC_SPENT_H
#define TEXTMAGIC_SPENT_H

#include <entity/base.h>

namespace Textmagic {
	class SpentModel:public Textmagic::BaseModel {
		public:
			SpentModel() : Textmagic::BaseModel(){};
			SpentModel(const std::string& data) : Textmagic::BaseModel(data){};

			void deserialize();
			///Textmagic::Rest::RequestData serialize() const;
		
			std::string id;
			std::string userId;
			std::string date;
			float balance;
			float delta;
			std::string type;
			std::string value;
			std::string comment;

	};
}

#endif /* TEXTMAGIC_SPENT_H */