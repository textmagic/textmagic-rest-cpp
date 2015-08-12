#include <iostream>
#include <textmagic.h>

using namespace Textmagic;

int main(int argc, char* argv[]){
	if (argc < 3) {
		std::cout << "********* Please enter valid login & api key *********" << std::endl;
		std::cout << ">> bin/messages_example username C7XDKZOQZo6HvhJPtO0MBcWl3qwtp2" << std::endl;
		return 1;
	}

    std::cout << "********* MessagesController example *********" << std::endl;
    Rest::RequestData vars;
    Client tm(argv[1], argv[2]);


	//********************* list example ***********************
	std::cout << "********* MessagesController.list() *********" << std::endl;

	Resources<MessageModel> messages = tm.Messages().list();

	if (tm.Messages().isError) {
		std::cout
			<< tm.Messages().lastError.code << " * "
			<< tm.Messages().lastError.message << " * "
			<< std::endl;
	} else {
		std::cout  << messages.page << " * "
		   << messages.limit  << " * "
		   << messages.pageCount  << " * "
		   << messages.resources[0].id << " * "
		   << messages.resources[0].messageTime << " * "
		   << messages.resources[0].status  << " * "
		   << messages.resources[0].text  << " * "
		   << std::endl;
	}

	//******************* Get example ***********************
    std::cout << "********* MessagesController.get() *********" << std::endl;

	MessageModel message = tm.Messages().get(messages.resources[0].id);
	if (tm.Messages().isError){
		std::cout
			<< tm.Messages().lastError.code << " * "
			<< tm.Messages().lastError.message << " * "
			<< std::endl;

	} else {
		std::cout
  		   << message.id << " * "
		   << message.messageTime << " * "
		   << message.status  << " * "
		   << message.text  << " * "
		   << std::endl;
	}

	//******************* Send example ***********************
    std::cout << "********* MessagesController.send() *********" << std::endl;
	vars["phones"] = "999";
	vars["text"] = "The simple fake message";
	SendResultModel result = tm.Messages().send(vars);
	if (tm.Messages().isError){
		std::cout
			<< tm.Messages().lastError.code << " * "
			<< tm.Messages().lastError.message << " * "
			<< std::endl;
		return 1;
	} else {
		std::cout
		   << result.href << " * "
		   << result.type  << " * "
		   << result.messageId  << " * "
		   << std::endl;
	}

	//******************* Remove example ***********************
	std::cout << "********* MessagesController.remove() *********" << std::endl;
	bool rresult = tm.Messages().remove(result.messageId);
	std::cout  << "Result: " << rresult
			   << std::endl;


	//******************* Get example ***********************
    std::cout << "********* MessagesController.get() *********" << std::endl;

	message = tm.Messages().get(result.messageId);
	if (tm.Messages().isError){
		std::cout
			<< tm.Messages().lastError.code << " * "
			<< tm.Messages().lastError.message << " * "
			<< std::endl;

	} else {
		std::cout
  		   << message.id << " * "
		   << message.messageTime << " * "
		   << message.status  << " * "
		   << message.text  << " * "
		   << std::endl;
	}

	return 0;
};

