#include "extra-task-1.h"

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
    assert(minutes >= 0 && minutes < 60 && seconds >= 0 && seconds < 60);
    return hours + minutes / 60.0 + seconds / 3600.0;
}

double to_24_hour_clock(double hours)
{
    assert(hours >= 0);
    double int_part, fractional_part;
    fractional_part = modf(hours, &int_part);
    return (int)int_part % 24 + fractional_part;
}

int get_hours(int seconds) {
    assert(seconds >= 0);
    return seconds / 3600 % 24;
}

int get_minutes(int seconds) {
    assert(seconds >= 0);
    return seconds / 60 % 60;
}

int get_seconds(int seconds) {
    assert(seconds >= 0);
    return seconds % 60;
}

double time_to_utc(int utc_offset, double time)
{
    assert((time >= 0) && (time <= 24) && (utc_offset >= -24) && (utc_offset <= 24));
    return (int)(time - utc_offset + 24) % 24;
}

double time_from_utc(int utc_offset, double time)
{
    assert((time >= 0) && (time <= 24) && (utc_offset >= -24) && (utc_offset <= 24));
    return (int)(time + utc_offset + 24) % 24;
}
