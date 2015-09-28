#pragma once

#include "base.h"
#include <entity/chat.h>
#include <entity/message.h>

namespace Textmagic {
	class ChatsController: public Textmagic::BaseController<Textmagic::ChatModel>   {
		public:
			ChatsController(Textmagic::Rest* r, std::string path) : Textmagic::BaseController<Textmagic::ChatModel> (r, path) {}

			Textmagic::ChatModel get(std::string id) {
				Textmagic::ChatModel e;
                return e;
			};

			int create(Textmagic::ChatModel& entity) {
				return 0;
			};

			int update(Textmagic::ChatModel& entity) {
				return 0;
			};
			
			bool remove(std::string id) {
				return false;
			};

			Textmagic::Resources<Textmagic::ChatModel> search(Rest::RequestData& options){
				Textmagic::Resources<Textmagic::ChatModel> r;
				return r;
			};

			Textmagic::Resources<Textmagic::ChatModel> search(){
				Rest::RequestData options;
				return search(options);
			};


			Resources<Textmagic::MessageModel> history(std::string phone, Textmagic::Rest::RequestData& data) {
				std::string path = basePath + "/" + phone ;
				return getResources<Textmagic::MessageModel>(path, data);
			};

			Resources<Textmagic::MessageModel> history(std::string phone) {
			 	Textmagic::Rest::RequestData data;
				return history(phone, data);
			};

			Resources<Textmagic::MessageModel> history(Textmagic::ChatModel& entity) {
				Textmagic::Rest::RequestData data;
				return history(entity.phone, data);
			};

	};
}