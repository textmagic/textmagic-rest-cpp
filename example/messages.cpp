#include <iostream>
#include <textmagic.h>
#include <thread>

using namespace Textmagic;


template <typename T>
static void printError(Textmagic::BaseController<T>& controller);
static void printSendResult(Textmagic::SendResultModel& sendResult);
static void printMessage(const Textmagic::MessageModel& message);

int main(int argc, char* argv[]){
	std::cout << "********* MessagesController example *********" << std::endl;
	if (argc < 3) {
		std::cout << "********* Please enter valid login & api key *********" << std::endl;
		std::cout << ">> bin/messages_example username C7XDKZOQZo6HvhJPtO0MBcWl3qwtp2" << std::endl;
		return 1;
	}
	
	Rest::RequestData vars;
	Client tm(argv[1], argv[2]);
	
	//********************* list example ***********************
	std::cout << "********* MessagesController.list() *********" << std::endl;
	
	Resources<MessageModel> messageList  = tm.Messages().list();
	if (tm.Messages().isError) {
		printError(tm.Messages());
		return 1;
	} else {
		std::cout  << messageList.page << " * "
		<< messageList.limit  << " * "
		<< messageList.pageCount  << " * ";
		for ( size_t i = 0; i< messageList.resources.size(); ++i)
		{
			printMessage(messageList.resources[i]);
		}
	}
	
	
	std::cout << "********* MessagesController get list of messages *********" << std::endl;
	
	if (messageList.resources.empty()) {
		std::cout << "no messages" << std::endl;
	} else {
		MessageModel message = tm.Messages().get(messageList.resources.begin()->id);
		if (tm.Messages().isError){
			printError(tm.Messages());
		} else {
			printMessage(message);
		}
	}
	
	std::cout << "********* Obtain price *********" << std::endl;
	
	const std::string phoneNumber = "999"; // 999 - is special number for testing (free)
	Textmagic::PriceResultModel priceResult = tm.Messages().price(phoneNumber, "The simple fake message");
	if (tm.Messages().isError){
		printError(tm.Messages());
		return 1;
	} else {
		std::cout << "Price for message to " << phoneNumber << " = "
		<< priceResult.getPriceForCountry("")
		<< std::endl;
	}
	
	//******************* Send example ***********************
	std::cout << "********* MessagesController.send() *********" << std::endl;
	Textmagic::SendResultModel result = tm.Messages().send(phoneNumber, "The simple fake message");
	if (tm.Messages().isError){
		printError(tm.Messages());
		return 1;
	} else {
		printSendResult(result);
	}
	
	//******************* Get example ***********************
	std::cout << "********* MessagesController.get() *********" << std::endl;
	
	MessageModel message = tm.Messages().get(result.messageId);
	if (tm.Messages().isError){
		printError(tm.Messages());
	} else {
		printMessage(message);
	}
	
	//******************* Remove example ***********************
	std::cout << "********* MessagesController.remove() *********" << std::endl;
	bool rresult = tm.Messages().remove(message.id);
	std::cout  << "Delete Result: " << (rresult ? "Ok" : "Fail") << std::endl;
	
	
	return 0;
}


template <typename T>
static void printError(Textmagic::BaseController<T>& controller)
{
	std::cout
	<< controller.lastError.code << " * "
	<< controller.lastError.message << " * "
	<< std::endl;
}


static void printSendResult(Textmagic::SendResultModel& sendResult)
{
	std::cout
	<< sendResult.href << " * "
	<< sendResult.type  << " * "
	<< sendResult.messageId  << " * "
	<< std::endl;
	std::cout
	<< "Sent Ok"
	<< std::endl;
}

static void printMessage(const Textmagic::MessageModel& message)
{
	std::cout  <<  message.id << " * "
	<< message.messageTime << " * "
	<< message.status  << " * "
	<< message.text  << " * "
	<< std::endl;
}