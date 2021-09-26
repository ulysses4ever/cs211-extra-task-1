#include <cmath> 
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

    return seconds_difference(time_1, time_2) / 3600;
    /*
        Return the number of hours later that a time in seconds
        time_2 is than a time in seconds time_1.
    
    */
}

double to_float_hours(int hours, int minutes, int seconds)
{
    assert(0 <= minutes);
    assert(60 > minutes);
    assert(0 <= seconds);
    assert(60 > seconds);
    return (double)hours + ((double)minutes / 60) + ((double)seconds / 3600);

    /*
        Return the total number of hours in the specified number
        of hours, minutes, and seconds.

        Precondition: 0 <= minutes < 60  and  0 <= seconds < 60

    */
}

double to_24_hour_clock(double hours)
{
    assert(hours >= 0);
    return hours - floor(hours / 24) * 24;
    /*
        hours is a number of hours since midnight. Return the
        hour as seen on a 24-hour clock.

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

double get_hours(double time)
{
    return floor(time / 3600);
}
double get_minutes(double time)
{
    time -= get_hours(time)*3600;
    return floor(time / 60);
}
double get_seconds(double time)
{
    
    return time - get_hours(time) * 3600 - get_minutes(time) * 60;
}

double time_to_utc(int utc_offset, double time)
{
    double k = time - utc_offset;
    if (k<0) return 24 - to_24_hour_clock(-1*k);
    return to_24_hour_clock(k);
    /*
        Return time at UTC+0, where utc_offset is the number of hours away from
        UTC+0.
        You may be interested in:
        https://en.wikipedia.org/wiki/Coordinated_Universal_Time

    */
}

double time_from_utc(int utc_offset, double time)
{
    double k = time + utc_offset;
    if (k < 0) return 24 - to_24_hour_clock(-1 * k);
    return to_24_hour_clock(k);
    /*
        Return UTC time in time zone utc_offset.


    */
}
int main()
{
    #define DBL_EPSILON 2.2204460492503131e-16
    assert(fabs(seconds_difference(1800.0, 3600.0)-1800)<DBL_EPSILON);
    assert(fabs(seconds_difference(3600.0, 1800.0) - (-1800)) < DBL_EPSILON);
    assert(fabs(seconds_difference(1800.0, 2160.0) - 360) < DBL_EPSILON);
    assert(fabs(seconds_difference(1800.0, 1800.0) - 0) < DBL_EPSILON);


    assert(fabs(hours_difference(1800.0, 3600.0) - 0.5) < DBL_EPSILON);
    assert(fabs(hours_difference(3600.0, 1800.0) - (-0.5)) < DBL_EPSILON);
    assert(fabs(hours_difference(1800.0, 2160.0) - 0.1) < DBL_EPSILON);
    assert(fabs(hours_difference(1800.0, 1800.0) - 0) < DBL_EPSILON);


    assert(fabs(to_float_hours(0, 15, 0) - 0.25) < DBL_EPSILON);
    assert(fabs(to_float_hours(2, 45, 9) - 2.7525) < DBL_EPSILON);
    assert(fabs(to_float_hours(1, 0, 36) - 1.01) < DBL_EPSILON);


    assert(fabs(to_24_hour_clock(24) - 0) < DBL_EPSILON);
    assert(fabs(to_24_hour_clock(48) - 0) < DBL_EPSILON);
    assert(fabs(to_24_hour_clock(25) - 1) < DBL_EPSILON);
    assert(fabs(to_24_hour_clock(4) - 4) < DBL_EPSILON);
    assert(fabs(to_24_hour_clock(28.5) - 4.5) < DBL_EPSILON);


    assert(fabs(get_hours(3800) - 1) < DBL_EPSILON);
    assert(fabs(get_minutes(3800) - 3) < DBL_EPSILON);
    assert(fabs(get_seconds(3800) - 20) < DBL_EPSILON);


    assert(fabs(time_to_utc(+0, 12.0) - 12.0) < DBL_EPSILON);
    assert(fabs(time_to_utc(+1, 12.0) - 11) < DBL_EPSILON);
    assert(fabs(time_to_utc(-1, 12.0) - 13) < DBL_EPSILON);
    assert(fabs(time_to_utc(-11, 18.0) - 5) < DBL_EPSILON);
    assert(fabs(time_to_utc(-1, 0.0) - 1) < DBL_EPSILON);
    assert(fabs(time_to_utc(-1, 23.0) - 0) < DBL_EPSILON);

    assert(fabs(time_from_utc(+0, 12.0) - 12) < DBL_EPSILON);
    assert(fabs(time_from_utc(+1, 12.0) - 13) < DBL_EPSILON);
    assert(fabs(time_from_utc(-1, 12.0) - 11) < DBL_EPSILON);
    assert(fabs(time_from_utc(+6, 6.0) - 12) < DBL_EPSILON);
    assert(fabs(time_from_utc(-7, 6.0) - 23) < DBL_EPSILON);
    assert(fabs(time_from_utc(-1, 0.0) - 23) < DBL_EPSILON);
    assert(fabs(time_from_utc(-1, 23.0) - 22) < DBL_EPSILON);
    assert(fabs(time_from_utc(+1, 23.0) - 0) < DBL_EPSILON);
   
}