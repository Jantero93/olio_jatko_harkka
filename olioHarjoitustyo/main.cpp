#include <iostream>
#include "Engine.h"
#include "Car.h"
#include "App.h"

int Engine::engine_ptr_count = 0;
App* App::instance = 0;

using std::cout; using std::endl;

int main() {
	App* app = App::getInstance();

	app->start();

	system("pause");
	return EXIT_SUCCESS;
}