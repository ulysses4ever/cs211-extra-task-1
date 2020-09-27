#include <iostream>
#include <cassert>

double seconds_difference(double time_1, double time_2)
{
    return double((time_2 - time_1));

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
    return double((time_2 - time_1) / 3600);
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
    assert(hours >= 0 && minutes >= 0 && minutes <= 60 && seconds >= 0 && seconds <= 60);
    return double(hours + minutes / 60.0 + seconds / 3600.0);
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

    assert(hours >= 0);
    return double(hours - ((int)hours / 24) * 24);
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

double get_hours(double sec)
{
    assert(sec >= 0);
    return (int)sec / 3600;
}
double get_minutes(double sec)
{
    assert(sec >= 0);
    return (int(sec) / 60) % 60;

}
double get_seconds(double sec)
{
    assert(sec >= 0);
    return (int)sec % 60;
}

double time_to_utc(int utc_offset, double time)
{
    assert(time >= 0 && time <= 24);
    assert(utc_offset >= -12 && utc_offset <= 12);
    return ((int)time - utc_offset) % 24;

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
    assert(time >= 0 && time <= 24);
    assert(utc_offset >= -12 && utc_offset <= 12);
    if (fabs(utc_offset) > fabs(time))
    {
        return 24 - (fabs(utc_offset) - fabs(time));
    }
    else
    {
        return ((int)time + utc_offset) % 24;
    }
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


int main()
{
    const auto eps = DBL_EPSILON;
    

    std::cout << "seconds_difference:" << std::endl;
    assert(fabs(seconds_difference(1800.0, 3600.0) - 1800.0) < eps);
    assert(fabs(seconds_difference(3600.0, 1800.0) - -1800.0) < eps);
    assert(fabs(seconds_difference(1800.0, 2160.0) - 360.0) < eps);
    assert(fabs(seconds_difference(1800.0, 1800.0) - 0.00) < eps);
    std::cout << "All test have been passed!" << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "hours_difference:" << std::endl;
    assert(fabs(hours_difference(1800.0, 3600.0) - 0.5) < eps);
    assert(fabs(hours_difference(3600.0, 1800.0) - -0.5) < eps);
    assert(fabs(hours_difference(1800.0, 2160.0) - 0.1) < eps);
    assert(fabs(hours_difference(1800.0, 1800.0) - 0.0) < eps);
    std::cout << "All test have been passed!" << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "to_float_hours:" << std::endl;
    assert(fabs(to_float_hours(0, 15, 0) - 0.25) < eps);
    assert(fabs(to_float_hours(2, 45, 9) - 2.7525) < eps);
    assert(fabs(to_float_hours(1, 0, 36) - 1.01) < eps);
    std::cout << "All test have been passed!" << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "to_24_hour_clock:" << std::endl;
    assert(fabs(to_24_hour_clock(24) - 0) < eps);
    assert(fabs(to_24_hour_clock(48) - 0) < eps);
    assert(fabs(to_24_hour_clock(25) - 1) < eps);
    assert(fabs(to_24_hour_clock(4) - 4) < eps);
    assert(fabs(to_24_hour_clock(28.5) - 4.5) < eps);
    std::cout << "All test have been passed!" << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;


    std::cout << "get_hours:" << std::endl;
    assert(fabs(get_hours(3800) - 1) < eps);
    std::cout << "All test have been passed!" << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "get_minutes:" << std::endl;
    assert(fabs(get_minutes(3800) - 3) < eps);
    std::cout << "All test have been passed!" << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "get_seconds:" << std::endl;
    assert(fabs(get_seconds(3800) - 20) < eps);
    std::cout << "All test have been passed!" << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "time_to_utc:" << std::endl;
    assert(fabs(time_to_utc(+0, 12.0) - 12.0) < eps);
    assert(fabs(time_to_utc(+1, 12.0) - 11.0) < eps);
    assert(fabs(time_to_utc(-1, 12.0) - 13.0) < eps);
    assert(fabs(time_to_utc(-11, 18.0) - 5.0) < eps);
    assert(fabs(time_to_utc(-1, 0.0) - 1.0) < eps);
    assert(fabs(time_to_utc(-1, 23.0) - 0.0) < eps);
    std::cout << "All test have been passed!" << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "time_to_utc:" << std::endl;
    assert(fabs(time_from_utc(+0, 12.0) - 12.0) < eps);
    assert(fabs(time_from_utc(+1, 12.0) - 13.0) < eps);
    assert(fabs(time_from_utc(-1, 12.0) - 11.0) < eps);
    assert(fabs(time_from_utc(+6, 6.0) - 12.0) < eps);
    assert(fabs(time_from_utc(-7, 6.0) - 23.0) < eps);
    assert(fabs(time_from_utc(-1, 0.0) - 23.0) < eps);
    assert(fabs(time_from_utc(-1, 23.0) - 22.0) < eps);
    assert(fabs(time_from_utc(+1, 23.0) - 0.0) < eps);
    std::cout << "All test have been passed!" << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;

    system("pause");





}