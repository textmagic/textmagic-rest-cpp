#ifndef TEXTMAGIC_SCHEDULE_H
#define TEXTMAGIC_SCHEDULE_H

#include <entity/base.h>

namespace Textmagic {
	class ScheduleModel:public Textmagic::BaseModel {
		public:
			ScheduleModel() : Textmagic::BaseModel(){};
			ScheduleModel(const std::string& data) : Textmagic::BaseModel(data){};

			void deserialize();
			Textmagic::Rest::RequestData serialize();
		
			std::string id;
			std::string nextSend;
			std::string sessionId;

	};
}

#endif /* TEXTMAGIC_SCHEDULE_H */