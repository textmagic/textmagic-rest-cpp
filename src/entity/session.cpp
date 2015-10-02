#include <entity/session.h>

using namespace Textmagic;


void SessionModel::deserialize() {
	Json::Value root = this->asJsonValue();
	id = root.get("id", "").asString();
	startTime = root.get("startTime", "").asString();
	text = root.get("text", "").asString();
	source = root.get("source", "").asString();
	referenceId = root.get("referenceId", "").asString();
	price = root.get("price", 0).asFloat();
	numbersCount = root.get("numbersCount", 0).asInt();
};