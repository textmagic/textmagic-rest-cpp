#ifndef TEXTMAGIC_BULK_H
#define TEXTMAGIC_BULK_H

namespace Textmagic {
	class BulkModel:public Textmagic::BaseModel {
		public:
			BulkModel() : Textmagic::BaseModel(){};
			BulkModel(const std::string& data) : Textmagic::BaseModel(data){};

			void deserialize() {
				Json::Value root = this->asJsonValue();
			 	id = root.get("id", "").asString();
			 	status = root.get("status", "").asString();
			 	itemsProcessed = root.get("itemsProcessed", 0).asInt();
			 	itemsTotal = root.get("itemsTotal", 0).asInt();
			 	createdAt = root.get("createdAt", "").asString();
			 	sessionId = root.get("sessionId", "").asString();
			 	text = root.get("text", "").asString();
			};

			Textmagic::Rest::RequestData serialize(){
				Textmagic::Rest::RequestData data;
				return data;
			};

			std::string id;
			std::string status;
			int itemsProcessed;
			int itemsTotal;
			std::string createdAt;
			std::string sessionId;
			std::string text;

	};
}

#endif /* TEXTMAGIC_BULK_H */