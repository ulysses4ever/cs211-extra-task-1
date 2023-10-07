#include <assert.h>
#include <cmath>

double seconds_difference(double time_1, double time_2) {
    return time_2 - time_1;
}

double hours_difference(double time_1, double time_2) {
    return seconds_difference(time_1, time_2) / 3600.0;
}

double to_float_hours(int hours, int minutes, int seconds) {
    assert(minutes >= 0 && minutes < 60);
    assert(seconds >= 0 && seconds < 60);
    return hours + minutes / 60.0 + seconds / 3600.0;
}

double to_24_hour_clock(double hours) {
    return hours - static_cast<int>(hours) + static_cast<int>(hours) % 24;
}


int get_hours(int sec) {
    return sec / 3600 % 24;
}

int get_minutes(int sec) {
    return (sec - get_hours(sec) * 3600) / 60 % 60;
}

int get_seconds(int sec) {
    return (sec - get_hours(sec) * 3600 - get_minutes(sec) * 60) % 60;
}

double time_to_utc(int utc_offset, double time)
{
    double res = time - utc_offset;
    return res < 0 ? 24 - res : res - static_cast<int>(res) + static_cast<int>(res) % 24;
}