#include <entity/schedule.h>

using namespace Textmagic;


void ScheduleModel::deserialize() {
	Json::Value root = this->asJsonValue();
	id = root.get("id", "").asString();
	nextSend = root.get("nextSend", "").asString();
	sessionId = root.get("sessionId", "").asString();
};
