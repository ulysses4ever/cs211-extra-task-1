#pragma once

//calculates seconds difference
double seconds_difference(double time_1, double time_2);

//testing function for seconds_difference
void run_tests_seconds_difference();

//calulates hours difference ( time is given in seconds)
double hours_difference(double time_1, double time_2);

//testing function for hours_difference
void run_tests_hours_difference();

//Returns the total number of hours in the specified number of hours, minutes, and seconds
double to_float_hours(int hours, int minutes, int seconds);

//testing function for to_float_hours
void run_tests_to_float_hours();

//hours is a number of hours since midnight.Function returns the hour as seen on a 24 - hour clock.
double to_24_hour_clock(double hours);

//testing function for to_24_hour_clock
void run_tests_to_24_hour_clock();

//calculates hours elapsed since midnight ( time is given in seconds )
int get_hours(double time);

//testing function for get_hours
void run_tests_get_hours();

//calculates minutes elapsed since midnight ( time is given in seconds )
int get_minutes(double time);

//testing function for get_minutes
void run_tests_get_minutes();

//calculates seconds elapsed since midnight ( time is given in seconds )
int get_seconds(double time);

//testing function for get_seconds
void run_tests_get_seconds();

// time to utc
double time_to_utc(int utc_offset, double time);

//testing function for time_to_utc
void run_tests_time_to_utc();

//time from utc
double time_from_utc(int utc_offset, double time);

//testing function for time_from_utc
void run_tests_time_from_utc();