#include <iostream>
#include <assert.h>
#include <cfloat> // for using DBL_EPSILON

using namespace std;

double seconds_difference(double time_1, double time_2)
{
	//Return the number of seconds later that a time in seconds
	//time_2 is than a time in seconds time_1.
	return time_2 - time_1;
}

double hours_difference(double time_1, double time_2)
{
	/*
	Return the number of hours later that a time in seconds
	time_2 is than a time in seconds time_1.
	*/
	return seconds_difference(time_1, time_2) / 3600.0;
}

double to_float_hours(int hours, int minutes, int seconds)
{
	assert(minutes < 60);
	assert(minutes >= 0);
	assert(seconds < 60);
	assert(seconds >= 0);
	/*
	Return the total number of hours in the specified number
	of hours, minutes, and seconds.
	*/
	return hours + minutes / 60.0 + seconds / 3600.0;
}

double to_24_hour_clock(double hours)
{
	/*
	hours is a number of hours since midnight. Return the
	hour as seen on a 24-hour clock.
	*/
	assert(hours >= 0);

	int int_hours = floor(hours) / 24;
	return hours - int_hours * 24;
}

/*
Implement three functions
* get_hours
* get_minutes
* get_seconds
They are used to determine the hours part, minutes part and seconds part
of a time in seconds. E.g.:

In other words, if 3800 seconds have elapsed since midnight,
it is currently 01:03:20 (hh:mm:ss).
*/

int get_hours(int seconds)
{
	return seconds / 3600;
}

int get_minutes(int seconds)
{
	return (seconds / 60) % 60;
}

int get_seconds(int seconds)
{
	return seconds % 60;
}

double to_abs_24_hour_clock(double hours) //вспомогательная функция для двух последующих
{
	while (hours < 0)
	{
		hours = hours + 24;
	}

	int int_hours = floor(hours) / 24;
	return hours - int_hours * 24;
}

double time_to_utc(int utc_offset, double time)
{
	/*
	Return time at UTC+0, where utc_offset is the number of hours away from
	UTC+0.
	*/
	return to_abs_24_hour_clock(time - utc_offset);
}

double time_from_utc(int utc_offset, double time)
{
	//Return UTC time in time zone utc_offset.

	return to_abs_24_hour_clock(time + utc_offset);
}

bool compare_double(double x, double y)
{
	return fabs(x - y) < DBL_EPSILON;
}

int main()
{   
	//tests for seconds_difference
	assert(compare_double(seconds_difference(1800.0, 3600.0), 1800.0) && "test 1");
	assert(compare_double(seconds_difference(3600.0, 1800.0), -1800.0) && "test 2");
	assert(compare_double(seconds_difference(1800.0, 2160.0), 360.0) && "test 3");
	assert(compare_double(seconds_difference(1800.0, 1800.0), 0.0) && "test 4");
	
	//tests for hours_difference
	assert(compare_double(hours_difference(1800.0, 3600.0), 0.5) && "test 5");
	assert(compare_double(hours_difference(3600.0, 1800.0), -0.5) && "test 6");
	assert(compare_double(hours_difference(1800.0, 2160.0), 0.1) && "test 7");
	assert(compare_double(hours_difference(1800.0, 1800.0), 0.0) && "test 8");

	//tests for to_float_hours
	assert(compare_double(to_float_hours(0, 15, 0), 0.25) && "test 9");
	assert(compare_double(to_float_hours(2, 45, 9), 2.7525) && "test 10");
	assert(compare_double(to_float_hours(1, 0, 36), 1.01) && "test 11");

	//tests for to_24_hour_clock
	assert(compare_double(to_24_hour_clock(24), 0) && "test 12");
	assert(compare_double(to_24_hour_clock(48), 0) && "test 13");
	assert(compare_double(to_24_hour_clock(25), 1) && "test 14");
	assert(compare_double(to_24_hour_clock(4), 4) && "test 15");
	assert(compare_double(to_24_hour_clock(28.5), 4.5) && "test 16");

	//tests for "three functions"
	assert((get_hours(3800) == 1) && "test 17");
	assert((get_minutes(3800) == 3) && "test 18");
	assert((get_seconds(3800) == 20) && "test 19");

	//tests for time_to_utc
	assert(compare_double(time_to_utc(+0, 12.0), 12.0) && "test 20");
	assert(compare_double(time_to_utc(+1, 12.0), 11.0) && "test 21");
	assert(compare_double(time_to_utc(-1, 12.0), 13.0) && "test 22");
	assert(compare_double(time_to_utc(-11, 18.0), 5.0) && "test 23");
	assert(compare_double(time_to_utc(-1, 0.0), 1.0) && "test 24");
	assert(compare_double(time_to_utc(-1, 23.0), 0.0) && "test 25");

	//tests for time_from_utc
	assert(compare_double(time_from_utc(+0, 12.0), 12.0) && "test 26");
	assert(compare_double(time_from_utc(+1, 12.0), 13.0) && "test 27");
	assert(compare_double(time_from_utc(-1, 12.0), 11.0) && "test 28");
	assert(compare_double(time_from_utc(+6, 6.0), 12.0) && "test 29");
	assert(compare_double(time_from_utc(-7, 6.0), 23.0) && "test 30");
	assert(compare_double(time_from_utc(-1, 0.0), 23.0) && "test 31");
	assert(compare_double(time_from_utc(-1, 23.0), 22.0) && "test 32");
	assert(compare_double(time_from_utc(+1, 23.0), 0.0) && "test 33");

	system("pause");
}