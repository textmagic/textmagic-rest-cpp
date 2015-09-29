#include <entity/reply.h>

using namespace Textmagic;


void ReplyModel::deserialize() {
	Json::Value root = this->asJsonValue();
	id = root.get("id", "").asString();
	sender = root.get("sender", "").asString();
	messageTime = root.get("messageTime", "").asString();
	text = root.get("text", "").asString();
	receiver = root.get("receiver", "").asString();
	
};
