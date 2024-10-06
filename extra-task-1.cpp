#include <iostream>
#include <assert.h>


double seconds_difference(double time_1, double time_2)
{
    return time_2 - time_1;
}

double hours_difference(double time_1, double time_2)
{
    return (time_2 - time_1) / 3600.0;
}

double to_float_hours(int hours, int minutes, int seconds)
{
    return hours + (minutes / 60.0) + (seconds / 3600.0);
}

double to_24_hour_clock(double hours)
{
    while (hours >= 24)
    {
        hours -= 24;
    }
    return hours;
}
int get_seconds(int seconds)
{
    return seconds % 60;
}
int get_hours(int seconds)
{
    return seconds / 3600;
}
int get_minutes(int seconds)
{
    return (seconds % 3600) / 60;
}


double time_to_utc(int utc_offset, double time)
{
    return to_24_hour_clock(time - utc_offset);
}

double time_from_utc(int utc_offset, double time)
{
    return to_24_hour_clock(time + utc_offset);
}

