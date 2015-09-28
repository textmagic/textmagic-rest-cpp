#include <entity/stat.h>

using namespace Textmagic;


void StatModel::deserialize() {
	Json::Value root = this->asJsonValue();
	id = root.get("id", "").asString();
	replyRate = root.get("replyRate", 0).asInt();
	messagesReceived = root.get("messagesReceived", 0).asInt();
	messagesSentDelivered = root.get("messagesSentDelivered", 0).asInt();
	messagesSentAccepted = root.get("messagesSentAccepted", 0).asInt();
	messagesSentBuffered = root.get("messagesSentBuffered", 0).asInt();
	messagesSentFailed = root.get("messagesSentFailed", 0).asInt();
	messagesSentRejected = root.get("messagesSentRejected", 0).asInt();
	messagesSentParts = root.get("messagesSentParts", 0).asInt();
	deliveryRate = root.get("deliveryRate", 0).asFloat();
	costs = root.get("costs", 0).asFloat();
	date = root.get("date", "").asString();
};

Rest::RequestData StatModel::serialize(){
	Textmagic::Rest::RequestData data;
	return data;
};