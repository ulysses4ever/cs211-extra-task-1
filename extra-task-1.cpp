#include <iostream>
#include <cassert>
#include <cmath>

using namespace std;

/*
Return the number of seconds later that a time in seconds
time_2 is than a time in seconds time_1.
*/
double seconds_difference(double time_1, double time_2)
{
	return time_2 - time_1;
}

/*
Return the number of hours later that a time in seconds
time_2 is than a time in seconds time_1.
*/
double hours_difference(double time_1, double time_2)
{
	return seconds_difference(time_1, time_2) / 3600.0;
}

/*
Return the total number of hours in the specified number
of hours, minutes, and seconds.

Precondition: 0 <= minutes < 60  and  0 <= seconds < 60
*/
double to_float_hours(int hours, int minutes, int seconds)
{
	return hours + minutes/60.0 + seconds/3600.0;
}

/*
hours is a number of hours since midnight. Return the
hour as seen on a 24-hour clock.

Precondition: hours >= 0
*/
double to_24_hour_clock(double hours)
{
	return fmod(hours, 24.0);
}

int get_hours(int seconds){
	return seconds / 3600;
}

int get_minutes(int seconds){
	return seconds % 3600 / 60;
}

int get_seconds(int seconds){
	return seconds % 60;
}

/*
Return time at UTC+0, where utc_offset is the number of hours away from
UTC+0.
*/
double time_to_utc(int utc_offset, double time)
{
	double res = time - utc_offset;
	return fmod(res < 0 ? res += 24 : res, 24.0);
}

/*
Return UTC time in time zone utc_offset.
*/
double time_from_utc(int utc_offset, double time)
{
	double res = time + utc_offset;
	return fmod(res < 0 ? res += 24 : res, 24.0);	
}

int main(){

	cout << "Start testing seconds_difference...\n";
	assert(abs(seconds_difference(1800.0, 3600.0) - 1800.0) < DBL_EPSILON);
	assert(abs(seconds_difference(3600.0, 1800.0) - (-1800.0)) < DBL_EPSILON);
	assert(abs(seconds_difference(1800.0, 2160.0) - 360.0) < DBL_EPSILON);
	assert(abs(seconds_difference(1800.0, 1800.0) - 0.0) < DBL_EPSILON);
	cout << "Testing is complete\n";

	cout << endl;

	cout << "Start testing hours_difference...\n";
	assert(abs(hours_difference(1800.0, 3600.0) - 0.5) < DBL_EPSILON);
	assert(abs(hours_difference(3600.0, 1800.0) - (-0.5)) < DBL_EPSILON);
	assert(abs(hours_difference(1800.0, 2160.0) - 0.1) < DBL_EPSILON);
	assert(abs(hours_difference(1800.0, 1800.0) - 0.0) < DBL_EPSILON);
	cout << "Testing is complete\n";

	cout << endl;

	cout << "Start testing to_float_hours...\n";
	assert(abs(to_float_hours(0, 15, 0) - 0.25) < DBL_EPSILON);
	assert(abs(to_float_hours(2, 45, 9) - 2.7525) < DBL_EPSILON);
	assert(abs(to_float_hours(1, 0, 36) - 1.01) < DBL_EPSILON);
	cout << "Testing is complete\n";

	cout << endl;

	cout << "Start testing to_24_hour_clock...\n";
	assert(abs(to_24_hour_clock(24) - 0) < DBL_EPSILON);
	assert(abs(to_24_hour_clock(48) - 0) < DBL_EPSILON);
	assert(abs(to_24_hour_clock(25) - 1) < DBL_EPSILON);
	assert(abs(to_24_hour_clock(4) - 4) < DBL_EPSILON);
	assert(abs(to_24_hour_clock(28.5) - 4.5) < DBL_EPSILON);
	cout << "Testing is complete\n";
	
	cout << endl;

	cout << "Start testing get_hors, get_minutes, get_seconds...\n";
	assert(get_hours(3800) == 1);
	assert(get_minutes(3800) == 3);
	assert(get_seconds(3800) == 20);
	cout << "Testing is complete\n";

	cout << endl;

	cout << "Start testing time_to_utc...\n";
	assert(abs(time_to_utc(+0, 12.0) - 12.0) < DBL_EPSILON);
	assert(abs(time_to_utc(+1, 12.0) - 11.0) < DBL_EPSILON);
	assert(abs(time_to_utc(-1, 12.0) - 13.0) < DBL_EPSILON);
	assert(abs(time_to_utc(-11, 18.0) - 5.0) < DBL_EPSILON);
	assert(abs(time_to_utc(-1, 0.0) - 1.0) < DBL_EPSILON);
	assert(abs(time_to_utc(-1, 23.0) - 0.0) < DBL_EPSILON);
	cout << "Testing is complete\n";

	cout << endl;

	cout << "Start testing time_from_utc...\n";
	assert(abs(time_from_utc(+0, 12.0) - 12.0) < DBL_EPSILON);
	assert(abs(time_from_utc(+1, 12.0) - 13.0) < DBL_EPSILON);
	assert(abs(time_from_utc(-1, 12.0) - 11.0) < DBL_EPSILON);
	assert(abs(time_from_utc(+6, 6.0) - 12.0) < DBL_EPSILON);
	assert(abs(time_from_utc(-7, 6.0) - 23.0) < DBL_EPSILON);
	assert(abs(time_from_utc(-1, 0.0) - 23.0) < DBL_EPSILON);
	assert(abs(time_from_utc(-1, 23.0) - 22.0) < DBL_EPSILON);
	assert(abs(time_from_utc(+1, 23.0) - 0.0) < DBL_EPSILON);
	cout << "Testing is complete\n";
	return 0;
}