#pragma once
#include <iostream>
#include <string>
#include "Engine.h"
#include <memory>
#include <functional>

class Vehicle {
public:
	// pure virtual
 //	virtual void printVehicleSound( std::function <void()>& ) = 0;
	virtual int calcTruePower() = 0;

	// setter
	void setManufactor(const std::string& m);
	void setModelName(const std::string& m);
	void setYear(const int y);

	// getter
	int getYear() const;
	std::string getManufactor() const;
	std::string getModelName() const;

protected:
	std::string m_manufactor;
	std::string m_model_name;
	std::shared_ptr<Engine> m_ptr_engine;
	int m_year;	
};