#pragma once

// checks if two double values are equal with accuracy of 10^-7
bool equal(double, double);

// returns the difference in seconds between two times given in seconds
double seconds_difference(double time_1, double time_2);

// returns the difference in hours between two times given in seconds
double hours_difference(double time_1, double time_2);

// returns the number of hours in given hrs, min, sec in total
double to_float_hours(int hours, int minutes, int seconds);

// retuens the hour as on the clock by given number of hours since midnight
double to_24_hour_clock(double hours);

// returns the number of hours in given time in seconds
int get_hours(int time);

// returns the number of minutes in given time in seconds
int get_minutes(int time);

// returns the number of seconds in given time in seconds
int get_seconds(int time);
