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

int main()
{
    test_seconds_difference();
    test_hours_difference();
}
