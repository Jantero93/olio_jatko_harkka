#include <iostream>
#include <string>

#include "App.h"
#include "VehicleData.h"

using std::cin; using std::cout; using std::endl;

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
		case 5: VehicleData::getInstance()->printAll(); break;
		case 6: VehicleData::getInstance()->saveData(); break;
		case 7: VehicleData::getInstance()->sortByPower(); break;
		case 8: VehicleData::getInstance()->printPowerIndexes(); break;
		case 9: continue_app = false; break;
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
	cout << "5. Print all vehicles" << endl;
	cout << "6. Save to file" << endl;
	cout << "7. Sort vehicles by horsepower (descending)" << endl;
	cout << "8. Print vehicles powerindex over x horsepoewr" << endl;
	cout << "9. Close app" << endl;
}

App::App()
{
	cout << "App oletus rakentaja, asetaa observer lambdat" << endl;

	auto lambdaAddVehicleListener = [](const std::string& model) {
		cout << "Observer: Added " << model << "!" << endl;
	};

	VehicleData::getInstance()->registerLambdaAddListener(lambdaAddVehicleListener);

	auto lambdaRemoveVehicleListener = [](const std::string& model) {
		cout << "Observer: Removed " << model << "!" << endl;
	};

	VehicleData::getInstance()->registerLamdaRemoveListener(lambdaRemoveVehicleListener);
}


App::~App()
{
	cout << "App purkaja" << endl;
}
