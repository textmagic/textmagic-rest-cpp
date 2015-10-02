#include <entity/sendresult.h>

using namespace Textmagic;

void SendResultModel::deserialize() {
	Json::Value root = this->asJsonValue();
	id = root.get("id", "").asString();
	href = root.get("href", "").asString();
	sessionId = root.get("sessionId", "").asString();
	type = root.get("type", "").asString();
	bulkId = root.get("bulkId", "").asString();
	messageId = root.get("messageId", "").asString();
	scheduleId = root.get("scheduleId", "").asString();
};


// serialize() is not needed

