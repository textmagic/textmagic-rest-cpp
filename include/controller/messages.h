#pragma once

#include "controller/base.h"
#include "entity/message.h"


#include "entity/outgoingmessage.h"
#include "entity/priceresult.h"
#include "entity/sendresult.h"

namespace Textmagic {
	class MessagesController: public Textmagic::BaseController<Textmagic::MessageModel>   {
		public:
			MessagesController(Textmagic::Rest* r, std::string path) : Textmagic::BaseController<Textmagic::MessageModel> (r, path) {}

			int create(Textmagic::MessageModel& entity) {
				return 0;
			};

			int update(Textmagic::MessageModel& entity) {
				return 0;
			};


			Textmagic::SendResultModel send (const std::string& phone, const std::string& text);
			Textmagic::PriceResultModel price (const std::string& phone, const std::string& text);
		
			Textmagic::SendResultModel send (const OutgoingMessage& mes);
			Textmagic::PriceResultModel price (const OutgoingMessage& mes);
		
			Textmagic::SendResultModel send(Rest::RequestData& data);
			Textmagic::PriceResultModel price(Rest::RequestData& data);
	};
}