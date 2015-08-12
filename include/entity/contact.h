#ifndef TEXTMAGIC_CONTACT_H
#define TEXTMAGIC_CONTACT_H

namespace Textmagic {
	class ContactModel:public Textmagic::BaseModel {
		public:
			ContactModel() : Textmagic::BaseModel(){};
			ContactModel(const std::string& data) : Textmagic::BaseModel(data){};

			struct CustomField {
                std::string id;
                std::string name;
                std::string value;
                std::string createdAt;
            };

			void deserialize() {
				Json::Value root = this->asJsonValue();
			 	id = root.get("id", "").asString();
			 	firstName = root.get("firstName", "").asString();
			 	lastName = root.get("lastName", "").asString();
			 	email = root.get("email", "").asString();
                phone = root.get("phone", "").asString();
                companyName = root.get("companyName", "").asString();
                countryId = root["country"]["id"].asString();
				countryName = root["country"]["name"].asString();
				CustomField c;
				const Json::Value array = root["customFields"];
                for(unsigned int i = 0; i < array.size(); ++i){
					c.id = array[i]["id"].asString();
					c.name = array[i]["name"].asString();
					c.value = array[i]["value"].asString();
					c.createdAt = array[i]["createdAt"].asString();
					customFields.push_back(c);
                }
			};

			Textmagic::Rest::RequestData serialize(){
				Textmagic::Rest::RequestData data;
				data["phone"] = phone;
                data["email"] = email;
				data["firstName"] = firstName;
				data["lastName"] = lastName;
				data["companyName"] = companyName;
				data["lists"] = Textmagic::Utils::vectorJoin(lists, ",");
				return data;
			};

			std::string id;
			std::string firstName;
			std::string lastName;
			std::string email;
			std::string phone;
			std::string companyName;
			std::string countryId;
			std::string countryName;
			std::vector<CustomField> customFields;
			std::vector<std::string> lists;
	};
}


#endif /* TEXTMAGIC_CONTACT_H */