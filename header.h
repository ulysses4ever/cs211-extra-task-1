#include<cassert>
#ifndef header_
#define header_

//Return the number of seconds later that a time in seconds time_2 is than a time in seconds time_1.
double seconds_difference(double , double );

// Return the number of hours later that a time in seconds time_2 is than a time in seconds time_1.
double hours_difference(double, double );

//Return the total number of hours in the specified number of hours, minutes, and seconds.
double to_float_hours(int, int, int);

//Return the hour as seen on a 24 - hour clock.
double to_24_hour_clock(double );

#endif  /* header_ */
