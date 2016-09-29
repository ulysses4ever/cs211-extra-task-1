#include "extra-task-1.h"

int main() {
    // seconds_difference
    assert(fabs(seconds_difference(1800.0, 3600.0) - 1800.0) < DBL_EPSILON && "test-1");
    assert(fabs(seconds_difference(3600.0, 1800.0) + 1800.0) < DBL_EPSILON && "test-2");
    assert(fabs(seconds_difference(1800.0, 2160.0) - 360.0) < DBL_EPSILON && "test-3");
    assert(fabs(seconds_difference(1800.0, 1800.0) - 0.0) < DBL_EPSILON && "test-4");

    // hours_difference
    assert(fabs(hours_difference(1800.0, 3600.0) - 0.5) < DBL_EPSILON && "test-5");
    assert(fabs(hours_difference(3600.0, 1800.0) + 0.5) < DBL_EPSILON && "test-6");
    assert(fabs(hours_difference(1800.0, 2160.0) - 0.1) < DBL_EPSILON && "test-7");
    assert(fabs(hours_difference(1800.0, 1800.0) - 0.0) < DBL_EPSILON && "test-8");

    // to_float_hours
    assert(fabs(to_float_hours(0, 15, 0) - 0.25) < DBL_EPSILON && "test-9");
    assert(fabs(to_float_hours(2, 45, 9) - 2.7525) < DBL_EPSILON && "test-10");
    assert(fabs(to_float_hours(1, 0, 36) - 1.01) < DBL_EPSILON && "test-11");

    // to_24_hour_clock
    assert(fabs(to_24_hour_clock(24) - 0.) < DBL_EPSILON && "test-12");
    assert(fabs(to_24_hour_clock(48) - 0.) < DBL_EPSILON && "test-13");
    assert(fabs(to_24_hour_clock(25) - 1.) < DBL_EPSILON && "test-14");
    assert(fabs(to_24_hour_clock(4) - 4.) < DBL_EPSILON && "test-15");
    assert(fabs(to_24_hour_clock(28.5) - 4.5) < DBL_EPSILON && "test-16");

    // get_hours
    assert(get_hours(3800) == 1 && "test-17");

    // get_minutes
    assert(get_minutes(3800) == 3 && "test-18");

    // get_seconds
    assert(get_seconds(3800) == 20 && "test-19");

    // time_to_utc
    assert(fabs(time_to_utc(+0, 12.0) - 12.0) < DBL_EPSILON && "test-20");
    assert(fabs(time_to_utc(+1, 12.0) - 11.0) < DBL_EPSILON && "test-21");
    assert(fabs(time_to_utc(-1, 12.0) - 13.0) < DBL_EPSILON && "test-22");
    assert(fabs(time_to_utc(-11, 18.0) - 5.0) < DBL_EPSILON && "test-23");
    assert(fabs(time_to_utc(-1, 0.0) - 1.0) < DBL_EPSILON && "test-24");
    assert(fabs(time_to_utc(-1, 23.0) - 0.0) < DBL_EPSILON && "test-25");
    assert(fabs(time_to_utc(+1, 0.0) - 23.0) < DBL_EPSILON && "test-26");

    // time_from_utc
    assert(fabs(time_from_utc(+0, 12.0) - 12.0) < DBL_EPSILON && "test-27");
    assert(fabs(time_from_utc(+1, 12.0) - 13.0) < DBL_EPSILON && "test-28");
    assert(fabs(time_from_utc(-1, 12.0) - 11.0) < DBL_EPSILON && "test-29");
    assert(fabs(time_from_utc(+6, 6.0) - 12.0) < DBL_EPSILON && "test-30");
    assert(fabs(time_from_utc(-7, 6.0) - 23.0) < DBL_EPSILON && "test-31");
    assert(fabs(time_from_utc(-1, 0.0) - 23.0) < DBL_EPSILON && "test-32");
    assert(fabs(time_from_utc(-1, 23.0) - 22.0) < DBL_EPSILON && "test-33");
    assert(fabs(time_from_utc(+1, 23.0) - 0.0) < DBL_EPSILON && "test-34");

    return 0;
}
