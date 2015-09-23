#include <entity/invoice.h>

using namespace Textmagic;


void InvoiceModel::deserialize() {
	Json::Value root = this->asJsonValue();
	id = root.get("id", "").asString();
	bundle = root.get("bundle", 0).asInt();
	currency = root.get("currency", "").asString();
	paymentMethod = root.get("paymentMethod", "").asString();
	vat = root.get("vat", 0).asFloat();
};


Rest::RequestData InvoiceModel::serialize(){
	Textmagic::Rest::RequestData data;
	return data;
};