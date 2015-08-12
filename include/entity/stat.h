#ifndef TEXTMAGIC_STAT_H
#define TEXTMAGIC_STAT_H

namespace Textmagic {
	class StatModel:public Textmagic::BaseModel {
		public:
			StatModel() : Textmagic::BaseModel(){};
			StatModel(const std::string& data) : Textmagic::BaseModel(data){};

			void deserialize() {
				Json::Value root = this->asJsonValue();
			 	id = root.get("id", "").asString();
			 	replyRate = root.get("replyRate", 0).asInt();
			 	messagesReceived = root.get("messagesReceived", 0).asInt();
			 	messagesSentDelivered = root.get("messagesSentDelivered", 0).asInt();
			 	messagesSentAccepted = root.get("messagesSentAccepted", 0).asInt();
			 	messagesSentBuffered = root.get("messagesSentBuffered", 0).asInt();
			 	messagesSentFailed = root.get("messagesSentFailed", 0).asInt();
			 	messagesSentRejected = root.get("messagesSentRejected", 0).asInt();
			 	messagesSentParts = root.get("messagesSentParts", 0).asInt();
			 	deliveryRate = root.get("deliveryRate", 0).asFloat();
			 	costs = root.get("costs", 0).asFloat();
			 	date = root.get("date", "").asString();
			};

			Textmagic::Rest::RequestData serialize(){
				Textmagic::Rest::RequestData data;
				return data;
			};

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