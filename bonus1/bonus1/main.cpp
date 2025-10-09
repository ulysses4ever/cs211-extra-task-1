#include "extra-task-1.h"
#include <iostream>
#include "cassert"
#include <float.h>
int main()
{
	setlocale(LC_ALL, "Russian");

	// task 1 Функция, возвращающая количество секунд, на которые отстаёт time_1 от time_2
	std::cout << "task 1 Функция, возвращающая количество секунд, на которые отстаёт time_1 от time_2" << std::endl;
	assert(fabs(seconds_difference(1800.0, 3600.0) - 1800.0) <= DBL_EPSILON);
	assert(fabs(seconds_difference(3600.0, 1800.0) - -1800.0) <= DBL_EPSILON);
	assert(fabs(seconds_difference(1800.0, 2160.0) - 360.0) <= DBL_EPSILON);
	assert(fabs(seconds_difference(1800.0, 1800.0) - 0.0) <= DBL_EPSILON);
	std::cout << "Тесты пройдены!" << std::endl << std::endl;

	// task 2 Функция, возвращающая разницу в часах между секундами time_1 и time_2
	std::cout << "task 2 Функция, возвращающая разницу в часах между секундами time_1 и time_2" << std::endl;
	assert(fabs(hours_difference(1800.0, 3600.0) - 0.5) <= DBL_EPSILON);
	assert(fabs(hours_difference(3600.0, 1800.0) - -0.5) <= DBL_EPSILON);
	assert(fabs(hours_difference(1800.0, 2160.0) - 0.1) <= DBL_EPSILON);
	assert(fabs(hours_difference(1800.0, 1800.0) - 0.0) <= DBL_EPSILON);
	std::cout << "Тесты пройдены!" << std::endl << std::endl;

}