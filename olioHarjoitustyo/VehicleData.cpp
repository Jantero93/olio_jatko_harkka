#include <algorithm>
#include <functional>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <memory>
#include <stdexcept>
#include <string>

#include "Car.h"
#include "Motorcycle.h"
#include "VehicleData.h"

using std::cout; using std::endl; using std::cin; using std::string;
using std::make_shared; using std::shared_ptr;

shared_ptr<VehicleData> VehicleData::instance = nullptr;

VehicleData::VehicleData() {
	this->loadData();
}

VehicleData::~VehicleData()
{
}

std::shared_ptr<VehicleData> VehicleData::getInstance()
{
	if (!instance) {
		instance = shared_ptr<VehicleData>(new VehicleData());
	}

	return instance;
}

void VehicleData::registerLambdaAddListener(std::function<void(const std::string&)> listener)
{
	m_vehicleAddedObsrvers.push_back(listener);
}

void VehicleData::registerLamdaRemoveListener(std::function<void(const std::string&)> listener)
{
	m_vehicleRemovedObsrvers.push_back(listener);
}

void VehicleData::addVehicle(const string& vehicle_type) {
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
			make_shared<Car>(manufactor, model, std::stoi(year), std::stoi(horsepower), engine_model)
		);
	}
	else {
		m_vehicle_data.push_back(
			make_shared<Motorcycle>(manufactor, model, std::stoi(year), std::stoi(horsepower), engine_model)
		);
	}

	for (auto& observer : m_vehicleAddedObsrvers) {
		observer(model);
	}
}

void VehicleData::loadData()
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
					make_shared<Car>(manufactor, model, std::stoi(year), std::stoi(horsepower), engine_model)
				);
			}
			else {
				m_vehicle_data.push_back(
					make_shared<Motorcycle>(manufactor, model, std::stoi(year), std::stoi(horsepower), engine_model)
				);
			}
		}

	}
	else {
		throw std::runtime_error("Could not open file");
	}
}

void VehicleData::printAll() const
{
	auto print_all = [](const shared_ptr<Vehicle>& vehicle) {
		cout << vehicle->getManufactor() << " "
			<< vehicle->getModelName() << " "
			<< vehicle->getEngine()->getHorsePower() << endl;
	};

	cout << "Manufactor Model Horsepower" << endl;
	for_each(m_vehicle_data.begin(), m_vehicle_data.end(), print_all);
}

void VehicleData::printPowerIndexes() const
{
	int input_horsepower;
	cout << "Vehicles minimun horsepower which powerindex is printed?(integer)";
	cin >> input_horsepower;
	cout << endl;
	cout << "Manufactor Model Horsepower PowerIndex" << endl << endl;

	auto print_power_indexes = [&input_horsepower](const shared_ptr<Vehicle>& vehicle) {
		if (vehicle->getEngine()->getHorsePower() >= input_horsepower) {
			cout << vehicle->getManufactor() << " "
				<< vehicle->getModelName() << " "
				<< vehicle->getEngine()->getHorsePower() << " "
				<< std::fixed << std::setprecision(2)
				<< vehicle->getPowerIndex() << endl;
		}
	};

	for_each(m_vehicle_data.begin(), m_vehicle_data.end(), print_power_indexes);
}

void VehicleData::removeVehicleByModel()
{
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	string model;
	cout << "Model to remove?";
	getline(cin, model);

	auto iterator = std::remove_if(m_vehicle_data.begin(), m_vehicle_data.end(),
		[&model](const shared_ptr<Vehicle>& vehicle) { return vehicle->getModelName() == model; }
	);

	m_vehicle_data.erase(iterator, m_vehicle_data.end());

	for (auto& observer : m_vehicleRemovedObsrvers) {
		observer(model);
	}
}

void VehicleData::saveData()
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

void VehicleData::sortByPower()
{
	// descending order
	auto sort_power_descending = [](const shared_ptr<Vehicle>& a, const shared_ptr<Vehicle>& b) {
		return a->getEngine()->getHorsePower() > b->getEngine()->getHorsePower();
	};

	std::sort(m_vehicle_data.begin(), m_vehicle_data.end(), sort_power_descending);
}
