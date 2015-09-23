#pragma once

#include <controller/base.h>
#include <entity/list.h>
#include <entity/contact.h>

namespace Textmagic {
	class ListsController: public Textmagic::BaseController<Textmagic::ListModel>   {
		public:
			ListsController(Textmagic::Rest* r, std::string path) : Textmagic::BaseController<Textmagic::ListModel> (r, path) {}

			Resources<Textmagic::ContactModel> contactsByList(std::string id) {
				Textmagic::Rest::RequestData data;
				std::string path = basePath + "/" + id + "/contacts";
				return contactsByList(id, data);
			};

			Resources<Textmagic::ContactModel> contactsByList(std::string id, Textmagic::Rest::RequestData& data) {
				std::string path = basePath + "/" + id + "/contacts";
				return getResources<Textmagic::ContactModel>(path, data);
			};

			int assign(std::string& id, std::vector<std::string>& contacts) {
				return assignRequest(id, contacts, "PUT");
			};

			int assign(Textmagic::ListModel& list, std::vector<std::string>& contacts) {
				return assignRequest(list.id, contacts, "PUT");
			};

			int unassign(std::string& id, std::vector<std::string>& contacts) {
				return assignRequest(id, contacts, "DELETE");
			};

			int unassign(Textmagic::ListModel& list, std::vector<std::string>& contacts) {
				return assignRequest(list.id, contacts, "DELETE");
			};

			int assignRequest(std::string& id, std::vector<std::string>& contacts, std::string method) {
            	Textmagic::Rest::RequestData data;
				data["contacts"] = Textmagic::Utils::vectorJoin(contacts, ",");
				std::string path = basePath + "/" + id +"/contacts";
				Textmagic::ListModel e(rest.request(path, method, data));
				if (errorHandler(e)) {
					return e.asJsonValue().get("id", 0).asInt();
				} else {
					return 0;
				}
			}

	};
}