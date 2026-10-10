#include <iostream>
#include <assert.h>
#include "extra-task-1.h"

int main()
{
    setlocale(LC_ALL, "RUSSIAN");

    //Разница в секундах
    assert((seconds_difference(1800.0, 3600.0) - 1800.0) <= DBL_EPSILON);
    assert((seconds_difference(3600.0, 1800.0) + 1800.0) <= DBL_EPSILON);
    assert((seconds_difference(1800.0, 2160.0) - 360.0) <= DBL_EPSILON);
    assert((seconds_difference(1800.0, 1800.0) - 0.0) <= DBL_EPSILON);

    //Разница в часах
    assert((hours_difference(1800.0, 3600.0) - 0.5) <= DBL_EPSILON);
    assert((hours_difference(3600.0, 1800.0) + 0.5) <= DBL_EPSILON);
    assert((hours_difference(1800.0, 2160.0) - 0.1) <= DBL_EPSILON);
    assert((hours_difference(1800.0, 1800.0) - 0.0) <= DBL_EPSILON);

    std::cout << "Все тесты прошли";
}