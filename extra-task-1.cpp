#include <iostream>
#include <cmath>
#include <cassert>
/*Return the number of seconds later that a time in seconds
time_2 is than a time in seconds time_1.*/
double seconds_difference(double time_1, double time_2)
{
    return time_2 - time_1;
}

/*Return the number of hours later that a time in seconds
time_2 is than a time in seconds time_1.*/
double hours_difference(double time_1, double time_2)
{
    return seconds_difference(time_1, time_2) / 3600;
}

/*Return the total number of hours in the specified number
of hours, minutes, and seconds.
Precondition: 0 <= minutes < 60  and  0 <= seconds < 60
*/
double to_float_hours(int hours, int minutes, int seconds)
{
    assert(minutes >= 0 && minutes < 60);
    assert(seconds >= 0 && seconds < 60);
    return hours + minutes/60.0 + seconds/3600.0;
}

/*hours is a number of hours since midnight. Return the
hour as seen on a 24-hour clock.
Precondition: hours >= 0
*/
double to_24_hour_clock(double hours)
{
    assert(hours >= 0);
    while (hours >= 24)
        hours -= 24;
    return hours;
}

int get_hours(int seconds)
{
    int hours = 0;
    while (seconds >= 3600)
    {
        seconds -= 3600;
        hours++;
        if (hours == 24)
            hours = 0;
    }
    return hours;
}

int get_minutes(int seconds)
{
    int minutes = 0;
    while (seconds >= 60)
    {
        seconds -= 60;
        minutes++;
        if (minutes == 60)
            minutes = 0;
    }
    return minutes;
}

int get_seconds(int seconds)
{
    int secs = 0;
    while (seconds > 0)
    {
        seconds--;
        secs++;
        if (secs == 60)
            secs = 0;
    }
    return secs;
}

double time_to_utc(int utc_offset, double time)
{
    int int_hour = (int)time;//целая часть
    double rem = time - int_hour;//остаток
    int seconds = int_hour * 3600 - utc_offset * 3600;
    if (seconds < 0)
        seconds = 24 * 3600 + seconds;
    return get_hours(seconds) + rem;
}

double time_from_utc(int utc_offset, double time)
{
    int int_hour = (int)time;//целая часть
    double rem = time - int_hour;//остаток
    int seconds = int_hour * 3600 + utc_offset * 3600;
    if (seconds < 0)
        seconds = 24 * 3600 + seconds;
    return get_hours(seconds) + rem;
}

int main()
{
    //task 1
    assert(fabs(seconds_difference(1800.0, 3600.0) - 1800.0) < DBL_EPSILON);
    assert(fabs(seconds_difference(3600.0, 1800.0) - (-1800.0)) < DBL_EPSILON);
    assert(fabs(seconds_difference(1800.0, 2160.0) - (360.0)) < DBL_EPSILON);
    assert(fabs(seconds_difference(1800.0, 1800.0)) < DBL_EPSILON);
    std::cout << "Tests #1 passed." << std::endl;
    //task 2
    assert(fabs(hours_difference(1800.0, 3600.0) - 0.5) < DBL_EPSILON);
    assert(fabs(hours_difference(3600.0, 1800.0) - (-0.5)) < DBL_EPSILON);
    assert(fabs(hours_difference(1800.0, 2160.0) - 0.1) < DBL_EPSILON);
    assert(fabs(hours_difference(1800.0, 1800.0)) < DBL_EPSILON);
    std::cout << "Tests #2 passed." << std::endl;
    //task 3
    assert(fabs(to_float_hours(0, 15, 0) - 0.25) < DBL_EPSILON);
    assert(fabs(to_float_hours(2, 45, 9) - 2.7525) < DBL_EPSILON);
    assert(fabs(to_float_hours(1, 0, 36) - 1.01) < DBL_EPSILON);
    std::cout << "Tests #3 passed." << std::endl;
    //task 4
    assert(fabs(to_24_hour_clock(24)) < DBL_EPSILON);
    assert(fabs(to_24_hour_clock(48)) < DBL_EPSILON);
    assert(fabs(to_24_hour_clock(25) - 1) < DBL_EPSILON);
    assert(fabs(to_24_hour_clock(4) - 4) < DBL_EPSILON);
    assert(fabs(to_24_hour_clock(28.5) - 4.5) < DBL_EPSILON);
    std::cout << "Tests #4 passed." << std::endl;
    //task 5
    assert(get_hours(3800) == 1);
    assert(get_minutes(3800) == 3);
    assert(get_seconds(3800) == 20);

    assert(fabs(time_to_utc(+0, 12.0) - 12.0) < DBL_EPSILON);
    assert(fabs(time_to_utc(+1, 12.0) - 11.0) < DBL_EPSILON);
    assert(fabs(time_to_utc(-1, 12.0) - 13.0) < DBL_EPSILON);
    assert(fabs(time_to_utc(-11, 18.0) - 5.0) < DBL_EPSILON);
    assert(fabs(time_to_utc(-1, 0.0) - 1) < DBL_EPSILON);
    assert(fabs(time_to_utc(-1, 23.0)) < DBL_EPSILON);
    std::cout << "Tests #5 passed." << std::endl;
    //task 6
    assert(fabs(time_from_utc(+0, 12.0) - 12.0) < DBL_EPSILON);
    assert(fabs(time_from_utc(+1, 12.0) - 13.0) < DBL_EPSILON);
    assert(fabs(time_from_utc(-1, 12.0) - 11.0) < DBL_EPSILON);
    assert(fabs(time_from_utc(+6, 6.0) - 12.0) < DBL_EPSILON);
    assert(fabs(time_from_utc(-7, 6.0) - 23.0) < DBL_EPSILON);
    assert(fabs(time_from_utc(-1, 0.0) - 23.0) < DBL_EPSILON);
    assert(fabs(time_from_utc(-1, 23.0) - 22.0) < DBL_EPSILON);
    assert(fabs(time_from_utc(+1, 23.0)) < DBL_EPSILON);
    std::cout << "Tests #6 passed." << std::endl;
}