#ifndef TEXTMAGIC_SESSION_H
#define TEXTMAGIC_SESSION_H

namespace Textmagic {
	class SessionModel:public Textmagic::BaseModel {
		public:
			SessionModel() : Textmagic::BaseModel(){};
			SessionModel(const std::string& data) : Textmagic::BaseModel(data){};

			void deserialize() {
				Json::Value root = this->asJsonValue();
			 	id = root.get("id", "").asString();
			 	startTime = root.get("startTime", "").asString();
			 	text = root.get("text", "").asString();
			 	source = root.get("source", "").asString();
			 	referenceId = root.get("referenceId", "").asString();
			 	price = root.get("price", 0).asFloat();
			 	numbersCount = root.get("numbersCount", 0).asInt();
			};

			Textmagic::Rest::RequestData serialize(){
				Textmagic::Rest::RequestData data;
				return data;
			};

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