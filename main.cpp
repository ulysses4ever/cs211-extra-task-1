#include <iostream>
#include <assert.h>
#include <cmath>
#include "Header.h"

using namespace std;

int main()
{
	assert(abs(seconds_difference(1800.0, 3600.0) - 1800) == 0);
	assert(abs(seconds_difference(3600.0, 1800.0) + 1800) == 0);
	assert(abs(seconds_difference(1800.0, 2160.0) - 360) == 0);
	assert(abs(seconds_difference(1800.0, 1800.0)) == 0);


	assert(abs(hours_difference(1800.0, 3600.0) - 0.5) == 0);
	assert(abs(hours_difference(3600.0, 1800.0) + 0.5) == 0);
	assert(abs(hours_difference(1800.0, 2160.0) - 0.1) == 0);
	assert(abs(hours_difference(1800.0, 1800.0)) == 0);


	assert(abs(to_float_hours(0, 15, 0) - 0.25) <= DBL_EPSILON);
	assert(abs(to_float_hours(2, 45, 9) - 2.7525) <= DBL_EPSILON);
	assert(abs(to_float_hours(1, 0, 36) - 1.01) <= DBL_EPSILON);
}