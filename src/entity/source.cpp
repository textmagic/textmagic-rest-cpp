#include <entity/source.h>

using namespace Textmagic;


void SourceModel::deserialize() {
	Json::Value root = this->asJsonValue();
	id = root.get("id", "").asString();
	dedicated = root["dedicated"];
	user = root["user"];
	shared = root["shared"];
	senderIds = root["senderIds"];
};