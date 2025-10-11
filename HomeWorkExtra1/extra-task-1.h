#pragma once
#include <cassert>
const double eps = 1e-7;

/// <summary>///¬ерните количество секунд, на которое врем€ в секундах time_2 отстаЄт от времени в секундах time_1.
/// </summary>/// <param name="time_1"></param>/// <param name="time_2"></param>/// <returns></returns>
double seconds_difference(double time_1, double time_2);