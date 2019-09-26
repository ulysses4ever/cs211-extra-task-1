#ifndef MAIN_H
#define MAIN_H

//Return the number of seconds later that a time in seconds
double seconds_difference(double time_1, double time_2);

//Return the number of hours later that a time in seconds
double hours_difference(double time_1, double time_2);


//Return the total number of hours in the specified number of hours, minutes, and seconds.
double to_float_hours(int hours, int minutes, int seconds);

//Return the hour as seen on a 24 - hour clock.
double to_24_hour_clock(double hours);

int get_hours(double);

int get_minutes(double);

int get_seconds(double);

//Return time at UTC+0, where utc_offset is the number of hours away from UTC + 0.
double time_to_utc(int utc_offset, double time);

//Return UTC time in time zone utc_offset.
double time_from_utc(int utc_offset, double time);

//Return UTC time in time zone utc_offset.
double time_from_utc(int utc_offset, double time);

#endif MAIN_H