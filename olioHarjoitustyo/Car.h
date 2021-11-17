#pragma once
#include "Vehicle.h"
class Car : public Vehicle
{
public:
	Car();
	~Car();

	int calcTruePower() override;


private:
	int m_wheel_count;
};

