#include <entity/user.h>

using namespace Textmagic;

void UserModel::deserialize() {
	Json::Value root = this->asJsonValue();
	id = root.get("id", "").asString();
	firstName = root.get("firstName", "").asString();
	lastName = root.get("lastName", "").asString();
	company = root.get("company", "").asString();
	username = root.get("username", "").asString();
	status = root.get("status", "").asString();
	subaccountType = root.get("subaccountType", "").asString();
	currency = root["currency"].get("id", "").asString();
	timezone = root["timezone"].get("timezone", "").asString();
	timezoneOffset = root["timezone"].get("offset", 0).asInt();
	balance = root.get("balance", 0).asFloat();
};

Rest::RequestData UserModel::serialize() const {
	Textmagic::Rest::RequestData data;
	data["firstName"] = firstName;
	data["lastName"] = lastName;
	data["company"] = company;	
	return data;
};

