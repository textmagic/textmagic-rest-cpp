#ifndef TEXTMAGIC_UNSUBSCRIBER_H
#define TEXTMAGIC_UNSUBSCRIBER_H

namespace Textmagic {
	class UnsubscriberModel:public Textmagic::BaseModel {
		public:
			UnsubscriberModel() : Textmagic::BaseModel(){};
			UnsubscriberModel(const std::string& data) : Textmagic::BaseModel(data){};

			void deserialize() {
				Json::Value root = this->asJsonValue();
			 	id = root.get("id", "").asString();
			 	phone = root.get("phone", "").asString();
			 	unsubscribeTime = root.get("unsubscribeTime", "").asString();
			 	firstName = root.get("firstName", "").asString();
			 	lastName = root.get("lastName", "").asString();


			};

			Textmagic::Rest::RequestData serialize(){
				Textmagic::Rest::RequestData data;
				data["phone"] = phone;
				return data;
			};

			std::string id;
			std::string phone;
			std::string unsubscribeTime;
			std::string firstName;
			std::string lastName;
	};
}

#endif /* TEXTMAGIC_UNSUBSCRIBER_H */