#ifndef TEXTMAGIC_SOURCE_H
#define TEXTMAGIC_SOURCE_H

#include <entity/base.h>

namespace Textmagic {
	class SourceModel:public Textmagic::BaseModel {
		public:
			SourceModel() : Textmagic::BaseModel(){};
			SourceModel(const std::string& data) : Textmagic::BaseModel(data){};

			void deserialize();
			Textmagic::Rest::RequestData serialize();
		
			std::string id;
			Json::Value dedicated;
			Json::Value user;
			Json::Value shared;
			Json::Value senderIds;

	};
}

#endif /* TEXTMAGIC_SOURCE_H */