#include<iostream>
#include"header.h"
int main()
{
	assert(seconds_difference(1800.0, 3600.0) == 1800.0);
	assert(seconds_difference(3600.0, 1800.0) == -1800.0);
	assert(seconds_difference(1800.0, 2160.0) == 360.0);
	assert(seconds_difference(1800.0, 1800.0) == 0.0);

	assert(hours_difference(1800.0, 3600.0) == 0.5);
	assert(hours_difference(3600.0, 1800.0) == -0.5);
	assert(hours_difference(1800.0, 2160.0) == 0.1);
	assert(hours_difference(1800.0, 1800.0) == 0.0);


	assert(to_float_hours(0, 15, 0) == 0.25);
	assert(to_float_hours(2, 45, 9) == 2.7525);
	assert(to_float_hours(1, 0, 36) == 1.01);

	assert(to_24_hour_clock(24) == 0);
	assert(to_24_hour_clock(48) == 0);
	assert(to_24_hour_clock(25) == 1);
	assert(to_24_hour_clock(4) == 4);
	assert(to_24_hour_clock(28.5) == 4.5);


	assert(get_hours(3800) == 1);
	assert(get_minutes(3800) == 3);
	assert(get_seconds(3800) == 20);



}