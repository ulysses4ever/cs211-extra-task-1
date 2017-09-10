#include <iostream>
#include <assert.h>
#include <cmath>

//Return the number of seconds later that a time in seconds time_2 is than a time in seconds time_1.
double seconds_difference(double time_1, double time_2)
{
	return time_2 - time_1;
}

//Return the number of hours later that a time in seconds time_2 is than a time in seconds time_1.
double hours_difference(double time_1, double time_2)
{
	return (time_2 - time_1) / 3600.0;
}

//Return the total number of hours in the specified number of hours, minutes, and seconds.
double to_float_hours(int hours, int minutes, int seconds)
{
	return hours + (minutes * 60 + seconds) / 3600.0;
}


//hours is a number of hours since midnight. Return the hour as seen on a 24 - hour clock.
double to_24_hour_clock(double hours)
{
	return (int)floor(hours) % 24 + hours-floor(hours);
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

//Return time at UTC+0, where utc_offset is the number of hours away from UTC + 0.
double time_to_utc(int utc_offset, double time)
{
	int hour = (int)floor(time) - utc_offset + 24;
	return (hour) % 24 + time - floor(time);
}

//Return UTC time in time zone utc_offset.
double time_from_utc(int utc_offset, double time)
{
    /*
        >>> time_from_utc(+0, 12.0)
        12.0
        >>> time_from_utc(+1, 12.0)
        13.0
        >>> time_from_utc(-1, 12.0)
        11.0
        >>> time_from_utc(+6, 6.0)
        12.0
        >>> time_from_utc(-7, 6.0)
        23.0
        >>> time_from_utc(-1, 0.0)
        23.0
        >>> time_from_utc(-1, 23.0)
        22.0
        >>> time_from_utc(+1, 23.0)
        0.0
    */
	return 0;
}

bool are_equal(double x, double y, double eps = 1e-10) {
	return (abs(x - y) <= eps);
}

int main() {
	//seconds_difference testing
	assert(are_equal(seconds_difference(1800, 3600), 1800) && "test 1");
	assert(are_equal(seconds_difference(3600, 1800), -1800) && "test 2");
	assert(are_equal(seconds_difference(1800, 2160), 360) && "test 3");
	assert(are_equal(seconds_difference(1800, 1800), 0) && "test 4");

	//hours_difference testing
	assert(are_equal(hours_difference(1800, 3600), 0.5) && "test 1");
	assert(are_equal(hours_difference(3600, 1800), -0.5) && "test 2");
	assert(are_equal(hours_difference(1800, 2160), 0.1) && "test 3");
	assert(are_equal(hours_difference(1800, 1800), 0) && "test 4");

	//to_float_hours testing
	assert(are_equal(to_float_hours(0, 15, 0), 0.25) && "test 1");
	assert(are_equal(to_float_hours(2, 45, 9), 2.7525) && "test 2");
	assert(are_equal(to_float_hours(1, 0, 36), 1.01) && "test 3");
	
	//to_24_hour_clock testing
	assert(are_equal(to_24_hour_clock(24), 0) && "test 1");
	assert(are_equal(to_24_hour_clock(48), 0) && "test 2");
	assert(are_equal(to_24_hour_clock(25), 1) && "test 3");
	assert(are_equal(to_24_hour_clock(4), 4) && "test 4");
	assert(are_equal(to_24_hour_clock(28.5), 4.5) && "test 5");

	//get_hours
	assert(get_hours(3800) == 1 && "test 1");
	assert(get_hours(7200) == 2 && "test 2");
	assert(get_hours(3599) == 0 && "test 3");

	//get_minutes
	assert(get_minutes(3800) == 3 && "test 1");
	assert(get_minutes(3600) == 0 && "test 2");
	assert(get_minutes(3719) == 1 && "test 3");

	//get_seconds
	assert(get_seconds(3800) == 20 && "test 1");
	assert(get_seconds(7219) == 19 && "test 2");
	assert(get_seconds(7199) == 59 && "test 3");

	//time_to_utc
	assert(are_equal(time_to_utc(+0, 12.0), 12) && "test 1");
	assert(are_equal(time_to_utc(+1, 12.0), 11) && "test 2");
	assert(are_equal(time_to_utc(-1, 0.0), 1) && "test 3");
	assert(are_equal(time_to_utc(-1, 23.0), 0) && "test 4");
	assert(are_equal(time_to_utc(-1, 12.0), 13) && "test 5");
	assert(are_equal(time_to_utc(-11, 18.0), 5) && "test 6");
	assert(are_equal(time_to_utc(1, 0.0), 23) && "test 7");
}