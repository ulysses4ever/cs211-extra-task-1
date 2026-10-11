#ifndef EXTRA_TASK_1
#define EXTRA_TASK_1

#include <iostream>

// Additional function for safe double comparison
bool is_close(double a, double b);

// Return the number of seconds later that a time in seconds time_2 is than a time in seconds time_1
double seconds_difference(double time_1, double time_2);

// Return the number of hours later that a time in seconds time_2 is than a time in seconds time_1
double hours_difference(double time_1, double time_2);

// Return the total number of hours in the specified number of hours, minutes, and seconds
double to_float_hours(int hours, int minutes, int seconds);

// Return the hour as seen on a 24 - hour clock
double to_24_hour_clock(double hours);

// Returns the number of whole hours in seconds.
int get_hours(int seconds);

// Returns the number of whole minutes in seconds.
int get_minutes(int seconds);

// Returns the number of remaining seconds.
int get_seconds(int seconds);

// Return time at UTC+0, where utc_offset is the number of hours away from UTC + 0.
double time_to_utc(int utc_offset, double time);

// Return UTC time in time zone utc_offset.
double time_from_utc(int utc_offset, double time);

/* EXTRA_TASK_1 */
#endif