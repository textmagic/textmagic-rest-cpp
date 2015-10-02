#include <entity/base.h>

using namespace Textmagic;

Json::Value BaseModel::asJsonValue() const {
	Json::Value root;
	Json::Reader reader;
	if (!reader.parse(response, root)){
		throw  "Failed to parse responce\n" + reader.getFormattedErrorMessages();
		return root;
	}
	return root;
};


Rest::RequestData BaseModel::serialize() const {
	Textmagic::Rest::RequestData data;
	return data;
};
