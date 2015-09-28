#pragma once

#include <controller/base.h>
#include <entity/number.h>

namespace Textmagic {
	class NumbersController: public Textmagic::BaseController<Textmagic::NumberModel>   {
		public:
			NumbersController(Textmagic::Rest* r, std::string path) : Textmagic::BaseController<Textmagic::NumberModel> (r, path) {}


			int buy(Rest::RequestData& data) {
				BaseModel e(rest.request(basePath, "POST", data));
				if (errorHandler(e)) {
					int id = e.asJsonValue().get("id", 0).asInt();
				    return id;
				} else {
				    return 0;
				}
			};


			Json::Value available(Rest::RequestData& data) {
				BaseModel e(rest.request(basePath + "/available", "GET", data));
				errorHandler(e);
				return e.asJsonValue();
			};

			int create(Textmagic::NumberModel& entity) {
				return 0;
			};

			int update(Textmagic::NumberModel& entity) {
				return 0;
			};
			
			Textmagic::Resources<Textmagic::NumberModel> search(Rest::RequestData& options){
				Textmagic::Resources<Textmagic::NumberModel> r;
				return r;
			};

			Textmagic::Resources<Textmagic::NumberModel> search(){
				Rest::RequestData options;
				return search(options);
			};

	};
}