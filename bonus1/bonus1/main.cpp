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

	cout << "Тесты для первого задания выполнены!" << endl << endl;









	system("pause");


}