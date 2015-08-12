namespace Textmagic {
	class SessionsController: public Textmagic::BaseController<Textmagic::SessionModel>   {
		public:
			SessionsController(Textmagic::Rest* r, std::string path) : Textmagic::BaseController<Textmagic::SessionModel> (r, path) {}

			int create(Textmagic::SessionModel& entity) {
				return 0;
			};

			int update(Textmagic::SessionModel& entity) {
				return 0;
			};

			Textmagic::Resources<Textmagic::SessionModel> search(Rest::RequestData& options){
				Textmagic::Resources<Textmagic::SessionModel> r;
				return r;
			};

			Textmagic::Resources<Textmagic::SessionModel> search(){
				Rest::RequestData options;
				return search(options);
			};


			Resources<Textmagic::MessageModel> messages(std::string id, Textmagic::Rest::RequestData& data) {
				std::string path = basePath + "/" + id + "/messages";
				return getResources<Textmagic::MessageModel>(path, data);
			};

			Resources<Textmagic::MessageModel> messages(std::string id) {
			 	Textmagic::Rest::RequestData data;
				return messages(id, data);
			};

	};
}