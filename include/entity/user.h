#ifndef TEXTMAGIC_USER_H
#define TEXTMAGIC_USER_H

namespace Textmagic {
	class UserModel:public Textmagic::BaseModel {
		public:
			UserModel() : Textmagic::BaseModel(){};
			UserModel(const std::string& data) : Textmagic::BaseModel(data){};

			void deserialize() {
				Json::Value root = this->asJsonValue();
			 	id = root.get("id", "").asString();
			 	firstName = root.get("firstName", "").asString();
				lastName = root.get("lastName", "").asString();
				company = root.get("company", "").asString();
				username = root.get("username", "").asString();
				status = root.get("status", "").asString();
				subaccountType = root.get("subaccountType", "").asString();
				currency = root["currency"].get("id", "").asString();
				timezone = root["timezone"].get("timezone", "").asString();
				timezoneOffset = root["timezone"].get("offset", 0).asInt();
				balance = root.get("balance", 0).asFloat();
			};

			Textmagic::Rest::RequestData serialize(){
				Textmagic::Rest::RequestData data;
				data["firstName"] = firstName;
                data["lastName"] = lastName;
                data["company"] = company;
				return data;
			};

			std::string id;
			std::string firstName;
			std::string lastName;
			std::string company;
			std::string timezone;
			int timezoneOffset;
			std::string username;
			std::string status;
			float balance;
			std::string currency;
			std::string subaccountType;
	};
}

#endif /* TEXTMAGIC_USER_H */