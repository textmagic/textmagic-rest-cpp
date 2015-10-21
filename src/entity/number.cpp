#include <entity/number.h>

using namespace Textmagic;


void NumberModel::deserialize() {
	Json::Value root = this->asJsonValue();
	id = root.get("id", "").asString();
	userId = root["user"].get("id", "").asString();
	username = root["user"].get("username", "").asString();
	purchasedAt = root.get("purchasedAt", "").asString();
	expireAt = root.get("expireAt", "").asString();
	phone = root.get("phone", "").asString();
	country = root["country"].get("id", "").asString();
	countryName = root["country"].get("name", "").asString();
	status = root.get("status", "").asString();
	
};


Rest::RequestData NumberModel::serialize() const {
	Textmagic::Rest::RequestData data;
	data["phone"] = phone;
	data["country"] = country;
	data["userId"] = userId;
	return data;
};
