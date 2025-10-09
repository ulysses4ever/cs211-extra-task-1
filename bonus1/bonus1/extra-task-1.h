#pragma once

// task 1 Функция, возвращающая количество секунд, на которые отстаёт time_1 от time_2
double seconds_difference(double time_1, double time_2);

// task 2 Функция, возвращающая разницу в часах между секундами time_1 и time_2
double hours_difference(double time_1, double time_2);

// task 3 Функция, возвращающая общее количество часов в заданном количестве часов, минут и секунд
double to_float_hours(int hours, int minutes, int seconds);

// task 4 Функция, возвращающая значение времени, показанное на 24 - часовых часах
double to_24_hour_clock(double hours);

// task 5.1 Часы на циферблате
int get_hours(int seconds);

// task 5.2 Минуты на циферблате
int get_minutes(int seconds);

// task 5.3 Секундны на циферблате
int get_seconds(int seconds);
