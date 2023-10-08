#pragma once
#include <iostream>
#include <cassert>
//Возвращает разницу между секундами time_2 и time_1
double seconds_difference(double, double);
//Возвращает разницу между секундами time_2 и time_1 в часах
double hours_difference(double, double);
//Возвращает время в часах
double to_float_hours(int, int, int);