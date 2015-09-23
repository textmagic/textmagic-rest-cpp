#include <entity/senderid.h>

using namespace Textmagic;


void SenderIdModel::deserialize() {
	Json::Value root = this->asJsonValue();
	id = root.get("id", "").asString();
	senderId = root.get("senderId", "").asString();
	status = root.get("status", "").asString();
	userId = root["user"].get("id", "").asString();
	userName = root["user"].get("name", "").asString();
	
};

Rest::RequestData SenderIdModel::serialize(){
	Textmagic::Rest::RequestData data;
	data["senderId"] = senderId;
	data["explanation"] = explanation;
	return data;
};