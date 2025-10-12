#pragma once
#include <cassert>

// Вычисляет разницу в секундах
double seconds_difference(double, double);
// Вычисляет разницу в часах
double hours_difference(double, double);
// Вычисляет количество часов по данным часам, минутам и секундам
double to_float_hours(int, int, int);
// Преобразует указанное количество часов в 24-х часовой формат
double to_24_hour_clock(double);
// Возвращает количество часов по заданному количеству секунд
int get_hours(int);
// Возвращает количество минут по заданному количеству секунд (0 <= res < 60)
int get_minutes(int);
// Возвращает количество секунд по заданному количеству секунд (0 <= res < 60)
int get_seconds(int);