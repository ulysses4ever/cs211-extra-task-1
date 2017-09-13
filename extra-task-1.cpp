#include <iostream>
#include <cassert>
#include <cmath>

bool RealEq(double x, double y, double eps = 0.0000000001) {
	return (abs(x - y) <= eps);
}

double seconds_difference(double time_1, double time_2)
{
	return time_2 - time_1;
}

double hours_difference(double time_1, double time_2)
{
	return (time_2 - time_1) / 3600.0;
}

double to_float_hours(int hours, int minutes, int seconds)
{
	return (hours * 3600 + minutes * 60 + seconds) / 3600.0;
}

double to_24_hour_clock(double hours)
{
	while (hours>=24)
		hours -= 24;
	return hours;
}

int get_hours(int time) {
	return time / 3600 % 24;
}

int get_minutes(int time) {
	return time / 60 % 60;
}

int get_seconds(int time) {
	return time % 60;
}

double time_to_utc(int utc_offset, double time)
{
	time -= utc_offset - 24;
	while (time >= 24)
		time -= 24;
	return time;
}

double time_from_utc(int utc_offset, double time)
{
	time += utc_offset + 24;
	while (time >= 24)
		time -= 24;
	return time;
}

int main() {
	assert(RealEq(seconds_difference(1800, 3600), 1800) && "number 1");
	assert(RealEq(seconds_difference(3600, 1800), -1800) && "number 2");
	assert(RealEq(seconds_difference(1800, 2160), 360) && "number 3");
	assert(RealEq(seconds_difference(1800, 1800), 0) && "number 4");

	assert(RealEq(hours_difference(1800, 3600), 0.5) && "number 1");
	assert(RealEq(hours_difference(3600, 1800), -0.5) && "number 2");
	assert(RealEq(hours_difference(1800, 2160), 0.1) && "number 3");
	assert(RealEq(hours_difference(1800, 1800), 0) && "number 4");

	assert(RealEq(to_float_hours(0, 15, 0), 0.25) && "number 1");
	assert(RealEq(to_float_hours(2, 45, 9), 2.7525) && "number 2");
	assert(RealEq(to_float_hours(1, 0, 36), 1.01) && "number 3");

	assert(RealEq(to_24_hour_clock(24), 0) && "number 1");
	assert(RealEq(to_24_hour_clock(48), 0) && "number 2");
	assert(RealEq(to_24_hour_clock(25), 1) && "number 3");
	assert(RealEq(to_24_hour_clock(4), 4) && "number 4");
	assert(RealEq(to_24_hour_clock(28.5), 4.5) && "number 5");

	assert(RealEq(time_to_utc(+0, 12.0), 12) && "number 1");
	assert(RealEq(time_to_utc(+1, 12.0), 11) && "number 2");
	assert(RealEq(time_to_utc(-1, 0.0), 1) && "number 3");
	assert(RealEq(time_to_utc(-1, 23.0), 0) && "number 4");
	assert(RealEq(time_to_utc(-1, 12.0), 13) && "number 5");
	assert(RealEq(time_to_utc(-11, 18.0), 5) && "number 6");
	assert(RealEq(time_to_utc(1, 0.0), 23) && "number 7");

	assert(RealEq(time_from_utc(+0, 12.0), 12) && "number 1");
	assert(RealEq(time_from_utc(+1, 12.0), 13) && "number 2");
	assert(RealEq(time_from_utc(-1, 12.0), 11) && "number 3");
	assert(RealEq(time_from_utc(+6, 6.0), 12) && "number 4");
	assert(RealEq(time_from_utc(-7, 6.0), 23) && "number 5");
	assert(RealEq(time_from_utc(-1, 0.0), 23) && "number 6"); 
	assert(RealEq(time_from_utc(-1, 23.0), 22) && "number 7");
	assert(RealEq(time_from_utc(+1, 23.0), 0) && "number 8");
}