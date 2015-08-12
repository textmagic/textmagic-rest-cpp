#include <iostream>
#include <textmagic.h>

int main(int argc, char* argv[]){
	if (argc < 3) {
		std::cout << "********* Please enter valid login & api key *********" << std::endl;
		std::cout << ">> bin/contacts_example username C7XDKZOQZo6HvhJPtO0MBcWl3qwtp2" << std::endl;
		return 1;
	}

    std::cout << "********* Textmagic::ContactsController example *********" << std::endl;
    Textmagic::Rest::RequestData vars;
    Textmagic::Client tm(argv[1], argv[2]);

	//******************* Get example ***********************
    std::cout << "********* ContactsController.get() *********" << std::endl;

	Textmagic::ContactModel contact = tm.Contacts().get("4379425");

	if (tm.Contacts().isError){
		std::cout
			<< tm.Contacts().lastError.code << " * "
			<< tm.Contacts().lastError.message << " * "
			<< tm.Contacts().lastError.errors["fields"]["phone"][0]
			<< std::endl;

	} else {
		std::cout
			<< contact.id << " * "
			<< contact.firstName << " * "
			<< contact.customFields[3].value
			<< std::endl;
	}

   //******************* contactLists example ***********************
    std::cout << "********* ContactsController.contactLists() *********" << std::endl;

	vars["limit"] = "5";

	Textmagic::Resources<Textmagic::ListModel> lists = tm.Contacts().contactLists("4379425", vars);

	if (tm.Contacts().isError) {
		std::cout
			<< tm.Contacts().lastError.code << " * "
			<< tm.Contacts().lastError.message << " * "
			<< std::endl;
	} else {
		std::cout  << lists.page << " * "
		   << lists.limit  << " * "
		   << lists.pageCount  << " * "
		   << lists.resources[0].name << " * "
		   << lists.resources[0].description  << " * "
		   << std::endl;
	}

   //******************* Create example ***********************
    std::cout << "********* ContactsController.create() *********" << std::endl;

	contact.firstName = "test2";
	contact.phone = "+79045857773";
	contact.lists.push_back("106872");
	std::cout  << "Result: " << tm.Contacts().create(contact) << std::endl;

	if (tm.Contacts().isError){
		std::cout
			<< tm.Contacts().lastError.code << " * "
			<< tm.Contacts().lastError.message << " * "
			<< tm.Contacts().lastError.errors["fields"]["phone"][0].asString()
			<< std::endl;
	}

	//********************* list example ***********************
	std::cout << "********* ContactsController.list() *********" << std::endl;

	vars["limit"] = "5";
	vars["shared"] = "0";
	Textmagic::Resources<Textmagic::ContactModel> contacts = tm.Contacts().list(vars);

	if (tm.Contacts().isError) {
		std::cout
			<< tm.Contacts().lastError.code << " * "
			<< tm.Contacts().lastError.message << " * "
			<< std::endl;
	} else {
		std::cout  << contacts.page << " * "
		   << contacts.limit  << " * "
		   << contacts.pageCount  << " * "
		   << contacts.resources[1].firstName << " * "
		   << contacts.resources[1].phone  << " * "
		   << std::endl;
	}

	//******************* Remove example ***********************
	std::cout << "********* ContactsController.remove() *********" << std::endl;
	bool result = tm.Contacts().remove("4379606");
	std::cout  << "Result: " << result
			   << std::endl;

	return 0;
};
