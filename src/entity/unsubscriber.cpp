#include <entity/unsubscriber.h>

using namespace Textmagic;

void UnsubscriberModel::deserialize() {
	Json::Value root = this->asJsonValue();
	id = root.get("id", "").asString();
	phone = root.get("phone", "").asString();
	unsubscribeTime = root.get("unsubscribeTime", "").asString();
	firstName = root.get("firstName", "").asString();
	lastName = root.get("lastName", "").asString();
	
	
};

Rest::RequestData UnsubscriberModel::serialize() const {
	Textmagic::Rest::RequestData data;
	data["phone"] = phone;
	return data;
};
