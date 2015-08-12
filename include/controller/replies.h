namespace Textmagic {
	class RepliesController: public Textmagic::BaseController<Textmagic::ReplyModel>   {
		public:
			RepliesController(Textmagic::Rest* r, std::string path) : Textmagic::BaseController<Textmagic::ReplyModel> (r, path) {}

			int create(Textmagic::ReplyModel& entity) {
				return 0;
			};

			int update(Textmagic::ReplyModel& entity) {
				return 0;
			};

	};
}