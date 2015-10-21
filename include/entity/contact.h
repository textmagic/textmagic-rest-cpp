#ifndef TEXTMAGIC_CONTACT_H
#define TEXTMAGIC_CONTACT_H

#include <entity/base.h>

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

			void deserialize();
			Textmagic::Rest::RequestData serialize() const;

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