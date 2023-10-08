#pragma once

//Возвращает количество секунд спустя, когда время в секундах time_2 больше времени в секундах time_1
double seconds_difference(double time_1, double time_2);

//Возвращает количество часов спустя, когда время в секундах time_2 больше времени в секундах time_1
double hours_difference(double time_1, double time_2);

//Возвращает общее количество часов в указанном количестве часов, минут и секунд
double to_float_hours(int hours, int minutes, int seconds);

//Возвращает время, показанное на 24 - часовых часах
double to_24_hour_clock(double hours);

//Метод возвращающий часовую часть времени 
int get_hours(int seconds);

//Метод возвращающий минутную часть времени 
int get_minutes(int seconds);

//Метод возвращающий секундную часть времени 
int get_seconds(int seconds);

//Возвращает время в UTC+0, где utc_offset - количество часов, оставшихся до UTC + 0
double time_to_utc(int utc_offset, double time);

//Возвращает время UTC в часовом поясе utc_offset
double time_from_utc(int utc_offset, double time);