#include <iostream>
#include <textmagic.h>

using namespace Textmagic;

int main(int argc, char* argv[]){
	if (argc < 3) {
		std::cout << "********* Please enter valid login & api key *********" << std::endl;
		std::cout << ">> bin/schedules_example username C7XDKZOQZo6HvhJPtO0MBcWl3qwtp2" << std::endl;
		return 1;
	}

    std::cout << "********* SchedulesController example *********" << std::endl;
    Rest::RequestData vars;
    Client tm(argv[1], argv[2]);

	//******************* Get example ***********************
    std::cout << "********* SchedulesController.get() *********" << std::endl;

	ScheduleModel schedule = tm.Schedules().get("4488");
	if (tm.Schedules().isError){
		std::cout
			<< tm.Schedules().lastError.code << " * "
			<< tm.Schedules().lastError.message << " * "
			<< std::endl;

	} else {
		std::cout
			<< schedule.id << " * "
			<< schedule.nextSend << " * "
			<< schedule.sessionId << " * "
			<< std::endl;
	}


	//********************* list example ***********************
	std::cout << "********* SchedulesController.list() *********" << std::endl;

	vars["limit"] = "5";
	vars["shared"] = "0";
	Resources<ScheduleModel> schedules = tm.Schedules().list();

	if (tm.Schedules().isError) {
		std::cout
			<< tm.Schedules().lastError.code << " * "
			<< tm.Schedules().lastError.message << " * "
			<< std::endl;
	} else {
		std::cout  << schedules.page << " * "
		   << schedules.limit  << " * "
		   << schedules.pageCount  << " * "
		   << schedules.resources[0].nextSend << " * "
		   << schedules.resources[0].sessionId  << " * "
		   << std::endl;
	}



 //******************* Create example ***********************
    std::cout << "********* SchedulesController.create() *********" << std::endl;

	int id = tm.Schedules().create(schedule);
	std::cout  << "Result: " << id << std::endl;

	if (tm.Schedules().isError){
		std::cout
			<< tm.Schedules().lastError.code << " * "
			<< tm.Schedules().lastError.message << " * "
			<< std::endl;
	}


	//******************* Remove example ***********************
//	std::cout << "********* SchedulesController.remove() *********" << std::endl;
//	bool result = tm.Schedules().remove(schedule.id);
//	std::cout  << "Result: " << result
//			   << std::endl;

	return 0;
};

