#include <iostream>
#include <textmagic.h>

using namespace Textmagic;

int main(int argc, char* argv[]){
	if (argc < 3) {
		std::cout << "********* Please enter valid login & api key *********" << std::endl;
		std::cout << ">> bin/unsubscribers_example username C7XDKZOQZo6HvhJPtO0MBcWl3qwtp2" << std::endl;
		return 1;
	}

    std::cout << "********* UnsubscribersController example *********" << std::endl;
    Rest::RequestData vars;
    Client tm(argv[1], argv[2]);

	//******************* Get example ***********************
    std::cout << "********* UnsubscribersController.get() *********" << std::endl;

	UnsubscriberModel contact = tm.Unsubscribers().get("17485");
	if (tm.Unsubscribers().isError){
		std::cout
			<< tm.Unsubscribers().lastError.code << " * "
			<< tm.Unsubscribers().lastError.message << " * "
			<< std::endl;

	} else {
		std::cout
			<< contact.id << " * "
			<< contact.phone << " * "
			<< contact.firstName << " * "
			<< contact.lastName << " * "
			<< std::endl;
	}


	//********************* list example ***********************
	std::cout << "********* UnsubscribersController.list() *********" << std::endl;

	vars["limit"] = "5";
	vars["shared"] = "0";
	Resources<UnsubscriberModel> unsubscribers = tm.Unsubscribers().list();

	if (tm.Unsubscribers().isError) {
		std::cout
			<< tm.Unsubscribers().lastError.code << " * "
			<< tm.Unsubscribers().lastError.message << " * "
			<< std::endl;
	} else {
		std::cout  << unsubscribers.page << " * "
		   << unsubscribers.limit  << " * "
		   << unsubscribers.pageCount  << " * "
		   << unsubscribers.resources[0].phone << " * "
		   << unsubscribers.resources[0].firstName  << " * "
		   << std::endl;
	}


 //******************* Create example ***********************
    std::cout << "********* UnsubscribersController.create() *********" << std::endl;

	int id = tm.Unsubscribers().create(contact);
	std::cout  << "Result: " << id << std::endl;

	if (tm.Unsubscribers().isError){
		std::cout
			<< tm.Unsubscribers().lastError.code << " * "
			<< tm.Unsubscribers().lastError.message << " * "
			<< std::endl;
	}


 //******************* Create example ***********************
    std::cout << "********* UnsubscribersController.update() *********" << std::endl;

	id = tm.Unsubscribers().update(contact);
	std::cout  << "Result: " << id << std::endl;

	if (tm.Unsubscribers().isError){
		std::cout
			<< tm.Unsubscribers().lastError.code << " * "
			<< tm.Unsubscribers().lastError.message << " * "
			<< std::endl;
	}


	//******************* Remove example ***********************
	std::cout << "********* UnsubscribersController.remove() *********" << std::endl;
	bool result = tm.Unsubscribers().remove(contact.id);
	std::cout  << "Result: " << result
			   << std::endl;

	return 0;
};
