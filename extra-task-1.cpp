#include <assert.h>
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
    assert(minutes >= 0 && minutes < 60);
    assert(seconds >= 0 && seconds < 60);
    return (hours + minutes * 1.0 / 60 + seconds * 1.0 / 3600);
}

double to_24_hour_clock(double hours)
{
    assert(hours > 0);
    return int(floor(hours)) % 24 + hours - floor(hours);
}

int get_hours(int sec)
{
    return sec / 3600;
}

int get_minutes(int sec)
{
    return (sec - 3600*get_hours(sec))/60;
}

int get_seconds(int sec)
{
    return (sec - 3600 * get_hours(sec) - 60 * get_minutes(sec)) / 60;
}

double time_to_utc(int utc_offset, double time)
{
    return to_24_hour_clock(time - utc_offset * 1.0);
}

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
