#pragma once

//Возвращает, насколько секунд второе время позже первого
double seconds_difference(double time_1, double time_2);

//Возвращает, насколько часов второе время позже первого
double hours_difference(double time_1, double time_2);

//Переводит время в часы
double to_float_hours(int hours, int minutes, int seconds);

//Переводит время в часах в 24-часовой формат
double to_24_hour_clock(double hours);

//Возвращает количество часов во времени в формате ЧЧ:ММ:СС
int get_hours(int time);

//Возвращает количество минут во времени в формате ЧЧ:ММ:СС
int get_minutes(int time);

//Возвращает количество секунд во времени в формате ЧЧ:ММ:СС
int get_seconds(int time);

//Переводит время в UTC
double time_to_utc(int utc_offset, double time);

//Переводит время из UTC
double time_from_utc(int utc_offset, double time);
