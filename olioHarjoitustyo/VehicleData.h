#pragma once
#include <memory>
#include <string>
#include <vector>

#include "Vehicle.h"

class VehicleData final
{
public:
	~VehicleData();

	static std::shared_ptr<VehicleData> getInstance();

	void addVehicle(const std::string& vehicle_type);
	void loadData();
	void printPowerIndexes() const;
	void removeVehicleByModel();
	void saveData();
	void sortByPower();

private:
	// constructors
	VehicleData();
	VehicleData(const VehicleData& vehicle_data) = delete;
	static std::shared_ptr<VehicleData> instance;

	std::vector<std::shared_ptr<Vehicle>> m_vehicle_data;

};

