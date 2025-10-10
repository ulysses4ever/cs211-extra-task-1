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

	//Задание 5 

	//Перевод из секунд в часовую часть
	cout << "//Задание 5 Перевод из секунд в часовую часть" << endl << endl;
	assert(get_hours(3800) == 1);
	assert(get_hours(11000) == 3);
	assert(get_hours(3600 * 24 + 3601) == 1);
	assert(get_hours(3600 * 24 ) == 0);

	cout << "Тесты для первой функции из пятого задания прошли успешно!" << endl << endl;

	//Перевод из секунд в минутную часть
	cout << "//Задание 5 Перевод из секунд в минутную часть" << endl << endl;
	assert(get_minutes(3800) == 3);
	assert(get_minutes(7300) == 1);
	assert(get_minutes(36061) == 1);
	assert(get_minutes(36000) == 0);
	assert(get_minutes(36120) == 2);

	cout << "Тесты для второй функции из пятого задания прошли успешно!" << endl << endl;

	//Перевод из секунд в секундную часть
	cout << "//Задание 5 Перевод из секунд в секундную часть" << endl << endl;
	assert(get_seconds(3800) == 20);
	assert(get_seconds(36121) == 1);
	assert(get_seconds(7207) == 7);
	assert(get_seconds(3) == 3);

	cout << "Тесты для третьей функции из пятого задания прошли успешно!" << endl << endl;

	//Задание 6. Return time at UTC+0, where utc_offset is the number of hours away from UTC + 0.
	cout << "//Задание 6. Return time at UTC+0, where utc_offset is the number of hours away from UTC + 0." << endl << endl;
	assert(fabs(time_to_utc(+0, 12.0) - 12.0) < DBL_EPSILON);
	assert(fabs(time_to_utc(+1, 12.0) - 11.0) < DBL_EPSILON);
	assert(fabs(time_to_utc(+23, 12.0) - 13.0) < DBL_EPSILON);
	assert(fabs(time_to_utc(+12, 12.0) - 0.0) < DBL_EPSILON);
	assert(fabs(time_to_utc(-1,23.0) - 0.0) < DBL_EPSILON);
	assert(fabs(time_to_utc(-8, 15.0) - 23.0) < DBL_EPSILON);
	assert(fabs(time_to_utc(-15, 17.0) - 8.0) < DBL_EPSILON);

	cout << "Тесты для шестого задания прошли успешно!" << endl << endl;

	//Задание 7.  Return UTC time in time zone utc_offset.
	cout << "//Задание 7.  Return UTC time in time zone utc_offset." << endl << endl;
	assert(fabs(time_from_utc(+0, 12.0) - 12.0) < DBL_EPSILON);
	assert(fabs(time_from_utc(+3, 12.0) - 15.0) < DBL_EPSILON);
	assert(fabs(time_from_utc(+12, 12.0) - 0.0) < DBL_EPSILON);
	assert(fabs(time_from_utc(+5, 23.0) - 4.0) < DBL_EPSILON);
	assert(fabs(time_from_utc(-2, 10.0) - 8.0) < DBL_EPSILON);
	assert(fabs(time_from_utc(-11, 10.0) - 23.0) < DBL_EPSILON);
	assert(fabs(time_from_utc(-2, 0.0) - 22.0) < DBL_EPSILON);

	cout << "Тесты для седьмого задания прошли успешно!" << endl << endl;










	system("pause");


}