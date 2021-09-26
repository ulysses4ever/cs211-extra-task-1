#include "extra-task-1.h"
#include <assert.h>
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

    assert(minutes >= 0);
    assert(minutes < 60);
    assert(seconds >= 0);
    assert(seconds < 60);
    return hours + minutes / static_cast<double>(60) + seconds / static_cast<double>(3600);
}

double to_24_hour_clock(double hours)
{

    assert(hours >= 0);
    double doublePart;
    int intPart;
    doublePart =hours-floor(hours);
    intPart = floor(hours);
    return intPart%24+doublePart;
}

int get_hours(int seconds) {
    assert(seconds >= 0);
    return seconds / 3600;
}

int get_minutes(int seconds) {
    assert(seconds >= 0);
    return (seconds % 3600) / 60;

}

int get_seconds(int seconds) {
    assert(seconds >= 0);
    return  seconds % 3600 % 60 % 60;
}
double time_to_utc(int utc_offset, double time)
{
    assert(abs(utc_offset) <= 12);
    return to_24_hour_clock((time - utc_offset) > 0 ? (time - utc_offset) : 24 - (time - utc_offset));
}

double time_from_utc(int utc_offset, double time)
{

    assert(abs(utc_offset) <= 12);
    return to_24_hour_clock((time + utc_offset) > 0 ? (time + utc_offset) : 24 + (time + utc_offset));
}
