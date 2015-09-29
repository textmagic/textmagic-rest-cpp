#include <controller/messages.h>

using namespace Textmagic;

Textmagic::SendResultModel MessagesController::send (const std::string& phone, const std::string& text)
{
	OutgoingMessage mes;
	mes.phones.push_back(phone);
	mes.text = text;
	return send(mes);
}

Textmagic::PriceResultModel MessagesController::price (const std::string& phone, const std::string& text)
{
	OutgoingMessage mes;
	mes.phones.push_back(phone);
	mes.text = text;
	return price(mes);
}




SendResultModel MessagesController::send (const OutgoingMessage& mes)
{
	Rest::RequestData data = mes.serialize();
	return send(data);
}


Textmagic::PriceResultModel MessagesController::price (const OutgoingMessage& mes)
{
	Rest::RequestData data = mes.serialize();
	return price(data);
}



PriceResultModel MessagesController::price(Rest::RequestData& data)
{
	
	Textmagic::PriceResultModel e(rest.request(basePath + "/price", "GET", data));
	if (errorHandler(e)) {
		e.deserialize();
	}
	return e;
}


SendResultModel MessagesController::send(Rest::RequestData& data) {
	Textmagic::SendResultModel e(rest.request(basePath, "POST", data));
	if (errorHandler(e)) {
		e.deserialize();
	}
	return e;
};