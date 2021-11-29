#pragma once

#include <functional>
#include <memory>
#include <vector>

#include "Vehicle.h"

class VehicleData final
{
public:
	~VehicleData();

	static std::shared_ptr<VehicleData> getInstance();

	// interface for listeners
	void registerLambdaAddListener(std::function<void(const std::string&)> listener);
	void registerLamdaRemoveListener(std::function<void(const std::string&)> listener);


	// methods
	void addVehicle(const std::string& vehicle_type);
	void loadData();
	void printAll() const;
	void printPowerIndexes() const;
	void removeVehicleByModel();
	void saveData();
	void sortByPower();

private:
	// constructors
	VehicleData();
	VehicleData(const VehicleData& vehicle_data) = delete;
	static std::shared_ptr<VehicleData> instance;

	// data
	std::vector<std::shared_ptr<Vehicle>> m_vehicle_data;

	// lambda observers
	std::vector<std::function<void(const std::string&)>> m_vehicleAddedObsrvers;
	std::vector<std::function<void(const std::string&)>> m_vehicleRemovedObsrvers;
};

