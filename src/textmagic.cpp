#include <textmagic.h>

using namespace Textmagic;

Client::Client(std::string login, std::string key) :
_contacts(nullptr),
_templates(nullptr),
_lists(nullptr),
_unsubscribers(nullptr),
_customfields(nullptr),
_replies(nullptr),
_schedules(nullptr),
_sessions(nullptr),
_bulks(nullptr),
_chats(nullptr),
_messages(nullptr),
_misc(nullptr),
_numbers(nullptr),
_senderids(nullptr),
_subaccounts(nullptr)
{
	rest = new Textmagic::Rest (login, key);
};


Client::~Client() {
	delete rest;
	delete _contacts;
	delete _templates;
	delete _lists;
	delete _unsubscribers;
	delete _customfields;
	delete _replies;
	delete _schedules;
	delete _sessions;
	delete _bulks;
	delete _chats;
	delete _messages;
	delete _misc;
	delete _numbers;
	delete _senderids;
	delete _subaccounts;
}