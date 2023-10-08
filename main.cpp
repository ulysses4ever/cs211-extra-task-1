#include<iostream>
#include "cassert"
#include <cfloat>
#include <cmath>
#include "extra-task-1.h"
int main()
{
	//task1
	assert(abs(1800.0 - seconds_difference(1800.0, 3600.0)) < DBL_EPSILON);
	assert(abs(-1800.0 - seconds_difference(3600.0, 1800.0)) < DBL_EPSILON);
	assert(abs(360.0 - seconds_difference(1800.0, 2160.0)) < DBL_EPSILON);
	assert(abs(0 - seconds_difference(1800.0, 1800.0)) < DBL_EPSILON);

	//task2
	assert(abs(0.5 - hours_difference(1800.0, 3600.0)) < DBL_EPSILON);
	assert(abs(-0.5 - hours_difference(3600.0, 1800.0)) < DBL_EPSILON);
	assert(abs(0.1 - hours_difference(1800.0, 2160.0)) < DBL_EPSILON);
	assert(abs(0 - hours_difference(1800.0, 1800.0)) < DBL_EPSILON);

	//task3
	assert(abs(to_float_hours(0, 15, 0) - 0.25) < DBL_EPSILON);
	assert(abs(to_float_hours(2, 45, 9) - 2.7525) < DBL_EPSILON);
	assert(abs(to_float_hours(1, 0, 36) - 1.01) < DBL_EPSILON);




}