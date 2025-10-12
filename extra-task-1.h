#pragma once
#include <iostream>
#include "cassert"
#include <cmath>
using namespace std;
// A function that calculates the difference in seconds between two timestamps
double seconds_difference(double, double);
// A function that calculates the difference in hours between two time stamps
double hours_difference(double, double);
// A function that returns the total amount of time in hours
double to_float_hours(int , int, int);
// A function that converts "time from midnight" to "time on the clock"
double to_24_hour_clock(double);
// A function that receives a whole number of hours
int get_hours(int);
// A function that gets an integer number of minutes
int get_minutes(int);
// A function that gets an integer number of seconds
int get_seconds(int);
// A function that convents time
double time_to_utc(int, double);
// 
double time_from_utc(int, double);
// Approximate double comparison function
bool are_equal(double, double);

