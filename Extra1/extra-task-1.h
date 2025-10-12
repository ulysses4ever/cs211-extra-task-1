#pragma once
#include <cassert>
#include <cmath>

// Return the number of seconds that a time in seconds time_2 is later than a time in seconds time_1.
double seconds_difference(double, double);

// Return the number of hours that a time in seconds time_2 is later than a time in seconds time_1.
double hours_difference(double, double);

// Return the total number of hours in the specified number of hours, minutes, and seconds.
double to_float_hours(int, int, int);

// Convert a number of hours since midnight to a 24-hour clock format.
double to_24_hour_clock(double);

// Return the hours part of a time in seconds.
double get_hours(int);

// Return the minutes part of a time in seconds.
double get_minutes(int);

// Return the seconds part of a time in seconds.
double get_seconds(int);