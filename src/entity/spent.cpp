#include <entity/spent.h>

using namespace Textmagic;


void SpentModel::deserialize() {
	Json::Value root = this->asJsonValue();
	id = root.get("id", "").asString();
	userId = root.get("userId", "").asString();
	date = root.get("date", "").asString();
	type = root.get("type", "").asString();
	value = root.get("value", "").asString();
	comment = root.get("comment", "").asString();
	balance = root.get("balance", 0).asFloat();
	delta = root.get("delta", 0).asFloat();
};

