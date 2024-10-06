#include <assert.h>
#include <cmath>
#include <iostream>

// Return the number of seconds later that a time in seconds
double seconds_difference(double time_1, double time_2)
{
    assert(time_2 > time_1);
    return time_2 - time_1;
}

// Return the number of hours later that a time in seconds
double hours_difference(double time_1, double time_2)
{
    assert(time_2 > time_1);
    return (time_2 - time_1) / 3600.0;
}

// Return the total number of hours in the specified number of hours, minutes, and seconds.
double to_float_hours(int hours, int minutes, int seconds)
{
    assert(0 <= minutes && minutes < 60);
    assert(0 <= seconds && seconds < 60);
    return hours + minutes / 60.0 + seconds / 3600.0;
}

// Return the hour as seen on a 24 - hour clock.
double to_24_hour_clock(double hours)
{
    assert(hours >= 0);
    return fmod(hours, 24.0);
}

// It is used to determine the hours part
int get_hours(int seconds)
{
    return seconds / 3600;
}

// It is used to determine the minutes part
int get_minutes(int seconds)
{
    return (seconds % 3600) / 60;
}

// It is used to determine the seconds part
int get_seconds(int seconds)
{
    return seconds % 60;
}

// Return time at UTC+0, where utc_offset is the number of hours away from UTC + 0.
double time_to_utc(int utc_offset, double time)
{
    return fmod(time - utc_offset, 24.0);
}

// Return UTC time in time zone utc_offset.
double time_from_utc(int utc_offset, double time)
{
    return fmod(time + utc_offset + 24.0, 24.0);
}

int main()
{
    // Проверка функции seconds_difference
    assert(fabs(seconds_difference(1800.0, 3600.0) - 1800.0) < DBL_EPSILON);
    assert(fabs(seconds_difference(3600.0, 1800.0) + 1800.0) < DBL_EPSILON);
    assert(fabs(seconds_difference(1800.0, 2160.0) - 360.0) < DBL_EPSILON);
    assert(fabs(seconds_difference(1800.0, 1800.0)) < DBL_EPSILON);

    // Проверка функции hours_difference
    assert(fabs(hours_difference(1800.0, 3600.0) - 0.5) < DBL_EPSILON);
    assert(fabs(hours_difference(3600.0, 1800.0) + 0.5) < DBL_EPSILON);
    assert(fabs(hours_difference(1800.0, 2160.0) - 0.1) < DBL_EPSILON);
    assert(fabs(hours_difference(1800.0, 1800.0)) < DBL_EPSILON);

    // Проверка функции to_float_hours
    assert(fabs(to_float_hours(0, 15, 0) - 0.25) < DBL_EPSILON);
    assert(fabs(to_float_hours(2, 45, 9) - 2.7525) < DBL_EPSILON);
    assert(fabs(to_float_hours(1, 0, 36) - 1.01) < DBL_EPSILON);

    // Проверка функции to_24_hour_clock
    assert(fabs(to_24_hour_clock(24) - 0) < DBL_EPSILON);
    assert(fabs(to_24_hour_clock(48) - 0) < DBL_EPSILON);
    assert(fabs(to_24_hour_clock(25) - 1) < DBL_EPSILON);
    assert(fabs(to_24_hour_clock(4) - 4) < DBL_EPSILON);
    assert(fabs(to_24_hour_clock(28.5) - 4.5) < DBL_EPSILON);

    // Проверка функций get_hours, get_minutes, get_seconds
    assert(get_hours(3800) == 1);
    assert(get_minutes(3800) == 3);
    assert(get_seconds(3800) == 20);

    // Проверка функции time_to_utc
    assert(fabs(time_to_utc(0, 12.0) - 12.0) < DBL_EPSILON);
    assert(fabs(time_to_utc(1, 12.0) - 11.0) < DBL_EPSILON);
    assert(fabs(time_to_utc(-1, 12.0) - 13.0) < DBL_EPSILON);
    assert(fabs(time_to_utc(-11, 18.0) - 5.0) < DBL_EPSILON);
    assert(fabs(time_to_utc(-1, 0.0) - 1.0) < DBL_EPSILON);
    assert(fabs(time_to_utc(-1, 23.0) - 0.0) < DBL_EPSILON);

    // Проверка функции time_from_utc
    assert(fabs(time_from_utc(0, 12.0) - 12.0) < DBL_EPSILON);
    assert(fabs(time_from_utc(1, 12.0) - 13.0) < DBL_EPSILON);
    assert(fabs(time_from_utc(-1, 12.0) - 11.0) < DBL_EPSILON);
    assert(fabs(time_from_utc(6, 6.0) - 12.0) < DBL_EPSILON);
    assert(fabs(time_from_utc(-7, 6.0) - 23.0) < DBL_EPSILON);
    assert(fabs(time_from_utc(-1, 0.0) - 23.0) < DBL_EPSILON);
    assert(fabs(time_from_utc(-1, 23.0) - 22.0) < DBL_EPSILON);
    assert(fabs(time_from_utc(1, 23.0) - 0.0) < DBL_EPSILON);

    std::cout << "Тесты прошли" << std::endl;

    return 0;
}