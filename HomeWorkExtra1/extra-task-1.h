#pragma once
#include <cassert>
const double eps = 1e-7;

/// <summary>///Верните количество секунд, на которое время в секундах time_2 отстаёт от времени в секундах time_1.
/// </summary>/// <param name="time_1"></param>/// <param name="time_2"></param>/// <returns></returns>
double seconds_difference(double time_1, double time_2);


/// <summary>///Верните количество часов, на которое время (в секундах) time_2 больше времени (в секундах) time_1. /// </summary>/// <param name="time_1"></param>/// <param name="time_2"></param>/// <returns></returns>
double hours_difference(double time_1, double time_2);