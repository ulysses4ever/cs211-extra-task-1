#pragma once

#include <iostream>
#include "assert.h"
#include <cmath>

//¬озвращает отставание time_2 от time_1
double seconds_difference(double time_1, double time_2);

//¬озвращает количество часов, на которое врем€ в секундах time_2 отстает от времени в секундах time_1
double hours_difference(double time_1, double time_2);

//¬озвращает общее количество часов в указанном количестве часов, минут и секунд
double to_float_hours(int hours, int minutes, int seconds);

//¬озвращает час, как он отображаетс€ в 24 - часовом формате
double to_24_hour_clock(double hours);

//¬озвращает часовую часть времени
int get_hours(int seconds);

//¬озвращает минутную часть времени
int get_minutes(int seconds);

//¬озвращает секундную часть времени
int get_seconds(int seconds);

//¬озвращает врем€, переведенное из UTC в часовой по€с utc_offset
double time_to_utc(int utc_offset, double time);

//¬озвращает врем€ UTC в часовом по€се utc_offset
double time_from_utc(int utc_offset, double time);