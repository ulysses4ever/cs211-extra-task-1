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

}