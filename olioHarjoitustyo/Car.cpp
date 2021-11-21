#include "Car.h"
#include <iostream>
#include <memory>
#include <sstream>

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

std::string Car::getCSVFormat()
{
	int engine_power = m_ptr_engine
		? m_ptr_engine->getHorsePower()
		: -1;

	std::string engine_model = m_ptr_engine
		? m_ptr_engine->getModelName()
		: "";

	std::stringstream ss;
	ss << "car;" << m_manufactor << ";" << m_model_name << ";" << m_year << ";" << engine_power << ";" << engine_model;
	return ss.str();
}

void Car::printVehicleSound()
{
	std::cout << "CAR GOES BRMMM" << std::endl;
}

float Car::calcPowerIndex()
{
	if (!m_ptr_engine) {
		std::cout << "No engine in car!" << std::endl;
		return -1.0f;
	}
	
	return m_ptr_engine->getHorsePower() / static_cast<float>(m_wheel_count);
}
