#ifndef EXTRA_TASK
#define EXTRA_TASK
//task1
//Return the number of seconds later that a time in seconds time_2 is than a time in seconds time_1.
double seconds_difference(double time_1, double time_2);
//task2
//Return the number of hours later that a time in seconds time_2 is than a time in seconds time_1.
double hours_difference(double time_1, double time_2);
//task3
//hours is a number of hours since midnight. Return the hour as seen on a 24 - hour clock.
double to_24_hour_clock(double hours);
//task4
//Determine hours part
int get_hours(int seconds);
//determine minutes part
int get_minutes(int seconds);
//determine seconds part
int get_seconds(int seconds);
//task5
//Return time at UTC+0, where utc_offset is the number of hours away from UTC + 0.
double time_to_utc(int utc_offset, double time);
#endif