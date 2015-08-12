#ifndef TEXTMAGIC_SCHEDULE_H
#define TEXTMAGIC_SCHEDULE_H

namespace Textmagic {
	class ScheduleModel:public Textmagic::BaseModel {
		public:
			ScheduleModel() : Textmagic::BaseModel(){};
			ScheduleModel(const std::string& data) : Textmagic::BaseModel(data){};

			void deserialize() {
				Json::Value root = this->asJsonValue();
			 	id = root.get("id", "").asString();
			 	nextSend = root.get("nextSend", "").asString();
			 	sessionId = root.get("sessionId", "").asString();
			};

			Textmagic::Rest::RequestData serialize(){
				Textmagic::Rest::RequestData data;
				return data;
			};

			std::string id;
			std::string nextSend;
			std::string sessionId;

	};
}

#endif /* TEXTMAGIC_SCHEDULE_H */