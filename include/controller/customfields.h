//#pragma once
#include <controller/base.h>
#include <entity/customfield.h>

namespace Textmagic {
	class CustomfieldsController: public Textmagic::BaseController<Textmagic::CustomfieldModel>   {
		public:
			CustomfieldsController(Textmagic::Rest* r, std::string path) : Textmagic::BaseController<Textmagic::CustomfieldModel> (r, path) {}
	};
}