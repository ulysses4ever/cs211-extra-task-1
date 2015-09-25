#include <cassert>
#include <cmath>
#include <cfloat>

bool areEquals(double x, double y) {
	return fabs(x - y) < DBL_EPSILON;
}

double seconds_difference(double time_1, double time_2)
{
	return time_2 - time_1;
}

double hours_difference(double time_1, double time_2)
{
	return (time_2 / 3600) - (time_1 / 3600);
}

double to_float_hours(int hours, int minutes, int seconds)
{
	assert((minutes >= 0) && (minutes < 60));
	assert((seconds >= 0) && (seconds < 60));
	return hours + (double(minutes) / 60) + (double(seconds) / 3600);
}


double to_24_hour_clock(double hours)
{
	assert(hours >= 0);
	return (int)hours % 24 + (hours - trunc(hours));
}

/*
    Implement three functions
        * get_hours
        * get_minutes
        * get_seconds
    They are used to determine the hours part, minutes part and seconds part 
    of a time in seconds. E.g.:

    >>> get_hours(3800)
    1

    >>> get_minutes(3800)
    3

    >>> get_seconds(3800)
    20

    In other words, if 3800 seconds have elapsed since midnight, 
    it is currently 01:03:20 (hh:mm:ss).
*/

double time_to_utc(int utc_offset, double time)
{
    /*
        Return time at UTC+0, where utc_offset is the number of hours away from
        UTC+0.
        You may be interested in:
        https://en.wikipedia.org/wiki/Coordinated_Universal_Time

        >>> time_to_utc(+0, 12.0)
        12.0
 
        >>> time_to_utc(+1, 12.0)
        11.0
 
        >>> time_to_utc(-1, 12.0)
        13.0
 
        >>> time_to_utc(-11, 18.0)
        5.0
 
        >>> time_to_utc(-1, 0.0)
        1.0
 
        >>> time_to_utc(-1, 23.0)
        0.0
    */
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
}

int main() {
	//seconds_difference tests
	assert(areEquals(seconds_difference(1800.0, 3600.0), 1800.0) && ("test #1.1"));
	assert(areEquals(seconds_difference(3600.0, 1800.0), -1800.0) && ("test #1.2"));
	assert(areEquals(seconds_difference(1800.0, 2160.0), 360.0) && ("test #1.3"));
	assert(areEquals(seconds_difference(1800.0, 1800.0), 0.0) && ("test #1.4"));

	//hours_difference tests
	assert(areEquals(hours_difference(1800.0, 3600.0), 0.5) && ("test #2.1"));
	assert(areEquals(hours_difference(3600.0, 1800.0), -0.5) && ("test #2.2"));
	assert(areEquals(hours_difference(1800.0, 2160.0), 0.1) && ("test #2.3"));
	assert(areEquals(hours_difference(1800.0, 1800.0), 0.0) && ("test #2.4"));

	//to_float_hours tests
	assert(areEquals(to_float_hours(0, 15, 0), 0.25) && ("test #3.1"));
	assert(areEquals(to_float_hours(2, 45, 9), 2.7525) && ("test #3.2"));
	assert(areEquals(to_float_hours(1, 0, 36), 1.01) && ("test #3.3"));

	//to_24_hour_clock tests
	assert(areEquals(to_24_hour_clock(24), 0) && ("test #4.1"));
	assert(areEquals(to_24_hour_clock(48), 0) && ("test #4.2"));
	assert(areEquals(to_24_hour_clock(25), 1) && ("test #4.3"));
	assert(areEquals(to_24_hour_clock(4), 4) && ("test #4.4"));
	assert(areEquals(to_24_hour_clock(28.5), 4.5) && ("test #4.5"));
}