namespace Textmagic {
	class MessagesController: public Textmagic::BaseController<Textmagic::MessageModel>   {
		public:
			MessagesController(Textmagic::Rest* r, std::string path) : Textmagic::BaseController<Textmagic::MessageModel> (r, path) {}

			int create(Textmagic::MessageModel& entity) {
				return 0;
			};

			int update(Textmagic::MessageModel& entity) {
				return 0;
			};


			Textmagic::PriceResultModel price(Rest::RequestData& data) {
				Textmagic::PriceResultModel e(rest.request(basePath + "/price", "GET", data));
				if (errorHandler(e)) {
					e.deserialize();
				}
				return e;
			};

			Textmagic::SendResultModel send(Rest::RequestData& data) {
				Textmagic::SendResultModel e(rest.request(basePath, "POST", data));
				if (errorHandler(e)) {
					e.deserialize();
				}
				return e;
			};

	};
}