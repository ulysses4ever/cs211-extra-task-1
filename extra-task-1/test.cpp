#include <cassert>
#include "extra-task-1.h"

void test_seconds_difference()
{
    assert(seconds_difference(1800.0, 3600.0) == 1800.0);
    assert(seconds_difference(3600.0, 1800.0) == -1800.0);
    assert(seconds_difference(1800.0, 1800.0) == 0.0);
}