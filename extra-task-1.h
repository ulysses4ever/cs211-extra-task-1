#pragma once
#include <iostream>
#include "cassert"
using namespace std;
// A function that calculates the difference in seconds between two timestamps
double seconds_difference(double, double);
// A function that calculates the difference in hours between two time stamps
double hours_difference(double, double);
//
double to_float_hours(int , int, int);
//
double to_24_hour_clock(double);
//
double time_to_utc(int, double);
//
double time_from_utc(int, double);
// Approximate double comparison function
bool are_equal(double, double);

