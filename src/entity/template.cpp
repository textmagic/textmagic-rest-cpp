#include <entity/template.h>

using namespace Textmagic;


void TemplateModel::deserialize() {
	Json::Value root = this->asJsonValue();
	id = root.get("id", "").asString();
	name = root.get("name", "").asString();
	content = root.get("content", "").asString();
	lastModified = root.get("lastModified", "").asString();
};

Rest::RequestData TemplateModel::serialize() const {
	Textmagic::Rest::RequestData data;
	data["name"] = name;
	data["content"] = content;
	return data;
};
