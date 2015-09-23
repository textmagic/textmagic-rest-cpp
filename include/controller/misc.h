#pragma once

#include <controller/base.h>
#include <entity/base.h>
#include <entity/invoice.h>
#include <entity/stat.h>
#include <entity/spent.h>
#include <entity/source.h>
#include <entity/user.h>

namespace Textmagic {
	class MiscController: public Textmagic::BaseController<Textmagic::BaseModel>   {
		public:
			MiscController(Textmagic::Rest* r, std::string path) : Textmagic::BaseController<Textmagic::BaseModel> (r, path) {}

			Textmagic::BaseModel get(std::string id) {
				Textmagic::BaseModel e;
                return e;
			};

			int create(Textmagic::BaseModel& entity) {
				return 0;
			};

			int update(Textmagic::BaseModel& entity) {
				return 0;
			};
			
			bool remove(std::string id) {
				return false;
			};

			Textmagic::Resources<Textmagic::BaseModel> search(Rest::RequestData& options){
				Textmagic::Resources<Textmagic::BaseModel> r;
				return r;
			};

			Textmagic::Resources<Textmagic::BaseModel> search(){
				Rest::RequestData options;
				return search(options);
			};

		    Textmagic::Resources<Textmagic::BaseModel> list(Rest::RequestData& options){
				Textmagic::Resources<Textmagic::BaseModel> r;
				return r;
			};

			Textmagic::Resources<Textmagic::BaseModel> list(){
				Rest::RequestData options;
				return list(options);
			};


			Resources<Textmagic::InvoiceModel> invoices(Textmagic::Rest::RequestData& data) {
				std::string path = basePath + "/invoices" ;
				return getResources<Textmagic::InvoiceModel>(path, data);
			};

			Resources<Textmagic::InvoiceModel> invoices() {
			 	Textmagic::Rest::RequestData data;
				return invoices(data);
			};

	        Resources<Textmagic::StatModel> statsMessaging(Textmagic::Rest::RequestData& data) {
				std::string path = basePath + "/stats/messaging" ;
				return getResources<Textmagic::StatModel>(path, data);
			};

			Resources<Textmagic::StatModel> statsMessaging() {
			 	Textmagic::Rest::RequestData data;
				return statsMessaging(data);
			};

            Resources<Textmagic::SpentModel> statsSpending(Textmagic::Rest::RequestData& data) {
                std::string path = basePath + "/stats/spending" ;
                return getResources<Textmagic::SpentModel>(path, data);
            };

            Resources<Textmagic::SpentModel> statsSpending() {
                Textmagic::Rest::RequestData data;
                return statsSpending(data);
            };


	        Textmagic::SourceModel sources() {
				Rest::RequestData data;
				Textmagic::SourceModel e(rest.request(basePath + "/sources", "GET", data));
                if (errorHandler(e)) {
                    e.deserialize();
                }
				return e;
			};

			Textmagic::UserModel userInfo() {
				Rest::RequestData data;
				Textmagic::UserModel e(rest.request(basePath + "/user", "GET", data));
				if (errorHandler(e)) {
					e.deserialize();
				}
				return e;
			};

			bool updateUserInfo(Textmagic::UserModel& user) {
				Rest::RequestData data = user.serialize();
				Textmagic::UserModel e(rest.request(basePath + "/user", "PUT", data));
				return errorHandler(e);
			};

	};
}