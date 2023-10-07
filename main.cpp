#include <cassert>
#include <iostream>
#include <cfloat>
#include "extra-task-1.h"

int main() {

	setlocale(LC_ALL, "Russian");

	//seconds_difference tests
	assert(fabs(seconds_difference(1800.0, 3600.0) - 1800) < DBL_EPSILON);
	assert(fabs(seconds_difference(3600.0, 1800.0) + 1800) < DBL_EPSILON);
	assert(fabs(seconds_difference(1800.0, 2160.0) - 360) < DBL_EPSILON);
	assert(fabs(seconds_difference(1800.0, 1800.0)) < DBL_EPSILON);

}

