#ifndef TEXTMAGIC_SENDRESULT_H
#define TEXTMAGIC_SENDRESULT_H

#include <entity/base.h>

namespace Textmagic {
	class SendResultModel:public Textmagic::BaseModel {
		public:
			SendResultModel() : Textmagic::BaseModel(){};
			SendResultModel(const std::string& data) : Textmagic::BaseModel(data){};

			void deserialize();
			// the model is not used in POST/PUT requests
			//Textmagic::Rest::RequestData serialize() const;
		
			std::string id;
			std::string href;
			std::string type;
			std::string sessionId;
			std::string bulkId;
			std::string messageId;
			std::string scheduleId;
	};
}

#endif /* TEXTMAGIC_SENDRESULT_H */