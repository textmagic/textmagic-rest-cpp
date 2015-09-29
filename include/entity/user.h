#ifndef TEXTMAGIC_USER_H
#define TEXTMAGIC_USER_H

#include <entity/base.h>

namespace Textmagic {
	class UserModel:public Textmagic::BaseModel {
		public:
			UserModel() : Textmagic::BaseModel(){};
			UserModel(const std::string& data) : Textmagic::BaseModel(data){};

			void deserialize();
			Textmagic::Rest::RequestData serialize() const;
		
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