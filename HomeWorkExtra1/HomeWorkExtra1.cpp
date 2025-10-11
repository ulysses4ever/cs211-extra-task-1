#include <iostream>
#include "extra-task-1.h"
using namespace std;



int main()
{
	setlocale(LC_ALL, "russian");
	//Ассерты для  seconds_difference
	{
		assert(abs(seconds_difference(1800.0, 3600.0) - 1800) < eps);
		assert(abs(seconds_difference(3600.0, 1800) + 1800) < eps);
		assert(abs(seconds_difference(1800.0, 2160.0) - 360) < eps);
		assert(abs(seconds_difference(1800.0, 1800.0) - 0) < eps);

	}
}
