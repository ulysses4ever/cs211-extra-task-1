#pragma once
#ifndef EXTRA_H
#define EXTRA_H

#include <iostream>
#include <vector>

double seconds_difference(double, double);

double hours_difference(double, double);

double to_float_hours(int, int, int);

double to_24_hour_clock(double);

double time_to_utc(int, double);

double time_from_utc(int, double);

int get_hours(int);

int get_minutes(int);

int get_seconds(int);
#endif EXTRA_H