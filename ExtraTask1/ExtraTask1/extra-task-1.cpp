#include "extra-task-1.h"
#include <cassert>
#include <cmath>
double seconds_difference(double time_1, double time_2)
{
    return time_2 - time_1;
}

double hours_difference(double time_1, double time_2)
{
    return seconds_difference(time_1, time_2) / 3600;
}

double to_float_hours(int hours, int minutes, int seconds)
{
    assert(0 <= minutes < 60 && 0 <= seconds < 60);
    return hours + minutes / 60.0 + seconds / 3600.0;
}

double to_24_hour_clock(double hours)
{
    assert(hours >= 0);
    int f = floor(hours);
    return f % 24 + hours - f;
}

int get_hours(int seconds)
{
    return seconds / 3600;
}

int get_minutes(int seconds)
{
    return (seconds - get_hours(seconds) * 3600) / 60;
}

int get_seconds(int seconds)
{
    return seconds - get_hours(seconds) * 3600 - get_minutes(seconds) * 60;
}

double time_to_utc(int utc_offset, double time)
{
    int h = time - utc_offset;
    return to_24_hour_clock(h >= 0? h : h + 24);
}

double time_from_utc(int utc_offset, double time)
{
    int h = time + utc_offset;
    return to_24_hour_clock(h >= 0 ? h : h + 24);
}

