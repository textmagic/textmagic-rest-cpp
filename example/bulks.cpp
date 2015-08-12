#include <iostream>
#include <textmagic.h>

using namespace Textmagic;

int main(int argc, char* argv[]){
	if (argc < 3) {
		std::cout << "********* Please enter valid login & api key *********" << std::endl;
		std::cout << ">> bin/bulks_example username C7XDKZOQZo6HvhJPtO0MBcWl3qwtp2" << std::endl;
		return 1;
	}

    std::cout << "********* BulksController example *********" << std::endl;
    Rest::RequestData vars;
    Client tm(argv[1], argv[2]);

	//******************* Get example ***********************
    std::cout << "********* BulksController.get() *********" << std::endl;

	BulkModel bulk = tm.Bulks().get("100");
	if (tm.Bulks().isError){
		std::cout
			<< tm.Bulks().lastError.code << " * "
			<< tm.Bulks().lastError.message << " * "
			<< std::endl;

	} else {
		std::cout
			<< bulk.id << " * "
			<< bulk.status << " * "
			<< bulk.itemsProcessed << " * "
			<< bulk.createdAt << " * "
			<< std::endl;
	}


	//********************* list example ***********************
	std::cout << "********* BulksController.list() *********" << std::endl;

	vars["limit"] = "5";
	vars["shared"] = "0";
	Resources<BulkModel> bulks = tm.Bulks().list();

	if (tm.Bulks().isError) {
		std::cout
			<< tm.Bulks().lastError.code << " * "
			<< tm.Bulks().lastError.message << " * "
			<< std::endl;
	} else {
		std::cout  << bulks.page << " * "
		   << bulks.limit  << " * "
		   << bulks.pageCount  << " * "
		   << bulks.resources[0].status  << " * "
		   << bulks.resources[0].itemsProcessed << " * "
		   << bulks.resources[0].createdAt  << " * "
		   << std::endl;
	}

	return 0;
};

