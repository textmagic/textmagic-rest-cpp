#ifndef TEXTMAGIC_BULK_H
#define TEXTMAGIC_BULK_H

#include <entity/base.h>

namespace Textmagic {
	class BulkModel:public Textmagic::BaseModel {
		public:
			BulkModel() : Textmagic::BaseModel(){};
			BulkModel(const std::string& data) : Textmagic::BaseModel(data){};

			void deserialize();
			
			std::string status;
			int itemsProcessed;
			int itemsTotal;
			std::string createdAt;
			std::string sessionId;
			std::string text;

	};
}

#endif /* TEXTMAGIC_BULK_H */