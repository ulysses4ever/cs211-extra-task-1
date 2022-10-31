#include <assert.h>
#include "Header.h"

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
    assert(0 <= minutes);
    assert(60 > minutes);
    assert(0 <= seconds);
    assert(60 > seconds);

    return hours + (minutes / 60.0) + (seconds / 3600.0);
}

double to_24_hour_clock(double hours)
{
    return (int)hours % 24 + hours - (int)hours;
}

double get_hours(double time) {
    return (int)(time / 3600);
}

double get_minutes(double time) {
    return (int)time % 3600 / 60;
}

double get_seconds(double time) {
    return (int)time % 3600 % 60;
}

double time_to_utc(int utc_offset, double time)
{
    double res = time - utc_offset;
    if (res > 0) 
        return (int)res % 24 + res - (int)res;
    return  24 - ((int)(-res) % 24) + res - (int)res;
}

double time_from_utc(int utc_offset, double time)
{

    double res = time + utc_offset;
    if (res > 0) return (int)res % 24 + res - (int)res;
    return  24 - ((int)(-res) % 24) + res - (int)res;
}