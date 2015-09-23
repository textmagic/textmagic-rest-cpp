#ifndef TEXTMAGIC_INVOICE_H
#define TEXTMAGIC_INVOICE_H

#include <entity/base.h>

namespace Textmagic {
	class InvoiceModel:public Textmagic::BaseModel {
		public:
			InvoiceModel() : Textmagic::BaseModel(){};
			InvoiceModel(const std::string& data) : Textmagic::BaseModel(data){};

			void deserialize();
			Textmagic::Rest::RequestData serialize();
		
			std::string id;
			int bundle;
			std::string currency;
			float vat;
			std::string paymentMethod;

	};
}

#endif /* TEXTMAGIC_INVOICE_H */