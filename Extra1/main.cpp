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

}