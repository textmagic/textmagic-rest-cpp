#ifndef TEXTMAGIC_CUSTOMFIELD_H
#define TEXTMAGIC_CUSTOMFIELD_H

namespace Textmagic {
	class CustomfieldModel:public Textmagic::BaseModel {
		public:
			CustomfieldModel() : Textmagic::BaseModel(){};
			CustomfieldModel(const std::string& data) : Textmagic::BaseModel(data){};

			void deserialize() {
				Json::Value root = this->asJsonValue();
			 	id = root.get("id", "").asString();
			 	name = root.get("name", "").asString();
			 	createdAt = root.get("createdAt", "").asString();
			};

			Textmagic::Rest::RequestData serialize(){
				Textmagic::Rest::RequestData data;
				data["name"] = name;
				return data;
			};

			std::string id;
			std::string name;
			std::string createdAt;

	};
}

#endif /* TEXTMAGIC_CUSTOMFIELD_H */