#include <entity/chat.h>

using namespace Textmagic;

void ChatModel::deserialize() {
	Json::Value root = this->asJsonValue();
	id = root.get("id", "").asString();
	phone = root.get("phone", "").asString();
	contactId = root.get("contactId", "").asString();
	unread = root.get("unread", 0).asInt();
	updatedAt = root.get("updatedAt", "").asString();
};