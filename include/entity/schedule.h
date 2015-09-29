#ifndef TEXTMAGIC_SCHEDULE_H
#define TEXTMAGIC_SCHEDULE_H

#include <entity/base.h>

namespace Textmagic {
	class ScheduleModel:public Textmagic::BaseModel {
		public:
			ScheduleModel() : Textmagic::BaseModel(){};
			ScheduleModel(const std::string& data) : Textmagic::BaseModel(data){};

			void deserialize();
			// the model is not used in POST/PUT requests
			//Textmagic::Rest::RequestData serialize() const;
		
			std::string id;
			std::string nextSend;
			std::string sessionId;

	};
}

#endif /* TEXTMAGIC_SCHEDULE_H */