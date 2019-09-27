#include <iostream>
#include <assert.h>

double seconds_difference(double time_1, double time_2)
{
	return time_2 - time_1;

    /*    
        Return the number of seconds later that a time in seconds
        time_2 is than a time in seconds time_1.

    */
}

double hours_difference(double time_1, double time_2)
{
	return (time_2 - time_1) / 3600;
    /*
        Return the number of hours later that a time in seconds
        time_2 is than a time in seconds time_1. 
	*/
} 

double to_float_hours(int hours, int minutes, int seconds)
{
	assert(0 <= minutes && minutes < 60);
	assert(0 <= seconds && seconds < 60);
	return hours + (double)minutes / 60 + (double)seconds / 3600;
    /*
        Return the total number of hours in the specified number
        of hours, minutes, and seconds.
	*/
} 
	
double to_24_hour_clock(double hours)
{
	assert(hours >= 0);
	while (hours >= 24)
		hours -= 24;
	return hours;
	/*
        hours is a number of hours since midnight. Return the
        hour as seen on a 24-hour clock.

        Precondition: hours >= 0
	*/  
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
	*/
	double t = time - utc_offset;
	if (t < 0)
		t += 24;
	return to_24_hour_clock(t);
 
}

	
double time_from_utc(int utc_offset, double time)
{
	double t = time + utc_offset;
	if (t < 0)
		t += 24;
	return to_24_hour_clock(t);
    /*
        Return UTC time in time zone utc_offset.
	*/
} 


int main()
{
	setlocale(LC_ALL, "RUSSIAN");

	// #1
	assert(seconds_difference(1800,3600) == 1800);
	assert(seconds_difference(3600.0, 1800.0) == -1800);
	assert(seconds_difference(1800.0, 2160.0) == 360);
	assert(seconds_difference(1800.0, 1800.0) == 0);

	// #2
	assert(hours_difference(1800.0, 3600.0) == 0.5);
	assert(hours_difference(3600.0, 1800.0) == -0.5);
	assert(hours_difference(1800.0, 2160.0) == 0.1);
	assert(hours_difference(1800.0, 1800.0) == 0.0);

	// #3

	assert(to_float_hours(0, 15, 0) == 0.25);
	assert(to_float_hours(2, 45, 9) == 2.7525);
	assert(to_float_hours(1, 0, 36) == 1.01);

	// #4
	assert(to_24_hour_clock(24) == 0);
	assert(to_24_hour_clock(48) == 0);
	assert(to_24_hour_clock(25) == 1);
	assert(to_24_hour_clock(4) == 4);
	assert(to_24_hour_clock(28.5) == 4.5);

	// #5
	assert(time_to_utc(+0, 12.0) == 12.0);
	assert(time_to_utc(+1, 12.0) == 11.0);
	assert(time_to_utc(-1, 12.0) == 13.0);
	assert(time_to_utc(-11, 18.0) == 5.0);
	assert(time_to_utc(-1, 0.0) == 1.0);
	assert(time_to_utc(-1, 23.0) == 0.0);

	// #6 
	assert(time_from_utc(+0, 12.0) == 12.0);
	assert(time_from_utc(+1, 12.0) == 13.0);
	assert(time_from_utc(-1, 12.0) == 11.0);
	assert(time_from_utc(+6, 6.0) == 12.0);
	assert(time_from_utc(-7, 6.0) == 23.0);
	assert(time_from_utc(-1, 0.0) == 23.0);
	assert(time_from_utc(-1, 23.0) == 22.0);
	assert(time_from_utc(+1, 23.0) == 0.0);

	system("pause");
}