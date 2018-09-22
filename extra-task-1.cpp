#include <cassert>
#include <cfloat>
#include <cmath>

using namespace std;

//Return are equel numbers or not.
bool areEquel(double x, double y)
{
	return (abs(x - y) < DBL_EPSILON);
}

//Return the number of seconds later that a time in seconds
//time_2 is than a time in seconds time_1.
double seconds_difference(double time_1, double time_2)
{
	return time_2 - time_1;
}

//Return the number of hours later that a time in seconds
//time_2 is than a time in seconds time_1.
double hours_difference(double time_1, double time_2)
{
	return seconds_difference(time_1, time_2) / (double)3600;
}

//Return the total number of hours in the specified number
//of hours, minutes, and seconds.
double to_float_hours(int hours, int minutes, int seconds)
{
	assert(minutes >= 0 && minutes < 60);
	assert(seconds >= 0 && seconds < 60);

	return hours + minutes / 60.0 + seconds / 3600.0;
}

//hours is a number of hours since midnight. Return the
//hour as seen on a 24 - hour clock.
double to_24_hour_clock(double hours)
{
	assert(hours >= 0);
	return (int)floor(hours) % 24 + (hours - floor(hours));
}

int get_hours(int time)
{
	return time / 3600 % 24;
}

int get_minutes(int time)
{
	return time / 60 % 60;
}

int get_seconds(int time)
{
	return time % 60;
}

//Return time at UTC+0, where utc_offset is the number of hours away from
//UTC + 0.
double time_to_utc(int utc_offset, double time)
{
	return ((int)floor(time) - utc_offset + 24) % 24 + (time - floor(time));
}

double time_from_utc(int utc_offset, double time)
{
    /*
        Return UTC time in time zone utc_offset.

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

int main()
{
	//seconds_difference
	assert(areEquel(seconds_difference(1800.0, 1800.0), 0.0));
	assert(areEquel(seconds_difference(1800.0, 3600.0), 1800.0));
	assert(areEquel(seconds_difference(3600.0, 1800.0), -1800.0));
	assert(areEquel(seconds_difference(1800.0, 2160.0), 360.0));
	//hours_difference
	assert(areEquel(hours_difference(1800.0, 3600.0), 0.5));
	assert(areEquel(hours_difference(3600.0, 1800.0), -0.5));
	assert(areEquel(hours_difference(1800.0, 2160.0), 0.1));
	assert(areEquel(hours_difference(1800.0, 1800.0), 0.0));
	//to_float_hours
	assert(areEquel(to_float_hours(0, 15, 0), 0.25));
	assert(areEquel(to_float_hours(2, 45, 9), 2.7525));
	assert(areEquel(to_float_hours(1, 0, 36), 1.01));
	//to_24_hour_clock
	assert(areEquel(to_24_hour_clock(24), 0));
	assert(areEquel(to_24_hour_clock(48), 0));
	assert(areEquel(to_24_hour_clock(25), 1));
	assert(areEquel(to_24_hour_clock(4), 4));
	assert(areEquel(to_24_hour_clock(28.5), 4.5));
	//get_hours
	assert(get_hours(3800), 1);
	assert(get_minutes(3800), 3);
	assert(get_seconds(3800), 20);
	//time_to_utc
	assert(areEquel(time_to_utc(0, 12.0), 12.0));
	assert(areEquel(time_to_utc(1, 12.0), 11.0));
	assert(areEquel(time_to_utc(-1, 12.0), 13.0));
	assert(areEquel(time_to_utc(-11, 18.0), 5.0));
	assert(areEquel(time_to_utc(-1, 0.0), 1.0));
	assert(areEquel(time_to_utc(-1, 23.0), 0.0));
}