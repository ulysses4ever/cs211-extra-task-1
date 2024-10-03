#include <iostream>
#include <assert.h>
#include <cmath>
#include "extra-task-1.h"

int main() {
	setlocale(LC_ALL, "Russian");

	assert(fabs(seconds_difference(1800.0, 3600.0) - 1800.0) < DBL_EPSILON);
	assert(fabs(seconds_difference(3600.0, 1800.0) + 1800.0) < DBL_EPSILON);
	assert(fabs(seconds_difference(1800.0, 1800.0) - 0.0) < DBL_EPSILON);
	assert(fabs(seconds_difference(1800.0, 2160.0) - 360.0) < DBL_EPSILON);
	std::cout << "Проверка функции seconds_difference пройдена" << std::endl;

	assert(fabs(hours_difference(1800, 3600) - 0.5) < DBL_EPSILON);
	assert(fabs(hours_difference(3600, 1800) + 0.5) < DBL_EPSILON);
	assert(fabs(hours_difference(1800, 2160) - 0.1) < DBL_EPSILON);
	assert(fabs(hours_difference(1800, 1800) - 0.0) < DBL_EPSILON);
	std::cout << "Проверка функции hours_difference пройдена" << std::endl;

	assert(fabs(to_float_hours(0, 15, 0) - 0.25) < DBL_EPSILON);
	assert(fabs(to_float_hours(2, 45, 9) - 2.7525) < DBL_EPSILON);
	assert(fabs(to_float_hours(1, 0, 36) - 1.01) < DBL_EPSILON);
	std::cout << "Проверка функции to_float_hours пройдена" << std::endl;

	assert(fabs(to_24_hour_clock(24) - 0) < DBL_EPSILON);
	assert(fabs(to_24_hour_clock(48) - 0) < DBL_EPSILON);
	assert(fabs(to_24_hour_clock(25) - 1) < DBL_EPSILON);
	assert(fabs(to_24_hour_clock(4) - 4) < DBL_EPSILON);
	assert(fabs(to_24_hour_clock(28.5) - 4.5) < DBL_EPSILON);
	std::cout << "Проверка функции to_24_hour_clock пройдена" << std::endl;

	assert(get_hourse(3800) == 1);
	assert(get_minutes(3800) == 3);
	assert(get_seconds(3800) == 20);
	std::cout << "Проверка функций get_hourse, get_minutes, get_seconds пройдена" << std::endl;

	assert(fabs(time_to_utc(+0, 12.0) - 12.0) < DBL_EPSILON);
	assert(fabs(time_to_utc(+1, 0.0) - 23.0) < DBL_EPSILON);
	assert(fabs(time_to_utc(+4, 1.0) - 21.0) < DBL_EPSILON);
	assert(fabs(time_to_utc(+1, 12.0) - 11.0) < DBL_EPSILON);
	assert(fabs(time_to_utc(-1, 12.0) - 13.0) < DBL_EPSILON);
	assert(fabs(time_to_utc(-11, 18.0) - 5.0) < DBL_EPSILON);
	assert(fabs(time_to_utc(-1, 0.0) - 1.0) < DBL_EPSILON);
	assert(fabs(time_to_utc(-1, 23.0) - 0.0) < DBL_EPSILON);
	std::cout << "Проверка функции time_to_utc пройдена" << std::endl;

	
	assert(fabs(time_from_utc(+0, 12.0) - 12.0) < DBL_EPSILON);
	assert(fabs(time_from_utc(+1, 12.0) - 13.0) < DBL_EPSILON);
	assert(fabs(time_from_utc(-1, 12.0) - 11.0) < DBL_EPSILON);
	assert(fabs(time_from_utc(+6, 6.0) - 12.0) < DBL_EPSILON);
	assert(fabs(time_from_utc(-7, 6.0) - 23.0) < DBL_EPSILON);
	assert(fabs(time_from_utc(-1, 23.0) - 22.0) < DBL_EPSILON);
	std::cout << "Проверка функции time_from_utc пройдена" << std::endl;
}