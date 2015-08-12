#include <iostream>
#include <textmagic.h>
#include <exception>

using namespace Textmagic;

int main(int argc, char* argv[]){
	if (argc < 3) {
		std::cout << "********* Please enter valid login & api key *********" << std::endl;
		std::cout << ">> bin/sessions_example username C7XDKZOQZo6HvhJPtO0MBcWl3qwtp2" << std::endl;
		return 1;
	}

    std::cout << "********* SessionsController example *********" << std::endl;
    Rest::RequestData vars;
    Client tm(argv[1], argv[2]);

	//******************* Get example ***********************
    std::cout << "********* SessionsController.get() *********" << std::endl;

	SessionModel session = tm.Sessions().get("34419228");
	if (tm.Sessions().isError){
		std::cout
			<< tm.Sessions().lastError.code << " * "
			<< tm.Sessions().lastError.message << " * "
			<< std::endl;

	} else {
		std::cout
			<< session.id << " * "
			<< session.source << " * "
			<< session.startTime << " * "
			<< session.text << " * "
			<< std::endl;
	}

//********************* Messages example ***********************
	std::cout << "********* SessionsController.messages() *********" << std::endl;

	vars["limit"] = "5";
	vars["shared"] = "0";
	Resources<MessageModel> messages = tm.Sessions().messages(session.id);

	if (tm.Sessions().isError) {
		std::cout
			<< tm.Sessions().lastError.code << " * "
			<< tm.Sessions().lastError.message << " * "
			<< std::endl;
	} else {
		std::cout
		   << messages.page << " * "
		   << messages.limit  << " * "
		   << messages.pageCount  << " * "
		   << messages.resources[0].receiver  << " * "
		   << messages.resources[0].status << " * "
		   << messages.resources[0].text  << " * "
		   << std::endl;
	}


	//********************* list example ***********************
	std::cout << "********* SessionsController.list() *********" << std::endl;

	vars["limit"] = "5";
	vars["shared"] = "0";
	Resources<SessionModel> sessions = tm.Sessions().list();

	if (tm.Sessions().isError) {
		std::cout
			<< tm.Sessions().lastError.code << " * "
			<< tm.Sessions().lastError.message << " * "
			<< std::endl;
	} else {
		std::cout  << sessions.page << " * "
		   << sessions.limit  << " * "
		   << sessions.pageCount  << " * "
		   << sessions.resources[0].source  << " * "
		   << sessions.resources[0].startTime << " * "
		   << sessions.resources[0].text  << " * "
		   << std::endl;
	}



 //******************* Create example ***********************
    std::cout << "********* SessionsController.create() *********" << std::endl;

	int id = tm.Sessions().create(session);
	std::cout  << "Result: " << id << std::endl;

	if (tm.Sessions().isError){
		std::cout
			<< tm.Sessions().lastError.code << " * "
			<< tm.Sessions().lastError.message << " * "
			<< std::endl;
	}


	//******************* Remove example ***********************
//	std::cout << "********* SessionsController.remove() *********" << std::endl;
//	bool result = tm.Sessions().remove(session.id);
//	std::cout  << "Result: " << result
//			   << std::endl;

	return 0;
};

