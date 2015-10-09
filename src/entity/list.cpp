#include <entity/list.h>

using namespace Textmagic;


void ListModel::deserialize() {
	Json::Value root = this->asJsonValue();
	id = root.get("id", "").asString();
	name = root.get("name", "").asString();
	description = root.get("description", "").asString();
	membersCount = root.get("membersCount", 0).asInt();
	shared = root.get("shared", "").asBool();
};


Rest::RequestData ListModel::serialize() const {
	Textmagic::Rest::RequestData data;
	data["name"] = name;
	data["shared"]		 = Textmagic::Utils::toString((int)shared);
	return data;
};