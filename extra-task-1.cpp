#include "extra-task-1.h"


bool CompareDoubles2 (double A, double B)
{
    double diff = A - B;
    return (diff < DBL_EPSILON) && (-diff < DBL_EPSILON);
}

double seconds_difference(double time_1, double time_2)
{
    assert(time_1 >= 0. && time_2 >= 0.);
    return time_2 - time_1;
}

double hours_difference(double time_1, double time_2)
{
    return seconds_difference(time_1, time_2) / 3600.0;
}

double to_float_hours(int hours, int minutes, int seconds)
{
    assert(0 <= minutes < 60  &&  0 <= seconds < 60);

    const double comparing = 0.0;
    double time = hours*3600 + minutes*60 + seconds;

    return hours_difference(comparing,time);
}


double to_24_hour_clock(double hours)
{
    assert(hours >= 0);
    return std::fmod(hours,24.0);
}

int get_hours(int time) {
    assert(time >= 0);
    return time / 3600;
}

int get_minutes(int time) {
    assert(time >= 0);
    return (time - get_hours(time) * 3600) / 60;
}

int get_seconds(int time) {
    assert(time >= 0);
    return (time - get_hours(time) * 3600) % 60;
}

double time_to_utc(int utc_offset, double time)
{
    assert(time >= 0);
    return to_24_hour_clock(-1*utc_offset+time);
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
