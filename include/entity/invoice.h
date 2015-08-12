#ifndef TEXTMAGIC_INVOICE_H
#define TEXTMAGIC_INVOICE_H

namespace Textmagic {
	class InvoiceModel:public Textmagic::BaseModel {
		public:
			InvoiceModel() : Textmagic::BaseModel(){};
			InvoiceModel(const std::string& data) : Textmagic::BaseModel(data){};

			void deserialize() {
				Json::Value root = this->asJsonValue();
			 	id = root.get("id", "").asString();
			 	bundle = root.get("bundle", 0).asInt();
			 	currency = root.get("currency", "").asString();
			 	paymentMethod = root.get("paymentMethod", "").asString();
			 	vat = root.get("vat", 0).asFloat();
			};

			Textmagic::Rest::RequestData serialize(){
				Textmagic::Rest::RequestData data;
				return data;
			};

			std::string id;
			int bundle;
			std::string currency;
			float vat;
			std::string paymentMethod;

	};
}

#endif /* TEXTMAGIC_INVOICE_H */