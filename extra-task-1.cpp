#include <iostream>
#include <cassert>
#include <cmath>
using namespace std;

//Return the number of seconds later that a time in seconds
//time_2 is than a time in seconds time_1.
double seconds_difference(double time_1, double time_2)
{
	return time_2 - time_1;
}

//Return the number of hours later that a time in seconds
//time_2 is than a time in seconds time_1.
double hours_difference(double time_1, double time_2)
{
		return (time_2 - time_1) / 3600;
}

       
//	Return the total number of hours in the specified number
//of hours, minutes, and seconds.
double to_float_hours(int hours, int minutes, int seconds)
{
	assert(0 <= minutes && minutes < 60 && 0 <= seconds && seconds < 60);
	return hours + minutes / 60 + seconds / 3600;
}

//hours is a number of hours since midnight. Return the hour as seen on a 24-hour clock.
double to_24_hour_clock(double hours)
{
		int x = ceil(hours);
		return x % 24 + hours - x;
}

//They are used to determine the hours part of a time in seconds
int get_hours(int time)
{
	return time / 3600;
}

//They are used to determine the minutes part of a time in seconds
int get_minutes(int time)
{
	return (time % 3600) / 60;
}

//They are used to determine the seconds part of a time in seconds
int get_seconds(int time)
{
	return time % 60;
}

//	Return time at UTC+0, where utc_offset is the number of hours away from UTC + 0.
double time_to_utc(int utc_offset, double time)
{
	int x = ceil(time); //������������, ����� ��������� ������� �����
	return (x - utc_offset) % 24 + time - x;
}

//Return UTC time in time zone utc_offset.
double time_from_utc(int utc_offset, double time)
{
		int x = ceil(time);//������������, ����� ��������� ������� �����
		return (x + utc_offset + 24) % 24 + time - x;
}

int main()
{
	//��������� ������ seconds_difference
	assert((seconds_difference(1800.0, 3600.0) - 1800) < DBL_EPSILON && "test-1");
	assert((seconds_difference(3600.0, 1800.0) + 1800) < DBL_EPSILON && "test-2");
	assert((seconds_difference(1800.0, 2160.0) - 360) < DBL_EPSILON && "test-3");
	assert(seconds_difference(1800.0, 1800.0) < DBL_EPSILON && "test-4");

	//��������� ������ hours_difference
	assert((hours_difference(1800.0, 3600.0) - 0.5) < DBL_EPSILON && "test-5");
	assert((hours_difference(3600.0, 1800.0) + 0.5) < DBL_EPSILON && "test-6");
	assert((hours_difference(1800.0, 2160.0) - 0.1) < DBL_EPSILON && "test-7");
	assert(hours_difference(1800.0, 1800.0) < DBL_EPSILON && "test-8");

	//��������� ������ to_float_hours
	assert((to_float_hours(0, 15, 0) - 0.25) < DBL_EPSILON && "test-9");
	assert((to_float_hours(2, 45, 9) - 2.7525) < DBL_EPSILON && "test-10");
	assert((to_float_hours(1, 0, 36) - 1.01) < DBL_EPSILON && "test-11");

	// ��������� ������ to_24_hour_clock
	assert(to_24_hour_clock(24) < DBL_EPSILON && "test-12");
	assert(to_24_hour_clock(48) < DBL_EPSILON && "test-13");
	assert((to_24_hour_clock(25) - 1) < DBL_EPSILON && "test-14");
	assert((to_24_hour_clock(4) - 4) < DBL_EPSILON && "test-15");
	assert((to_24_hour_clock(28.5) - 4.5) < DBL_EPSILON && "test-16");

	//��������� ������ get_hours, get_minutes, get_seconds
	assert((get_hours(3800) - 1) < DBL_EPSILON && "test-17");
	assert((get_minutes(3800) - 3) < DBL_EPSILON && "test-18");
	assert((get_seconds(3800) - 120) < DBL_EPSILON && "test-19");

	//��������� ������ time_to_utc
	assert((time_to_utc(+0, 12.0) - 12) < DBL_EPSILON && "test-20");
	assert((time_to_utc(+1, 12.0) - 11) < DBL_EPSILON && "test-21");
	assert((time_to_utc(-1, 12.0) - 13) < DBL_EPSILON && "test-22");
	assert((time_to_utc(-11, 18.0) - 5) < DBL_EPSILON && "test-23");
	assert((time_to_utc(-1, 0.0) - 1) < DBL_EPSILON && "test-24");
	assert((time_to_utc(-1, 23.0) - 0.0) < DBL_EPSILON && "test-25");

	//��������� ������ time_from_utc
	assert((time_from_utc(+0, 12.0) - 12) < DBL_EPSILON && "test-26");
	assert((time_from_utc(+1, 12.0) - 13) < DBL_EPSILON && "test-27");
	assert((time_from_utc(-1, 12.0) - 11) < DBL_EPSILON && "test-28");
	assert((time_from_utc(+6, 6.0) - 12) < DBL_EPSILON && "test-29");
	assert((time_from_utc(-7, 6.0) - 23) < DBL_EPSILON && "test-30");
	assert((time_from_utc(-1, 0.0) - 23) < DBL_EPSILON && "test-31");
	assert((time_from_utc(-1, 23.0) - 22) < DBL_EPSILON && "test-32");
	assert(time_from_utc(+1, 23.0) < DBL_EPSILON && "test-26");
}