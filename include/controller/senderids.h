namespace Textmagic {
	class SenderIdsController: public Textmagic::BaseController<Textmagic::SenderIdModel>   {
		public:
			SenderIdsController(Textmagic::Rest* r, std::string path) : Textmagic::BaseController<Textmagic::SenderIdModel> (r, path) {}

			int create(Rest::RequestData& data) {
				BaseModel e(rest.request(basePath, "POST", data));
				if (errorHandler(e)) {
					int id = e.asJsonValue().get("id", 0).asInt();
					return id;
				} else {
					return 0;
				}
			};

			int update(Textmagic::SenderIdModel& entity) {
				return 0;
			};
			
			Textmagic::Resources<Textmagic::SenderIdModel> search(Rest::RequestData& options){
				Textmagic::Resources<Textmagic::SenderIdModel> r;
				return r;
			};

			Textmagic::Resources<Textmagic::SenderIdModel> search(){
				Rest::RequestData options;
				return search(options);
			};

	};
}