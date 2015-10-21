#ifndef TEXTMAGIC_TEMPLATE_H
#define TEXTMAGIC_TEMPLATE_H

#include <entity/base.h>

namespace Textmagic {
	class TemplateModel:public Textmagic::BaseModel {
		public:
			TemplateModel() : Textmagic::BaseModel(){};
			TemplateModel(const std::string& data) : Textmagic::BaseModel(data){};

			void deserialize();
			Textmagic::Rest::RequestData serialize() const;
		
			std::string name;
			std::string content;
			std::string lastModified;

	};
}

#endif /* TEXTMAGIC_TEMPLATE_H */