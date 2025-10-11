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

	//Ассерты для hours_difference
	{
		assert(abs(hours_difference(1800.0, 3600.0) - 0.5) < eps);
		assert(abs(hours_difference(3600.0, 1800.0) + 0.5) < eps);
		assert(abs(hours_difference(1800.0, 2160.0) - 0.1) < eps);
		assert(abs(hours_difference(1800.0, 1800.0) - 0) < eps);
	}

	//Ассерты для to_float_hours
	{
		assert(abs(to_float_hours(0, 15, 0) - 0.25) < eps);
		assert(abs(to_float_hours(2, 45, 9) - 2.7525) < eps);
		assert(abs(to_float_hours(1, 0, 36) - 1.01) < eps);
	}

	//Ассерты для  to_24_hour_clock
	{
		assert(to_24_hour_clock(24) - 0 < eps);
		assert(to_24_hour_clock(48) - 0 < eps);
		assert(to_24_hour_clock(49) - 1 < eps);
		assert(to_24_hour_clock(4) - 4 < eps);
		assert(to_24_hour_clock(28.5) - 4.5 < eps);
	}

	//Ассерты для time_to_utc
	{
		assert(abs(time_to_utc(+0, 12.0) - 12.0) < eps);
		assert(abs(time_to_utc(+1, 12.0) - 11.0) < eps);
		assert(abs(time_to_utc(-1, 12.0) - 13.0) < eps);
		assert(abs(time_to_utc(-11, 18.0) - 5.0) < eps);
		assert(abs(time_to_utc(-1, 0.0) - 1.0) < eps);
		assert(abs(time_to_utc(-1, 23.0) - 0.0) < eps);
	}



	//Ассерты для time from
	{
		assert(abs(time_from_utc(+0, 12.0) - 12.0) < eps);
		assert(abs(time_from_utc(+1, 12.0) - 13.0) < eps);
		assert(abs(time_from_utc(-1, 12.0) - 11.0) < eps);
		assert(abs(time_from_utc(+6, 6.0) - 12.0) < eps);
		assert(abs(time_from_utc(-7, 6.0) - 23.0) < eps);
		assert(abs(time_from_utc(-1, 0.0) - 23.0) < eps);
		assert(abs(time_from_utc(-1, 23.0) - 22.0) < eps);
		assert(abs(time_from_utc(+1, 23.0) - 0.0) < eps);
	}
}
