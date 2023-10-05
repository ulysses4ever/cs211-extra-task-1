#pragma once
//Return the number of seconds later that a time in seconds
double seconds_difference(double, double);

//Return the number of hours later that a time in seconds
double hours_difference(double, double);

//Return the total number of hours in the specified number of hours, minutes, and seconds.
double to_float_hours(int hours, int minutes, int seconds);
