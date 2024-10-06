#include "extra-task-1.h"
#include <cassert>
#include <cmath>

constexpr int num_sec_in_hour{3600};
constexpr int num_minutes_in_hour{60};
constexpr int num_sec_in_minute{60};
constexpr int num_hours_in_day{24};

// returns time in hours from time given in minutes
int get_hours(int time) { return time / num_sec_in_hour; }

// returns time in minutes from given time minus whole hours
int get_minutes(int time) { return time % num_sec_in_hour / num_sec_in_minute; }

// returns time in seconds from given time minus whole minutes
int get_seconds(int time) { return time % num_sec_in_minute; }

// Returns the number of seconds later that a time in seconds time2 than
// time1
double seconds_difference(double time_1, double time_2)
{
    return time_2 - time_1;
}

// Returns the number of hours later that a time in seconds
double hours_difference(double time_1, double time_2)
{
    return static_cast<double>(time_2 - time_1) / num_sec_in_hour;
}

// Return the total number of hours in the specified number of hours,
// minutes, and seconds.
double to_float_hours(int hours, int minutes, int seconds)
{
    assert(minutes >= 0 && minutes < num_minutes_in_hour);
    assert(seconds >= 0 && seconds < num_sec_in_minute);

    return static_cast<double>(hours * num_sec_in_hour +
                               minutes * num_sec_in_minute + seconds) /
           num_sec_in_hour;
}

// Returns the hour as seen on a 24-hour clock.
double to_24_hour_clock(double hours)
{
    assert(hours >= 0);

    return std::fmod(hours, num_hours_in_day);
}

// Returns time at UTC+0, where utc_offset is the number of hours away from UTC
// +0
double time_to_utc(int utc_offset, double time)
{
    return std::fmod((time - utc_offset), num_hours_in_day);
}

// Returns UTC time in time zone utc_offset.
double time_from_utc(int utc_offset, double time)
{
    return std::fmod((num_hours_in_day + utc_offset + time), num_hours_in_day);
}