#include <fstream>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include "App.h"
#include "Car.h"
#include "Motorcycle.h"
using std::cout; using std::endl; using std::string; using std::cin;
using std::getline; using std::make_unique; using std::unique_ptr;

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

#include "Car.h"
void App::loadData()
{
	std::fstream file("data.txt", std::ios::in);
	string manufactor, model, vehicle_type, engine_model, year, horsepower;

	if (file.is_open()) {

		while (file.peek() != EOF) {
			getline(file, vehicle_type, ';');
			getline(file, manufactor, ';');
			getline(file, model, ';');
			getline(file, year, ';');
			getline(file, horsepower, ';');
			getline(file, engine_model);

			if (vehicle_type == "car") {
				vehicle_data.push_back(
					make_unique<Car>(manufactor, model, std::stoi(year), std::stoi(horsepower), engine_model)
				);
			}
			else {
				vehicle_data.push_back(
					make_unique<Motorcycle>(manufactor, model, std::stoi(year), std::stoi(horsepower), engine_model)
				);
			}
		}

	}
	else {
		throw std::runtime_error("Could not open file");
	}
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
	Car car("bwm", "325", 2010, 210, "E63FAAAAAAAAAa");
	Motorcycle moto("Honda", "CBR", 2003, 130, "BFG2100");

	std::ofstream file("data.txt");
	if (file.is_open()) {
		file << car.getCSVFormat() << '\n';
		file << moto.getCSVFormat() << '\n';
	}
	else {
		throw std::runtime_error("Could not open file");
	}

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
	this->loadData();
}