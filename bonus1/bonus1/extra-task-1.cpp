#include "extra-task-1.h"
#include <cassert>
#include <cfloat>
#include <cmath>

// task 1 Функция, возвращающая количество секунд, на которые отстаёт time_1 от time_2
double seconds_difference(double time_1, double time_2)
{
    assert(time_1 >= 0);
    assert(time_2 >= 0);
    return time_2 - time_1;
}

// task 2 Функция, возвращающая разницу в часах между секундами time_1 и time_2
double hours_difference(double time_1, double time_2)
{
    assert(time_1 >= 0);
    assert(time_2 >= 0);
    return (time_2 - time_1) / 3600;
}

// task 3 Функция, возвращающая общее количество часов в заданном количестве часов, минут и секунд
double to_float_hours(int hours, int minutes, int seconds)
{
    assert(hours >= 0);
    assert(minutes >= 0);
    assert(minutes <= 60);
    assert(seconds >= 0);
    assert(seconds <= 60);
    return hours + minutes / 60.0 + seconds / 3600.0;
}

// task 4 Функция, возвращающая значение времени, показанное на 24 - часовых часах
double to_24_hour_clock(double hours)
{
    assert(hours >= 0);
    while (hours >= 24)
    {
        hours -= 24;
    }
    return hours;
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

// task 5.1 Часы на циферблате
int get_hours(int seconds)
{
    assert(seconds >= 0);
    while (seconds / 3600 > 23)
    {
        seconds -= 3600 * 24;
    }
    return seconds / 3600;
}

// task 5.2 Минуты на циферблате
int get_minutes(int seconds)
{
    assert(seconds >= 0);
    while ((seconds % 3600) / 60 > 59)
    {
        seconds -= 3600 * 60 * 59;
    }
    return (seconds % 3600) / 60;
}

// task 5.3 Секундны на циферблате
int get_seconds(int seconds)
{
    while (seconds % 3600 > 59)
    {
        seconds -= 60;
    }
    return seconds % 3600;
}

double time_to_utc(int utc_offset, double time)
{
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
    return 1;

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
    return 1;

}
