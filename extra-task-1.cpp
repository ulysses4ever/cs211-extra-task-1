#include <iostream>
#include <cassert>
#include <cmath>

double seconds_difference(double time_1, double time_2)
{
    return (time_2 - time_1);

}

double hours_difference(double time_1, double time_2)
{
    return (time_2 / 3600.) - (time_1 / 3600.);

}

double to_float_hours(int hours, int minutes, int seconds)
{
    assert(minutes >= 0 && minutes < 60 && 0 <= seconds && seconds < 60);

    return hours + (minutes / 60.) + (seconds / 3600.);

}

double to_24_hour_clock(double hours)
{
    return fmod(hours, 24);

}
double get_hours(double time_in_seconds) {
    return floor(time_in_seconds / 3600);
}

double get_minutes(double time_in_seconds) {
    return floor(fmod(time_in_seconds, 3600) / 60);
}

double get_seconds(double time_in_seconds) {
    return fmod(time_in_seconds, 60);
}


double time_to_utc(int utc_offset, double time)
{
    return fmod(time - utc_offset, 24);

}

double time_from_utc(int utc_offset, double time)
{
    if (fmod(time + utc_offset, 24) < 0 && fmod(time + utc_offset, 24) <= 24) {
        return 24 + (time + utc_offset);
    }
    return fmod(time + utc_offset, 24);

}
