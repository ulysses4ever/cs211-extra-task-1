#include <cassert>
#include <cfloat>
#include <cmath>
#include "extra-task-1.h"

void test_seconds_difference()
{
    assert(fabs(1800.0 - seconds_difference(1800.0, 3600.0)) < DBL_EPSILON);
    assert(fabs(-1800.0 - seconds_difference(3600.0, 1800.0)) < DBL_EPSILON);
    assert(fabs(360.0 - seconds_difference(1800.0, 2160.0)) < DBL_EPSILON);
    assert(fabs(0.0 - seconds_difference(1800.0, 1800.0)) < DBL_EPSILON);
}

void test_hours_difference()
{
    assert(fabs(0.5 - hours_difference(1800.0, 3600.0)) < DBL_EPSILON);
    assert(fabs(-0.5 - hours_difference(3600.0, 1800.0)) < DBL_EPSILON);
    assert(fabs(0.1 - hours_difference(1800.0, 2160.0)) < DBL_EPSILON);
    assert(fabs(0.0 - hours_difference(1800.0, 1800.0)) < DBL_EPSILON);
}

void test_to_float_hours()
{
    assert(fabs(0.25 - to_float_hours(0, 15, 0)) < DBL_EPSILON);
    assert(fabs(2.7525 - to_float_hours(2, 45, 9)) < DBL_EPSILON);
    assert(fabs(1.01 - to_float_hours(1, 0, 36)) < DBL_EPSILON);
}

void test_to_24_hour_clock()
{
    assert(fabs(0 - to_24_hour_clock(24)) < DBL_EPSILON);
    assert(fabs(0 - to_24_hour_clock(48)) < DBL_EPSILON);
    assert(fabs(1 - to_24_hour_clock(25)) < DBL_EPSILON);
    assert(fabs(4 - to_24_hour_clock(4)) < DBL_EPSILON);
    assert(fabs(4.5 - to_24_hour_clock(28.5)) < DBL_EPSILON);
}

void test_time_to_utc()
{
    assert(fabs(12 - time_to_utc(+0, 12.0)) < DBL_EPSILON);
    assert(fabs(11 - time_to_utc(+1, 12.0)) < DBL_EPSILON);
    assert(fabs(13 - time_to_utc(-1, 12.0)) < DBL_EPSILON);
    assert(fabs(5 - time_to_utc(-11, 18.0)) < DBL_EPSILON);
    assert(fabs(1 - time_to_utc(-1, 0.0)) < DBL_EPSILON);
    assert(fabs(0 - time_to_utc(-1, 23.0)) < DBL_EPSILON);
    assert(fabs(23 - time_to_utc(+1, 0.0)) < DBL_EPSILON);
}

void test_time_from_utc()
{
    assert(fabs(12 - time_from_utc(+0,12)) < DBL_EPSILON);
    assert(fabs(13 - time_from_utc(+1,12)) < DBL_EPSILON);
    assert(fabs(11 - time_from_utc(-1,12)) < DBL_EPSILON);
    assert(fabs(12 - time_from_utc(+6,6)) < DBL_EPSILON);
    assert(fabs(23 - time_from_utc(-7,6)) < DBL_EPSILON);
    assert(fabs(23 - time_from_utc(-1,0)) < DBL_EPSILON);
    assert(fabs(22 - time_from_utc(-1,23)) < DBL_EPSILON);
    assert(fabs(0 - time_from_utc(+1,23)) < DBL_EPSILON);
}

void test_get_hours_minutes_seconds()
{
    assert(get_hours(3212) == 0);
    assert(get_hours(7277) == 2);
    assert(get_hours(6712) == 1);
    assert(get_minutes(7511) == 5);
    assert(get_minutes(3655) == 0);
    assert(get_minutes(3094) == 51);
    assert(get_seconds(1972) == 52);
    assert(get_seconds(5064) == 24);
    assert(get_seconds(7765) == 25);
}

int main()
{
    test_seconds_difference();
    test_hours_difference();
    test_to_float_hours();
    test_to_24_hour_clock();
    test_get_hours_minutes_seconds();
    test_time_to_utc();
    test_time_from_utc();
}
