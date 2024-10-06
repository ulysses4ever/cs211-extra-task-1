#pragma once
//Returns the number of seconds later that a time in seconds time_2 is than a time in seconds time_1
double seconds_difference(double time_1, double time_2);
//Returns the number of hours later that a time in seconds time_2 is than a time in seconds time_1
double hours_difference(double time_1, double time_2);
//Returns the total number of hours in the specified number of hours, minutes, and seconds
double to_float_hours(int hours, int minutes, int seconds);
//Return the number of hours since midnight as seen on a 24 - hour clock
double to_24_hour_clock(double hours);
//Hours part of a time in seconds
int get_hours(int seconds);
//Minutes part of a time in seconds
int get_minutes(int seconds);
//Seconds part of a time in seconds
int get_seconds(int seconds);
//Returns time at UTC+0, where utc_offset is the number of hours away from UTC + 0
double time_to_utc(int utc_offset, double time);
//Returns UTC time in time zone utc_offset
double time_from_utc(int utc_offset, double time);