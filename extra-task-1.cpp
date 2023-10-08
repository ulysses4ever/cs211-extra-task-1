#include <cassert>
#include <cmath>

double seconds_difference(double time_1, double time_2)
{
    return time_2 - time_1;
}

double hours_difference(double time_1, double time_2)
{
    return (time_2 - time_1) / 3600;
}

double to_float_hours(int hours, int minutes, int seconds)
{
    assert(minutes < 60 && minutes >= 0);
    assert(minutes < 60 && seconds >= 0);
    return hours + (minutes / 60.0) + (seconds / 3600.0);
}

double to_24_hour_clock(double hours)
{
    assert(hours >= 0);
    return fmod(hours, 24);
}

int get_hours(double time)
{
    return (time / 3600);
}

int get_minutes(double time)
{
    return ((int)time % 3600) / 60;
}

double get_seconds(double time)
{
    return fmod(time, 60);
}

double time_to_utc(int utc_offset, double time)
{
    return fmod((24 + time - utc_offset), 24);
}

double time_from_utc(int utc_offset, double time)
{
    return fmod((24 + time + utc_offset), 24);
}
