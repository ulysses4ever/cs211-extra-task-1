#include<iostream>
#include<cassert>
using namespace std;
const double DBL_EPSILN = 0.00001;

double seconds_difference(double time_1, double time_2)
{
	return time_2 - time_1;
    
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
	return seconds_difference(time_1, time_2) / 3600;
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
	assert((minutes >= 0) && (minutes < 60) && "Minutes are in wrong format!");
	assert((seconds >= 0) && (seconds < 60) && "Seconds are in wrong format!");
	return hours + (minutes / 60.0) + (seconds / 3600.0);
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
}

double to_24_hour_clock(double hours)
{
	assert(hours >= 0 && "Wrong format for hours in to_24_hour_clock() function");
	int int_hours = (int)hours;
	return (int_hours % 24) + (hours - int_hours);
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
}

int get_seconds(int seconds) {
	return seconds % 60;
	/*
	Return number of seconds, which have already been gone since midnight
	*/
}

int get_minutes(int seconds) {
	return ((seconds - get_seconds(seconds)) / 60) % 60;
	/*
	Return number of minutes, which have already been gone since midnight
	*/
}

int get_hours(int seconds) {
	return seconds / 3600;
	/*
	Return number of hours, which have already been gone since midnight
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
	int int_hours = (int)time;
	return ((int_hours - utc_offset) % 24) + (time - int_hours);
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
	int int_hours = (int)time;
	return ((int_hours + utc_offset + 24) % 24) + (time - int_hours);
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
	// asserts for seconds_difference()
	assert(abs(seconds_difference(1800.0, 1800.0) - 0.0) < DBL_EPSILN    && "seconds_difference, test 1");
	assert(abs(seconds_difference(1233.0, 1200.0) + 33.0) < DBL_EPSILN   && "seconds_difference, test 2");
	assert(abs(seconds_difference(1800.0, 2160.0) - 360.0) < DBL_EPSILN  && "seconds_difference, test 3");
	assert(abs(seconds_difference(1800.0, 3600.0) - 1800.0) < DBL_EPSILN && "seconds_difference, test 4");
	assert(abs(seconds_difference(3600.0, 1800.0) + 1800.0) < DBL_EPSILN && "seconds_difference, test 5");
	cout << "Tests for seconds_difference() function have been gone.\n";

	// asserts for hours_differrence()
	assert(abs(hours_difference(1800.0, 1800.0) - 0.0) < DBL_EPSILN && "hours_difference, test 1");
	assert(abs(hours_difference(1800.0, 3600.0) - 0.5) < DBL_EPSILN && "hours_difference, test 2");
	assert(abs(hours_difference(3600.0, 1800.0) + 0.5) < DBL_EPSILN && "hours_difference, test 3");
	assert(abs(hours_difference(3600.0, 0.0) + 1.0) < DBL_EPSILN    && "hours_difference, test 4");
	assert(abs(hours_difference(0.0, 3600.0) - 1.0) < DBL_EPSILN    && "hours_difference, test 5");
	cout << "Tests for hours_difference() function have been gone.\n";

	// asserts for to_float_hours()
	assert(abs(to_float_hours(0, 15, 0) - 0.25)   < DBL_EPSILN && "to_float_hours, test 1");
	assert(abs(to_float_hours(1, 0, 36) - 1.01)   < DBL_EPSILN && "to_float_hours, test 2");
	assert(abs(to_float_hours(1, 15, 0) - 1.25)   < DBL_EPSILN && "to_float_hours, test 3");
	assert(abs(to_float_hours(2, 15, 36) - 2.26)  < DBL_EPSILN && "to_float_hours, test 4");
	assert(abs(to_float_hours(2, 45, 9) - 2.7525) < DBL_EPSILN && "to_float_hours, test 5");
	cout << "Tests for hours_difference() function have been gone.\n";

	//asserts for to_24_hour_clock()
	assert(abs(to_24_hour_clock(4) - 4)      < DBL_EPSILN && "to_24_hours, test 1");
	assert(abs(to_24_hour_clock(24) - 0)     < DBL_EPSILN && "to_24_hours, test 2");
	assert(abs(to_24_hour_clock(25) - 1)     < DBL_EPSILN && "to_24_hours, test 3");
	assert(abs(to_24_hour_clock(48.3) - 0.3) < DBL_EPSILN && "to_24_hours, test 4");
	assert(abs(to_24_hour_clock(28.5) - 4.5) < DBL_EPSILN && "to_24_hours, test 5");
	cout << "Tests for to_24_hour_clock() function have been gone.\n";

	//asserts for get_seconds()
	assert(get_seconds(3600) == 0, "get_seconds, test 1");
	assert(get_seconds(3910) == 10, "get_seconds, test 2");
	assert(get_seconds(3800) == 20, "get_seconds, test 3");
	assert(get_seconds(4050) == 30, "get_seconds, test 4");
	assert(get_seconds(3700) == 40, "get_seconds, test 5");
	cout << "Tests for get_seconds() function have been gone.\n";

	//asserts for get_minutes()
	assert(get_minutes(3800) == 3,  "get_minutes, test 1");
	assert(get_minutes(3900) == 5,  "get_minutes, test 2");
	assert(get_minutes(4100) == 8,  "get_minutes, test 3");
	assert(get_minutes(4800) == 20, "get_minutes, test 4");
	assert(get_minutes(5300) == 28, "get_minutes, test 5");
	cout << "Tests for get_minutes() function have been gone.\n";

	//asserts for get_hours()
	assert(get_hours(3500)  == 0, "get_hours, test 1");
	assert(get_hours(3800)  == 1, "get_hours, test 2");
	assert(get_hours(4800)  == 1, "get_hours, test 3");
	assert(get_hours(7210)  == 2, "get_hours, test 4");
	assert(get_hours(15300) == 4, "get_hours, test 5");
	cout << "Tests for get_minutes() function have been gone.\n";

	//asserts for time_to_utc()
	assert(abs(time_to_utc(0, 12.0)   - 12.0) < DBL_EPSILN && "time_to_utc, test 1");
	assert(abs(time_to_utc(1, 12.0)   - 11.0) < DBL_EPSILN && "time_to_utc, test 2");
	assert(abs(time_to_utc(-1, 23.0)  - 0.0)  < DBL_EPSILN && "time_to_utc, test 3");
	assert(abs(time_to_utc(-11, 18.0) - 5.0)  < DBL_EPSILN && "time_to_utc, test 4");
	assert(abs(time_to_utc(-1, 12.0)  - 13.0) < DBL_EPSILN && "time_to_utc, test 5");
	cout << "Tests for time_to_utc() function have been gone.\n";
	
	//asserts for time_from_utc()
	assert(abs(time_from_utc(1, 23.0)  - 0.0)  < DBL_EPSILN && "time_from_utc, test 1");
	assert(abs(time_from_utc(6, 6.0)   - 12.0) < DBL_EPSILN && "time_from_utc, test 2");
	assert(abs(time_from_utc(0, 12.0)  - 12.0) < DBL_EPSILN && "time_from_utc, test 3");
	assert(abs(time_from_utc(1, 12.0)  - 13.0) < DBL_EPSILN && "time_from_utc, test 4");
	assert(abs(time_from_utc(-7, 6.0)  - 23.0) < DBL_EPSILN && "time_from_utc, test 5");
	assert(abs(time_from_utc(-1, 12.0) - 11.0) < DBL_EPSILN && "time_from_utc, test 6");
	cout << "Tests for time_from_utc() function have been gone.\n";

	cout << "All tests have past!!! Wonderful! :)";
}