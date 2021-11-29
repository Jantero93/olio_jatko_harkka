#include <iostream>

#include "App.h"
#include "VehicleData.h"

using std::cout; using std::endl; using std::cin; using std::getline; 


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
