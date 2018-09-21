#include <iostream>
#include "Header.h"
#include <assert.h>
#include <cmath>

double seconds_difference(double time_1, double time_2)
{
	return time_2 - time_1;

}

double hours_difference(double time_1, double time_2)
{

	return (time_2 - time_1) / 3600;
}

double to_float_hours(int hours, int minutes, int seconds)
{
	assert(0 <= minutes < 60 && 0 <= seconds < 60);

	return hours + minutes / 60 + seconds / 3600;

}
	double to_24_hour_clock(double hours)
	{
		assert(hours >= 0);
		int trH = trunc(hours);
		return hours < 24 ? hours : (int)(fabs(24 - trH)) % 24 + (hours - trH);
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


int get_hours(double time)
{
	return (int)(trunc(time / 3600));
}

int get_minutes(double time)
{
	return (int)(trunc((time - get_hours(time) * 3600) / 60));
}

int get_seconds(double time)
{
	return (int)(time - get_hours(time) * 3600 - get_minutes(time) * 60);
}


double time_to_utc(int utc_offset, double time)
{
	int trT = trunc(time);
	return (trT - utc_offset) % 24 + (time - (double)trT);
   
}

double time_from_utc(int utc_offset, double time)
{
	int tr = trunc(time);
	return (24 + utc_offset + tr) % 24 + (time - (double)tr);
    
}
