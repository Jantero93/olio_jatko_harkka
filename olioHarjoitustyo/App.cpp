#include "App.h"
#include <iostream>
#include <string>
using std::cout; using std::endl; using std::string; using std::cin; using std::getline;

App* App::getInstance()
{
	if (!instance)
		instance = new App();
	
	return instance;
}

void App::start()
{
	int input = -1;
	bool continue_app = true;

	do {
		this->printMainMenu();
		cin >> input;

		switch (input) {
		case 1: cout << "jahuu" << endl; break;
		case 6: this->saveData(); break;
		case 7: continue_app = false; break;
		case 99: this->debug(); break;
		default: continue;
		}
	} while (continue_app);

}

void App::printMainMenu()
{
	cout << "Vehicle handler 9000" << endl;
	cout << "1. Add car" << endl;
	cout << "2. Remove car" << endl;
	cout << "3. Add motorcycle" << endl;
	cout << "4. Remove motorcycle" << endl;
	cout << "5. Print all vehicles over 100 horsepower" << endl;
	cout << "6. Save to file" << endl;
	cout << "7. Close app" << endl;
}

void App::saveData()
{
	cout << "save data btt" << endl;   
}

App::App()
{
	cout << "App oletus rakentaja" << endl;
}


App::~App()
{
	cout << "App purkaja" << endl;
}

void App::debug()
{
}