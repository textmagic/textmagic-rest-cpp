#ifndef TEXTMAGIC_NUMBER_H
#define TEXTMAGIC_NUMBER_H

#include <entity/base.h>

namespace Textmagic {
	class NumberModel:public Textmagic::BaseModel {
		public:
			NumberModel() : Textmagic::BaseModel(){};
			NumberModel(const std::string& data) : Textmagic::BaseModel(data){};

			void deserialize();
			Textmagic::Rest::RequestData serialize();
		
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