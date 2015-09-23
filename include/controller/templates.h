#pragma once

#include <controller/base.h>
#include <entity/template.h>

namespace Textmagic {
	class TemplatesController: public Textmagic::BaseController<Textmagic::TemplateModel>   {
		public:
			TemplatesController(Textmagic::Rest* r, std::string path) : Textmagic::BaseController<Textmagic::TemplateModel> (r, path) {}
	};
}