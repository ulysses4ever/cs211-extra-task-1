#pragma once

//Return the number of seconds later that a time in seconds time_2 is than a time in seconds time_1
double seconds_difference(double time_1, double time_2);

//Return the number of hours later that a time in seconds time_2 is than a time in seconds time_1
double hours_difference(double time_1, double time_2);

//Return the total number of hours in the specified number of hours, minutes, and seconds
double to_float_hours(int hours, int minutes, int seconds);

//hours is a number of hours since midnight. Return the hour as seen on a 24 - hour clock
double to_24_hour_clock(double hours);

//Метод возвращающий часовую часть времени 
int get_hours(int seconds);

//Метод возвращающий минутную часть времени 
int get_minutes(int seconds);

//Метод возвращающий секундную часть времени 
int get_seconds(int seconds);