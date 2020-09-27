﻿
#include <iostream>

#include "extra-task-1.h"

int main()
{
    setlocale(LC_ALL, "RUSSIAN");

    double eps = 0.0001;

    assert(fabs(seconds_difference(1800, 3600) - 1800) < eps);
    assert(fabs(seconds_difference(3600, 1800) + 1800) < eps);
    assert(fabs(seconds_difference(1800, 2160) - 360) < eps);
    assert(seconds_difference(1800, 1800) < eps);
    std::cout << "Тесты seconds_difference успешно пройдены!\n";
    /*
        >>> seconds_difference(1800.0, 3600.0)
        1800.0

        >>> seconds_difference(3600.0, 1800.0)
        -1800.0

        >>> seconds_difference(1800.0, 2160.0)
        360.0

        >>> seconds_difference(1800.0, 1800.0)
        0.0
    */

    assert(fabs(hours_difference(1800, 3600) - 0.5) < eps);
    assert(fabs(hours_difference(3600, 1800) + 0.5) < eps);
    assert(fabs(hours_difference(1800, 2160) - 0.1) < eps);
    assert(hours_difference(1800, 1800) < eps);
    std::cout << "Тесты hours_difference успешно пройдены!\n";
    /*
        >>> hours_difference(1800.0, 3600.0)
        0.5

        >>> hours_difference(3600.0, 1800.0)
        -0.5

        >>> hours_difference(1800.0, 2160.0)
        0.1

        >>> hours_difference(1800.0, 1800.0)
        0.0
    */


    assert(fabs(to_float_hours(0, 15, 0) - 0.25) < eps);
    assert(fabs(to_float_hours(2, 45, 9) - 2.7525) < eps);
    assert(fabs(to_float_hours(1, 0, 36) - 1.01) < eps);
    std::cout << "Тесты to_float_hours успешно пройдены!\n";
    /*
        Precondition: 0 <= minutes < 60  and  0 <= seconds < 60

        >>> to_float_hours(0, 15, 0)
        0.25

        >>> to_float_hours(2, 45, 9)
        2.7525

        >>> to_float_hours(1, 0, 36)
        1.01
    */

    assert(to_24_hour_clock(24) < eps);
    assert(to_24_hour_clock(48) < eps);
    assert(fabs(to_24_hour_clock(25) - 1) < eps);
    assert(fabs(to_24_hour_clock(4) - 4) < eps);
    assert(fabs(to_24_hour_clock(28.5) - 4.5) < eps);
    std::cout << "Тесты to_24_hour_clock успешно пройдены!\n";
    /*
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


    assert(fabs(get_hours(3800) - 1) < eps);
    assert(fabs(get_minutes(3800) - 3) < eps);
    assert(fabs(get_seconds(3800) - 20) < eps);
    std::cout << "Тесты three functions _get успешно пройдены!\n";
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

    assert(fabs(time_to_utc(+0, 12.0) - 12) < eps);
    assert(fabs(time_to_utc(+1, 12.0) - 11) < eps);
    assert(fabs(time_to_utc(-1, 12.0) - 13) < eps);
    assert(fabs(time_to_utc(-11, 18.0) - 5) < eps);
    assert(fabs(time_to_utc(-1, 0.0) - 1) < eps);
    assert(time_to_utc(-1, 23.0) < eps);
    std::cout << "Тесты time_to_utc успешно пройдены!\n";



/*

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
    assert(fabs(time_from_utc(+0, 12.0) - 12) < eps);
    assert(fabs(time_from_utc(+1, 12.0) - 13) < eps);
    assert(fabs(time_from_utc(-1, 12.0) - 11) < eps);
    assert(fabs(time_from_utc(+6, 6.0) - 12) < eps);
    assert(fabs(time_from_utc(-7, 6.0) - 23) < eps);
    assert(fabs(time_from_utc(-1, 0.0) - 23) < eps);
    assert(time_from_utc(+1, 23.0) < eps);
    std::cout << "Тесты time_from_utc успешно пройдены!\n";

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
