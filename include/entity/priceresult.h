#ifndef TEXTMAGIC_PRICERESULT_H
#define TEXTMAGIC_PRICERESULT_H

#include <entity/base.h>

namespace Textmagic {
	class PriceResultModel:public Textmagic::BaseModel {
		public:
			PriceResultModel() : Textmagic::BaseModel(){};
			PriceResultModel(const std::string& data) : Textmagic::BaseModel(data){};

			void deserialize();
			// the model is not used in POST/PUT requests
			//Textmagic::Rest::RequestData serialize() const;
		
			std::string id;
			float total;
			int parts;
			Json::Value countries;
		
			float getPriceForCountry(const std::string& countryId);
		
	};
}

#endif /* TEXTMAGIC_PRICERESULT_H */