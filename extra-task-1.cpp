#include "../cs211-extra-task-1/ExtraTask1/ExtraTask1/extra-task-1.h"
double seconds_difference(double time_1, double time_2)
{
    return time_2 - time_1;
}




double hours_difference(double time_1, double time_2)
{
    return (time_2 - time_1) / 60.0 / 60.0;
}

double to_float_hours(int hours, int minutes, int seconds)
{
    assert(0 <= minutes < 60 && 0 <= seconds < 60);
    return hours + (minutes / 60.0) + (seconds / 60.0 / 60.0);
}

double to_24_hour_clock(double hours)
{
    double res = fmod(hours, 24);
    if (res < 0)
    {
        res += 24;
    }
    return res;
}
int get_hours(double seconds)
{
    return seconds / 60 / 60;
}
int get_minutes(double seconds)
{
    return fmod(seconds, 60 * 60) / 60;
}
int get_seconds(double seconds)
{
    return fmod(fmod(seconds, 60 * 60), 60);
}
double time_to_utc(int utc_offset, double time)
{
    double res = time - utc_offset;
    if (res >= 24.0) {
        res -= 24.0;
    }
    if (res < 0.0) {
        res += 24.0;
    }
    return res;
}
#if 0
double time_from_utc(int utc_offset, double time)
{
    /*
        Return UTC time in time zone utc_offset.

        >>> time_from_utc(+0, 12.0)
        12.0
 
        >>> time_from_utc(+1, 12.0)
        13.0
 
        >>> time_from_utc(-1, 12.0)
        11.0
 
        >>> time_from_utc(+6, 6.0)
        12.0
 
        >>> time_from_utc(-7, 6.0)
        23.0
 
        >>> time_from_utc(-1, 0.0)
        23.0
 
        >>> time_from_utc(-1, 23.0)
        22.0
 
        >>> time_from_utc(+1, 23.0)
        0.0
    */
}
#endif // 0