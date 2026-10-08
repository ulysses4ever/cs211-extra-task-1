#include <assert.h>
#include <math.h>
#pragma once

//Возвращает количество секунд, на сколько time_2 больше time_1
double seconds_difference(double time_1, double time_2);

//Возвращает количество часов, на сколько time_2 больше time_1
double hours_difference(double time_1, double time_2);

//Возвращает общее количество часов в указанном количестве часов, минут и секунд
double to_float_hours(int hours, int minutes, int seconds);

//Возвращает час так, как он отображается на 24-часовом циферблате
double to_24_hour_clock(double hours);

//Возвращает часы с времени в секундах
int get_hours(int seconds);

//Возвращает минуты с времени в секундах
int get_minutes(int seconds);

//Возвращает секунды с времени в секундах
int get_seconds(int seconds);

//Возвращает время в UTC+0,
double time_to_utc(int utc_offset, double time);

//Возвращает время в часовом поясе utc_offset
double time_from_utc(int utc_offset, double time);