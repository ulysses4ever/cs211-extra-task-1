#pragma once
#include <cassert>
#include "extra-task-1.h"
#include <cmath>
const double eps = 1e-7;

/// <summary>///¬ерните количество секунд, на которое врем€ в секундах time_2 отстаЄт от времени в секундах time_1.
/// </summary>/// <param name="time_1"></param>/// <param name="time_2"></param>/// <returns></returns>
double seconds_difference(double time_1, double time_2);


/// <summary>///¬ерните количество часов, на которое врем€ (в секундах) time_2 больше времени (в секундах) time_1. /// </summary>/// <param name="time_1"></param>/// <param name="time_2"></param>/// <returns></returns>
double hours_difference(double time_1, double time_2);


/// <summary>///ѕереводит всЄ в суммарные часы /// </summary>/// <param name="hours"></param>/// <param name="minutes"></param>/// <param name="seconds"></param>/// <returns></returns>
double to_float_hours(int hours, int minutes, int seconds);

/// <summary>/// возвращает  часы в формате 24 
/// </summary>/// <param name="hours"></param>/// <returns></returns>
double to_24_hour_clock(double hours);


double time_to_utc(int utc_offset, double time);

double time_from_utc(int utc_offset, double time);