#include "extra-task-1.h"
#include <iostream>
#include "cassert"
#include <cfloat>

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

	// task 4 Функция, возвращающая значение времени, показанное на 24 - часовых часах
	std::cout << "task 4 Функция, возвращающая значение времени, показанное на 24 - часовых часах." << std::endl;
	assert(fabs(to_24_hour_clock(24) - 0.0) <= DBL_EPSILON);
	assert(fabs(to_24_hour_clock(48) - 0.0) <= DBL_EPSILON);
	assert(fabs(to_24_hour_clock(25) - 1.0) <= DBL_EPSILON);
	assert(fabs(to_24_hour_clock(4) - 4.0) <= DBL_EPSILON);
	assert(fabs(to_24_hour_clock(28.5) - 4.5) <= DBL_EPSILON);
	std::cout << "Тесты пройдены!" << std::endl << std::endl;

	// task 5.1 Часы на циферблате
	std::cout << "task 5.1 Часы на циферблате" << std::endl;
	assert(get_hours(3800) == 1);
	assert(get_hours(7300) == 2);
	assert(get_hours(3600*24) == 0);
	std::cout << "Тесты пройдены!" << std::endl << std::endl;

	// task 5.2 Минуты на циферблате
	std::cout << "task 5.2 Минуты на циферблате" << std::endl;
	assert(get_minutes(3800) == 3);
	assert(get_minutes(9500) == 38);
	assert(get_minutes(3600) == 0);
	std::cout << "Тесты пройдены!" << std::endl << std::endl;

	// task 5.3 Секундны на циферблате
	std::cout << "task 5.3 Секундны на циферблате" << std::endl;
	assert(get_seconds(3800) == 20);
	assert(get_seconds(3601) == 1);
	assert(get_seconds(3600) == 0);
	std::cout << "Тесты пройдены!" << std::endl << std::endl;

	// task 6 Функция, возвращающая время в UTC+0, где utc_offset - это количество часов, отделяющих от UTC+0
	std::cout << "task 6 Функция, возвращающая время в UTC+0, где utc_offset - это количество часов, отделяющих от UTC+0" << std::endl;
	assert(fabs(time_to_utc(+0, 12.0) - 12.0) < DBL_EPSILON);
	assert(fabs(time_to_utc(+1, 12.0) - 11.0) < DBL_EPSILON);
	assert(fabs(time_to_utc(-1, 12.0) - 13.0) < DBL_EPSILON);
	assert(fabs(time_to_utc(-11, 18.0) - 5.0) < DBL_EPSILON);
	assert(fabs(time_to_utc(-1, 0.0) - 1.0) < DBL_EPSILON);
	assert(fabs(time_to_utc(-1, 23.0) - 0.0) < DBL_EPSILON);





}