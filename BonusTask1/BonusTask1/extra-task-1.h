#ifndef EXTRA_TASK_1
#define EXTRA_TASK_1

#include <iostream>

// Additional function for safe double comparison
bool is_close(double a, double b);

// Return the number of seconds later that a time in seconds time_2 is than a time in seconds time_1
double seconds_difference(double time_1, double time_2);

// Return the number of hours later that a time in seconds time_2 is than a time in seconds time_1
double hours_difference(double time_1, double time_2);

// Return the total number of hours in the specified number of hours, minutes, and seconds
double to_float_hours(int hours, int minutes, int seconds);

/* EXTRA_TASK_1 */
#endif