#include <iostream>
#include "assert.h"
#include <cmath>

using namespace std;

double seconds_difference(double time_1, double time_2)
{
	//Return the number of seconds later that a time in seconds	time_2 is than a time in seconds time_1.
	assert((time_1 >= 0) && (time_2 >= 0));
	 return time_2 - time_1;
}

double hours_difference(double time_1, double time_2)
{
	//Return the number of hours later that a time in seconds time_2 is than a time in seconds time_1.
	assert((time_1 >= 0) && (time_2 >= 0));
	return seconds_difference(time_1, time_2) / 3600.0;
}

double to_float_hours(int hours, int minutes, int seconds)
{
	//Return the total number of hours in the specified number	of hours, minutes, and seconds.
	assert(hours >= 0);
	assert(0 <= minutes && minutes < 60);
	assert(0 <= seconds && seconds < 60);
	return hours + minutes / 60.0 + seconds / 3600.0;
}

double to_24_hour_clock(double hours)
{
 //	hours is a number of hours since midnight.Return the hour as seen on a 24 - hour clock.
	assert(hours >= 0);
	return fmod(hours, 24);
}

double get_hours(double time)
{
	assert(time >= 0);
	return fmod(floor(time / 3600.0), 24);;
}

double get_minutes(double time)
{
	assert(time >= 0);
	return fmod(floor(time / 60.0), 60);
}

double get_seconds(double time)
{
	assert(time >= 0);
	return fmod(time, 60);
}

double time_to_utc(int utc_offset, double time)
{
	//Return time at UTC+0, where utc_offset is the number of hours away from
	assert(time >= 0);
	int trT = trunc(time);
	return (trT - utc_offset) % 24 + (time - (double)trT);
}

double time_from_utc(int utc_offset, double time)
{

	//	Return UTC time in time zone utc_offset.
		
	assert(time >= 0);
	int tr = trunc(time);
	return (24 + utc_offset + tr) % 24 + (time - (double)tr);
}



int main()
{
	assert(seconds_difference(1800.0, 3600.0) - 1800.0 < DBL_EPSILON);
	assert(seconds_difference(3600.0, 1800.0) - (-1800.0) < DBL_EPSILON);
	assert(seconds_difference(1800.0, 2160.0) - 360.0 < DBL_EPSILON);
	assert(seconds_difference(1800.0, 1800.0) - 0.0 < DBL_EPSILON);

	assert(hours_difference(1800.0, 3600.0) - 0.5 < DBL_EPSILON);
	assert(hours_difference(3600.0, 1800.0) - (-0.5) < DBL_EPSILON);
	assert(hours_difference(1800.0, 2160.0) - 0.1 < DBL_EPSILON);
	assert(hours_difference(1800.0, 1800.0) - 0.0 < DBL_EPSILON);

	assert(to_float_hours(0, 15, 0) - 0.25 < DBL_EPSILON);
	assert(to_float_hours(2, 45, 9) - 2.7525 < DBL_EPSILON);
	assert(to_float_hours(1, 0, 36) - 1.01 < DBL_EPSILON);

	cout << to_24_hour_clock(25) << endl;
	cout << to_24_hour_clock(24) << endl;
	cout << to_24_hour_clock(48) << endl;
	cout << to_24_hour_clock(4) << endl;
	cout << to_24_hour_clock(28.5) << endl;

	assert(fabs(time_to_utc(+0, 12.0) - 12.0) < DBL_EPSILON);
	assert(fabs(time_to_utc(+1, 12.0) - 11.0) < DBL_EPSILON);
	assert(fabs(time_to_utc(-1, 12.0) - 13.0) < DBL_EPSILON);
	assert(fabs(time_to_utc(-11, 18.0) - 5.0) < DBL_EPSILON);
	assert(fabs(time_to_utc(-1, 0.0) - 1.0) < DBL_EPSILON);
	assert(fabs(time_to_utc(-1, 23.0) - 0.0) < DBL_EPSILON);

	assert(fabs(time_from_utc(+0, 12.0) - 12.0) < DBL_EPSILON);
	assert(fabs(time_from_utc(+1, 12.0) - 13.0) < DBL_EPSILON);
	assert(fabs(time_from_utc(-1, 12.0) - 11.0) < DBL_EPSILON);
	assert(fabs(time_from_utc(+6, 6.0) - 12.0) < DBL_EPSILON);
	assert(fabs(time_from_utc(-7, 6.0) - 23.0) < DBL_EPSILON);
	assert(fabs(time_from_utc(-1, 0.0) - 23.0) < DBL_EPSILON);
	assert(fabs(time_from_utc(-1, 23.0) - 22.0) < DBL_EPSILON);
	assert(fabs(time_from_utc(+1, 23.0) - 0.0) < DBL_EPSILON);

	system("pause");
}
