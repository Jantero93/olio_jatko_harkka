#include "Vehicle.h"

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

std::string Vehicle::getManufactor() const
{
	return m_manufactor;
}

std::string Vehicle::getModelName() const
{
	return m_model_name;
}
