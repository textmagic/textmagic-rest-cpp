#ifndef TEXTMAGIC_TEMPLATE_H
#define TEXTMAGIC_TEMPLATE_H

namespace Textmagic {
	class TemplateModel:public Textmagic::BaseModel {
		public:
			TemplateModel() : Textmagic::BaseModel(){};
			TemplateModel(const std::string& data) : Textmagic::BaseModel(data){};

			void deserialize() {
				Json::Value root = this->asJsonValue();
			 	id = root.get("id", "").asString();
			 	name = root.get("name", "").asString();
			 	content = root.get("content", "").asString();
			 	lastModified = root.get("lastModified", "").asString();
			};

			Textmagic::Rest::RequestData serialize(){
				Textmagic::Rest::RequestData data;
				data["name"] = name;
				data["content"] = content;
				return data;
			};

			std::string id;
			std::string name;
			std::string content;
			std::string lastModified;

	};
}

#endif /* TEXTMAGIC_TEMPLATE_H */