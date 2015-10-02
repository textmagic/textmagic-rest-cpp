#include <entity/message.h>


using namespace Textmagic;

void MessageModel::deserialize() {
	Json::Value root = this->asJsonValue();
	id = root.get("id", "").asString();
	direction = root.get("direction", "o").asString();   // ???
	receiver = root.get("receiver", "").asString();
	messageTime = root.get("messageTime", "").asString();
	status = root.get("status", "").asString();
	text = root.get("text", "").asString();
	charset = root.get("charset", "").asString();
	firstName = root.get("firstName", "").asString();
	lastName = root.get("lastName", "").asString();
	country = root.get("country", "").asString();
	sender = root.get("sender", "").asString();
	price = root.get("price", 0).asFloat();
	partsCount = root.get("partsCount", 0).asInt();
	
};

/*
Rest::RequestData MessageModel::serialize() const {
	
	Textmagic::Rest::RequestData data;
	return data;
};
*/