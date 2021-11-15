#include "Engine.h"

#include <iostream>
using std::cout; using std::endl;

Engine::Engine(const int horsepower, const std::string& model_name) :
	m_horsepower{horsepower},
	m_model_name{model_name}
{
	cout << "Engine parametri rakentaja" << endl;
	m_Engine_ptr_count++;
}

Engine::Engine(const Engine & engine) :
	m_horsepower{engine.m_horsepower},
	m_model_name(engine.m_model_name)
{
	cout << "Engine kopio rakentaja" << endl;
	m_Engine_ptr_count++;
}


Engine::~Engine()
{
	cout << "Engine purkaja" << endl;
	m_Engine_ptr_count--;
}

void Engine::setHorsepower(const int horsepower)
{
	m_horsepower = horsepower;
}

void Engine::setModelName(const std::string & model_name)
{
	m_model_name = model_name;
}

int Engine::getHorsePower() const
{
	return m_horsepower;
}

std::string Engine::getModelName() const
{
	return m_model_name;
}
