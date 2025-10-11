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
    cout << "Тесты задания №2 прошли успешно!\n\n";

    assert(to_float_hours(0, 15, 0) == 0.25);
    assert(to_float_hours(2, 45, 9) == 2.7525);
    assert(to_float_hours(1, 0, 36) == 1.01);
    cout << "Тесты задания №3 прошли успешно!\n\n";

    assert(to_24_hour_clock(24) == 0);
    assert(to_24_hour_clock(48) == 0);
    assert(to_24_hour_clock(25) == 1);
    assert(to_24_hour_clock(4) == 4);
    assert(to_24_hour_clock(28.5) == 4.5);
    cout << "Тесты задания №4 прошли успешно!\n\n";

    assert(get_hours(3800) == 1);
    assert(get_minutes(3800) == 3);
    assert(get_seconds(3800) == 20);
    cout << "Тесты микро-функций прошли успешно!\n\n";

    assert(time_to_utc(0, 12.0) == 12.0);
    assert(time_to_utc(1, 12.0) == 11.0);
    assert(time_to_utc(-1, 12.0) == 13.0);
    assert(time_to_utc(-11, 18.0) == 5.0);
    assert(time_to_utc(-1, 0.0) == 1.0);
    assert(time_to_utc(-1, 23.0) == 0.0);
    cout << "Тесты задания №5 прошли успешно!\n\n";

    assert(time_from_utc(0, 12.0) == 12.0);
    assert(time_from_utc(1, 12.0) == 13.0);
    assert(time_from_utc(-1, 12.0) == 11.0);
    assert(time_from_utc(6, 6.0) == 12.0);
    assert(time_from_utc(-7, 6.0) == 23.0);
    assert(time_from_utc(-1, 0.0) == 23.0);
    assert(time_from_utc(-1, 23.0) == 22.0);
    assert(time_from_utc(1, 23.0) == 0.0);
    cout << "Тесты задания №6 прошли успешно!";
}
