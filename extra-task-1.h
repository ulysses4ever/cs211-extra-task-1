#pragma once
//Return the number of seconds later that a time in seconds
double seconds_difference(double, double);

//Return the number of hours later that a time in seconds
double hours_difference(double, double);

//Return the total number of hours in the specified number of hours, minutes, and seconds.
double to_float_hours(int hours, int minutes, int seconds);

//Return the hour as seen on a 24 - hour clock.
double to_24_hour_clock(double);

//determine the hours part
int get_hours(int);

//determine the minutes part
int get_minutes(int);

//determine the seconds part
int get_seconds(int);


double time_to_utc(int, double);