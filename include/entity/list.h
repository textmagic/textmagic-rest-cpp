#ifndef TEXTMAGIC_LIST_H
#define TEXTMAGIC_LIST_H

namespace Textmagic {
	class ListModel:public Textmagic::BaseModel {
		public:
			ListModel() : Textmagic::BaseModel(){};
			ListModel(const std::string& data) : Textmagic::BaseModel(data){};

			void deserialize() {
				Json::Value root = this->asJsonValue();
			 	id = root.get("id", "").asString();
			 	name = root.get("name", "").asString();
			 	description = root.get("description", "").asString();
			 	membersCount = root.get("membersCount", 0).asInt();
			 	shared = root.get("shared", "").asBool();
			};

			Textmagic::Rest::RequestData serialize(){
				Textmagic::Rest::RequestData data;
				data["name"] = name;
				data["shared"]		 = Textmagic::Utils::toString((int)shared);
				return data;
			};

			std::string id;
			std::string name;
			std::string description;
			int membersCount;
			bool shared;

	};
}

#endif /* TEXTMAGIC_LIST_H */