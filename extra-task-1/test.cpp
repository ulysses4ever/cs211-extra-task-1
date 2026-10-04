#include <cassert>
#include "extra-task-1.h"

void test_seconds_difference()
{
    assert(seconds_difference(1800.0, 3600.0) == 1800.0);
    assert(seconds_difference(3600.0, 1800.0) == -1800.0);
    assert(seconds_difference(1800.0, 1800.0) == 0.0);
}

void test_hours_difference()
{
    assert(hours_difference(1800.0, 3600.0) == 0.5);
    assert(hours_difference(3600.0, 1800.0) == -0.5);
    assert(hours_difference(1800.0, 2160.0) == 0.1);
}
void test_to_float_hours()
{
    assert(to_float_hours(0, 15, 0) == 0.25);
    assert(to_float_hours(2, 45, 9) == 2.7525);
    assert(to_float_hours(1, 0, 36) == 1.01);
}
void test_to_24_hour_clock()
{
    assert(to_24_hour_clock(24) == 0);
    assert(to_24_hour_clock(25) == 1);
    assert(to_24_hour_clock(28.5) == 4.5);
}