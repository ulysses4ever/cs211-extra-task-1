#pragma once

// checks if two double values are equal with accuracy of 10^-7
bool equal(double, double);

// returns the difference in seconds between two times given in seconds
double seconds_difference(double time_1, double time_2);

// returns the difference in hours between two times given in seconds
double hours_difference(double time_1, double time_2);
