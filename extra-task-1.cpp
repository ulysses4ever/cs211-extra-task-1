#include "extra-task-1.h"

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

    return seconds_difference(time_1, time_2) / 3600.;
    /*
        Return the number of hours later that a time in seconds
        time_2 is than a time in seconds time_1.
    */
}

double to_float_hours(int hours, int minutes, int seconds)
{
    assert(0 <= minutes && minutes < 60 && 0 <= seconds && seconds < 60);
    return hours + minutes / 60. + seconds / 3600.;
    /*
        Return the total number of hours in the specified number
        of hours, minutes, and seconds.
    */
}

double to_24_hour_clock(double hours)
{
    return hours - ((int)hours / 24) * 24;
    /*
        hours is a number of hours since midnight. Return the
        hour as seen on a 24-hour clock.
    */
}

int get_hours(int seconds) 
{
    return seconds / 3600;
}

int get_minutes(int seconds)
{
    return (seconds - (get_hours(seconds) * 3600) - (seconds % 60)) / 60;
}

int get_seconds(int seconds)
{
    return seconds % 60;
}

/*
    Implement three functions
        * get_hours
        * get_minutes
        * get_seconds
    They are used to determine the hours part, minutes part and seconds part 
    of a time in seconds.
*/

double time_to_utc(int utc_offset, double time)
{
    assert(time >=0. && time <24.);
    return (time - utc_offset + 24.) - ((int)(time - utc_offset + 24.) / 24) * 24;

    /*
        Return time at UTC+0, where utc_offset is the number of hours away from
        UTC+0.
    */
}

double time_from_utc(int utc_offset, double time)
{
    assert(time >= 0. && time < 24.);
    return (time + utc_offset + 24.) - ((int)(time + utc_offset + 24.) / 24) * 24;
    /*
        Return UTC time in time zone utc_offset.
    */
}
