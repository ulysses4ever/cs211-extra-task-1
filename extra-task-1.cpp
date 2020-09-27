#include "extra-task-1.h"
#include <cmath>

//Return the number of seconds later that a time in seconds time_2 is than a time in seconds time_1.
double seconds_difference(double time_1, double time_2)
{
    return time_2 - time_1;
}

//Return the number of hours later that a time in seconds time_2 is than a time in seconds time_1.
double hours_difference(double time_1, double time_2)
{
    return (time_2 - time_1)/3600.0;
}

//Return the total number of hours in the specified number of hours, minutes, and seconds.
double to_float_hours(int hours, int minutes, int seconds)
{
    assert(0<=minutes);
    assert(minutes<60);
    assert(0 <= seconds);
    assert(seconds <60);
    return hours + minutes / 60.0 + seconds / 3600.0;
}

//hours is a number of hours since midnight.Return the hour as seen on a 24 - hour clock.
double to_24_hour_clock(double hours)
{
    assert(hours >= 0);
    int int_part = floor(hours);
    return int_part % 24 + (hours - int_part);
}


//takes seconds elapsed since midnight and returns the hours as seen on a 24 - hour clock.
int get_hours(int seconds)
{
    assert(seconds >= 0);
    return to_24_hour_clock(seconds / 3600);
}

//takes seconds elapsed since midnight and returns the minutes as seen on a 24 - hour clock.
int get_minutes(int seconds)
{
    assert(seconds >= 0);
    return (seconds % 3600) / 60;
}

//takes seconds elapsed since midnight and returns the seconds as seen on a 24 - hour clock.
int get_seconds(int seconds)
{
    assert(seconds >= 0);
    return (seconds % 3600) % 60;
}

//Return time at UTC+0, where utc_offset is the number of hours away from UTC + 0.
//double time_to_utc(int utc_offset, double time)
//{
//    /*
//        Return time at UTC+0, where utc_offset is the number of hours away from
//        UTC+0.
//        You may be interested in:
//        https://en.wikipedia.org/wiki/Coordinated_Universal_Time
//
//        >>> time_to_utc(+0, 12.0)
//        12.0
// 
//        >>> time_to_utc(+1, 12.0)
//        11.0
// 
//        >>> time_to_utc(-1, 12.0)
//        13.0
// 
//        >>> time_to_utc(-11, 18.0)
//        5.0
// 
//        >>> time_to_utc(-1, 0.0)
//        1.0
// 
//        >>> time_to_utc(-1, 23.0)
//        0.0
//    */
//}
//
////Return UTC time in time zone utc_offset.
//double time_from_utc(int utc_offset, double time)
//{
//    /*
//        Return UTC time in time zone utc_offset.
//
//        >>> time_from_utc(+0, 12.0)
//        12.0
// 
//        >>> time_from_utc(+1, 12.0)
//        13.0
// 
//        >>> time_from_utc(-1, 12.0)
//        11.0
// 
//        >>> time_from_utc(+6, 6.0)
//        12.0
// 
//        >>> time_from_utc(-7, 6.0)
//        23.0
// 
//        >>> time_from_utc(-1, 0.0)
//        23.0
// 
//        >>> time_from_utc(-1, 23.0)
//        22.0
// 
//        >>> time_from_utc(+1, 23.0)
//        0.0
//    */
//}
