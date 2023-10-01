#include <iostream>
#include "extra-task-1.h"
#include <cassert>

int main() {

	//task1

	assert(equal(seconds_difference(3600.0, 1800.0), -1800.0));
	assert(equal(seconds_difference(1800.0, 1800.0), 0.0));
	assert(equal(seconds_difference(1800.0, 3600.0), 1800.0));
	assert(equal(seconds_difference(256.0, 0.0), -256.0));
	assert(equal(seconds_difference(123.1, 832.8), 709.7));
}
