#ifndef EXTRA_TASK_1_H
#define EXTRA_TASK_1_H
#include <iostream>
#include <assert.h>
#include <float.h>
#include <cmath>

/// Returns are double numbers equal or not
bool CompareDoubles2 (double A, double B);

///Return the number of seconds later that a time in seconds time_2 is than a time in seconds time_1.
double seconds_difference(double time_1, double time_2);

///Return the number of hours later that a time in seconds time_2 is than a time in seconds time_1.
double hours_difference(double time_1, double time_2);

///Return the total number of hours in the specified number of hours, minutes, and seconds.
double to_float_hours(int hours, int minutes, int seconds);

///Return the hour as seen on a 24-hour clock.
double to_24_hour_clock(double hours);

///Return the hours part from time in seconds
int get_hours(int time);

///Return the minutes part from time in seconds
int get_minutes(int time);

///Return the seconds part from time in seconds
int get_seconds(int time);

///Return time at UTC+0, where utc_offset is the number of hours away from UTC+0.
double time_to_utc(int utc_offset, double time);

#endif //EXTRA_TASK_1_H
