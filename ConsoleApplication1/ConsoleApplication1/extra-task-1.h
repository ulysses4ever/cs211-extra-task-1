#pragma once
#include <iostream>
#include <cassert>
//Возвращает разницу между секундами time_2 и time_1
double seconds_difference(double, double);
//Возвращает разницу между секундами time_2 и time_1 в часах
double hours_difference(double, double);
//Возвращает время в часах
double to_float_hours(int, int, int);
//Возвращает часы на 24 часовых часах
double to_24_hour_clock(double);
//Возвращает часовую часть в секундах
int get_hours(int);
//Возвращает минутную часть в секундах
int get_minutes(int);
//Возвращает секундую часть
int get_seconds(int);