#include <iostream>
#include <cmath>
#include <cassert>

bool f(double x, double y, double eps = 1e-10) {

	return(abs(x - y) < eps);
}

double seconds_difference(double time_1, double time_2)
{
	return(time_2 - time_1);
}

double hours_difference(double time_1, double time_2)
{
	return (time_2 / 3600 - time_1 / 3600);
}

double to_float_hours(int hours, int minutes, int seconds)
{
	return(hours + (minutes / 60.0) + (seconds / 3600.0));
}

double to_24_hour_clock(double hours)
{
	while (hours > 24) {
		hours -= 24.0;
	}
	if (hours == 24) { hours = 0; }
	return (hours);
}

double time_to_utc(int utc_offset, double time)
{
	if (time - utc_offset == 24) {
		time = 0;
		utc_offset = 0;
	}
	double a = time - utc_offset;
	if (a > 24) {
		a -= 24;
	}
	return(a);
}

double time_from_utc(int utc_offset, double time)
{
	double a = time + utc_offset;
	if (a < 0) {
		a += 24;
	}
	if (a >= 24) {
		a -= 24;
	}
	return a;
}


int main() {

	assert(f(seconds_difference(1800, 3600), 1800) && "test 1.1");
	assert(f(seconds_difference(3600, 1800), -1800) && "test 1.2");
	assert(f(seconds_difference(1800, 2160), 360) && "test 1.3");
	assert(f(seconds_difference(1800, 1800), 0) && "test 1.4");

	assert(f(hours_difference(1800.0, 3600.0), 0.5) && "test 2.1");
	assert(f(hours_difference(3600.0, 1800.0), -0.5) && "test 2.2");
	assert(f(hours_difference(1800.0, 2160.0), 0.1) && "test 2.3");
	assert(f(hours_difference(1800.0, 1800.0), 0.0) && "test 2.4");

	assert(f(to_float_hours(0, 15, 0), 0.25) && "test 3.1");
	assert(f(to_float_hours(2, 45, 9), 2.7525) && "test 3.2");
	assert(f(to_float_hours(1, 0, 36), 1.01) && "test 3.3");

	assert(f(to_24_hour_clock(24), 0) && "test 4.1");
	assert(f(to_24_hour_clock(48), 0) && "test 4.2");
	assert(f(to_24_hour_clock(25), 1) && "test 4.3");
	assert(f(to_24_hour_clock(4), 4) && "test 4.4");
	assert(f(to_24_hour_clock(28.5), 4.5) && "test 4.5");

	assert(f(time_to_utc(+0, 12.0), 12.0) && "test 5.1");
	assert(f(time_to_utc(-1, 12.0), 13.0) && "test 5.2");
	assert(f(time_to_utc(-11, 18.0), 5.0) && "test 5.3");
	assert(f(time_to_utc(-1, 0.0), 1.0) && "test 5.4");
	assert(f(time_to_utc(-1, 23.0), 0.0) && "test 5.5");

	assert(f(time_from_utc(+0, 12.0), 12.0) && "test 6.1");
	assert(f(time_from_utc(+1, 12.0), 13.0) && "test 6.2");
	assert(f(time_from_utc(-1, 12.0), 11.0) && "test 6.3");
	assert(f(time_from_utc(+6, 6.0), 12.0) && "test 6.4");
	assert(f(time_from_utc(-7, 6.0), 23.0) && "test 6.5");
	assert(f(time_from_utc(-1, 0.0), 23.0) && "test 6.6");
	assert(f(time_from_utc(-1, 23.0), 22.0) && "test 6.7");
	assert(f(time_from_utc(+1, 23.0), 0.0) && "test 6.8");


	return 0;
}