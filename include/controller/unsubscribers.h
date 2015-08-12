namespace Textmagic {
	class UnsubscribersController: public Textmagic::BaseController<Textmagic::UnsubscriberModel>   {
		public:
			UnsubscribersController(Textmagic::Rest* r, std::string path) : Textmagic::BaseController<Textmagic::UnsubscriberModel> (r, path) {}


			int update(Textmagic::UnsubscriberModel& entity) {
				return 0;
			};

			bool remove(std::string id) {
				return false;
			};

			Textmagic::Resources<Textmagic::UnsubscriberModel> search(Rest::RequestData& options){
				Textmagic::Resources<Textmagic::UnsubscriberModel> r;
				return r;
			};
	};
}