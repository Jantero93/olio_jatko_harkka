#include <iostream>
#include "Engine.h"
#include "Car.h"

int Engine::engine_ptr_count = 0;

using std::cout; using std::endl;

int main() {

	Car car = Car();


	system("pause");
	return EXIT_SUCCESS;
}