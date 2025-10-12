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

	return 0;
}