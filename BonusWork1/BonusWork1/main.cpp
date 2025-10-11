#include <iostream>
#include "extra_task_1.h"
#include <cassert>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    assert(seconds_difference(1800.0, 3600.0) == 1800.0);
    assert(seconds_difference(3600.0, 1800.0) == -1800.0);
    assert(seconds_difference(1800.0, 2160) == 360.0);
    assert(seconds_difference(1800.0, 1800.0) == 0.0);
    cout << "Тесты задания №1 прошли успешно!\n\n";

    assert(hours_difference(1800.0, 3600.0) == 0.5);
    assert(hours_difference(3600.0, 1800.0) == -0.5);
    assert(hours_difference(1800.0, 2160) == 0.1);
    assert(hours_difference(1800.0, 1800.0) == 0.0);
    cout << "Тесты задания №2 прошли успешно!\n";
}
