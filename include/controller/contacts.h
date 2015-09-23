#pragma once

#include <controller/base.h>
#include <entity/contact.h>
#include <entity/list.h>

namespace Textmagic {
	class ContactsController: public Textmagic::BaseController<Textmagic::ContactModel>   {
		public:
			ContactsController(Textmagic::Rest* r, std::string path) : Textmagic::BaseController<Textmagic::ContactModel> (r, path) {}

			Resources<Textmagic::ListModel> contactLists(std::string id) {
				Textmagic::Rest::RequestData data;
				std::string path = basePath + "/" + id + "/lists";
				return getResources<Textmagic::ListModel>(path, data);
			};

			Resources<Textmagic::ListModel> contactLists(std::string id, Textmagic::Rest::RequestData& data) {
				std::string path = basePath + "/" + id + "/lists";
				return getResources<Textmagic::ListModel>(path, data);
			};
	};
}