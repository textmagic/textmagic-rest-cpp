#include <iostream>
#include <textmagic.h>

using namespace Textmagic;

int main(int argc, char* argv[]){
	if (argc < 3) {
		std::cout << "********* Please enter valid login & api key *********" << std::endl;
		std::cout << ">> bin/senderids_example username C7XDKZOQZo6HvhJPtO0MBcWl3qwtp2" << std::endl;
		return 1;
	}

    std::cout << "********* SenderIdsController example *********" << std::endl;
    Rest::RequestData vars;
    Client tm(argv[1], argv[2]);


	//********************* list example ***********************
	std::cout << "********* SenderIdsController.list() *********" << std::endl;


	Resources<SenderIdModel> senderids = tm.SenderIds().list();

	if (tm.SenderIds().isError) {
		std::cout
			<< tm.SenderIds().lastError.code << " * "
			<< tm.SenderIds().lastError.message << " * "
			<< std::endl;
	} else {
		std::cout  << senderids.page << " * "
		   << senderids.limit  << " * "
		   << senderids.pageCount  << " * "
		   << senderids.resources[0].senderId << " * "
		   << senderids.resources[0].status  << " * "
		   << std::endl;
	}

	//******************* Create example ***********************
    std::cout << "********* SenderIdsController.create() *********" << std::endl;

	vars["senderId"] = "CPPTEST";
	vars["explanation"] = "CPPTEST explanation";

	int id = tm.SenderIds().create(vars);
	std::cout  << "Result: " << id << std::endl;

	if (tm.SenderIds().isError){
		std::cout
			<< tm.SenderIds().lastError.code << " * "
			<< tm.SenderIds().lastError.message << " * "
			<< std::endl;
	}

	//******************* Get example ***********************
    std::cout << "********* SenderIdsController.get() *********" << std::endl;

	SenderIdModel senderid = tm.SenderIds().get(Utils::toString(id));
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


//	******************* Remove example ***********************
	std::cout << "********* SenderIdsController.remove() *********" << std::endl;
	bool result = tm.SenderIds().remove(senderid.id);
	std::cout  << "Result: " << result
			   << std::endl;

	return 0;
};

