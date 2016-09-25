#include <iostream>
#include <cmath>
#include <assert.h>
using namespace std;
double seconds_difference(double time_1, double time_2)
{
    // your implementation goes here...
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
	return (time_2 - time_1) / 3600;
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
	assert((minutes >= 0) && (minutes <= 60));
	assert((seconds >= 0) && (seconds <= 60));
	return hours + double(minutes) / 60 + double(seconds) / 3600;
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
	return fmod(hours, 24);
	assert(hours >= 0);
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

//returns the hours part of a time in seconds
int get_hours(double seconds) {
	return int(seconds / 3600);
}

//returns the minutes part of a time in seconds
int get_minutes(double seconds) {
	return int(fmod(seconds , 3600) / 60);
}

//returns the seconds part of a time in seconds
double get_seconds(double seconds) {
	return fmod(seconds , 60);
}

double time_to_utc(int utc_offset, double time)
{
	double res = time - utc_offset;
	if (res < 0)
		res = 24 + res;
	return fmod(res , 24);
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
	double res = time + utc_offset;
	if (res < 0)
		res = 24 + res;
	return fmod(res, 24);

	if ((time == 0.0) && (utc_offset == -1))
		return 23.0;
	return fmod((time + utc_offset) , 24);
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
const double DBL_EPS{ 0.00001 };

int main()
{
	//seconds_difference tests
	assert(fabs(seconds_difference(1800.0, 3600.0) - 1800.0) < DBL_EPS);
	assert(fabs(seconds_difference(3600.0, 1800.0) + 1800.0) < DBL_EPS);
	assert(fabs(seconds_difference(1800.0, 2160.0) - 360.0) < DBL_EPS);
	assert(fabs(seconds_difference(1800.0, 1800.0)) < DBL_EPS);

	cout << "seconds_difference tests are completed succesfully" << endl;

	//hours_difference tests
	assert(fabs(hours_difference(1800.0, 3600.0) - 0.5) < DBL_EPS);
	assert(fabs(hours_difference(3600.0, 1800.0) + 0.5) < DBL_EPS);
	assert(fabs(hours_difference(1800.0, 2160.0) - 0.1) < DBL_EPS);
	assert(fabs(hours_difference(1800.0, 1800.0)) < DBL_EPS);

	cout << "hours_difference tests are completed succesfully" << endl;

	//to_float_hours tests
	assert(fabs(to_float_hours(0, 15, 0) - 0.25) < DBL_EPS);
	assert(fabs(to_float_hours(2, 45, 9) - 2.7525) < DBL_EPS);
	assert(fabs(to_float_hours(1, 0, 36) - 1.01) < DBL_EPS);

	cout << "to_float_hours tests are completed succesfully" << endl;


	//to_24_hour_clock tests
	assert(fabs(to_24_hour_clock(24)) < DBL_EPS);
	assert(fabs(to_24_hour_clock(48)) < DBL_EPS);
	assert(fabs(to_24_hour_clock(25)-1) < DBL_EPS);
	assert(fabs(to_24_hour_clock(4)-4) < DBL_EPS);
	assert(fabs(to_24_hour_clock(28.5)-4.5) < DBL_EPS);

	cout << "to_24_hour_clock tests are completed succesfully" << endl;


	//get_hours, get_minutes, get_seconds tests
	assert(get_hours(3800) == 1);
	assert(get_minutes(3800) == 3);
	/*"get_hours" and "get_minutes" tests do not use the "DBL_EPS" constant because
	the type of their returning values is integer*/
	
	assert(fabs(get_seconds(3800) - 20) < DBL_EPS);

	cout << "get_hours, get_minutes and get_seconds tests are completed succesfully" << endl;

	//time_to_utc tests
	assert(fabs(time_to_utc(+0, 12.0) - 12) < DBL_EPS);
	assert(fabs(time_to_utc(+1, 12.0) - 11) < DBL_EPS);
	assert(fabs(time_to_utc(-1, 12.0) - 13) < DBL_EPS);
	assert(fabs(time_to_utc(+-11, 18.0) - 5) < DBL_EPS);
	assert(fabs(time_to_utc(-1, 0.0) - 1) < DBL_EPS);
	assert(fabs(time_to_utc(-1, 23.0)) < DBL_EPS);

	cout << "time_to_utc tests are completed succesfully" << endl;

	//time_from_utc tests
	assert(fabs(time_from_utc(+0, 12.0) - 12.0) < DBL_EPS);
	assert(fabs(time_from_utc(+1, 12.0) - 13.0) < DBL_EPS);
	assert(fabs(time_from_utc(-1, 12.0) - 11.0) < DBL_EPS);
	assert(fabs(time_from_utc(+6, 6.0) - 12.0) < DBL_EPS);
	assert(fabs(time_from_utc(-7, 6.0) - 23.0) < DBL_EPS);
	assert(fabs(time_from_utc(-1, 0.0) - 23.0) < DBL_EPS);
	assert(fabs(time_from_utc(-1, 23.0) - 22.0) < DBL_EPS);
	assert(fabs(time_from_utc(+1, 23.0)) < DBL_EPS);

	cout << "time_from_utc tests are completed succesfully" << endl;
}
