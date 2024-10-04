#include "extra-task-1.h"
#include <assert.h>
#include <cfloat>
#include <math.h>
#include <iostream>

int main()
{
	//task1
	assert(fabs(seconds_difference(1800.0, 3600.0) - 1800.0) < DBL_EPSILON);
	assert(fabs(seconds_difference(3600.0, 1800.0) - (-1800.0)) < DBL_EPSILON);
	assert(fabs(seconds_difference(1800.0, 2160.0) - 360.0) < DBL_EPSILON);
	assert(fabs(seconds_difference(1800.0, 1800.0) - 0.0) < DBL_EPSILON);

	//task2
	assert(fabs(hours_difference(1800.0, 3600.0) - 0.5) < DBL_EPSILON);
	assert(fabs(hours_difference(3600.0, 1800.0) - (-0.5)) < DBL_EPSILON);
	assert(fabs(hours_difference(1800.0, 2160.0) - 0.1) < DBL_EPSILON);
	assert(fabs(hours_difference(1800.0, 1800.0) - 0.0) < DBL_EPSILON);

	//task3
	assert(fabs(to_float_hours(0, 15, 0) - 0.25) < DBL_EPSILON);
	assert(fabs(to_float_hours(2, 45, 9) - 2.7525) < DBL_EPSILON);
	assert(fabs(to_float_hours(1, 0, 36) - 1.01) < DBL_EPSILON);

	//task4
	assert(fabs(to_24_hour_clock(24) - 0.0) < DBL_EPSILON);
	assert(fabs(to_24_hour_clock(48) - 0.0) < DBL_EPSILON);
	assert(fabs(to_24_hour_clock(25) - 1.0) < DBL_EPSILON);
	assert(fabs(to_24_hour_clock(4) - 4.0) < DBL_EPSILON);
	assert(fabs(to_24_hour_clock(28.5) - 4.5) < DBL_EPSILON);

	//task5
	assert(fabs(get_hours(86400 + 3800) - 1) < DBL_EPSILON);
	assert(fabs(get_hours(3800) - 1) < DBL_EPSILON);
	assert(fabs(get_minutes(86400 + 3800) - 3) < DBL_EPSILON);
	assert(fabs(get_minutes(3800) - 3) < DBL_EPSILON);
	assert(fabs(get_seconds(86400 + 3800) - 20) < DBL_EPSILON);
	assert(fabs(get_seconds(3800) - 20) < DBL_EPSILON);

	//task6
	assert(fabs(time_to_utc(+0, 12.0) - 12) < DBL_EPSILON);
	assert(fabs(time_to_utc(+1, 12.0) - 11.0) < DBL_EPSILON);
	assert(fabs(time_to_utc(-1, 12.0) - 13.0) < DBL_EPSILON);
	assert(fabs(time_to_utc(-11, 18.0) - 5.0) < DBL_EPSILON);
	assert(fabs(time_to_utc(-1, 0.0) - 1.0) < DBL_EPSILON);
	assert(fabs(time_to_utc(-1, 23.0) - 0.0) < DBL_EPSILON);

	//task7
	assert(fabs(time_from_utc(+0, 12.0) - 12) < DBL_EPSILON);
	assert(fabs(time_to_utc(+1, 12.0) - 13.0) < DBL_EPSILON);
	assert(fabs(time_to_utc(-1, 12.0) - 11.0) < DBL_EPSILON);
	assert(fabs(time_to_utc(+6, 6.0) - 12.0) < DBL_EPSILON);
	assert(fabs(time_to_utc(-7, 6.0) - 23.0) < DBL_EPSILON);
	assert(fabs(time_to_utc(-1, 0.0) - 23.0) < DBL_EPSILON);
	assert(fabs(time_to_utc(-1, 23.0) - 22.0) < DBL_EPSILON);
	assert(fabs(time_to_utc(+1, 23.0) - 0.0) < DBL_EPSILON);
}