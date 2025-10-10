#include <iostream>
#include <cassert>
#include <cmath>
#include "extra-task-1.h"

double seconds_difference(double time_1, double time_2)
{
    // your implementation goes here...

    assert(time_1 >= 0.0);
    assert(time_2 >= 0.0);
    return time_2 - time_1;
}

double hours_difference(double time_1, double time_2)
{
    assert(time_1 >= 0.0);
    assert(time_2 >= 0.0);

    return (time_2 - time_1) / 3600.0;
}


double to_float_hours(int hours, int minutes, int seconds)
{
    assert(minutes >= 0 && minutes < 60);
    assert(seconds >= 0 && seconds < 60);
    assert(hours >= 0);

    auto total_hours = hours + (minutes / 60.0) + (seconds / 3600.0);
    return total_hours;
}

double to_24_hour_clock(double hours)
{
    assert(hours >= 0);
    auto res = std::fmod(hours, 24);

    if (std::fabs(res - 24.0) < EPS)
        return 0.0;
    return res;
}

int get_hours(int seconds)
{
    assert(seconds >= 0);
    return (seconds / 3600) % 24;
}

int get_minutes(int seconds)
{
    assert(seconds >= 0);
    return (seconds % 3600) / 60;
}

int get_seconds(int seconds)
{
    assert(seconds >= 0);
    return seconds % 60;
}

double time_to_utc(int utc_offset, double time)
{
    assert(time >= 0.0 && time < 24.0);
    assert(utc_offset >= -12 && utc_offset <= 14);

    auto time2 = time - utc_offset;

    return time2 >= 24.0 ? time2 - 24.0 : time2 < 0.0 ? time2 + 24.0 : time2;
}

double time_from_utc(int utc_offset, double time)
{
    assert(time >= 0.0 && time < 24.0);
    assert(utc_offset >= -12 && utc_offset <= 14);

    double time2 = time + utc_offset;
    return time2 >= 24.0 ? time2 - 24.0 : time2 < 0.0 ? time2 + 24.0 : time2;
}
