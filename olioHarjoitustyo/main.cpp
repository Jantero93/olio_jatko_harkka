#include <iostream>
#include "Engine.h"
#include "Car.h"

int Engine::engine_ptr_count = 0;

using std::cout; using std::endl;

int main() {


	Car car = Car("BMW", "520", 2011, 231, "E3&B");

	Car car3 = Car(car);

	cout << "auton voima " << std::to_string(car3.calcPowerIndex()) << endl;


	system("pause");
	return EXIT_SUCCESS;
}