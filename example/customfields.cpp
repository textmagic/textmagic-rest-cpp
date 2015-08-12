#include <iostream>
#include <textmagic.h>

using namespace Textmagic;

int main(int argc, char* argv[]){
	if (argc < 3) {
		std::cout << "********* Please enter valid login & api key *********" << std::endl;
		std::cout << ">> bin/customfields_example username C7XDKZOQZo6HvhJPtO0MBcWl3qwtp2" << std::endl;
		return 1;
	}

    std::cout << "********* CustomfieldsController example *********" << std::endl;
    Rest::RequestData vars;
    Client tm(argv[1], argv[2]);

	//******************* Get example ***********************
    std::cout << "********* CustomfieldsController.get() *********" << std::endl;

	CustomfieldModel customfield = tm.Customfields().get("1082");
	if (tm.Customfields().isError){
		std::cout
			<< tm.Customfields().lastError.code << " * "
			<< tm.Customfields().lastError.message << " * "
			<< std::endl;

	} else {
		std::cout
			<< customfield.id << " * "
			<< customfield.name << " * "
			<< customfield.createdAt << " * "
			<< std::endl;
	}


	//********************* list example ***********************
	std::cout << "********* CustomfieldsController.list() *********" << std::endl;

	vars["limit"] = "5";
	vars["shared"] = "0";
	Resources<CustomfieldModel> customfields = tm.Customfields().list();

	if (tm.Customfields().isError) {
		std::cout
			<< tm.Customfields().lastError.code << " * "
			<< tm.Customfields().lastError.message << " * "
			<< std::endl;
	} else {
		std::cout  << customfields.page << " * "
		   << customfields.limit  << " * "
		   << customfields.pageCount  << " * "
		   << customfields.resources[0].id << " * "
		   << customfields.resources[0].name  << " * "
		   << std::endl;
	}


 //******************* Update example ***********************
    std::cout << "********* CustomfieldsController.update() *********" << std::endl;

	customfield.name = "cpp_customfield_test!";

	int id = tm.Customfields().update(customfield);
	std::cout  << "Result: " << id << std::endl;

	if (tm.Customfields().isError){
		std::cout
			<< tm.Customfields().lastError.code << " * "
			<< tm.Customfields().lastError.message << " * "
			<< std::endl;
	}


 //******************* Create example ***********************
    std::cout << "********* CustomfieldsController.create() *********" << std::endl;

	customfield.name = "cpp_customfield_test";

	id = tm.Customfields().create(customfield);
	std::cout  << "Result: " << id << std::endl;

	if (tm.Customfields().isError){
		std::cout
			<< tm.Customfields().lastError.code << " * "
			<< tm.Customfields().lastError.message << " * "
			<< std::endl;
	}


	//******************* Remove example ***********************
	std::cout << "********* CustomfieldsController.remove() *********" << std::endl;
	bool result = tm.Customfields().remove(Textmagic::Utils::toString(id));
	std::cout  << "Result: " << result
			   << std::endl;

	return 0;
};
