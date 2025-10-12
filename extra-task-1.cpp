#include "extra-task-1.h"
#include <cassert>
#include <cmath>

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
    return (double)hours + (double)minutes / 60 + (double)seconds / 3600;
}

double to_24_hour_clock(double hours)
{
    assert(hours >= 0);

    return std::fmod(hours, 24);
}

/*
    Implement three functions
        * get_hours
        * get_minutes
        * get_seconds
    They are used to determine the hours part, minutes part and seconds part
    of a time in seconds. E.g.:

    >>> get_hours(3800)
    1

    >>> get_minutes(3800)
    3

    >>> get_seconds(3800)
    20

    In other words, if 3800 seconds have elapsed since midnight,
    it is currently 01:03:20 (hh:mm:ss).
*/
int get_hours(int seconds)
{
  return seconds / 3600;
}

int get_minutes(int seconds)
{
  return seconds / 60 % 60;
}

int get_seconds(int seconds)
{
  return seconds % 60;
}

double time_to_utc(int utc_offset, double time)
{
  assert(utc_offset >= -12 && utc_offset <= 14);
  double t = time - (double)utc_offset;
  while (t < 0) t += 24;
  while (t >= 24) t -= 24;
  return t;
}

double time_from_utc(int utc_offset, double time)
{
    assert(utc_offset >= -12 && utc_offset <= 14);
    double t = time + (double)utc_offset;
    while (t < 0) t += 24;
    while (t >= 24) t -= 24;
    return t;
}
