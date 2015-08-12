#include <iostream>
#include <textmagic.h>

using namespace Textmagic;

int main(int argc, char* argv[]){
	if (argc < 3) {
		std::cout << "********* Please enter valid login & api key *********" << std::endl;
		std::cout << ">> bin/errors_example username C7XDKZOQZo6HvhJPtO0MBcWl3qwtp2" << std::endl;
		return 1;
	}

    std::cout << "********* SenderIdsController example *********" << std::endl;
    Rest::RequestData vars;
    Client tm(argv[1], argv[2]);

	//******************* Get example ***********************
    std::cout << "********* SenderIdsController.get() *********" << std::endl;
	SenderIdModel senderid = tm.SenderIds().get("1234567");

	if (tm.SenderIds().isError){
		std::cout
			<< tm.SenderIds().lastError.code << " * "
			<< tm.SenderIds().lastError.message << " * "
			<< std::endl;

	} else {
		std::cout
			<< senderid.id << " * "
			<< senderid.senderId << " * "
			<< senderid.status << " * "
			<< std::endl;
	}

	return 0;
};

