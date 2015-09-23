#include <entity/customfield.h>

using namespace Textmagic;

void CustomfieldModel::deserialize() {
	Json::Value root = this->asJsonValue();
	id = root.get("id", "").asString();
	name = root.get("name", "").asString();
	createdAt = root.get("createdAt", "").asString();
};


Rest::RequestData CustomfieldModel::serialize(){
	Textmagic::Rest::RequestData data;
	data["name"] = name;
	return data;
};