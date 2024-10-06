#include <assert.h>
#include <cmath>


/*
        Returns the number of seconds later that a time in seconds
        time_2 is than a time in seconds time_1.
*/
double seconds_difference(double time_1, double time_2)
{
    assert((time_1 > 0) && (time_2 > 0));
    return (time_2 - time_1);
    
}

/*
        Returns the number of hours later that a time in seconds
        time_2 is than a time in seconds time_1.
*/
double hours_difference(double time_1, double time_2)
{
    assert((time_1 > 0) && (time_2 > 0));
    return ((time_2 / 3600) - (time_1 / 3600));
   
}

/*
        Return the total number of hours in the specified number
        of hours, minutes, and seconds.
*/
double to_float_hours(int hours, int minutes, int seconds)
{
    assert((hours >= 0) && (hours < 24));
    assert((minutes >= 0) && (minutes < 60));
    assert((seconds >= 0) && (seconds < 60));
    return (hours + (minutes / 60.0) + (seconds / 3600.0));

}

/*
        hours is a number of hours since midnight. Return the
        hour as seen on a 24-hour clock.
*/
double to_24_hour_clock(double hours)
{

   return (fmod(hours, 24));
}

/*
    Implementation of  three functions
        * get_hours
        * get_minutes
        * get_seconds
*/
int get_hours(int seconds)
{
    return seconds / 3600;
}

int get_minutes(int seconds)
{
    return (seconds % 3600) / 60;
}

int get_seconds(int seconds)
{
    return (seconds % 3600) % 60;
}

/*
        Return time at UTC+0, where utc_offset is the number of hours away from
        UTC+0.
*/
double time_to_utc(int utc_offset, double time)
{

   if (time - utc_offset >= 24)
   {
    return time - utc_offset - 24;
   }
   if (time - utc_offset < 0)
   {
    return time - utc_offset + 24;
   }
   return time - utc_offset;
}

/*
        Return UTC time in time zone utc_offset.
*/
double time_from_utc(int utc_offset, double time)
{
   if (time + utc_offset >= 24)
   {
    return time + utc_offset - 24;
   }
   if (time + utc_offset < 0)
   {
    return time + utc_offset + 24;
   }
   return time + utc_offset;
}
