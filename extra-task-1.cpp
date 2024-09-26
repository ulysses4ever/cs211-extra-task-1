#include <iostream>
#include <cassert> 
#include <cmath>

/*
Return the number of seconds later that a time in seconds
time_2 is than a time in seconds time_1.
*/
double seconds_difference(double time_1, double time_2)
{
	return (time_2 - time_1);
}

/*
Return the number of hours later that a time in seconds
time_2 is than a time in seconds time_1.
*/
double hours_difference(double time_1, double time_2)
{
	return ((time_2 - time_1) / 3600.0);
}

/*
Return the total number of hours in the specified number
of hours, minutes, and seconds.
*/
double to_float_hours(int hours, int minutes, int seconds)
{
	assert((minutes >= 0) && (minutes < 60));
	assert((seconds >= 0) && (seconds < 60));

	return (hours + (minutes / 60.0) + (seconds / 3600.0));
	
}

/*
Return the hour as seen on a 24-hour clock.
*/
double to_24_hour_clock(double hours)
{
	assert(hours >= 0);

	double fractpart, intpart;
	fractpart = modf(hours, &intpart);
	int intpart2 = intpart; // сужающее преобразование

	if (hours < 24)
		return hours;
	else if ((hours > 24) && (hours < 48))
		return (hours - 24);
	else if (intpart2 % 12 == 0)
		return 0; 
}

/*
Next 3 functions used to determine the hours part, minutes part and seconds part
of a time in seconds.
In other words, if 3800 seconds have elapsed since midnight,
it is currently 01:03:20 (hh:mm:ss).
*/

// ~~~ 1 ~~~
double get_hours(double seconds)
{
	double h = 0;
	while (seconds >= 3600)
	{
		h++;
		seconds -= 3600;
	}
	
	return h;
}

// ~~~ 2 ~~~
double get_minutes(double seconds)
{
	double m = 0;
	while (seconds >= 3600)
		seconds -= 3600;
	while (seconds >= 60)
	{
		m++;
		seconds -= 60;
	}

	return m;

}

// ~~~ 3 ~~~
double get_seconds(double seconds)
{
	double s = 0;
	while (seconds >= 3600)
		seconds -= 3600;
	while (seconds >= 60)
		seconds -= 60;

	return seconds;
}

/*
Return time at UTC+0, where utc_offset is the number of hours away from
UTC+0.
*/
double time_to_utc(int utc_offset, double time)
{
	int x = (time - utc_offset);
	return x % 24;
}

/*
Return UTC time in time zone utc_offset.
*/
double time_from_utc(int utc_offset, double time)
{
	int x = (time + utc_offset);
	if (x < 0)
		return (x + 24);
	else return x % 24;
}


int main()
{
	// >>> seconds_difference(1800.0, 3600.0)
	//     1800.0
	assert(seconds_difference(1800.0, 3600.0) == 1800.0);

	// >>> seconds_difference(3600.0, 1800.0)
	//     -1800.0
	assert(seconds_difference(3600.0, 1800.0) == -1800.0);

	// >>> seconds_difference(1800.0, 2160.0)
	//     360.0
	assert(seconds_difference(1800.0, 2160.0) == 360.0);

	// >>> seconds_difference(1800.0, 1800.0)
	//     0.0
	assert(seconds_difference(1800.0, 1800.0) == 0.0);

	// -------------------------------------------------

	// >>> hours_difference(1800.0, 3600.0)
	//     0.5
	assert(hours_difference(1800.0, 3600.0) == 0.5);

	// >>> hours_difference(3600.0, 1800.0)
	//     -0.5
	assert(hours_difference(3600.0, 1800.0) == -0.5);

	// >>> hours_difference(1800.0, 2160.0)
	//     0.1
	assert(hours_difference(1800.0, 2160.0) == 0.1);

	// >>> hours_difference(1800.0, 1800.0)
	//     0.0
	assert(hours_difference(1800.0, 1800.0) == 0.0);

	// -------------------------------------------------

	// >>> to_float_hours(0, 15, 0)
	//     0.25
	assert(fabs(to_float_hours(0, 15, 0) - 0.25) < DBL_EPSILON);

	// >>> to_float_hours(2, 45, 9)
	//     2.7525
	assert(fabs(to_float_hours(2, 45, 9) - 2.7525) < DBL_EPSILON);

	// >>> to_float_hours(1, 0, 36)
	//     1.01
	assert(fabs(to_float_hours(1, 0, 36) - 1.01) < DBL_EPSILON);

	// -------------------------------------------------

	// >>> to_24_hour_clock(24)
	//     0
	assert(to_24_hour_clock(24) == 0);

	// >>> to_24_hour_clock(48)
	//     0
	assert(to_24_hour_clock(48) == 0);

	// >>> to_24_hour_clock(25)
	//	   1
	assert(to_24_hour_clock(25) == 1);

	// >>> to_24_hour_clock(4)
	// 	   4
	assert(to_24_hour_clock(4) == 4);

	// >>> to_24_hour_clock(28.5)
	//     4.5
	assert(fabs(to_24_hour_clock(28.5) - 4.5) < DBL_EPSILON);

	// -------------------------------------------------

	// >>> get_hours(3800)
	//     1
	assert(get_hours(3800) == 1);
	assert(get_hours(1800) == 0);
	assert(get_hours(5000) == 1);

	// >>> get_minutes(3800)
	//     3
	assert(get_minutes(3800) == 3);
	assert(get_minutes(5000) == 23);
	assert(get_minutes(60) == 1);

	// >>> get_seconds(3800)
	//     20
	assert(get_seconds(3800) == 20);
	assert(get_seconds(5000) == 20);
	assert(get_seconds(60) == 0);

	// -------------------------------------------------

	// >>> time_to_utc(+0, 12.0)
	//     12.0
	assert(fabs(time_to_utc(+0, 12.0) - 12.0) < DBL_EPSILON);

	// >>> time_to_utc(+1, 12.0)
	//     11.0
	assert(fabs(time_to_utc(+1, 12.0) - 11.0) < DBL_EPSILON);

	// >>> time_to_utc(-1, 12.0)
	//     13.0
	assert(fabs(time_to_utc(-1, 12.0) - 13.0) < DBL_EPSILON);

	// >>> time_to_utc(-11, 18.0)
	//     5.0
	assert(fabs(time_to_utc(-11, 18.0) - 5.0) < DBL_EPSILON);

	// >>> time_to_utc(-1, 0.0)
	//     1.0
	assert(fabs(time_to_utc(-1, 0.0) - 1.0) < DBL_EPSILON);

	// >>> time_to_utc(-1, 23.0)
	//     0.0
	assert(fabs(time_to_utc(-1, 23.0) - 0.0) < DBL_EPSILON);

	// -------------------------------------------------

	// >>> time_from_utc(+0, 12.0)
	//     12.0
	assert(time_from_utc(+0, 12.0) == 12);

	// >>> time_from_utc(+1, 12.0)
	//     13.0
	assert(time_from_utc(+1, 12.0) == 13);

	// >>> time_from_utc(-1, 12.0)
	//     11.0
	assert(time_from_utc(-1, 12.0) == 11);

	// >>> time_from_utc(+6, 6.0)
	//     12.0
	assert(time_from_utc(+6, 6.0) == 12);

	// >>> time_from_utc(-7, 6.0)
	//     23.0
	assert(time_from_utc(-7, 6.0) == 23);

	// >>> time_from_utc(-1, 0.0)
	//     23.0
	assert(time_from_utc(-1, 0.0) == 23);

	// >>> time_from_utc(-1, 23.0)
	//     22.0
	assert(time_from_utc(-1, 23.0) == 22);

	// >>> time_from_utc(+1, 23.0)
	//     0.0
	assert(time_from_utc(+1, 23.0) == 0);

}