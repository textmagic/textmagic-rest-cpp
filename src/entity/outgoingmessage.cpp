#include <entity/outgoingmessage.h>
#include <utils.h>

using namespace Textmagic;

static std::string boolToStringNumber (bool param)
{
	return param ? "1" : "0";
}

Rest::RequestData OutgoingMessage::serialize() const {
	Textmagic::Rest::RequestData data;
	data["text"] = text;
	data["templateId"] = templateId;
	data["sendingTime"] = sendingTime;
	data["contacts"] = Utils::vectorJoin(contacts, ",");
	data["lists"] = Utils::vectorJoin(lists, ",");
	data["phones"] = Utils::vectorJoin(phones, ",");;
	data["cutExtra"] = boolToStringNumber(cutExtra);
	data["partsCount"] = partsCount ? Utils::toString(partsCount) : "";
	data["referenceId"] = referenceId;
	data["from"] = from;
	data["rrule"] = rrule;
	return data;
};
