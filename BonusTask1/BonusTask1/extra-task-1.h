#pragma once

/*
* Returns the number of seconds later that a time in seconds time_2 is than a time in seconds time_1.
*/
double seconds_difference(double time_1, double time_2);


/*
* Returns the number of hours later that a time in seconds time_2 is than a time in seconds time_1.
*/
double hours_difference(double time_1, double time_2);


/*
* Returns the total number of hours in the specified number of hours, minutes, and seconds.
* Precondition: 0 <= minutes < 60  and  0 <= seconds < 60
*/
double to_float_hours(int hours, int minutes, int seconds);


/*
* Hours is a number of hours since midnight. 
* Returns the hour as seen on a 24-hour clock.
* Precondition: hours >= 0
*/
double to_24_hour_clock(double hours);


/*
* This function is used to determine the hours part of a time in seconds.
*/
int get_hours(int seconds);


/*
* This function is used to determine the minutes part of a time in seconds.
*/
int get_minutes(int seconds);

/*
* This function is used to determine the seconds part of a time in seconds.
*/
int get_seconds(int seconds);


/*
* Returns time at UTC + 0, where utc_offset is the number of hours away from UTC + 0.
*/
double time_to_utc(int utc_offset, double time);


/*
* Returns UTC time in time zone utc_offset.
*/
double time_from_utc(int utc_offset, double time);