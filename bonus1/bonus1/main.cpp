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

	// task 3 Функция, возвращающая общее количество часов в заданном количестве часов, минут и секунд
	std::cout << "task 3 Функция, возвращающая общее количество часов в заданном количестве часов, минут и секунд" << std::endl;
	assert(fabs(to_float_hours(0, 15, 0) - 0.25) <= DBL_EPSILON);
	assert(fabs(to_float_hours(2, 45, 9) - 2.7525) <= DBL_EPSILON);
	assert(fabs(to_float_hours(1, 0, 36) - 1.01) <= DBL_EPSILON);
	std::cout << "Тесты пройдены!" << std::endl << std::endl;
}