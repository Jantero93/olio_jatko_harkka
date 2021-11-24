#pragma once
#include <vector>
#include "Vehicle.h"

class App
{
public:
	// removed constructors
	App(const App&) = delete;
	App& operator=(const App&) = delete;

public:
	static App* getInstance();
	void start();

private:
	static App* instance;
	std::vector<std::unique_ptr<Vehicle>> m_vehicle_data;

	// methods
	void addVehicle(const std::string& vehicle_type);
	void loadData();
	void removeVehicleByModel();
	void printMainMenu() const;
	void printPowerIndexes() const;
	void saveData();
	void sortByPower();

	void debug();

	// construcor
	App();
	~App();
};

