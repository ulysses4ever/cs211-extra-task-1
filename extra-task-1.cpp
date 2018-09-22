#include<cmath>
#include<assert.h>
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
	assert(0 <= minutes && 60 > minutes && 0 <= seconds && 60 > seconds);
	return hours + minutes / 60.0 + seconds / 3600.0;
    /*
        Return the total number of hours in the specified number
        of hours, minutes, and seconds.

        Precondition: 0 <= minutes < 60  and  0 <= seconds < 60
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

double time_to_utc(int utc_offset, double time)
{

	time -= utc_offset - 24;
	while (time >= 24)
		time -= 24;
	return time;
	/*
		Return time at UTC+0, where utc_offset is the number of hours away from
		UTC+0.
		You may be interested in:
		https://en.wikipedia.org/wiki/Coordinated_Universal_Time
	*/
}

double time_from_utc(int utc_offset, double time)
{
		time += utc_offset + 24;
		while (time >= 24)
			time -= 24;
		return time;
		/*
			Return UTC time in time zone utc_offset.
		*/
}
   
}
#include <cfloat>
using namespace std;
int main()
{
	// seconds_difference
	assert(fabs(seconds_difference(1800, 3600) - 1800) < DBL_EPSILON);
	assert(fabs(seconds_difference(3600, 1800) - -1800) < DBL_EPSILON);
	assert(fabs(seconds_difference(1800, 2160) - 360) < DBL_EPSILON);
	assert(fabs(seconds_difference(1800, 1800)) < DBL_EPSILON);
	// hours_difference
	assert(fabs(hours_difference(1800, 3600) - 0.5) < DBL_EPSILON);
	assert(fabs(hours_difference(3600, 1800) - -0.5) < DBL_EPSILON);
	assert(fabs(hours_difference(1800, 2160) - 0.1) < DBL_EPSILON);
	assert(fabs(hours_difference(1800, 1800)) < DBL_EPSILON);
	// to_float_hours
	assert(fabs(to_float_hours(0, 15, 0) - 0.25) < DBL_EPSILON);
	assert(fabs(to_float_hours(2, 45, 9) - 2.7525) < DBL_EPSILON);
	assert(fabs(to_float_hours(1, 0, 36) - 1.01) < DBL_EPSILON);
	// to_24_hour_clock
	assert(fabs(to_24_hour_clock(24)) < DBL_EPSILON);
	assert(fabs(to_24_hour_clock(48)) < DBL_EPSILON);
	assert(fabs(to_24_hour_clock(25) - 1) < DBL_EPSILON);
	assert(fabs(to_24_hour_clock(4) - 4) < DBL_EPSILON);
	assert(fabs(to_24_hour_clock(28.5) - 4.5) < DBL_EPSILON);
	// get_hours
	assert(fabs(get_hours(3800)) == 1);
	// get_minutes
	assert(fabs(get_minutes(3800)) == 3);
	// get_seconds
	assert(fabs(get_seconds(3800)) == 20);
	// time_to_utc
	assert(fabs(time_to_utc(0, 12) - 12) < DBL_EPSILON);
	assert(fabs(time_to_utc(1, 12) - 11) < DBL_EPSILON);
	assert(fabs(time_to_utc(-1, 12) - 13) < DBL_EPSILON);
	assert(fabs(time_to_utc(-11, 18) - 5) < DBL_EPSILON);
	assert(fabs(time_to_utc(-1, 0) - 1) < DBL_EPSILON);
	assert(fabs(time_to_utc(-1, 23)) < DBL_EPSILON);
	// time_from_utc
	assert(fabs(time_from_utc(0, 12) - 12) < DBL_EPSILON);
	assert(fabs(time_from_utc(1, 12) - 13) < DBL_EPSILON);
	assert(fabs(time_from_utc(-1, 12) - 11) < DBL_EPSILON);
	assert(fabs(time_from_utc(6, 6) - 12) < DBL_EPSILON);
	assert(fabs(time_from_utc(-7, 6) - 23) < DBL_EPSILON);
	assert(fabs(time_from_utc(-1, 0) - 23) < DBL_EPSILON);
	assert(fabs(time_from_utc(-1, 23) - 22) < DBL_EPSILON);
	assert(fabs(time_from_utc(1, 23)) < DBL_EPSILON);
}
