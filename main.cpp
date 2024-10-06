#include <cmath>
#include "extra-task-1.h"
#include <cassert>
#include <iostream>

int main()
{
    assert(fabs(seconds_difference(1800.0, 3600.0) - 1800.0) < __DBL_EPSILON__);
    assert(fabs(seconds_difference(3600.0, 1800.0) - -1800.0) < __DBL_EPSILON__);
    assert(fabs(seconds_difference(1800.0, 2160.0) - 360.0) < __DBL_EPSILON__);
    assert(fabs(seconds_difference(1800.0, 1800.0) - 0.0) < __DBL_EPSILON__);
    //hours_difference
    assert(fabs(hours_difference(1800.0, 3600.0) - 0.5) < __DBL_EPSILON__);
    assert(fabs(hours_difference(3600.0, 1800.0) - -0.5) < __DBL_EPSILON__);
    assert(fabs(hours_difference(1800.0, 2160.0) - 0.1) < __DBL_EPSILON__);
    assert(fabs(hours_difference(1800.0, 1800.0) - 0.0) < __DBL_EPSILON__);
    //to_float_hours
    assert(fabs(to_float_hours(0, 15, 0) - 0.25) < __DBL_EPSILON__);
    assert(fabs(to_float_hours(2, 45, 9) - 2.7525) < __DBL_EPSILON__);
    assert(fabs(to_float_hours(1, 0, 36) - 1.01) < __DBL_EPSILON__);
    //to_24_hour_clock
    assert(fabs(to_24_hour_clock(48) - 0.0) < __DBL_EPSILON__);
    assert(fabs(to_24_hour_clock(25) - 1.0) < __DBL_EPSILON__);
    assert(fabs(to_24_hour_clock(4) - 4.0) < __DBL_EPSILON__);
    assert(fabs(to_24_hour_clock(28.5) - 4.5) < __DBL_EPSILON__);
    //get_hours
    assert(fabs(get_hours(3800) - 1) < __DBL_EPSILON__);
    //get_minutes
    assert(fabs(get_minutes(3800) - 3) < __DBL_EPSILON__);
    //get_seconds
    assert(fabs(get_seconds(3800) - 20) < __DBL_EPSILON__);
    //time_to_utc
    assert(fabs(time_to_utc(+0, 12.0) - 12.0) < __DBL_EPSILON__);
    assert(fabs(time_to_utc(+1, 12.0) - 11.0) < __DBL_EPSILON__);
    assert(fabs(time_to_utc(-1, 12.0) - 13.0) < __DBL_EPSILON__);
    assert(fabs(time_to_utc(-11, 18.0) - 5.0) < __DBL_EPSILON__);
    assert(fabs(time_to_utc(-1, 0.0) - 1.0) < __DBL_EPSILON__);
    assert(fabs(time_to_utc(-1, 23.0) - 0.0) < __DBL_EPSILON__);
    //time_from_utc
    assert(fabs(time_from_utc(+0, 12.0) - 12.0) < __DBL_EPSILON__);
    assert(fabs(time_from_utc(+1, 12.0) - 13.0) < __DBL_EPSILON__);
    assert(fabs(time_from_utc(-1, 12.0) - 11.0) < __DBL_EPSILON__);
    assert(fabs(time_from_utc(+6, 6.0) - 12.0) < __DBL_EPSILON__);
    assert(fabs(time_from_utc(-7, 6.0) - 23.0) < __DBL_EPSILON__);
    assert(fabs(time_from_utc(-1, 0.0) - 23.0) < __DBL_EPSILON__);
    assert(fabs(time_from_utc(-1, 23.0) - 22.0) < __DBL_EPSILON__);
    assert(fabs(time_from_utc(+1, 23.0) - 0.0) < __DBL_EPSILON__);
}