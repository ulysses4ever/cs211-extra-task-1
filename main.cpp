#include <iostream>
#include <assert.h>
using namespace std; 

int main()
{
	// Задание 1 (seconds_difference)
	assert(seconds_difference(1800.0, 3600.0) - 1800.0 <= DBL_EPSILON); 
	assert(seconds_difference(3600.0, 1800.0) + 1800.0 <= DBL_EPSILON);
	assert(seconds_difference(1800.0, 2160.0) - 360.0 <= DBL_EPSILON);
	assert(seconds_difference(1800.0, 1800.0) <= DBL_EPSILON);

	// Задание 2 (hours_difference)
	assert(hours_difference(1800.0, 3600.0) - 0.5 <= DBL_EPSILON);
	assert(hours_difference(3600.0, 1800.0) + 0.5 <= DBL_EPSILON);
	assert(hours_difference(1800.0, 2160.0) - 0.1 <= DBL_EPSILON);
	assert(hours_difference(1800.0, 1800.0) <= DBL_EPSILON);

	// Задание 3 (to_float_hours)
	assert(to_float_hours(0, 15, 0) - 0.25 <= DBL_EPSILON);
	assert(to_float_hours(2, 45, 9) - 2.7525 <= DBL_EPSILON);
	assert(to_float_hours(1, 0, 36) - 1.01 <= DBL_EPSILON);

	// Задание 4 (to_24_hour_clock)
	assert(to_24_hour_clock(24) <= DBL_EPSILON);
	assert(to_24_hour_clock(48) <= DBL_EPSILON);
	assert(to_24_hour_clock(25) - 1 <= DBL_EPSILON);
	assert(to_24_hour_clock(4) - 4 <= DBL_EPSILON);
	assert(to_24_hour_clock(28.5) - 4.5 <= DBL_EPSILON);

	// Задание 5 (get_hours, get_minutes, get_seonds)
	assert(get_hours(3800) == 1); 
	assert(get_minutes(3800) == 3);
	assert(get_seconds(3800) == 20);

	// Задание 6 (time_to_utc)
	assert(time_to_utc(+0, 12.0) - 12 <= DBL_EPSILON);
	assert(time_to_utc(+1, 12.0) - 11 <= DBL_EPSILON);
	assert(time_to_utc(-1, 12.0) - 13 <= DBL_EPSILON);
	assert(time_to_utc(-11, 18.0) - 5 <= DBL_EPSILON);
	assert(time_to_utc(-1, 0.0) - 1 <= DBL_EPSILON);
	assert(time_to_utc(-1, 23.0) <= DBL_EPSILON);

	// Задание 7 (time_from_utc) 
	assert(time_from_utc(+0, 12.0) - 12 <= DBL_EPSILON);
	assert(time_from_utc(+1, 12.0) - 13 <= DBL_EPSILON);
	assert(time_from_utc(-1, 12.0) - 11.0 <= DBL_EPSILON);
	assert(time_from_utc(+6, 6.0) - 12.0 <= DBL_EPSILON);
	assert(time_from_utc(-7, 6.0) - 23 <= DBL_EPSILON);
	assert(time_from_utc(-1, 0.0) - 23 <= DBL_EPSILON);
	assert(time_from_utc(-1, 23.0) - 22 <= DBL_EPSILON);
	assert(time_from_utc(+1, 23.0) <= DBL_EPSILON);

	system("pause"); 
}