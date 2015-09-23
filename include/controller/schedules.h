#pragma once

#include <controller/base.h>
#include <entity/schedule.h>


namespace Textmagic {
	class SchedulesController: public Textmagic::BaseController<Textmagic::ScheduleModel>   {
		public:
			SchedulesController(Textmagic::Rest* r, std::string path) : Textmagic::BaseController<Textmagic::ScheduleModel> (r, path) {}

			int create(Textmagic::ScheduleModel& entity) {
				return 0;
			};

			int update(Textmagic::ScheduleModel& entity) {
				return 0;
			};

			bool remove(std::string id) {
				return false;
			};

			Textmagic::Resources<Textmagic::ScheduleModel> search(Rest::RequestData& options){
				Textmagic::Resources<Textmagic::ScheduleModel> r;
				return r;
			};

	};
}