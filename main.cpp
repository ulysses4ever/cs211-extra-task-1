﻿#include <iostream>
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


	assert(abs(to_24_hour_clock(24)) <= DBL_EPSILON);
	assert(abs(to_24_hour_clock(48)) <= DBL_EPSILON);
	assert(abs(to_24_hour_clock(25) - 1) <= DBL_EPSILON);
	assert(abs(to_24_hour_clock(4) - 4) <= DBL_EPSILON);
	assert(abs(to_24_hour_clock(28.5) - 4.5) <= DBL_EPSILON);


	assert(abs(get_hours(3800) - 1) <= DBL_EPSILON);
	assert(abs(get_minutes(3800) - 3) <= DBL_EPSILON);
	assert(abs(get_seconds(3800) - 20) <= DBL_EPSILON);

	
	assert(abs(time_to_utc(+0, 12.0) - 12.0) <= DBL_EPSILON);
	assert(abs(time_to_utc(+1, 12.0) - 11.0) <= DBL_EPSILON);
	assert(abs(time_to_utc(-1, 12.0) - 13.0) <= DBL_EPSILON);
	assert(abs(time_to_utc(-11, 18.0) - 5.0) <= DBL_EPSILON);
	assert(abs(time_to_utc(-1, 0.0) - 1.0) <= DBL_EPSILON);
	assert(abs(time_to_utc(-1, 23.0)) <= DBL_EPSILON);
	

	assert(abs(time_from_utc(+0, 12.0) - 12.0) <= DBL_EPSILON);
	assert(abs(time_from_utc(+1, 12.0) - 13.0) <= DBL_EPSILON);
	assert(abs(time_from_utc(-1, 12.0) - 11.0) <= DBL_EPSILON);
	assert(abs(time_from_utc(+6, 6.0) - 12.0) <= DBL_EPSILON);
	assert(abs(time_from_utc(-7, 6.0) - 23.0) <= DBL_EPSILON);
	assert(abs(time_from_utc(-1, 0.0) - 23.0) <= DBL_EPSILON);
	assert(abs(time_from_utc(-1, 23.0) - 22.0) <= DBL_EPSILON);
	assert(abs(time_from_utc(+1, 23.0)) <= DBL_EPSILON);
}