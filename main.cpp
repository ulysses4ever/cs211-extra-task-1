#include <iostream>
#include "extra-task-1.h"
int main()
{
    // Проверка функции seconds_difference()
    assert(are_equal(seconds_difference(1800.0, 3600.0), 1800.0));
    assert(are_equal(seconds_difference(3600.0, 1800.0), -1800.0));
    assert(are_equal(seconds_difference(1800.0, 2160.0), 360.0));
    assert(are_equal(seconds_difference(1800.0, 1800.0), 0.0));
    // Проверка функции hours_difference()
    assert(are_equal(hours_difference(1800.0, 3600.0), 0.5));
    assert(are_equal(hours_difference(3600.0, 1800.0), -0.5));
    assert(are_equal(hours_difference(1800.0, 2160.0), 0.1));
    assert(are_equal(hours_difference(1800.0, 1800.0), 0.0));

    

}


