#pragma once
#include <functional>
#include <iostream>
#include <memory>
#include <string>
#include "Engine.h"

class Vehicle {
public:
	// interface
	virtual float calcPowerIndex() = 0;
	virtual std::string getCSVFormat() = 0;
	virtual void printVehicleSound() = 0;

	// destroyer
	~Vehicle();

	// setter
	void setEngine(const Engine& engine);
	void setManufactor(const std::string& m);
	void setModelName(const std::string& m);
	void setYear(const int y);

	// getter
	std::shared_ptr<Engine> getEngine() const;
	std::string getManufactor() const;
	std::string getModelName() const;
	int getYear() const;

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