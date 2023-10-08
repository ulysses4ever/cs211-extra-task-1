#include "extra-task-1.h"
#include <assert.h>
#include <math.h>
#include <float.h>
#include <iostream>

void main()
{
	//seconds_difference
	assert(fabs(seconds_difference(1800.0, 3600.0) - 1800.0) <= DBL_EPSILON);
	assert(fabs(seconds_difference(3600.0, 1800.0) - (-1800.0)) <= DBL_EPSILON);
	assert(fabs(seconds_difference(1800.0, 2160.0) - 360.0) <= DBL_EPSILON);
	assert(fabs(seconds_difference(1800.0, 1800.0)) <= DBL_EPSILON);
	std::cout << "seconds_difference works!" << std::endl;

	//hours_difference
	assert(fabs(hours_difference(1800.0, 3600.0) - 0.5) <= DBL_EPSILON);
	assert(fabs(hours_difference(3600.0, 1800.0) - (-0.5)) <= DBL_EPSILON);
	assert(fabs(hours_difference(1800.0, 2160.0) - 0.1) <= DBL_EPSILON);
	assert(fabs(hours_difference(1800.0, 1800.0)) <= DBL_EPSILON);
	std::cout << "hours_difference works!" << std::endl;

	//to_float_hours
	assert(fabs(to_float_hours(0, 15, 0) - 0.25) <= DBL_EPSILON);
	assert(fabs(to_float_hours(2, 45, 9) - 2.7525) <= DBL_EPSILON);
	assert(fabs(to_float_hours(1, 0, 36) - 1.01) <= DBL_EPSILON);
	std::cout << "to_float_hours works!" << std::endl;

	//to_24_hour_clock
	assert(fabs(to_24_hour_clock(24)) <= DBL_EPSILON);
	assert(fabs(to_24_hour_clock(48)) <= DBL_EPSILON);
	assert(fabs(to_24_hour_clock(25) - 1) <= DBL_EPSILON);
	assert(fabs(to_24_hour_clock(4) - 4) <= DBL_EPSILON);
	assert(fabs(to_24_hour_clock(28.5) - 4.5) <= DBL_EPSILON);

	//get_hours
	assert(get_hours(3800) == 1);
	assert(get_hours(1) == 0);
	assert(get_hours(9000) == 2);
	std::cout << "to_24_hour_clock works!" << std::endl;
}