#include <algorithm>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <memory>
#include <stdexcept>
#include <string>
#include "App.h"
#include "Car.h"
#include "Motorcycle.h"
using std::cout; using std::endl; using std::string; using std::cin;
using std::getline; using std::make_unique; using std::unique_ptr;

App* App::instance = 0;

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
		case 1: this->addVehicle("car"); break;
		case 3: this->addVehicle("motorcycle"); break;
		case 6: this->saveData(); break;
		case 7: this->sortByPower(); break;
		case 8: continue_app = false; break;
		case 9: this->printPowerIndexes(); break;
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
	cout << "2. Remove car" << endl;
	cout << "3. Add motorcycle" << endl;
	cout << "4. Remove motorcycle" << endl;
	cout << "5. Print all vehicles over 100 horsepower" << endl;
	cout << "6. Save to file" << endl;
	cout << "7. Sort vehicles by horsepower (descending)" << endl;
	cout << "8. Close app" << endl;
	cout << "9. Print all vehicles powerindex over 100 hp" << endl;
}

void App::printPowerIndexes() const
{
	cout << endl;
	cout << "Manufactor Model Horsepower PowerIndex" << endl << endl;

	auto print_power_indexes = [](const unique_ptr<Vehicle>& vehicle) {
		if (vehicle->getEngine()->getHorsePower() > 100) {
			cout << vehicle->getManufactor() << " "
				<< vehicle->getModelName() << " "
				<< vehicle->getEngine()->getHorsePower() << " "
				<< std::fixed << std::setprecision(2)
				<< vehicle->getPowerIndex() << endl;
		}
	};

	for_each(m_vehicle_data.begin(), m_vehicle_data.end(), print_power_indexes);
}

void App::addVehicle(const string& vehicle_type)
{
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	string manufactor, model, year, horsepower, engine_model;

	cout << "Manufactor: ";
	getline(cin, manufactor);
	cout << "Model: ";
	getline(cin, model);
	cout << "Year of manufacture(integer): ";
	getline(cin, year);
	cout << "Horsepower (integer): ";
	getline(cin, horsepower);
	cout << "Engine model: ";
	getline(cin, engine_model);

	if (vehicle_type == "car") {
		m_vehicle_data.push_back(
			make_unique<Car>(manufactor, model, std::stoi(year), std::stoi(horsepower), engine_model)
		);
	}
	else {
		m_vehicle_data.push_back(
			make_unique<Motorcycle>(manufactor, model, std::stoi(year), std::stoi(horsepower), engine_model)
		);
	}

	cout << "Vehicle added to database!" << endl;
}

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
				m_vehicle_data.push_back(
					make_unique<Car>(manufactor, model, std::stoi(year), std::stoi(horsepower), engine_model)
				);
			}
			else {
				m_vehicle_data.push_back(
					make_unique<Motorcycle>(manufactor, model, std::stoi(year), std::stoi(horsepower), engine_model)
				);
			}
		}

	}
	else {
		throw std::runtime_error("Could not open file");
	}
}



void App::saveData()
{
	std::ofstream file("data.txt");
	if (file.is_open()) {
		for (const auto& vehicle : m_vehicle_data) {
			file << vehicle->getCSVFormat() << '\n';
		}
	}
	else {
		throw std::runtime_error("Could not open file");
	}

}

void App::sortByPower()
{
	// descending order
	auto sort_power_descending = [](const unique_ptr<Vehicle>& a, const unique_ptr<Vehicle>& b) {
		return a->getEngine()->getHorsePower() > b->getEngine()->getHorsePower();
	};

	std::sort(m_vehicle_data.begin(), m_vehicle_data.end(), sort_power_descending);
}

App::App()
{
	this->loadData();
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