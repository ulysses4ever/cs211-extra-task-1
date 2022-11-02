#include<assert.h>
#include<cmath>

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
    assert(0 <= minutes && minutes < 60);
    assert(0 <= seconds && seconds < 60);
    return hours + minutes / 60.0 + seconds / 3600.0;
}

double to_24_hour_clock(double hours)
{
    assert(hours >= 0);
    return fmod(hours, 24);
}

int get_hours(int seconds) {
    return fmod(seconds / 3600, 24);
}

int get_minutes(int seconds) {
    return (seconds / 60) % 60;
}

int get_seconds(int seconds) {
    return seconds % 60;
}

double time_to_utc(int utc_offset, double time)
{
    return fmod(time - utc_offset, 24);
}

double time_from_utc(int utc_offset, double time)
{
    double _0time = fmod(time + utc_offset, 24);
    return _0time < 0 ? 24 + _0time : _0time;
}
