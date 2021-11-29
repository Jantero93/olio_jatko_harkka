#pragma once
#include <vector>
#include "Vehicle.h"

class App
{
public:
	// removed constructors
	App();
	~App();
	void start();

private:
	std::vector<std::unique_ptr<Vehicle>> m_vehicle_data;

	// methods
	void printMainMenu() const;


	// construcor
	App(const App&) = delete;
	App& operator=(const App&) = delete;
};

