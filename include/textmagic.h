#include <vector>
#include <map>
#include <string>
#include <json/json.h>

#include <utils.h>
#include <restclient.h>
#include <entity/base.h>
#include <controller/base.h>

#include <entity/contact.h>
#include <entity/list.h>
#include <entity/template.h>
#include <entity/unsubscriber.h>
#include <entity/customfield.h>
#include <entity/reply.h>
#include <entity/schedule.h>
#include <entity/message.h>
#include <entity/session.h>
#include <entity/bulk.h>
#include <entity/chat.h>
#include <entity/sendresult.h>
#include <entity/priceresult.h>
#include <entity/invoice.h>
#include <entity/source.h>
#include <entity/spent.h>
#include <entity/stat.h>
#include <entity/number.h>
#include <entity/senderid.h>
#include <entity/user.h>

#include <controller/contacts.h>
#include <controller/lists.h>
#include <controller/templates.h>
#include <controller/unsubscribers.h>
#include <controller/customfields.h>
#include <controller/replies.h>
#include <controller/schedules.h>
#include <controller/sessions.h>
#include <controller/messages.h>
#include <controller/misc.h>
#include <controller/numbers.h>
#include <controller/senderids.h>
#include <controller/subaccounts.h>

#include <controller/bulks.h>
#include <controller/chats.h>

namespace Textmagic {
	class Client {
		public:
			Client(std::string login, std::string key);
			~Client();
			Textmagic::Rest* rest;

			Textmagic::ContactsController& Contacts(){
				return getController<Textmagic::ContactsController>(&_contacts,  "/contacts");
			};

			Textmagic::TemplatesController& Templates(){
				return getController<Textmagic::TemplatesController>(&_templates,  "/templates");
			};

			Textmagic::ListsController& Lists(){
				return getController<Textmagic::ListsController>(&_lists,  "/lists");
			};

			Textmagic::UnsubscribersController& Unsubscribers(){
				return getController<Textmagic::UnsubscribersController>(&_unsubscribers,  "/unsubscribers");
			};

			Textmagic::CustomfieldsController& Customfields(){
				return getController<Textmagic::CustomfieldsController>(&_customfields,  "/customfields");
			};

			Textmagic::RepliesController& Replies(){
				return getController<Textmagic::RepliesController>(&_replies,  "/replies");
			};

			Textmagic::SchedulesController& Schedules(){
				return getController<Textmagic::SchedulesController>(&_schedules,  "/schedules");
			};

			Textmagic::SessionsController& Sessions(){
				return getController<Textmagic::SessionsController>(&_sessions,  "/sessions");
			};

			Textmagic::BulksController& Bulks(){
				return getController<Textmagic::BulksController>(&_bulks,  "/bulks");
			};

			Textmagic::ChatsController& Chats(){
				return getController<Textmagic::ChatsController>(&_chats,  "/chats");
			};

			Textmagic::MessagesController& Messages(){
				return getController<Textmagic::MessagesController>(&_messages,  "/messages");
			};

			Textmagic::MiscController& Misc(){
                return getController<Textmagic::MiscController>(&_misc,  "");
            };

			Textmagic::NumbersController& Numbers(){
				return getController<Textmagic::NumbersController>(&_numbers,  "/numbers");
			};

			Textmagic::SenderIdsController& SenderIds(){
				return getController<Textmagic::SenderIdsController>(&_senderids,  "/senderids");
			};

			Textmagic::SubaccountsController& Subaccounts(){
				return getController<Textmagic::SubaccountsController>(&_subaccounts,  "/subaccounts");
			};

		private:
			template <class TController>
       			TController& getController(TController **p, std::string path){
       				if (! *p) {
						*p = new TController(rest, path);
					}
					return *(*p);
       			}

			Textmagic::ContactsController* _contacts;
			Textmagic::TemplatesController* _templates;
			Textmagic::ListsController* _lists;
			Textmagic::UnsubscribersController* _unsubscribers;
			Textmagic::CustomfieldsController* _customfields;
			Textmagic::RepliesController* _replies;
			Textmagic::SchedulesController* _schedules;
			Textmagic::SessionsController* _sessions;
			Textmagic::BulksController* _bulks;
			Textmagic::ChatsController* _chats;
			Textmagic::MessagesController* _messages;
			Textmagic::MiscController* _misc;
			Textmagic::NumbersController* _numbers;
			Textmagic::SenderIdsController* _senderids;
			Textmagic::SubaccountsController* _subaccounts;
	};

}