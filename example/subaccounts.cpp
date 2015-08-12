#include <iostream>
#include <textmagic.h>

using namespace Textmagic;

int main(int argc, char* argv[]){
	if (argc < 3) {
		std::cout << "********* Please enter valid login & api key *********" << std::endl;
		std::cout << ">> bin/subaccounts_example username C7XDKZOQZo6HvhJPtO0MBcWl3qwtp2" << std::endl;
		return 1;
	}

    std::cout << "********* SubaccountsController example *********" << std::endl;
    Rest::RequestData vars;
    Client tm(argv[1], argv[2]);


	//********************* list example ***********************
	std::cout << "********* SubaccountsController.list() *********" << std::endl;


	Resources<UserModel> subaccounts = tm.Subaccounts().list();

	if (tm.Subaccounts().isError) {
		std::cout
			<< tm.Subaccounts().lastError.code << " * "
			<< tm.Subaccounts().lastError.message << " * "
			<< std::endl;
	} else {
		std::cout  << subaccounts.page << " * "
		   << subaccounts.limit  << " * "
		   << subaccounts.pageCount  << " * "
		   << subaccounts.resources[0].username << " * "
		   << subaccounts.resources[0].subaccountType  << " * "
		   << std::endl;
	}

	//******************* Create example ***********************
    std::cout << "********* SubaccountsController.invite() *********" << std::endl;

	vars["email"] = "kuzinmv83@gmail.com";
	vars["role"] = "U";

	bool id = tm.Subaccounts().invite(vars);
	std::cout  << "Result: " << id << std::endl;

	if (tm.Subaccounts().isError){
		std::cout
			<< tm.Subaccounts().lastError.code << " * "
			<< tm.Subaccounts().lastError.message << " * "
			<< std::endl;
	}

	//******************* Get example ***********************
    std::cout << "********* SubaccountsController.get() *********" << std::endl;

	UserModel subaccount = tm.Subaccounts().get(subaccounts.resources[0].id);
	if (tm.Subaccounts().isError){
		std::cout
			<< tm.Subaccounts().lastError.code << " * "
			<< tm.Subaccounts().lastError.message << " * "
			<< std::endl;

	} else {
		std::cout
			<< subaccount.id << " * "
			<< subaccount.username << " * "
			<< subaccount.subaccountType << " * "
			<< std::endl;
	}


//	******************* Remove example ***********************
//	std::cout << "********* SubaccountsController.remove() *********" << std::endl;
//	bool result = tm.Subaccounts().remove(subaccount.id);
//	std::cout  << "Result: " << result
//			   << std::endl;

	return 0;
};

