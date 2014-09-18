#include <cmath>
#include <cfloat>
#include <iostream>
#include <assert.h>

using namespace std;


double seconds_difference(double time_1, double time_2)
{
    assert(time_1 >= 0 && time_2 >= 0);
    
    return time_2 - time_1;
    
    /*    
        Return the number of seconds later that a time in seconds
        time_2 is than a time in seconds time_1.
    */
}

double hours_difference(double time_1, double time_2)
{
    return seconds_difference(time_1, time_2)/3600;
    
    /*
        Return the number of hours later that a time in seconds
        time_2 is than a time in seconds time_1.
    */
}

double to_float_hours(int hours, int minutes, int seconds)
{
    assert(hours >= 0);
    assert(0 <= minutes && minutes < 60);
    assert(0 <= seconds && seconds < 60);
    
    return hours + minutes/60.0 + seconds/3600.0;
    
    /*
        Return the total number of hours in the specified number
        of hours, minutes, and seconds.
    */
}

double to_24_hour_clock(double hours)
{
    assert(hours >= 0);
    
    return fmod(hours, 24);
    
    /*
        hours is a number of hours since midnight. Return the
        hour as seen on a 24-hour clock.
    */
}

int get_hours(int seconds)
{
    assert(seconds >= 0);
    
    return to_24_hour_clock(seconds / 3600);
    
    //return seconds / 3600;
}

int get_minutes(int seconds)
{
    assert(seconds >= 0);
    
    return seconds % 3600 / 60;
}

int get_seconds(int seconds)
{
    assert(seconds >= 0);
    
    return seconds % 3600 % 60;
}

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

double time_to_utc(int utc_offset, double time)
{
    assert(abs(utc_offset) <= 12);
    assert(0 <= time && time <= 24);
    
    return to_24_hour_clock( time - utc_offset + 24 );
    
    /*
        Return time at UTC+0, where utc_offset is the number of hours away from
        UTC+0.
    */
}

double time_from_utc(int utc_offset, double time)
{
    return time_to_utc(-utc_offset, time);
    
    /*
        Return UTC time in time zone utc_offset
    */
}

int main(int argc, const char * argv[]) {
    
    assert( fabs(seconds_difference(1800.0, 3600.0) - 1800.0) <= DBL_EPSILON );
    assert( fabs(seconds_difference(3600.0, 1800) + 1800)     <= DBL_EPSILON );
    assert( fabs(seconds_difference(1800.0, 1800) - 0)        <= DBL_EPSILON );
    assert( fabs(seconds_difference(1800.0, 2160.0) - 360)    <= DBL_EPSILON );

    assert( fabs(hours_difference(1800.0, 3600.0) - 0.5) <= DBL_EPSILON );
    assert( fabs(hours_difference(3600.0, 1800.0) + 0.5) <= DBL_EPSILON );
    assert( fabs(hours_difference(1800.0, 2160.0) - 0.1) <= DBL_EPSILON );
    assert( fabs(hours_difference(1800.0, 1800.0) - 0.0) <= DBL_EPSILON );

    assert( fabs(to_float_hours(0, 15, 0) - 0.25)   <= DBL_EPSILON );
    assert( fabs(to_float_hours(2, 45, 9) - 2.7525) <= DBL_EPSILON );
    assert( fabs(to_float_hours(1, 0, 36) - 1.01)   <= DBL_EPSILON );
    
    assert( fabs(to_24_hour_clock(24) - 0)     <= DBL_EPSILON );
    assert( fabs(to_24_hour_clock(48) - 0)     <= DBL_EPSILON );
    assert( fabs(to_24_hour_clock(25) - 1)     <= DBL_EPSILON );
    assert( fabs(to_24_hour_clock(4) - 4)      <= DBL_EPSILON );
    assert( fabs(to_24_hour_clock(28.5) - 4.5) <= DBL_EPSILON );
    
    assert( get_hours(3800)   == 1 );
    assert( get_minutes(3800) == 3 );
    assert( get_seconds(3800) == 20 );

    assert( fabs(time_to_utc(+0, 12.0) - 12.0) <= DBL_EPSILON );
    assert( fabs(time_to_utc(+1, 12.0) - 11.0) <= DBL_EPSILON );
    assert( fabs(time_to_utc(-1, 12.0) - 13.0) <= DBL_EPSILON );
    assert( fabs(time_to_utc(-11, 18.0) - 5.0) <= DBL_EPSILON );
    assert( fabs(time_to_utc(-1, 0.0) - 1.0)   <= DBL_EPSILON );
    assert( fabs(time_to_utc(-1, 23.0) - 0.0)  <= DBL_EPSILON );
    
    assert( fabs(time_from_utc(+0, 12.0) - 12.0) <= DBL_EPSILON );
    assert( fabs(time_from_utc(-1, 12.0) - 11.0) <= DBL_EPSILON );
    assert( fabs(time_from_utc(+1, 12.0) - 13.0) <= DBL_EPSILON );
    assert( fabs(time_from_utc(+6, 6.0) - 12.0)  <= DBL_EPSILON );
    assert( fabs(time_from_utc(-7, 6.0) - 23.0)  <= DBL_EPSILON );
    assert( fabs(time_from_utc(-1, 0.0) - 23.0)  <= DBL_EPSILON );
    assert( fabs(time_from_utc(-1, 23.0) - 22.0) <= DBL_EPSILON );
    assert( fabs(time_from_utc(+1, 23.0) - 0.0)  <= DBL_EPSILON );
    
    return 0;
}
