#pragma once
#include <string>

class Engine
{
public:
	// constructors
	Engine() = delete;
	Engine(const int horsepower, const std::string& model_name);
	Engine(const Engine& engine);

	~Engine();

	// setter
	void setHorsepower(const int horsepower);
	void setModelName(const std::string& model_name);

	// getter
	int getHorsePower() const;
	std::string getModelName() const;

private:
	int m_horsepower;
	std::string m_model_name;

	static int engine_ptr_count;
};

