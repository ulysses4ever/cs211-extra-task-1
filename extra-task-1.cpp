#include <cmath>
#include <float.h>
#include <assert.h>

/*
Implement three functions
* get_hours
* get_minutes
* get_seconds
They are used to determine the hours part, minutes part and seconds part
of a time in seconds. E.g.:

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

double seconds_difference(double time_1, double time_2)
{
    // your implementation goes here...
    
    /*    
        Return the number of seconds later that a time in seconds
        time_2 is than a time in seconds time_1.
            
    */
	return time_2 - time_1;
}

double to_float_hours(int hours, int minutes, int seconds)
{ 
	/*
	Return the total number of hours in the specified number
	of hours, minutes, and seconds.

	Precondition: 0 <= minutes < 60  and  0 <= seconds < 60

	*/
	assert(minutes >= 0);
	assert(minutes < 60);
	assert(seconds >= 0);
	assert(seconds < 60);
	return (hours * 3600 + minutes * 60 + seconds) / 3600.0;
}

double hours_difference(double time_1, double time_2)
{
    /*
        Return the number of hours later that a time in seconds
        time_2 is than a time in seconds time_1.
            
    */
	int h1 = get_hours(time_1);
	int m1 = get_minutes(time_1);
	int s1 = get_seconds(time_1);

	int h2 = get_hours(time_2);
	int m2 = get_minutes(time_2);
	int s2 = get_seconds(time_2);

	return to_float_hours(h2, m2, s2) - to_float_hours(h1, m1, s1);
}


double to_24_hour_clock(double hours)
{
    /*
        hours is a number of hours since midnight. Return the
        hour as seen on a 24-hour clock.

        Precondition: hours >= 0

        You may wish to inspect various function in <cmath> to work
        with integer and fractional part of a hours separately.
        
    */
	assert(hours >= 0);
	double fractpart, intpart;
	fractpart = modf(hours, &intpart);
	return int(intpart) % 24 + fractpart;
}


double time_to_utc(int utc_offset, double time)
{
    /*
        Return time at UTC+0, where utc_offset is the number of hours away from
        UTC+0.
        You may be interested in:
        https://en.wikipedia.org/wiki/Coordinated_Universal_Time
    */
	auto t = abs(time - utc_offset);
	return to_24_hour_clock(t);
}

double time_from_utc(int utc_offset, double time)
{
    /*
        Return UTC time in time zone utc_offset.
    */
	auto t = abs(time + utc_offset);
	return to_24_hour_clock(t);
}
