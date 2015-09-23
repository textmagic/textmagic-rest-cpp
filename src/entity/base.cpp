#include <entity/base.h>

using namespace Textmagic;

Json::Value BaseModel::asJsonValue(){
	Json::Value root;
	Json::Reader reader;
	if (!reader.parse(response, root)){
		throw  "Failed to parse responce\n" + reader.getFormattedErrorMessages();
		return root;
	}
	return root;
};
