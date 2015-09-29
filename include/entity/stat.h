#ifndef TEXTMAGIC_STAT_H
#define TEXTMAGIC_STAT_H

#include <entity/base.h>

namespace Textmagic {
	class StatModel:public Textmagic::BaseModel {
		public:
			StatModel() : Textmagic::BaseModel(){};
			StatModel(const std::string& data) : Textmagic::BaseModel(data){};

			void deserialize();
			// the model is not used in POST/PUT requests
			//Textmagic::Rest::RequestData serialize() const;
		
			std::string id;
			int replyRate;
			std::string date;
			float deliveryRate;
			float costs;
			int messagesReceived;
			int messagesSentDelivered;
			int messagesSentAccepted;
			int messagesSentBuffered;
			int messagesSentFailed;
			int messagesSentRejected;
			int messagesSentParts;

	};
}

#endif /* TEXTMAGIC_STAT_H */