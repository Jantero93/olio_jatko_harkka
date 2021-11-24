#include <iostream>
#include "Vehicle.h"

Vehicle::Vehicle() :
	m_manufactor{ "" },
	m_model_name{ "" },
	m_year{ -1 },
	m_ptr_engine{ nullptr }
{
	std::cout << "Vehicle oletusrakentaja" << std::endl;
}

Vehicle::Vehicle(const std::string & manufactor, const std::string & model, const int year, const int engine_power, const std::string & engine_model) :
	m_manufactor{ manufactor },
	m_model_name{ model },
	m_year{ year },
	m_ptr_engine{ std::make_shared<Engine>(engine_power, engine_model) }
{
	std::cout << "Vehicle parametri rakentaja" << std::endl;
}

Vehicle::Vehicle(const std::string & manufactor, const std::string & model, const int year) :
	m_manufactor{ manufactor },
	m_model_name{ model },
	m_year{ year },
	m_ptr_engine{ nullptr }
{
	std::cout << "Parametri rakentaja ilman enginea" << std::endl;
}

Vehicle::~Vehicle()
{
	std::cout << "Engine purkaja" << std::endl;
}

void Vehicle::setEngine(const Engine& engine)
{
	m_ptr_engine->setHorsepower(engine.getHorsePower());
	m_ptr_engine->setModelName(engine.getModelName());
}

void Vehicle::setManufactor(const std::string & m)
{
	m_manufactor = m;
}

void Vehicle::setModelName(const std::string & m)
{
	m_model_name = m;
}

void Vehicle::setYear(const int y)
{
	m_year = y;
}

int Vehicle::getYear() const
{
	return m_year;
}

std::shared_ptr<Engine> Vehicle::getEngine() const
{
	return m_ptr_engine;
}

std::string Vehicle::getManufactor() const
{
	return m_manufactor;
}

std::string Vehicle::getModelName() const
{
	return m_model_name;
}
