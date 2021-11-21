#include "Car.h"
#include <iostream>
#include <memory>

Car::Car(const std::string & manufactor, const std::string & model_name, const int year, const int engine_power, const std::string& engine_model) :
	Vehicle( manufactor, model_name, year, engine_power, engine_model )
{
	std::cout << "Car parametri rakentaja" << std::endl;
}

Car::Car(const Car & car) :
	Vehicle( car.m_manufactor, car.m_model_name, car.m_year)
{
	if (car.m_ptr_engine) {
		m_ptr_engine = car.m_ptr_engine;
	}

	std::cout << "Car parametri rakentaja ilman moottoria" << std::endl;
}

Car::~Car()
{
	std::cout << "Car purkaja" << std::endl;
}

void Car::printVehicleSound()
{
	std::cout << "CAR GOES BRMMM" << std::endl;
}

float Car::calcPowerIndex()
{
	if (!m_ptr_engine) {
		std::cout << "No engine in car!" << std::endl;
		return -1;
	}
	
	return m_ptr_engine->getHorsePower() / static_cast<float>(m_wheel_count);
}
