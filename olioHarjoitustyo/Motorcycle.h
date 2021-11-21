#pragma once
#include "Vehicle.h"
class Motorcycle final : public Vehicle
{
public:
	Motorcycle() = delete;
	Motorcycle(const std::string& manufactor, const std::string model_name, const int year, const int engine_power, const std::string& engine_model);
	Motorcycle(const Motorcycle& motorcycle);
	
	~Motorcycle();
	
	// methods
	void printVehicleSound() override;
	float calcPowerIndex() override;

private: 
	int m_wheel_count = 2;
};

