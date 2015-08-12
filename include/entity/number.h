#ifndef TEXTMAGIC_NUMBER_H
#define TEXTMAGIC_NUMBER_H

namespace Textmagic {
	class NumberModel:public Textmagic::BaseModel {
		public:
			NumberModel() : Textmagic::BaseModel(){};
			NumberModel(const std::string& data) : Textmagic::BaseModel(data){};

			void deserialize() {
				Json::Value root = this->asJsonValue();
			 	id = root.get("id", "").asString();
			 	userId = root["user"].get("id", "").asString();
			 	username = root["user"].get("username", "").asString();
			 	purchasedAt = root.get("purchasedAt", "").asString();
			 	expireAt = root.get("expireAt", "").asString();
			 	phone = root.get("phone", "").asString();
			 	country = root["country"].get("id", "").asString();
			 	countryName = root["country"].get("name", "").asString();
			 	status = root.get("status", "").asString();

			};

			Textmagic::Rest::RequestData serialize(){
				Textmagic::Rest::RequestData data;
				data["phone"] = phone;
				data["country"] = country;
				data["userId"] = userId;
				return data;
			};

			std::string id;
			std::string userId;
			std::string username;
			std::string purchasedAt;
			std::string expireAt;
			std::string phone;
			std::string country;
			std::string countryName;
			std::string status;
	};
}

#endif /* TEXTMAGIC_NUMBER_H */