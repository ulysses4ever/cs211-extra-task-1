#include <iostream>
#include "extra-task-1.h"
#include <assert.h>

using namespace std;

int main() {
	setlocale(LC_ALL, "RUSSIAN");
	
    double eps = DBL_EPSILON;
	//Task1
    assert(abs(seconds_difference(1800.0, 3600.0) - 1800.0) < eps);
    assert(abs(seconds_difference(3600.0, 1800.0) + 1800.0) < eps);
    assert(abs(seconds_difference(1800.0, 2160.0) - 360.0) < eps);
    assert(abs(seconds_difference(1800.0, 1800.0) - 0.0) < eps);
    cout << "Тесты task1 прошли" << endl;

    //Task2
    assert(abs(hours_difference(1800.0, 3600.0) - 0.5) < eps);
    assert(abs(hours_difference(3600.0, 1800.0) + 0.5) < eps);
    assert(abs(hours_difference(1800.0, 2160.0) - 0.1) < eps);
    assert(abs(hours_difference(1800.0, 1800.0) - 0.0) < eps);
    cout << "Тесты task2 прошли" << endl;
    
    //Task3
    assert(abs(to_float_hours(0, 15, 0) - 0.25) < eps);
    assert(abs(to_float_hours(2, 45, 9) - 2.7525) < eps);
    assert(abs(to_float_hours(1, 0, 36) - 1.01) < eps);
    cout << "Тесты task3 прошли" << endl;

    //Task4
    assert(to_24_hour_clock(24) == 0);
    assert(to_24_hour_clock(48) == 0);
    assert(to_24_hour_clock(25) == 1);
    assert(to_24_hour_clock(4) == 4);
    assert(abs(to_24_hour_clock(28.5) - 4.5) < eps);
    cout << "Тесты task4 прошли" << endl;

    //Task5
    assert(get_hours(3800) == 1);
    assert(get_minutes(3800) == 3);
    assert(get_seconds(3800) == 20);
    cout << "Тесты task5 прошли" << endl;

	system("pause");
}