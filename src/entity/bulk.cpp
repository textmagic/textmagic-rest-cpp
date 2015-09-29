#include <entity/bulk.h>


using namespace Textmagic;

void BulkModel::deserialize()  {
	Json::Value root = this->asJsonValue();
	id = root.get("id", "").asString();
	status = root.get("status", "").asString();
	itemsProcessed = root.get("itemsProcessed", 0).asInt();
	itemsTotal = root.get("itemsTotal", 0).asInt();
	createdAt = root.get("createdAt", "").asString();
	sessionId = root.get("sessionId", "").asString();
	text = root.get("text", "").asString();
};