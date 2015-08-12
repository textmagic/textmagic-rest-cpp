#include <iostream>
#include <textmagic.h>


int printError(Textmagic::Client& tm){
	if (tm.Lists().isError) {
		std::cout
			<< tm.Lists().lastError.code << " * "
			<< tm.Lists().lastError.message << " * "
			<< std::endl;
			return 1;
	}
	return 0;
}

int main(int argc, char* argv[]){
	if (argc < 3) {
		std::cout << "********* Please enter valid login & api key *********" << std::endl;
		std::cout << ">> bin/contacts_example username C7XDKZOQZo6HvhJPtO0MBcWl3qwtp2" << std::endl;
		return 1;
	}

    std::cout << "********* Textmagic::ListsController example *********" << std::endl;
    Textmagic::Rest::RequestData vars;
    Textmagic::Client tm(argv[1], argv[2]);


//   //******************* contactLists example ***********************
    std::cout << "********* ListsController.contactLists() *********" << std::endl;

	vars["limit"] = "5";

	Textmagic::Resources<Textmagic::ContactModel> contacts = tm.Lists().contactsByList("106985");

	if (tm.Lists().isError) {
		std::cout
			<< tm.Lists().lastError.code << " * "
			<< tm.Lists().lastError.message << " * "
			<< std::endl;
	} else {
		std::cout
		   << contacts.page << " * "
		   << contacts.limit  << " * "
		   << contacts.pageCount  << " * "
		   << contacts.resources[0].phone << " * "
		   << contacts.resources[0].firstName  << " * "
		   << std::endl;
	}

//   //******************* get example ***********************
    std::cout << "********* ListsController.get() *********" << std::endl;
	Textmagic::ListModel glist = tm.Lists().get("106985");
	if (! tm.Lists().isError) {
		std::cout
		   << "get list by id " << " * "
		   << glist.id << " * "
		   << glist.name  << " * "
		   << std::endl;
	} else {
			printError(tm);
			return 1;
	}


//   ******************* create example ***********************
    std::cout << "********* ListsController.create() *********" << std::endl;
	Textmagic::ListModel list;
	list.name  = "!CPP_TEST_LIST";
	list.description  = "...";
	list.membersCount = 0;
	list.shared = false;

    int result = tm.Lists().create(list);

	if (! tm.Lists().isError) {
		std::cout
		   << "create list " << " * "
		   << result << " * "
		   << list.id << " * "
		   << std::endl;
	} else {
			printError(tm);
			return 1;
	}

//******************* assign / unassign example ***********************
    std::cout << "********* ListsController.assign/unassign() *********" << std::endl;

	std::vector<std::string> listContacts;
	listContacts.push_back("930065");

	result = tm.Lists().assign(list, listContacts);
    	std::cout
		   << "Assign result" << " * "
		   << list.id << " * "
		   << Textmagic::Utils::vectorJoin(listContacts, " ")  << " * "
		   << result << " * "
		   << std::endl;

	if (tm.Lists().isError) {
		printError(tm);
		return 1;
	}

//	result = tm.Lists().unassign(list, listContacts);
//    	std::cout
//		   << "Unassign result" << " * "
//		   << result << " * "
//		   << std::endl;
//
//	if (tm.Lists().isError) {
//		printError(tm);
//		return 1;
//	}

    result = tm.Lists().remove(list.id);
    	std::cout
		   << "Remove result" << " * "
		   << result << " * "
		   << std::endl;

	if (tm.Lists().isError) {
		printError(tm);
		return 1;
	}

	return 0;

};
