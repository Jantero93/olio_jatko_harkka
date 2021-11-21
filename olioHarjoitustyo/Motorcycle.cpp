#include "Motorcycle.h"
#include <sstream>

Motorcycle::Motorcycle(const std::string & manufactor, const std::string model_name, const int year, const int engine_power, const std::string & engine_model) :
	Vehicle(manufactor, model_name, year, engine_power, engine_model)
{
	std::cout << "Motorcycle parametri rakentaja kaikilla arvoilla" << std::endl;
}

Motorcycle::Motorcycle(const Motorcycle & motorcycle) :
	Vehicle(motorcycle.m_manufactor, motorcycle.m_model_name, motorcycle.m_year)
{
	if (motorcycle.m_ptr_engine) {
		m_ptr_engine = motorcycle.m_ptr_engine;
	}

	std::cout << "Motorcycle parametri rakentaja kaikilla arvoilla" << std::endl;
}


Motorcycle::~Motorcycle()
{
}

void Motorcycle::printVehicleSound()
{
	std::cout << "BIKE GOES MMMMMMFIIIUHH..." << std::endl;
}

float Motorcycle::calcPowerIndex()
{
	if (!m_ptr_engine) {
		std::cout << "No engine in car!" << std::endl;
		return -1.0f;
	}

	return m_ptr_engine->getHorsePower() / static_cast<float>(m_wheel_count);
}

std::string Motorcycle::getCSVFormat()
{
	int engine_power = m_ptr_engine 
		? m_ptr_engine->getHorsePower() 
		: -1;
	
	std::string engine_model = m_ptr_engine 
		? m_ptr_engine->getModelName() 
		: "";

	std::stringstream ss;
	ss << "motorcycle;" << m_manufactor << ";" << m_model_name << ";" << m_year << ";" << engine_power << ";" << engine_model;
	return ss.str();
}
