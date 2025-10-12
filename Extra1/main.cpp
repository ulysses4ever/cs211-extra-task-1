#include "extra-task-1.h"
#include <iostream>

using namespace std;

void assert_double_equal(double actual, double expected) {
	assert(fabs(actual - expected) < DBL_EPSILON);
}

void main()
{
    assert_double_equal(seconds_difference(1800.0, 3600.0), 1800.0);
    assert_double_equal(seconds_difference(3600.0, 1800.0), -1800.0);
    assert_double_equal(seconds_difference(1800.0, 2160.0), 360.0);
    assert_double_equal(seconds_difference(1800.0, 1800.0), 0.0);

    assert_double_equal(hours_difference(1800.0, 3600.0), 0.5);
    assert_double_equal(hours_difference(3600.0, 1800.0), -0.5);
    assert_double_equal(hours_difference(1800.0, 2160.0), 0.1);
    assert_double_equal(hours_difference(1800.0, 1800.0), 0.0);

    assert_double_equal(to_float_hours(0, 15, 0), 0.25);
    assert_double_equal(to_float_hours(2, 45, 9), 2.7525);
    assert_double_equal(to_float_hours(1, 0, 36), 1.01);

    assert_double_equal(to_24_hour_clock(24), 0);
    assert_double_equal(to_24_hour_clock(48), 0);
    assert_double_equal(to_24_hour_clock(25), 1);
    assert_double_equal(to_24_hour_clock(4), 4);
    assert_double_equal(to_24_hour_clock(28.5), 4.5);

	assert_double_equal(get_hours(3800), 1);
	assert_double_equal(get_minutes(3800), 3);
	assert_double_equal(get_seconds(3800), 20);

    assert_double_equal(time_to_utc(+0, 12.0), 12.0);
    assert_double_equal(time_to_utc(+1, 12.0), 11.0);
    assert_double_equal(time_to_utc(-1, 12.0), 13.0);
    assert_double_equal(time_to_utc(-11, 18.0), 5.0);
    assert_double_equal(time_to_utc(-1, 0.0), 1.0);
    assert_double_equal(time_to_utc(-1, 23.0), 0.0);


}