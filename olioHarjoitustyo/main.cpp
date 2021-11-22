#include <iostream>
#include "App.h"

int main() {
	App* app = App::getInstance();
	app->start();

	return EXIT_SUCCESS;
}