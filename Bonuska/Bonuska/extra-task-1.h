#pragma once

#include <iostream>
#include <assert.h>
#include <cmath>

double seconds_difference(double, double);

double hours_difference(double, double);

double to_float_hours(int, int, int);

double to_24_hour_clock(double);

double get_hours(double);

double get_minutes(double);

double get_seconds(double);

double time_to_utc(int, double);

double time_from_utc(int, double);