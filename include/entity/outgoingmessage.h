#pragma once

#include <entity/base.h>

namespace Textmagic {
	class OutgoingMessage {
		public:
		OutgoingMessage() : partsCount(0) {}
			Textmagic::Rest::RequestData serialize() const;
			std::string text;
			std::string templateId;
			std::string sendingTime; // Optional (required with rrule set)
			std::vector<std::string> contacts;
			std::vector<std::string> lists;
			std::vector<std::string> phones;
			bool cutExtra;
			size_t partsCount;
			std::string referenceId;
			std::string from;
			std::string rrule;
			bool dummy;				// if true then get price
	};
}
