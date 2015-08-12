#include <iostream>
#include <textmagic.h>

using namespace Textmagic;

int main(int argc, char* argv[]){
	if (argc < 3) {
		std::cout << "********* Please enter valid login & api key *********" << std::endl;
		std::cout << ">> bin/templates_example username C7XDKZOQZo6HvhJPtO0MBcWl3qwtp2" << std::endl;
		return 1;
	}

    std::cout << "********* TemplatesController example *********" << std::endl;
    Rest::RequestData vars;
    Client tm(argv[1], argv[2]);

	//******************* Get example ***********************
    std::cout << "********* TemplatesController.get() *********" << std::endl;

	TemplateModel tmTemplate = tm.Templates().get("51387");
	if (tm.Templates().isError){
		std::cout
			<< tm.Templates().lastError.code << " * "
			<< tm.Templates().lastError.message << " * "
			<< std::endl;

	} else {
		std::cout
			<< tmTemplate.id << " * "
			<< tmTemplate.name << " * "
			<< tmTemplate.content << " * "
			<< tmTemplate.lastModified << " * "
			<< std::endl;
	}


	//********************* list example ***********************
	std::cout << "********* TemplatesController.list() *********" << std::endl;

	vars["limit"] = "5";
	vars["shared"] = "0";
	Resources<TemplateModel> templates = tm.Templates().list();

	if (tm.Templates().isError) {
		std::cout
			<< tm.Templates().lastError.code << " * "
			<< tm.Templates().lastError.message << " * "
			<< std::endl;
	} else {
		std::cout  << templates.page << " * "
		   << templates.limit  << " * "
		   << templates.pageCount  << " * "
		   << templates.resources[0].name << " * "
		   << templates.resources[0].content  << " * "
		   << std::endl;
	}


 //******************* Update example ***********************
    std::cout << "********* TemplatesController.update() *********" << std::endl;

	tmTemplate.name = "cpp_template_test!";
	tmTemplate.content = "********* TemplatesController.update() *********";

	int id = tm.Templates().update(tmTemplate);
	std::cout  << "Result: " << id << std::endl;

	if (tm.Templates().isError){
		std::cout
			<< tm.Templates().lastError.code << " * "
			<< tm.Templates().lastError.message << " * "
			<< std::endl;
	}


 //******************* Create example ***********************
    std::cout << "********* TemplatesController.create() *********" << std::endl;

	tmTemplate.name = "cpp_template_test";
	tmTemplate.content = "********* TemplatesController.create() *********";

	id = tm.Templates().create(tmTemplate);
	std::cout  << "Result: " << id << std::endl;

	if (tm.Templates().isError){
		std::cout
			<< tm.Templates().lastError.code << " * "
			<< tm.Templates().lastError.message << " * "
			<< std::endl;
	}




	//******************* Remove example ***********************
	std::cout << "********* TemplatesController.remove() *********" << std::endl;
	bool result = tm.Templates().remove(Textmagic::Utils::toString(id));
	std::cout  << "Result: " << result
			   << std::endl;

	return 0;
};
