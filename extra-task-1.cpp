#include <cassert>
#include <cmath>

double seconds_difference(double time_1, double time_2)
{
    // your implementation goes here...
    
    /*    
        Return the number of seconds later that a time in seconds
        time_2 is than a time in seconds time_1.
            
        >>> seconds_difference(1800.0, 3600.0)
        1800.0

        >>> seconds_difference(3600.0, 1800.0)
        -1800.0

        >>> seconds_difference(1800.0, 2160.0)
        360.0

        >>> seconds_difference(1800.0, 1800.0)
        0.0
    */
	assert(time_1 >= 0);
	assert(time_2 >= 0);
	return time_2 - time_1;
}

double hours_difference(double time_1, double time_2)
{
    /*
        Return the number of hours later that a time in seconds
        time_2 is than a time in seconds time_1.
            
        >>> hours_difference(1800.0, 3600.0)
        0.5

        >>> hours_difference(3600.0, 1800.0)
        -0.5

        >>> hours_difference(1800.0, 2160.0)
        0.1

        >>> hours_difference(1800.0, 1800.0)
        0.0
    */
	assert(time_1 >= 0);
	assert(time_2 >= 0);
	return (time_2 - time_1) / 3600.0;
}

double to_float_hours(int hours, int minutes, int seconds)
{
    /*
        Return the total number of hours in the specified number
        of hours, minutes, and seconds.

        Precondition: 0 <= minutes < 60  and  0 <= seconds < 60

        >>> to_float_hours(0, 15, 0)
        0.25

        >>> to_float_hours(2, 45, 9)
        2.7525

        >>> to_float_hours(1, 0, 36)
        1.01
    */
	assert(hours >= 0);
	assert(minutes >= 0);
	assert(seconds >= 0);
	return hours + minutes / 60.0 + seconds / 3600.0;
}

double to_24_hour_clock(double hours)
{
    /*
        hours is a number of hours since midnight. Return the
        hour as seen on a 24-hour clock.

        Precondition: hours >= 0

        >>> to_24_hour_clock(24)
        0
        
        >>> to_24_hour_clock(48)
        0
        
        >>> to_24_hour_clock(25)
        1
        
        >>> to_24_hour_clock(4)
        4
        
        >>> to_24_hour_clock(28.5)
        4.5
        
        You may wish to inspect various function in <cmath> to work
        with integer and fractional part of a hours separately.
        
    */
	assert(hours >= 0);
	while (hours >= 24) hours -= 24;
	return hours;
	

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

double get_hours(double time)
{ 
	return floor(time / 3600.0);
}

double get_minutes(double time)
{ 
	while (time >= 3600) time - 3600;
	return floor(time / 60.0);
}

double get_seconds(double time)
{
	while (time >= 3600) time - 3600;
	while (time >= 60) time - 60;
	return time;
}




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
	double t = time - utc_offset;
	if (t >= 24) t -= 24.0;
	if (t < 0) t = abs(t);
	return t;
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
	double t = time + utc_offset;
	if (t >= 24) t -= 24.0;
	if (t < 0) t = abs(t);
	return t;
}

int main()
{
	assert(seconds_difference(1800.0, 3600.0) == 1800.0 && "test-1");
	assert(seconds_difference(3600.0, 1800.0) == -1800.0 && "test-2");
	assert(seconds_difference(1800.0, 2160.0) == 360.0 && "test-3");
	assert(seconds_difference(1800.0, 1800.0) == 0.0 && "test-4");

	assert(hours_difference(1800.0, 3600.0) == 0.5 && "test-5");
	assert(hours_difference(3600.0, 1800.0) == -0.5 && "test-6");
	assert(hours_difference(1800.0, 2160.0) == 0.1 && "test-7");
	assert(hours_difference(1800.0, 1800.0) == 0.0 && "test-8");

	assert(to_float_hours(0, 15, 0) == 0.25 && "test-9");
	assert(to_float_hours(2, 45, 9) == 2.7525 && "test-10");
	assert(to_float_hours(1, 0, 36) == 1.01 && "test-11");

	assert(to_24_hour_clock(24) == 0 && "test-12");
	assert(to_24_hour_clock(48) == 0 && "test-13");
	assert(to_24_hour_clock(25) == 1 && "test-14");
	assert(to_24_hour_clock(4) == 4 && "test-15");
	assert(to_24_hour_clock(28.5) == 4.5 && "test-16");

	assert(get_hours(3800.0) == 1.0 && "test-17" );
	assert(get_minutes(3800.0) == 3.0 && "test-18");
	assert(get_seconds(3800.0) == 20.0 && "test-19");

	assert(time_to_utc(+0, 12.0) == 12.0 && "test-20");
	assert(time_to_utc(+1, 12.0) == 11.0 && "test-21");
	assert(time_to_utc(-1, 12.0) == 13.0 && "test-22");
	assert(time_to_utc(-11, 18.0) == 5.0 && "test-23");
	assert(time_to_utc(-1, 0.0) == 1.0 && "test-24");
	assert(time_to_utc(-1, 23.0) == 0.0 && "test-25");

	assert(time_from_utc(+0, 12.0) == 12.0 && "test-26");
	assert(time_from_utc(+1, 12.0) == 13.0 && "test-27");
	assert(time_from_utc(-1, 12.0) == 11.0 && "test-28");
	assert(time_from_utc(+6, 6.0) == 12.0 && "test-29");
	assert(time_from_utc(-7, 6.0) == 23.0 && "test-30");
	assert(time_from_utc(-1, 0.0) == 23.0 && "test-31");
	assert(time_from_utc(-1, 23.0) == 22.0 && "test-32");
	assert(time_from_utc(+1, 23.0) == 0.0 && "test-33");

}