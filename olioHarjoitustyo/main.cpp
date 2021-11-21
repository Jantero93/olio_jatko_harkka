#include <iostream>
#include "App.h"
#include "Car.h"
#include "Engine.h"

int Engine::engine_ptr_count = 0;
App* App::instance = 0;

using std::cout; using std::endl;

int main() {
	App* app = App::getInstance();
	app->start();

	return EXIT_SUCCESS;
}