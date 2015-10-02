#ifndef TEXTMAGIC_LIST_H
#define TEXTMAGIC_LIST_H

#include <entity/base.h>

namespace Textmagic {
	class ListModel:public Textmagic::BaseModel {
		public:
			ListModel() : Textmagic::BaseModel(){};
			ListModel(const std::string& data) : Textmagic::BaseModel(data){};

			void deserialize();
			Textmagic::Rest::RequestData serialize() const;
		
			std::string id;
			std::string name;
			std::string description;
			int membersCount;
			bool shared;

	};
}

#endif /* TEXTMAGIC_LIST_H */