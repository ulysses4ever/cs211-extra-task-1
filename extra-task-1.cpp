#include <cmath>
#include <cassert>
#include <cfloat>

double seconds_difference(double time_1, double time_2)
{
    return time_2 - time_1;
}

double hours_difference(double time_1, double time_2)
{
    return (time_2 - time_1) / 3600.0;
}

double to_float_hours(int hours, int minutes, int seconds)
{
    return hours + minutes / 60.0 + seconds / 3600.0;
}

double to_24_hour_clock(double hours)
{
    while (hours >= 24.0)
    {
        hours = hours - 24.0;
    }

    return hours;
}

/*
    Implement three functions
        * get_hours
        * get_minutes
        * get_seconds
*/

int get_hours(int seconds)
{
    return seconds / 3600;
}

int get_minutes(int seconds)
{
    return (seconds / 60) % 60;
}

int get_seconds(int seconds)
{
    return seconds % 60;
}

double time_to_utc(int utc_offset, double time)
{
    time = time - utc_offset;

    while (time < 0)
        time += 24.0;

    while (time >= 24.0)
        time -= 24.0;

    return time;
}

double time_from_utc(int utc_offset, double time)
{
    time = time + utc_offset;

    while (time < 0)
        time += 24.0;

    while (time >= 24.0)
        time -= 24.0;

    return time;
}

int main()
{
    // Проверка 1 задания:

    assert(fabs(seconds_difference(1800.0, 3600.0) - 1800.0) < DBL_EPSILON);
    assert(fabs(seconds_difference(3600.0, 1800.0) - (-1800.0)) < DBL_EPSILON);
    assert(fabs(seconds_difference(1800.0, 2160.0) - 360.0) < DBL_EPSILON);
    assert(fabs(seconds_difference(1800.0, 1800.0) - 0.0) < DBL_EPSILON);

    return 0;
}
