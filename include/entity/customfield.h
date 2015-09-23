#ifndef TEXTMAGIC_CUSTOMFIELD_H
#define TEXTMAGIC_CUSTOMFIELD_H

#include <entity/base.h>

namespace Textmagic {
	class CustomfieldModel:public Textmagic::BaseModel {
		public:
			CustomfieldModel() : Textmagic::BaseModel(){};
			CustomfieldModel(const std::string& data) : Textmagic::BaseModel(data){};

			void deserialize();
			Textmagic::Rest::RequestData serialize();
		
			std::string id;
			std::string name;
			std::string createdAt;

	};
}

#endif /* TEXTMAGIC_CUSTOMFIELD_H */