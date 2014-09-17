#include <iostream>
#include <cassert>
#include <cmath>

using namespace std;

double seconds_difference(double time_1, double time_2)
{
	return (time_2 - time_1);
		/*
		Return the number of seconds later that a time in seconds
		time_2 is than a time in seconds time_1.
		*/
}

double hours_difference(double time_1, double time_2)
{
	return seconds_difference(time_1, time_2) / 3600;

	/*
	Return the number of hours later that a time in seconds
	time_2 is than a time in seconds time_1.
	*/

}

double to_float_hours(int hours, int minutes, int seconds)
{
	assert(minutes >= 0);
	assert(minutes < 60);
	assert(seconds >= 0);
	assert(seconds < 60);
	return hours + minutes / 60.0 + seconds / 3600.0;

	/*
	Return the total number of hours in the specified number
	of hours, minutes, and seconds.
	*/
}

double to_24_hour_clock(double hours)
{
	assert(hours >= 0);
	return fmod(hours, 24);

	/*
	hours is a number of hours since midnight. Return the
	hour as seen on a 24-hour clock.

	Precondition: hours >= 0
	*/
}

int get_hours(int sec)
{
	return sec / 3600 % 24;
	
}

int get_minutes(int sec)
{
	return sec % 3600 / 60;
}

int get_seconds(int sec)
{
	return sec % 3600 % 60;
}

double time_to_utc(int utc_offset, double time)
{
	double t = time - utc_offset;
	return (t >= 24) ? t - 24 : t;

	/*
	Return time at UTC+0, where utc_offset is the number of hours away from
	UTC+0.
	*/
}

double time_from_utc(int utc_offset, double time)
{
	double t = time + utc_offset;
	if (t < 0)
		t += 24;
	if (t == 24)
		t -= 24;
	return t;

	/*
	Return UTC time in time zone utc_offset.
	*/
}

int main(){
	assert(fabs(seconds_difference(1800.0, 3600.0) - 1800.0) < DBL_EPSILON);
	assert(fabs(seconds_difference(3600.0, 1800.0) - (-1800.0)) < DBL_EPSILON);
	assert(fabs(seconds_difference(1800.0, 2160.0) - 360.0) < DBL_EPSILON);
	assert(fabs(seconds_difference(1800.0, 1800.0) - 0.0) < DBL_EPSILON);
	cout << "Tests seconds_difference done" << endl;

	assert(fabs(hours_difference(1800.0, 3600.0) - 0.5) < DBL_EPSILON);
	assert(fabs(hours_difference(3600.0, 1800.0) + 0.5) < DBL_EPSILON);
	assert(fabs(hours_difference(1800.0, 2160.0) - 0.1) < DBL_EPSILON);
	assert(fabs(hours_difference(1800.0, 1800.0)) < DBL_EPSILON);
	cout << "Tests hours_difference done" << endl;

	assert(fabs(to_float_hours(0, 15, 0) - 0.25) < DBL_EPSILON);
	assert(fabs(to_float_hours(2, 45, 9) - 2.7525) < DBL_EPSILON);
	assert(fabs(to_float_hours(1, 0, 36) - 1.01) < DBL_EPSILON);
	cout << "Tests to_float_hours done" << endl;
	
	assert(fabs(to_24_hour_clock(24)) < DBL_EPSILON);
	assert(fabs(to_24_hour_clock(48)) < DBL_EPSILON);
	assert(fabs(to_24_hour_clock(25) - 1) < DBL_EPSILON);
	assert(fabs(to_24_hour_clock(4) - 4) < DBL_EPSILON);
	assert(fabs(to_24_hour_clock(28.5) - 4.5) < DBL_EPSILON);
	cout << "Tests to_24_hour_clock done" << endl;
		
	assert(get_hours(3800) == 1);
	cout << "Tests get_hours done" << endl;
	assert(get_minutes(3800) == 3);
	cout << "Tests get_minutes done" << endl;
	assert(get_seconds(3800) == 20);
	cout << "Tests get_seconds done" << endl;
		
	assert(fabs(time_to_utc(+0, 12.0) - 12.0) < DBL_EPSILON);
	assert(fabs(time_to_utc(+1, 12.0) - 11.0) < DBL_EPSILON);
	assert(fabs(time_to_utc(-1, 12.0) - 13.0) < DBL_EPSILON);
	assert(fabs(time_to_utc(-11, 18.0) - 5.0) < DBL_EPSILON);
	assert(fabs(time_to_utc(-1, 0.0) - 1.0) < DBL_EPSILON);
	assert(fabs(time_to_utc(-1, 23.0) - 0.0) < DBL_EPSILON);
	cout << "Tests time_to_utc done" << endl;
	
	assert(fabs(time_from_utc(0, 12.0) - 12.0) < DBL_EPSILON);
	assert(fabs(time_from_utc(1, 12.0) - 13.0) < DBL_EPSILON);
	assert(fabs(time_from_utc(-1, 12.0) - 11.0) < DBL_EPSILON);
	assert(fabs(time_from_utc(6, 6.0) - 12.0) < DBL_EPSILON);
	assert(fabs(time_from_utc(-7, 6.0) - 23.0) < DBL_EPSILON);
	assert(fabs(time_from_utc(-1, 0.0) - 23.0) < DBL_EPSILON);
	assert(fabs(time_from_utc(-1, 23.0) - 22.0) < DBL_EPSILON);
	assert(fabs(time_from_utc(1, 23.0)) < DBL_EPSILON);
	cout << "Tests time_from_utc done" << endl;
}
