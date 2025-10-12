#include "extra-task-1.h"
#include <iostream>
int main()
{
	// test - seconds_difference
	assert(double_equals(seconds_difference(1800.0, 3600.0), 1800.0));
	assert(double_equals(seconds_difference(3600.0, 1800.0), -1800.0));
	assert(double_equals(seconds_difference(1800.0, 2160.0), 360.0));
	assert(double_equals(seconds_difference(1800.0, 1800.0), 0.0));

	// test - hours_difference
	assert(double_equals(hours_difference(1800.0, 3600.0), 0.5));
	assert(double_equals(hours_difference(3600.0, 1800.0), -0.5));
	assert(double_equals(hours_difference(1800.0, 2160.0), 0.1));
	assert(double_equals(hours_difference(1800.0, 1800.0), 0.0));

	// test - to_float_hours
	assert(double_equals(to_float_hours(0, 15, 0), 0.25));
	assert(double_equals(to_float_hours(2, 45, 9), 2.7525));
	assert(double_equals(to_float_hours(1, 0, 36), 1.01));

	// test - to_24_hour_clock
	assert(double_equals(to_24_hour_clock(24), 0));
	assert(double_equals(to_24_hour_clock(48), 0));
	assert(double_equals(to_24_hour_clock(25), 1));
	assert(double_equals(to_24_hour_clock(4), 4));
	assert(double_equals(to_24_hour_clock(28.5), 4.5));

	// test - get_hours, get_minutes, get_seconds
	assert(get_hours(3800) == 1);
	assert(get_minutes(3800) == 3);
	assert(get_seconds(3800) == 20);

	// test - time_to_utc
	assert(double_equals(time_to_utc(+0, 12.0), 12.0));
	assert(double_equals(time_to_utc(+1, 12.0), 11.0));
	assert(double_equals(time_to_utc(-1, 12.0), 13.0));
	assert(double_equals(time_to_utc(-11, 18.0), 5.0));
	assert(double_equals(time_to_utc(-1, 0.0), 1.0));
	assert(double_equals(time_to_utc(-1, 23.0), 0.0));

	return 0;
}