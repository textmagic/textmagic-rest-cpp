#include <iostream>
#include <textmagic.h>

using namespace Textmagic;

int main(int argc, char* argv[]){
	if (argc < 3) {
		std::cout << "********* Please enter valid login & api key *********" << std::endl;
		std::cout << ">> bin/replies_example username C7XDKZOQZo6HvhJPtO0MBcWl3qwtp2" << std::endl;
		return 1;
	}

    std::cout << "********* RepliesController example *********" << std::endl;
    Rest::RequestData vars;
    Client tm(argv[1], argv[2]);

	//******************* Get example ***********************
    std::cout << "********* RepliesController.get() *********" << std::endl;

	ReplyModel reply = tm.Replies().get("5943412");
	if (tm.Replies().isError){
		std::cout
			<< tm.Replies().lastError.code << " * "
			<< tm.Replies().lastError.message << " * "
			<< std::endl;

	} else {
		std::cout
			<< reply.id << " * "
			<< reply.sender << " * "
			<< reply.receiver << " * "
			<< reply.text << " * "
			<< std::endl;
	}


	//********************* list example ***********************
	std::cout << "********* RepliesController.list() *********" << std::endl;

	vars["limit"] = "5";
	vars["shared"] = "0";
	Resources<ReplyModel> replies = tm.Replies().list();

	if (tm.Replies().isError) {
		std::cout
			<< tm.Replies().lastError.code << " * "
			<< tm.Replies().lastError.message << " * "
			<< std::endl;
	} else {
		std::cout  << replies.page << " * "
		   << replies.limit  << " * "
		   << replies.pageCount  << " * "
		   << replies.resources[0].sender << " * "
		   << replies.resources[0].receiver  << " * "
		   << std::endl;
	}


	//********************* search example ***********************
	std::cout << "********* RepliesController.search() *********" << std::endl;

	vars["limit"] = "5";
	vars["shared"] = "0";
	replies = tm.Replies().search();

	if (tm.Replies().isError) {
		std::cout
			<< tm.Replies().lastError.code << " * "
			<< tm.Replies().lastError.message << " * "
			<< std::endl;
	} else {
		std::cout  << replies.page << " * "
		   << replies.limit  << " * "
		   << replies.pageCount  << " * "
		   << replies.resources[0].sender << " * "
		   << replies.resources[0].receiver  << " * "
		   << std::endl;
	}


 //******************* Create example ***********************
    std::cout << "********* RepliesController.create() *********" << std::endl;

	int id = tm.Replies().create(reply);
	std::cout  << "Result: " << id << std::endl;

	if (tm.Replies().isError){
		std::cout
			<< tm.Replies().lastError.code << " * "
			<< tm.Replies().lastError.message << " * "
			<< std::endl;
	}


	//******************* Remove example ***********************
//	std::cout << "********* RepliesController.remove() *********" << std::endl;
//	bool result = tm.Replies().remove(reply.id);
//	std::cout  << "Result: " << result
//			   << std::endl;

	return 0;
};

