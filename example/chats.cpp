#include <iostream>
#include <textmagic.h>

using namespace Textmagic;

int main(int argc, char* argv[]){
	if (argc < 3) {
		std::cout << "********* Please enter valid login & api key *********" << std::endl;
		std::cout << ">> bin/chats_example username C7XDKZOQZo6HvhJPtO0MBcWl3qwtp2" << std::endl;
		return 1;
	}

    std::cout << "********* ChatsController example *********" << std::endl;
    Rest::RequestData vars;
    Client tm(argv[1], argv[2]);


	//********************* list example ***********************
	std::cout << "********* ChatsController.list() *********" << std::endl;

	vars["limit"] = "5";
	vars["shared"] = "0";
	Resources<ChatModel> chats = tm.Chats().list();

	if (tm.Chats().isError) {
		std::cout
			<< tm.Chats().lastError.code << " * "
			<< tm.Chats().lastError.message << " * "
			<< std::endl;
	} else {
		std::cout  << chats.page << " * "
		   << chats.limit  << " * "
		   << chats.pageCount  << " * "
		   << chats.resources[0].phone  << " * "
		   << chats.resources[0].contactId << " * "
		   << chats.resources[0].unread  << " * "
		   << std::endl;
	}

	//********************* History example ***********************
	std::cout << "********* ChatsController.history() *********" << std::endl;

	vars["limit"] = "5";
	vars["shared"] = "0";
	Resources<MessageModel> messages = tm.Chats().history(chats.resources[0]);

	if (tm.Chats().isError) {
		std::cout
			<< tm.Chats().lastError.code << " * "
			<< tm.Chats().lastError.message << " * "
			<< std::endl;
	} else {
		std::cout
		   << messages.page << " * "
		   << messages.limit  << " * "
		   << messages.pageCount  << " * "
		   << messages.resources[0].direction  << " * "
		   << messages.resources[0].receiver  << " * "
		   << messages.resources[0].status << " * "
		   << messages.resources[0].text  << " * "
		   << std::endl;
	}

	return 0;
};

