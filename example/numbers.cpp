#include <iostream>
#include <textmagic.h>

using namespace Textmagic;

int main(int argc, char* argv[]){
	if (argc < 3) {
		std::cout << "********* Please enter valid login & api key *********" << std::endl;
		std::cout << ">> bin/numbers_example username C7XDKZOQZo6HvhJPtO0MBcWl3qwtp2" << std::endl;
		return 1;
	}

    std::cout << "********* NumbersController example *********" << std::endl;
    Rest::RequestData vars;
    Client tm(argv[1], argv[2]);


	//******************* Available example ***********************
    std::cout << "********* NumbersController.available() *********" << std::endl;

	vars["country"] = "GB";
	Json::Value available = tm.Numbers().available(vars);

	if (tm.Numbers().isError){
		std::cout
			<< tm.Numbers().lastError.code << " * "
			<< tm.Numbers().lastError.message << " * "
			<< std::endl;

	} else {
		std::cout
			<< available["numbers"][0] << " * "
			<< available["numbers"][1] << " * "
			<< available["price"] << " * "
			<< std::endl;
	}

	//******************* Buy example ***********************
    std::cout << "********* NumbersController.buy() *********" << std::endl;

	vars["phone"] = available["numbers"][0].asString();
	vars["userId"] = "10319";
	int numberId = tm.Numbers().buy(vars);

	if (tm.Numbers().isError){
		std::cout
			<< tm.Numbers().lastError.code << " * "
			<< tm.Numbers().lastError.message << " * "
			<< std::endl;

	} else {
		std::cout
			<< numberId << " * "
			<< std::endl;
	}

	//******************* Get example ***********************
    std::cout << "********* NumbersController.get() *********" << std::endl;

	NumberModel number = tm.Numbers().get(Utils::toString(numberId));
	if (tm.Numbers().isError){
		std::cout
			<< tm.Numbers().lastError.code << " * "
			<< tm.Numbers().lastError.message << " * "
			<< std::endl;

	} else {
		std::cout
			<< number.id << " * "
			<< number.phone << " * "
			<< number.countryName << " * "
			<< number.status << " * "
			<< std::endl;
	}


	//********************* list example ***********************
	std::cout << "********* NumbersController.list() *********" << std::endl;

	Resources<NumberModel> numbers = tm.Numbers().list();

	if (tm.Numbers().isError) {
		std::cout
			<< tm.Numbers().lastError.code << " * "
			<< tm.Numbers().lastError.message << " * "
			<< std::endl;
	} else {
		std::cout  << numbers.page << " * "
		   << numbers.limit  << " * "
		   << numbers.pageCount  << " * "
		   << numbers.resources[0].phone << " * "
		   << numbers.resources[0].countryName  << " * "
		   << numbers.resources[0].status  << " * "
		   << std::endl;
	}

	//******************* Remove example ***********************
	std::cout << "********* NumbersController.remove() *********" << std::endl;
	bool result = tm.Numbers().remove(Utils::toString(numberId));
	std::cout  << "Result: " << result
			   << std::endl;

	return 0;
};

