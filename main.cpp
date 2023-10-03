#include <iostream>
#include "extra-task-1.h"
#include <cassert>

int main() {

	//task1

	assert(equal(seconds_difference(3600.0, 1800.0), -1800.0));
	assert(equal(seconds_difference(1800.0, 1800.0), 0.0));
	assert(equal(seconds_difference(1800.0, 3600.0), 1800.0));
	assert(equal(seconds_difference(256.0, 0.0), -256.0));
	assert(equal(seconds_difference(123.1, 832.8), 709.7));

	//task2

	assert(equal(hours_difference(1800.0, 3600.0), 0.5));
	assert(equal(hours_difference(3600.0, 1800.0), -0.5));
	assert(equal(hours_difference(1800.0, 2160.0), 0.1));
	assert(equal(hours_difference(0.0, 3600.0), 1.0));
	assert(equal(hours_difference(1800.0, 1800.0), 0.));

	//task3

	assert(equal(to_float_hours(0, 15, 0), 0.25));
	assert(equal(to_float_hours(2, 45, 9), 2.7525));
	assert(equal(to_float_hours(1, 0, 36), 1.01));
	assert(equal(to_float_hours(0, 15, 0), 0.25));
	assert(equal(to_float_hours(0, 15, 0), 0.25));

	//task4

	assert(equal(to_24_hour_clock(24), 0));
	assert(equal(to_24_hour_clock(48), 0));
	assert(equal(to_24_hour_clock(25), 1));
	assert(equal(to_24_hour_clock(4), 4));
	assert(equal(to_24_hour_clock(26.5), 2.5));
}
