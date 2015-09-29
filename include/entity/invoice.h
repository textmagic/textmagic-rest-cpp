#ifndef TEXTMAGIC_INVOICE_H
#define TEXTMAGIC_INVOICE_H

#include <entity/base.h>

namespace Textmagic {
	class InvoiceModel:public Textmagic::BaseModel {
		public:
			InvoiceModel() : Textmagic::BaseModel(){};
			InvoiceModel(const std::string& data) : Textmagic::BaseModel(data){};

			void deserialize();
			// the model is not used in POST/PUT requests
			//Textmagic::Rest::RequestData serialize() const;
		
			std::string id;
			int bundle;
			std::string currency;
			float vat;
			std::string paymentMethod;

	};
}

#endif /* TEXTMAGIC_INVOICE_H */