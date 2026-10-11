#include <iostream>
#include "extra-task-1.h"
#include <cassert>

int main()
{
    // tests for seconds_difference
    assert(is_close(seconds_difference(1800.0, 3600.0), 1800.0));
    assert(is_close(seconds_difference(3600.0, 1800.0), -1800.0));
    assert(is_close(seconds_difference(1800.0, 2160.0), 360.0));
    assert(is_close(seconds_difference(1800.0, 1800.0), 0.0));
}