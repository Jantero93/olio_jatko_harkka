#include "Car.h"



Car::Car()
{
}


Car::~Car()
{
}

int Car::calcTruePower()
{
	if(m_ptr_engine) return m_ptr_engine->getHorsePower() / m_wheel_count;
	else return -1;
}
