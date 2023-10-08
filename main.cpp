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

	//task4

	assert(abs(to_24_hour_clock(24) - 0) < DBL_EPSILON);
	assert(abs(to_24_hour_clock(48) - 0) < DBL_EPSILON);
	assert(abs(to_24_hour_clock(25) - 1) < DBL_EPSILON);
	assert(abs(to_24_hour_clock(4) - 4) < DBL_EPSILON);
	assert(abs(to_24_hour_clock(28.5) - 4.5) < DBL_EPSILON);

	//task5
	assert(abs(time_to_utc(+0, 12.0) - 12.0) < DBL_EPSILON);
	assert(abs(time_to_utc(+1, 12.0) - 11.0) < DBL_EPSILON);
	assert(abs(time_to_utc(-1, 12.0) - 13.0) < DBL_EPSILON);
	assert(abs(time_to_utc(-11, 18.0) - 5.0) < DBL_EPSILON);
	assert(abs(time_to_utc(-1, 0.0) - 1.0) < DBL_EPSILON);
	assert(abs(time_to_utc(-1, 23.0) - 0.0) < DBL_EPSILON);
	assert(abs(time_to_utc(1, 0.0) - 23.0) < DBL_EPSILON);

	//task6





}