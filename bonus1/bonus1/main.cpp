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



	





	system("pause");


}