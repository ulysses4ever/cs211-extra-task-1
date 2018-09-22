#include <assert.h>
#include <float.h>
#include <math.h>
#include <iostream>

using namespace std;

bool are_equals(double a, double b)
{
	return fabs(a-b)<=DBL_EPSILON;
}
///Return the number of seconds later that a time in seconds
///time_2 is than a time in seconds time_1.
double seconds_difference(double time_1, double time_2)
{
	return time_2-time_1;
}
///Return the number of hours later that a time in seconds
///time_2 is than a time in seconds time_1.
double hours_difference(double time_1, double time_2)
{
	return seconds_difference(time_1, time_2)/3600;
}

///Return the total number of hours in the specified number
///of hours, minutes, and seconds.

double to_float_hours(int hours, int minutes, int seconds)
{
	assert(0<=minutes && minutes<60);
	assert(0<=seconds && seconds<60);
        return hours+minutes/60.0+seconds/3600.0;
}

//hours is a number of hours since midnight. Return the
//hour as seen on a 24-hour clock.
double to_24_hour_clock(double hours)
{
	assert(hours>=0);
    	return fmod(hours, 24);
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
///Return the hours part of a time in seconds
int get_hours(int seconds)
{
	assert(seconds>=0);
	return seconds/3600%24;
}

///Return the minutes part of a time in seconds
int get_minutes(int seconds)
{
	assert(seconds>=0);
	return seconds/60%60;
}
///Return the seconds part of a time in seconds
int get_seconds(int seconds)
{
	assert(seconds>=0);
	return seconds%60;
}
///Return time at UTC+0, where utc_offset is the number of hours away from UTC+0.
double time_to_utc(int utc_offset, double time)
{
    	return fmod(time-utc_offset, 24);
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

        assert(are_equals(seconds_difference(1800.0, 3600.0),1800.0));
        assert(are_equals(seconds_difference(3600.0, 1800.0),-1800.0));
	assert(are_equals(seconds_difference(1800.0, 2160.0),360.0));
	assert(are_equals(seconds_difference(1800.0, 1800.0), 0.0));

	assert(are_equals(hours_difference(1800.0, 3600.0), 0.5));
	assert(are_equals(hours_difference(3600.0, 1800.0), -0.5));
	assert(are_equals(hours_difference(1800.0, 2160.0), 0.1));
	assert(are_equals(hours_difference(1800.0, 1800.0), 0.0));

	assert(are_equals(to_float_hours(0, 15, 0), 0.25));
	assert(are_equals(to_float_hours(2, 45, 9), 2.7525));
	assert(are_equals(to_float_hours(1, 0, 36), 1.01));

        assert(are_equals(to_24_hour_clock(24), 0));
        assert(are_equals(to_24_hour_clock(48), 0));
        assert(are_equals(to_24_hour_clock(25), 1));
        assert(are_equals(to_24_hour_clock(4),  4));
        assert(are_equals(to_24_hour_clock(28.5), 4.5));

	assert(get_hours(3800)==1);
	assert(get_hours(3600*(5+24*2))==5);
	assert(get_hours(3500)==0);

	assert(get_minutes(3800)==3);
	assert(get_minutes(3870)==4);
	assert(get_minutes(3600)==0);

	assert(get_seconds(3800)==20);
	assert(get_seconds(3870)==30);
	assert(get_seconds(3600)==0);

	assert(are_equals(time_to_utc(+0, 12.0), 12.0));
 	assert(are_equals(time_to_utc(+1, 12.0), 11.0));
 	assert(are_equals(time_to_utc(-1, 12.0), 13.0)); 
      	assert(are_equals(time_to_utc(-11, 18.0), 5.0));
	assert(are_equals(time_to_utc(-1, 0.0), 1.0));
	assert(are_equals(time_to_utc(-1, 23.0), 0.0));

	cout<<"Tests comleted"<<endl;	
}
