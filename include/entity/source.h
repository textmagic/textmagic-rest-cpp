#ifndef TEXTMAGIC_SOURCE_H
#define TEXTMAGIC_SOURCE_H

namespace Textmagic {
	class SourceModel:public Textmagic::BaseModel {
		public:
			SourceModel() : Textmagic::BaseModel(){};
			SourceModel(const std::string& data) : Textmagic::BaseModel(data){};

			void deserialize() {
				Json::Value root = this->asJsonValue();
			 	id = root.get("id", "").asString();
			 	dedicated = root["dedicated"];
			 	user = root["user"];
			 	shared = root["shared"];
			 	senderIds = root["senderIds"];
			};

			Textmagic::Rest::RequestData serialize(){
				Textmagic::Rest::RequestData data;
				return data;
			};

			std::string id;
			Json::Value dedicated;
			Json::Value user;
			Json::Value shared;
			Json::Value senderIds;

	};
}

#endif /* TEXTMAGIC_SOURCE_H */