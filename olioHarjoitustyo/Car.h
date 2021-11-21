#pragma once
#include <string>
#include "Engine.h"
#include "Vehicle.h"

class Car final : public Vehicle
{
public:

	// constructors
	Car() = delete;
	Car(const std::string& manufactor, const std::string& model_name, const int year, const int engine_power, const std::string& engine_model);
	Car(const Car& car);

	~Car();

	// methods
	float calcPowerIndex() override;
	std::string getCSVFormat() override;
	void printVehicleSound() override;

private:
	int m_wheel_count = 4;
};

