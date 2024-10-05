#pragma once
#ifndef EXTRA_TASK_1_H
#define EXTRA_TASK_1_H
#include <cassert>
#include <iostream>
#include <cmath>

//Returns the number of seconds later that a time in seconds time_2 is than a time in seconds time_1.
double seconds_difference(double, double);

//Returns the number of hours later that a time in seconds time_2 is than a time in seconds time_1.
double hours_difference(double, double);

//Returns the total number of hours in the specified number of hours, minutes, and seconds.
double to_float_hours(int, int, int);

//Returns the hour as seen on a 24 - hour clock.
double to_24_hour_clock(double);

//Determines the hours part.
int get_hours(int);

//Determines the minutes part.
int get_minutes(int);

//Determines the seconds part.
int get_seconds(int);

//Returns time at UTC+0, where utc_offset is the number of hours away from UTC + 0.
double time_to_utc(int, double);

//Returns UTC time in time zone utc_offset.
double time_from_utc(int, double);

#endif // !EXTRA_TASK_1_H
