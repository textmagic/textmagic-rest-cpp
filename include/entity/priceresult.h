#ifndef TEXTMAGIC_PRICERESULT_H
#define TEXTMAGIC_PRICERESULT_H

namespace Textmagic {
	class PriceResultModel:public Textmagic::BaseModel {
		public:
			PriceResultModel() : Textmagic::BaseModel(){};
			PriceResultModel(const std::string& data) : Textmagic::BaseModel(data){};

			void deserialize() {
				Json::Value root = this->asJsonValue();
			 	id = "";
			 	total = root.get("total", 0).asFloat();
				parts = root.get("parts", 0).asInt();
				countries = root["countries"];
			};

			Textmagic::Rest::RequestData serialize(){
				Textmagic::Rest::RequestData data;
				return data;
			};

			std::string id;
			float total;
			int parts;
			Json::Value countries;
	};
}

#endif /* TEXTMAGIC_PRICERESULT_H */