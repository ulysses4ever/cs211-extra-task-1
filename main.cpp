#include <iostream>
#include <assert.h>
#include "extra-task-1.h"

int main()
{
    // ==== test seconds_difference ====
    assert(fabs(seconds_difference(1800.0, 3600.0) - 1800.0) <= DBL_EPSILON);
    assert(fabs(seconds_difference(3600.0, 1800.0) + 1800.0) <= DBL_EPSILON);
    assert(fabs(seconds_difference(1800.0, 2160.0) - 360.0) <= DBL_EPSILON);
    assert(fabs(seconds_difference(1800.0, 1800.0) - 0.0) <= DBL_EPSILON);

    // ==== test hours_difference ====
    assert(fabs(hours_difference(1800.0, 3600.0) - 0.5) <= DBL_EPSILON);
    assert(fabs(hours_difference(3600.0, 1800.0) + 0.5) <= DBL_EPSILON);
    assert(fabs(hours_difference(1800.0, 2160.0) - 0.1) <= DBL_EPSILON);
    assert(fabs(hours_difference(1800.0, 1800.0) - 0.0) <= DBL_EPSILON);

    // ==== test to_float_hours ====
    assert(fabs(to_float_hours(0, 15, 0) - 0.25) <= DBL_EPSILON);
    assert(fabs(to_float_hours(2, 45, 9) - 2.7525) <= DBL_EPSILON);
    assert(fabs(to_float_hours(1, 0, 36) - 1.01) <= DBL_EPSILON);

    // ==== test to_24_hour_clock ====
    assert(fabs(to_24_hour_clock(24) - 0.0) <= DBL_EPSILON);
    assert(fabs(to_24_hour_clock(48) - 0.0) <= DBL_EPSILON);
    assert(fabs(to_24_hour_clock(25) - 1.0) <= DBL_EPSILON);
    assert(fabs(to_24_hour_clock(4) - 4.0) <= DBL_EPSILON);
    assert(fabs(to_24_hour_clock(28.5) - 4.5) <= DBL_EPSILON);

    // ==== test get_hours ====
    assert(get_hours(3800) == 1);
    // ==== test get_hours ====
    assert(get_minutes(3800) == 3);
    // ==== test get_hours ====
    assert(get_seconds(3800) == 20);

    // ==== test time_to_utc ====
    assert(fabs(time_to_utc(+0, 12.0) - 12.0) <= DBL_EPSILON);
    assert(fabs(time_to_utc(+1, 12.0) - 11.0) <= DBL_EPSILON);
    assert(fabs(time_to_utc(-1, 12.0) - 13.0) <= DBL_EPSILON);
    assert(fabs(time_to_utc(-11, 18.0) - 5.0) <= DBL_EPSILON);
    assert(fabs(time_to_utc(-1, 0.0) - 1.0) <= DBL_EPSILON);
    assert(fabs(time_to_utc(-1, 23.0) - 0.0) <= DBL_EPSILON);

    // ==== test time_from_utc ====
    assert(fabs(time_from_utc(+0, 12.0) - 12.0) <= DBL_EPSILON);
    assert(fabs(time_from_utc(+1, 12.0) - 13.0) <= DBL_EPSILON);
    assert(fabs(time_from_utc(-1, 12.0) - 11.0) <= DBL_EPSILON);
    assert(fabs(time_from_utc(+6, 6.0) - 12.0) <= DBL_EPSILON);
    assert(fabs(time_from_utc(-7, 6.0) - 23.0) <= DBL_EPSILON);
    assert(fabs(time_from_utc(-1, 0.0) - 23.0) <= DBL_EPSILON);
    assert(fabs(time_from_utc(-1, 23.0) - 22.0) <= DBL_EPSILON);
    assert(fabs(time_from_utc(+1, 23.0) - 0.0) <= DBL_EPSILON);
}