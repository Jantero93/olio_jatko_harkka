#pragma once
#include <iostream>
#include <string>
#include "Engine.h"
#include <memory>
#include <functional>

class Vehicle {
public:
	// interface
 	virtual void printVehicleSound() = 0;
	virtual float calcPowerIndex() = 0;
	virtual std::string getCSVFormat() = 0;

	// destroyer
	~Vehicle();

	// setter
	void setManufactor(const std::string& m);
	void setModelName(const std::string& m);
	void setYear(const int y);

	// getter
	int getYear() const;
	std::string getManufactor() const;
	std::string getModelName() const;

protected:
	// constructors
	Vehicle();
	Vehicle(const std::string& manufactor, const std::string& model, const int year, const int engine_power, const std::string& engine_model);
	Vehicle(const std::string& manufactor, const std::string& model, const int year);
	Vehicle(Vehicle& v) = delete;

	// class variables
	std::string m_manufactor;
	std::string m_model_name;
	std::shared_ptr<Engine> m_ptr_engine;
	int m_year;	
};