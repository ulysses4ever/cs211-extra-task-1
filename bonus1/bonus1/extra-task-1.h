#pragma once
#include "assert.h"
#include "float.h"
#include "math.h"

using namespace std;
//Задание 1.  Return the number of seconds later that a time in seconds time_2 is than a time in seconds time_1.
double seconds_difference(double, double);

//Задание 2. Return the number of hours later that a time in seconds time_2 is than a time in seconds time_1.
double hours_difference(double , double );

//Задание 3. Return the total number of hours in the specified numberof hours, minutes, and seconds.
double to_float_hours(int , int , int );

//Задание 4. hours is a number of hours since midnight. Return thehour as seen on a 24 - hour clock.
double to_24_hour_clock(double);

//Задание 5 

//Перевод из секунд в часовую часть
int get_hours(int);

//Перевод из секунд в минутную часть
int get_minutes(int);

//Перевод из секунд в секундную часть
int get_seconds(int);

//Задание 6. Return time at UTC+0, where utc_offset is the number of hours away from UTC + 0.
double time_to_utc(int , double );

//Задание 7.  Return UTC time in time zone utc_offset.
double time_from_utc(int , double );
