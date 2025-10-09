#include "iostream"
#include "extra-task-1.h"
#include "float.h"



using namespace std;

int main()
{
	setlocale(LC_ALL, "RUSSIAN");

	//Задание 1.  Return the number of seconds later that a time in seconds time_2 is than a time in seconds time_1.
	cout << "Задание 1.  Return the number of seconds later that a time in seconds time_2 is than a time in seconds time_1." << endl << endl;
	assert(fabs(seconds_difference(1800.0, 3600.0) - 1800.0) <= DBL_EPSILON);
	assert(fabs(seconds_difference(3600.0, 1800.0) + 1800.0) <= DBL_EPSILON);
	assert(fabs(seconds_difference(1800.0, 2160.0) - 360.0) <= DBL_EPSILON);
	assert(fabs(seconds_difference(1800.0, 1800.0) - 0.0) <= DBL_EPSILON);

	cout << "Тесты для первого задания прошли успешно!" << endl << endl;



	//Задание 2. Return the number of hours later that a time in seconds time_2 is than a time in seconds time_1.
	cout << "//Задание 2. Return the number of hours later that a time in seconds time_2 is than a time in seconds time_1." << endl << endl;
	assert(fabs(hours_difference(1800.0, 3600.0) - 0.5) <= DBL_EPSILON);
	assert(fabs(hours_difference(3600.0, 1800.0) - -0.5) <= DBL_EPSILON);
	assert(fabs(hours_difference(1800.0, 2160.0) - 0.1) <= DBL_EPSILON);
	assert(fabs(hours_difference(1800.0, 1800.0) - 0.0) <= DBL_EPSILON);

	cout << "Тесты для второго задания прошли успешно!" << endl << endl;



	//Задание 3. Return the total number of hours in the specified numberof hours, minutes, and seconds.
	cout << "//Задание 3. Return the total number of hours in the specified numberof hours, minutes, and seconds." << endl << endl;
	assert(fabs(to_float_hours(0, 15, 0) - 0.25) <= DBL_EPSILON);
	assert(fabs(to_float_hours(2, 45, 9) - 2.7525) <= DBL_EPSILON);
	assert(fabs(to_float_hours(1, 0, 36) - 1.01) <= DBL_EPSILON);

	cout << "Тесты для третьего задания прошли успешно!" << endl << endl;

	//Задание 4. hours is a number of hours since midnight. Return thehour as seen on a 24 - hour clock.
	cout << "//Задание 4. hours is a number of hours since midnight. Return thehour as seen on a 24 - hour clock." << endl << endl;
	assert(fabs(to_24_hour_clock(24) - 0) <= DBL_EPSILON);
	assert(fabs(to_24_hour_clock(48) - 0) <= DBL_EPSILON);
	assert(fabs(to_24_hour_clock(25) - 1) <= DBL_EPSILON);
	assert(fabs(to_24_hour_clock(4) - 4) <= DBL_EPSILON);
	assert(fabs(to_24_hour_clock(28.5) - 4.5) <= DBL_EPSILON);

	cout << "Тесты для четвёртого задания прошли успешно!" << endl << endl;


	system("pause");


}