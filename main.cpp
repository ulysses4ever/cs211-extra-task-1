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

	system("pause");
}