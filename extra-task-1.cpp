#include <assert.h>
#include <cmath>

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
    return (time_2 / 3600) - (time_1 / 3600);
    /*
        Return the number of hours later that a time in seconds
        time_2 is than a time in seconds time_1.
    */
}

double to_float_hours(int hours, int minutes, int seconds)
{
    assert(0 <= minutes < 60 && 0 <= seconds < 60);
    return hours + (minutes / 60.0) + (seconds / 3600.0);
    /*
        Return the total number of hours in the specified number
        of hours, minutes, and seconds.
    */
}

double to_24_hour_clock(double hours)
{
    assert(hours >= 0);
    double fract_part;
    double int_part;
    fract_part = modf(hours, &int_part);
    return ((int)int_part % 24) + fract_part;
    /*
        hours is a number of hours since midnight. Return the
        hour as seen on a 24-hour clock.
    */
}