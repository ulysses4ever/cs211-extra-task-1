#pragma once
#include <iostream>
#include "cassert"
using namespace std;
// Функция, которая вычисляет разницу между двумя временными метками
double seconds_difference(double, double);
//
double hours_difference(double, double);
//
double to_float_hours(int , int, int);
//
double to_24_hour_clock(double);
//
double time_to_utc(int, double);
//
double time_from_utc(int, double);
// Функция приближенного сравнения double
bool are_equal(double, double);

