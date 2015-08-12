#ifndef TEXTMAGIC_SPENT_H
#define TEXTMAGIC_SPENT_H

namespace Textmagic {
	class SpentModel:public Textmagic::BaseModel {
		public:
			SpentModel() : Textmagic::BaseModel(){};
			SpentModel(const std::string& data) : Textmagic::BaseModel(data){};

			void deserialize() {
				Json::Value root = this->asJsonValue();
			 	id = root.get("id", "").asString();
			 	userId = root.get("userId", "").asString();
                date = root.get("date", "").asString();
                type = root.get("type", "").asString();
                value = root.get("value", "").asString();
                comment = root.get("comment", "").asString();
			 	balance = root.get("balance", 0).asFloat();
                delta = root.get("delta", 0).asFloat();
			};

			Textmagic::Rest::RequestData serialize(){
				Textmagic::Rest::RequestData data;
				return data;
			};

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