#pragma once
#include <cmath>;
#include <assert.h>
// Разница в секундах
double seconds_difference(double time_1, double time_2);
//Разница в часах
double hours_difference(double time_1, double time_2);
// Перевод в доли часа
double to_float_hours(int hours, int minutes, int seconds);
//Приведение к 24ч типу
double to_24_hour_clock(double hours);
//Часы после полуночи
int get_hours(int sec);
//Минуты после полуночи
int get_minutes(int sec);
//Секунды после полуночи
int get_seconds(int sec);
//Приведение времени от Гринвического меридиана
double time_to_utc(int utc_offset, double time);


