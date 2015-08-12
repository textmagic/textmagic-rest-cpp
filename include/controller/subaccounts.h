namespace Textmagic {
	class SubaccountsController: public Textmagic::BaseController<Textmagic::UserModel>   {
		public:
			SubaccountsController(Textmagic::Rest* r, std::string path) : Textmagic::BaseController<Textmagic::UserModel> (r, path) {}

			bool invite(Rest::RequestData& data) {
				BaseModel e(rest.request(basePath, "POST", data));
				return errorHandler(e);
			};

			int create(Textmagic::UserModel& entity) {
				return 0;
			};

			int update(Textmagic::UserModel& entity) {
				return 0;
			};
			
			Textmagic::Resources<Textmagic::UserModel> search(Rest::RequestData& options){
				Textmagic::Resources<Textmagic::UserModel> r;
				return r;
			};

			Textmagic::Resources<Textmagic::UserModel> search(){
				Rest::RequestData options;
				return search(options);
			};

	};
}