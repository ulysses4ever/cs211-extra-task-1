#include <iostream>
#include <cassert>
#include "extra-task-1.h"

using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");

	// Задание 1
	assert(abs(seconds_difference(1800.0, 3600.0) - 1800.0) < DBL_EPSILON);
	assert(abs(seconds_difference(3600.0, 1800.0) - (-1800.0)) < DBL_EPSILON);
	assert(abs(seconds_difference(1800.0, 2160.0) - 360.0) < DBL_EPSILON);
	assert(abs(seconds_difference(1800.0, 1800.0) - 0.0) < DBL_EPSILON);

}
