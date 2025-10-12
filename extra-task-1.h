#pragma once

#include <cmath>
#include <iostream>
#include <cassert>

using namespace std;

// Returns the number of seconds later that time_2 is than time_1
double seconds_difference(double time_1, double time_2);

// Returns the number of hours later that time_2 is than time_1
double hours_difference(double time_1, double time_2);

// Returns the total number of hours in the specified hours, minutes, and seconds
// Precondition: 0 <= minutes < 60 and 0 <= seconds < 60
double to_float_hours(int hours, int minutes, int seconds);

// Returns the hour as seen on a 24-hour clock
// Precondition: hours >= 0
double to_24_hour_clock(double hours);

// Returns the hours part of a time in seconds
int get_hours(int seconds);

// Returns the minutes part of a time in seconds
int get_minutes(int seconds);

// Returns the seconds part of a time in seconds
int get_seconds(int seconds);

// Returns time at UTC+0, given a local time and UTC offset
double time_to_utc(int utc_offset, double time);

// Returns local time in time zone utc_offset, given a UTC time
double time_from_utc(int utc_offset, double time);