#include <algorithm>
#include <functional>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <memory>
#include <stdexcept>
#include <string>

#include "App.h"
#include "Car.h"
#include "Motorcycle.h"
#include "VehicleData.h"

using std::cout; using std::endl; using std::string; using std::cin;
using std::getline; using std::make_unique; using std::unique_ptr;

App* App::instance = 0;

App* App::getInstance()
{
	if (!instance) instance = new App();

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
		case 1: VehicleData::getInstance()->addVehicle("car"); break;
		case 2: VehicleData::getInstance()->removeVehicleByModel(); break;
		case 3: VehicleData::getInstance()->addVehicle("motorcycle"); break;
		case 6: VehicleData::getInstance()->saveData(); break;
		case 7: VehicleData::getInstance()->sortByPower(); break;
		case 8: continue_app = false; break;
		case 9: VehicleData::getInstance()->printPowerIndexes(); break;
		case 99: this->debug(); break;
		default: continue;
		}
	} while (continue_app);

}

void App::printMainMenu() const
{
	cout << endl;
	cout << "============================" << endl;
	cout << endl;
	cout << "Vehicle handler 9000" << endl;
	cout << "1. Add car" << endl;
	cout << "2. Remove vehicle" << endl;
	cout << "3. Add motorcycle" << endl;
	cout << "4. Remove motorcycle" << endl;
	cout << "6. Save to file" << endl;
	cout << "7. Sort vehicles by horsepower (descending)" << endl;
	cout << "8. Close app" << endl;
	cout << "9. Print vehicles powerindex over x horsepoewr" << endl;
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