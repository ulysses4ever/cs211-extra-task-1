#include <iostream>
#include <cassert>

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
	return seconds_difference(time_1, time_2) / 3600;
}

/*
Return the total number of hours in the specified number
of hours, minutes, and seconds.
*/
double to_float_hours(int hours, int minutes, int seconds)
{
	return hours + minutes / (double)60 + seconds / (double)3600;
}

/*
hours is a number of hours since midnight. Return the
hour as seen on a 24-hour clock.
*/
double to_24_hour_clock(double hours)
{
	while (hours >= 24)
		hours -= 24;
	return hours;
}

/*
They are used to determine the hours part of a time in seconds.
*/
int get_hours(int number)
{
	return number / 3600;
}

/*
They are used to determine the minutes part of a time in seconds.
*/
int get_minutes(int number)
{
	return (number - get_hours(number) * 3600) / 60;
}

/*
They are used to determine the seconds part of a time in seconds.
*/
int get_seconds(int number)
{
	return number - get_hours(number) * 3600 - get_minutes(number) * 60;
}

/*
Return time at UTC+0, where utc_offset is the number of hours away from
UTC+0.
*/
double time_to_utc(int utc_offset, double time)
{
	double new_time = time - utc_offset;
	new_time += new_time < 0 ? 24 : 0;
	return to_24_hour_clock(new_time);
}

/*
Return UTC time in time zone utc_offset.
*/
double time_from_utc(int utc_offset, double time)
{
	return time_to_utc(-utc_offset, time);
}

int main()
{
	assert(abs(seconds_difference(1800.0, 3600.0) - 1800.0) < DBL_EPSILON);
	assert(abs(seconds_difference(3600.0, 1800.0) - -1800.0) < DBL_EPSILON);
	assert(abs(seconds_difference(1800.0, 2160.0) - 360.0) < DBL_EPSILON);
	assert(abs(seconds_difference(1800.0, 1800.0) - 0.0) < DBL_EPSILON);

	assert(abs(hours_difference(1800.0, 3600.0) - 0.5) < DBL_EPSILON);
	assert(abs(hours_difference(3600.0, 1800.0) - -0.5) < DBL_EPSILON);
	assert(abs(hours_difference(1800.0, 2160.0) - 0.1) < DBL_EPSILON);
	assert(abs(hours_difference(1800.0, 1800.0) - 0.0) < DBL_EPSILON);

	assert(abs(to_float_hours(0, 15, 0) - 0.25) < DBL_EPSILON);
	assert(abs(to_float_hours(2, 45, 9) - 2.7525) < DBL_EPSILON);
	assert(abs(to_float_hours(1, 0, 36) - 1.01) < DBL_EPSILON);

	assert(abs(to_24_hour_clock(24) - 0.0) < DBL_EPSILON);
	assert(abs(to_24_hour_clock(48) - 0.0) < DBL_EPSILON);
	assert(abs(to_24_hour_clock(25) - 1.0) < DBL_EPSILON);
	assert(abs(to_24_hour_clock(4) - 4.0) < DBL_EPSILON);
	assert(abs(to_24_hour_clock(28.5) - 4.5) < DBL_EPSILON);

	assert(get_hours(3800) == 1);
	assert(get_minutes(3800) == 3);
	assert(get_seconds(3800) == 20);

	assert(abs(time_to_utc(+0, 12.0) - 12.0) < DBL_EPSILON);
	assert(abs(time_to_utc(+1, 12.0) - 11.0) < DBL_EPSILON);
	assert(abs(time_to_utc(-1, 12.0) - 13.0) < DBL_EPSILON);
	assert(abs(time_to_utc(-11, 18.0) - 5.0) < DBL_EPSILON);
	assert(abs(time_to_utc(-1, 0.0) - 1.0) < DBL_EPSILON);
	assert(abs(time_to_utc(-1, 23.0) - 0.0) < DBL_EPSILON);

	assert(abs(time_from_utc(+0, 12.0) - 12.0) < DBL_EPSILON);
	assert(abs(time_from_utc(+1, 12.0) - 13.0) < DBL_EPSILON);
	assert(abs(time_from_utc(-1, 12.0) - 11.0) < DBL_EPSILON);
	assert(abs(time_from_utc(+6, 6.0) - 12.0) < DBL_EPSILON);
	assert(abs(time_from_utc(-7, 6.0) - 23.0) < DBL_EPSILON);
	assert(abs(time_from_utc(-1, 0.0) - 23.0) < DBL_EPSILON);
	assert(abs(time_from_utc(-1, 23.0) - 22.0) < DBL_EPSILON);
	assert(abs(time_from_utc(+1, 23.0) - 0.0) < DBL_EPSILON);
}
