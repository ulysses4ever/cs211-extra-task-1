#include <iostream> 
#include <time.h>
#include <assert.h>

double seconds_difference(double time_1, double time_2)
{
    return time_2-time_1;
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
	
}

double hours_difference(double time_1, double time_2)
{
	return (seconds_difference(time_1, time_2) / 3600);
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
	return (hours*3600+minutes*60+seconds)/3600.0;
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
	double t = hours;
	if (t >= 24)
		for (int i = 1; t >= 24; i++)
			t -= 24;
	return t;
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

int get_hours(int a){ //думаю, здесь должен использоваться int на выход и int на выход
	 assert(a > 0);
	 return a / 3600;
}

 int get_minutes(int a){
	 assert(a > 0);
	 return (a - get_hours(a)*3600) / 60;
 }

 int get_seconds(int a){
	 assert(a > 0);
	 return (a - get_hours(a) * 3600 - get_minutes(a) * 60);
 }

double time_to_utc(int utc_offset, double time)
{
	double t = time - utc_offset;
	if (t >= 24)
		for (int i = 1; t >= 24; i++)
			t -= 24;
	else
		if (t < 0)
			for (int i = 1; t < 0; i++)
				t += 24;
	return t ;
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
	return 0;
}

double time_from_utc(int utc_offset, double time)
{
	double t = time + utc_offset;
	if (t >= 24)
		for (int i = 1; t >= 24; i++)
			t -= 24;
	else
		if (t < 0)
			for (int i = 1; t < 0; i++)
				t += 24;
	return t;
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

bool areequal(double x, double y){
	return fabs(x - y) < DBL_EPSILON;
}

int main(){
	assert(areequal(seconds_difference(1800.0, 3600.0), 1800.0) && "test-1");

	assert(areequal(seconds_difference(3600.0, 1800.0), -1800.0) && "test-2");

	assert(areequal(seconds_difference(1800.0, 2160.0), 360.0) && "test-3");

	assert(areequal(seconds_difference(1800.0, 1800.0), 0.0) && "test-4");
	assert(areequal(hours_difference(1800.0, 3600.0), 0.5) && "test-5");

	assert(areequal(hours_difference(3600.0, 1800.0), -0.5) && "test-6");

	assert(areequal(hours_difference(1800.0, 2160.0), 0.1) && "test-7");

	assert(areequal(hours_difference(1800.0, 1800.0), 0.0) && "test-15");

	assert(areequal(to_float_hours(0, 15, 0), 0.25) && "test-8");

	assert(areequal(to_float_hours(2, 45, 9), 2.7525) && "test-9");

	assert(areequal(to_float_hours(1, 0, 36), 1.01) && "test-10");
	assert(areequal(to_24_hour_clock(24), 0) && "test-11");

	assert(areequal(to_24_hour_clock(48), 0) && "test-12");

	assert(areequal(to_24_hour_clock(25), 1) && "test-13");

	assert(areequal(to_24_hour_clock(4), 4) && "test-14");

	assert(areequal(to_24_hour_clock(28.5), 4.5) && "test-15");
	assert(areequal(time_to_utc(+0, 12.0), 12.0) && "test-16");
	assert(areequal(time_to_utc(+1, 12.0), 11.0) && "test-17");

	assert(areequal(time_to_utc(-1, 12.0), 13.0) && "test-18");

	assert(areequal(time_to_utc(-11, 18.0), 5.0) && "test-19");

	assert(areequal(time_to_utc(-1, 0.0), 1.0) && "test-20a");

	assert(areequal(time_to_utc(-1, 23.0), 0.0) && "test-20b");
	assert(areequal(time_from_utc(+0, 12.0), 12.0) && "test-21");

	assert(areequal(time_from_utc(+1, 12.0), 13.0) && "test-22");

	assert(areequal(time_from_utc(-1, 12.0), 11.0) && "test-23");

	assert(areequal(time_from_utc(+6, 6.0), 12.0) && "test-24");

	assert(areequal(time_from_utc(-7, 6.0), 23.0) && "test-25");

	assert(areequal(time_from_utc(-1, 0.0), 23.0) && "test-26");

	assert(areequal(time_from_utc(-1, 23.0), 22.0) && "test-27");

	assert(areequal(time_from_utc(+1, 23.0), 0.0) && "test-28");
	assert(areequal(get_hours(3700),1) && "test-29");
	assert(areequal(get_hours(7711), 2) && "test-30");
	assert(areequal(get_minutes(601),10) && "test-31");
	assert(areequal(get_seconds(691),31) && "test-32");
	std::cout << "All tests complete successfully" << std::endl;
}