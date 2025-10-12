#include "extra-task-1.h"
#include <iostream>
#include <cassert>

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
}