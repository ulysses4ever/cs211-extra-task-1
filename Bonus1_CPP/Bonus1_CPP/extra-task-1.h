#ifndef EXTRA_TASK
#define EXTRA_TASK

//Return the number of seconds later that a time in seconds
//time_2 is than a time in seconds time_1.
double seconds_difference(double, double);

//return the number of hours later that a time in seconds
//time_2 is than a time in seconds time_1
double hours_difference(double, double);

//return the total number of hours in the specified number
//of hours, minutes, and seconds.
double to_float_hours(int, int, int);

//hours is a number of hours since midnight. return the
//hour as seen on a 24 - hour clock.
double to_24_hour_clock(double);

//    three functions
//    they are used to determine the hours part, minutes part and seconds part 
//    of a time in seconds. e.g.:
int get_hours(int);
int get_minutes(int);
int get_seconds(int);

//return time at utc+0, where utc_offset is the number of hours away from
//utc + 0.
double time_to_utc(int, double);

// return utc time in time zone utc_offset.
double time_from_utc(int, double);


#endif // !EXTRA_TASK
