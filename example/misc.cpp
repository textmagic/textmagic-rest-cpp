#include <iostream>
#include <textmagic.h>

using namespace Textmagic;

int main(int argc, char* argv[]){
	if (argc < 3) {
		std::cout << "********* Please enter valid login & api key *********" << std::endl;
		std::cout << ">> bin/misc_example username C7XDKZOQZo6HvhJPtO0MBcWl3qwtp2" << std::endl;
		return 1;
	}

    std::cout << "********* MiscController example *********" << std::endl;
    Rest::RequestData vars;
    Client tm(argv[1], argv[2]);

	//********************* userInfo example ***********************
	std::cout << "********* MiscController.userInfo() *********" << std::endl;

	UserModel user = tm.Misc().userInfo();
	if (tm.Misc().isError) {
		std::cout
			<< tm.Misc().lastError.code << " * "
			<< tm.Misc().lastError.message << " * "
			<< std::endl;
	} else {
		std::cout
		   << user.id << " * "
		   << user.firstName  << " * "
		   << user.company  << " * "
		   << std::endl;
	}

  //********************* updateUserInfo example ***********************
	std::cout << "********* MiscController.updateUserInfo() *********" << std::endl;

	user.company = "TEXTMAGIC 123";
	bool result = tm.Misc().updateUserInfo(user);
	if (tm.Misc().isError) {
		std::cout
			<< tm.Misc().lastError.code << " * "
			<< tm.Misc().lastError.message << " * "
			<< std::endl;
	} else {
		std::cout
		   << "Result : "
		   << result  << " * "
		   << std::endl;
	}



	//********************* invoices example ***********************
	std::cout << "********* MiscController.invoices() *********" << std::endl;

	vars["limit"] = "5";
	Resources<InvoiceModel> invoices = tm.Misc().invoices();

	if (tm.Misc().isError) {
		std::cout
			<< tm.Misc().lastError.code << " * "
			<< tm.Misc().lastError.message << " * "
			<< std::endl;
	} else {
		std::cout  << invoices.page << " * "
		   << invoices.limit  << " * "
		   << invoices.pageCount  << " * "
		   << invoices.resources[0].bundle << " * "
		   << invoices.resources[0].currency  << " * "
		   << invoices.resources[0].paymentMethod  << " * "
		   << std::endl;
	}


	//********************* statsMessaging example ***********************
	std::cout << "********* MiscController.statsMessaging() *********" << std::endl;

	Resources<StatModel> stat = tm.Misc().statsMessaging();

	if (tm.Misc().isError) {
		std::cout
			<< tm.Misc().lastError.code << " * "
			<< tm.Misc().lastError.message << " * "
			<< std::endl;
	} else {
		std::cout  << stat.page << " * "
		   << stat.limit  << " * "
		   << stat.pageCount  << " * "
		   << stat.resources[0].date << " * "
		   << stat.resources[0].messagesSentDelivered  << " * "
		   << stat.resources[0].messagesSentAccepted  << " * "
		   << std::endl;
	}


	//********************* statsSpending example ***********************
	std::cout << "********* MiscController.statsSpending() *********" << std::endl;

	Resources<SpentModel> spent = tm.Misc().statsSpending();

	if (tm.Misc().isError) {
		std::cout
			<< tm.Misc().lastError.code << " * "
			<< tm.Misc().lastError.message << " * "
			<< std::endl;
	} else {
		std::cout  << spent.page << " * "
		   << spent.limit  << " * "
		   << spent.pageCount  << " * "
		   << spent.resources[0].userId << " * "
		   << spent.resources[0].date  << " * "
		   << spent.resources[0].balance  << " * "
		   << std::endl;
	}

	return 0;
};

