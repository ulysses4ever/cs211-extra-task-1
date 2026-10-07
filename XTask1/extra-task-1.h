#pragma once
#include <cassert>
#include <cmath>
// Return the number of seconds later that a time in seconds
// time_2 is than a time in seconds time_1.
double seconds_difference(double, double );

// Return the number of hours later that a time in seconds
// time_2 is than a time in seconds time_1.1
double hours_difference(double, double);

// Return the total number of hours in the specified number
// of hours, minutes, and seconds.
double to_float_hours(int, int,int );

// Hours is a number of hours since midnight. Return the
// hour as seen on a 24 - hour clock.
double to_24_hour_clock(double);

// Return the hours that have elapsed since midnight;
double get_hours(int);

// Return the minutes that have elapsed since midnight;
double get_minutes(int);

// Return the seconds that have elapsed since midnight;
double get_seconds(int);

// Return time at UTC+0, where utc_offset is the number of hours away from
// UTC + 0.
double time_to_utc(int, double );

// Return UTC time in time zone utc_offset.
double time_from_utc(int utc_offset, double time);