#pragma once
#include <cassert>

// ¬ычисл€ет разницу в секундах
double seconds_difference(double, double);
// ¬ычисл€ет разницу в часах
double hours_difference(double, double);
// ¬ычисл€ет количество часов по данным часам, минутам и секундам
double to_float_hours(int, int, int);
// ѕреобразует указанное количество часов в 24-х часовой формат
double to_24_hour_clock(double);
// ¬озвращает количество часов по заданному количеству секунд
int get_hours(int);
// ¬озвращает количество минут по заданному количеству секунд (0 <= res < 60)
int get_minutes(int);