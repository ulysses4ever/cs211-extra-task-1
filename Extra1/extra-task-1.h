#pragma once
#include <cassert>

// Return the number of seconds that a time in seconds time_2 is later than a time in seconds time_1.
double seconds_difference(double, double);

// Return the number of hours that a time in seconds time_2 is later than a time in seconds time_1.
double hours_difference(double, double);

// Return the total number of hours in the specified number of hours, minutes, and seconds.
double to_float_hours(int, int, int);