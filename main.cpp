#include <iostream>
#include <cassert>
#include "extra-task-1.h"


void main() {

	// testing the function seconds_difference
	assert((seconds_difference(1800.0, 3600.0)) - 1800.0 < DBL_EPSILON);
	assert((seconds_difference(3600.0, 1800.0)) + 1800.0 < DBL_EPSILON);
	assert((seconds_difference(1800.0, 2160.0)) - 360.0 < DBL_EPSILON);
	assert((seconds_difference(1800.0, 1800.0)) - 0.0 < DBL_EPSILON);

	// testing the function hours_difference
	assert((hours_difference(1800.0, 3600.0) - 0.5) < DBL_EPSILON);
	assert((hours_difference(3600.0, 1800.0) + 0.5) < DBL_EPSILON);
	assert((hours_difference(1800.0, 2160.0) - 0.1) < DBL_EPSILON);
	assert((hours_difference(1800.0, 1800.0) - 0.0) < DBL_EPSILON);

	// testing the function to_float_hours
	assert((to_float_hours(0, 15, 0) - 0.25) < DBL_EPSILON);
	assert((to_float_hours(2, 45, 9) - 2.7525) < DBL_EPSILON);
	assert((to_float_hours(1, 0, 36) - 1.01) < DBL_EPSILON);

	// testing the function to_24_hour_clock
	assert((to_24_hour_clock(24) - 0.0) < DBL_EPSILON);
	assert((to_24_hour_clock(48) - 0.0) < DBL_EPSILON);
	assert((to_24_hour_clock(25) - 1.0) < DBL_EPSILON);
	assert((to_24_hour_clock(4) - 4.0) < DBL_EPSILON);
	assert((to_24_hour_clock(28.5) - 4.5) < DBL_EPSILON);

	// testing the function time_to_utc
	assert((time_to_utc(+0, 12.0) - 12.0) < DBL_EPSILON);
	assert((time_to_utc(+1, 11.0) - 11.0) < DBL_EPSILON);
	assert((time_to_utc(-1, 12.0) - 13.0) < DBL_EPSILON);
	assert((time_to_utc(-11, 18.0) - 5.0) < DBL_EPSILON);
	assert((time_to_utc(-1, 0.0) - 1.0) < DBL_EPSILON);
	assert((time_to_utc(-1, 23.0) - 0.0) < DBL_EPSILON);

	// testing the function time_from_utc
	assert((time_from_utc(+0, 12.0) - 12.0) < DBL_EPSILON);
	assert((time_from_utc(+1, 12.0) - 13.0) < DBL_EPSILON);
	assert((time_from_utc(-1, 12.0) - 11.0) < DBL_EPSILON);
	assert((time_from_utc(+6, 6.0) - 12.0) < DBL_EPSILON);
	assert((time_from_utc(-7, 6.0) - 23.0) < DBL_EPSILON);
	assert((time_from_utc(-1, 0.0) - 23.0) < DBL_EPSILON);
	assert((time_from_utc(-1, 23.0) - 22.0) < DBL_EPSILON);
	assert((time_from_utc(+1, 23.0) - 0.0) < DBL_EPSILON);

	std::cout << "All tests completed." << std::endl;
}