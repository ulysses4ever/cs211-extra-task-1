<<<<<<< HEAD
double seconds_difference(double time_1, double time_2)
{
    // your implementation goes here...
=======
#include "extra-task-1.h"
#include <assert.h>
<<<<<<< HEAD
double seconds_difference(double time_1, double time_2)
{
>>>>>>> dd59f1f (Сделаны задания 1-2)
    
    /*    
        Return the number of seconds later that a time in seconds
        time_2 is than a time in seconds time_1.
            
        >>> seconds_difference(1800.0, 3600.0)
        1800.0
=======
#include <cmath>
>>>>>>> 5471b41 (Сделано задание 3 и удалены лишние комментарии)


double seconds_difference(double time_1, double time_2)
{

<<<<<<< HEAD
        >>> seconds_difference(1800.0, 1800.0)
        0.0
    */
<<<<<<< HEAD
=======
=======
>>>>>>> 5471b41 (Сделано задание 3 и удалены лишние комментарии)
    return time_2 - time_1;
>>>>>>> dd59f1f (Сделаны задания 1-2)
}

double hours_difference(double time_1, double time_2)
{

<<<<<<< HEAD
        >>> hours_difference(1800.0, 2160.0)
        0.1

        >>> hours_difference(1800.0, 1800.0)
        0.0
    */
<<<<<<< HEAD
=======
=======
>>>>>>> 5471b41 (Сделано задание 3 и удалены лишние комментарии)
    return (time_2 - time_1) / 3600;
>>>>>>> dd59f1f (Сделаны задания 1-2)
}

double to_float_hours(int hours, int minutes, int seconds)
{

<<<<<<< HEAD
        >>> to_float_hours(1, 0, 36)
        1.01
    */
<<<<<<< HEAD
=======
=======
>>>>>>> 5471b41 (Сделано задание 3 и удалены лишние комментарии)
    assert(minutes >= 0);
    assert(minutes < 60);
    assert(seconds >= 0);
    assert(seconds < 60);
    return hours + minutes / static_cast<double>(60) + seconds / static_cast<double>(3600);
>>>>>>> dd59f1f (Сделаны задания 1-2)
}

double to_24_hour_clock(double hours)
{
<<<<<<< HEAD
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
<<<<<<< HEAD
=======
    return 0;
>>>>>>> dd59f1f (Сделаны задания 1-2)
=======

    assert(hours >= 0);
    double doublePart;
    int intPart;
    doublePart =hours-floor(hours);
    intPart = floor(hours);
    return intPart%24+doublePart;
>>>>>>> 5471b41 (Сделано задание 3 и удалены лишние комментарии)
}

int get_hours(int seconds) {
    assert(seconds >= 0);
    return seconds / 3600;
}

int get_minutes(int seconds) {
    assert(seconds >= 0);
    return (seconds % 3600) / 60;

}

int get_seconds(int seconds) {
    assert(seconds >= 0);
    return  seconds % 3600 % 60 % 60;
}
double time_to_utc(int utc_offset, double time)
{
<<<<<<< HEAD
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
<<<<<<< HEAD
=======
    return 0;
>>>>>>> dd59f1f (Сделаны задания 1-2)
=======
    assert(abs(utc_offset) <= 12);
    return to_24_hour_clock(time-utc_offset);
>>>>>>> 075a144 (Сделано задание 5)
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
<<<<<<< HEAD
=======
    return 0;
>>>>>>> dd59f1f (Сделаны задания 1-2)
}
