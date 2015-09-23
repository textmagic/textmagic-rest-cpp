#pragma once

#include <controller/base.h>
#include <entity/bulk.h>

namespace Textmagic {
	class BulksController: public Textmagic::BaseController<Textmagic::BulkModel>   {
		public:
			BulksController(Textmagic::Rest* r, std::string path) : Textmagic::BaseController<Textmagic::BulkModel> (r, path) {}

			int create(Textmagic::BulkModel& entity) {
				return 0;
			};

			int update(Textmagic::BulkModel& entity) {
				return 0;
			};
			
			bool remove(std::string id) {
				return false;
			};

			Textmagic::Resources<Textmagic::BulkModel> search(Rest::RequestData& options){
				Textmagic::Resources<Textmagic::BulkModel> r;
				return r;
			};

			Textmagic::Resources<Textmagic::BulkModel> search(){
				Rest::RequestData options;
				return search(options);
			};


	};
}