#include <cassert>
#include <cmath>
#include <cfloat>
//Return the number of seconds later that a time in seconds time_2 is than a time in seconds time_1.
double seconds_difference(double time_1, double time_2)
{
    // your implementation goes here...
	return time_2 - time_1;
}

//Return the number of hours later that a time in seconds time_2 is than a time in seconds time_1.
double hours_difference(double time_1, double time_2)
{
	return seconds_difference(time_1, time_2) / 3600.0;
}

//Return the total number of hours in the specified number of hours, minutes, and seconds.
double to_float_hours(int hours, int minutes, int seconds)
{
	assert(0 <= minutes && minutes < 60);
	assert(0 <= seconds && seconds < 60);
	return hours + minutes / 60.0 + seconds / 3600.0;
}

//hours is a number of hours since midnight. Return the hour as seen on a 24 - hour clock.
double to_24_hour_clock(double hours)
{
	assert(hours > 0);
	int tr = trunc(hours);
	return hours < 24 ? hours : (int)(fabs(24 - tr)) % 24 + (hours - tr);
}
/*
	Implement three functions
		* get_hours
		* get_minutes
		* get_seconds
	They are used to determine the hours part, minutes part and seconds part
	of a time in seconds. */

int get_hours(int sec)
{
	return sec / 3600;
}
int get_minutes(int sec)
{
	return  (sec % 3600) / 60;
}
int get_seconds(int sec)
{
	return (sec % 3600) % 60;
}

//	Return time at UTC+0, where utc_offset is the number of hours away from UTC + 0.
double time_to_utc(int utc_offset, double time)
{
	int tr = trunc(time);
	return (int)(fabs(tr - utc_offset)) % 24 + (time - (double)tr);
}

// Return UTC time in time zone utc_offset.
double time_from_utc(int utc_offset, double time)
{
	int tr = trunc(time);
	return (24 + utc_offset + tr) % 24 + (time - (double)tr);
}

int main()
{
	assert(fabs(seconds_difference(1800.0, 3600.0) - 1800.0) < DBL_EPSILON);
	assert(fabs(seconds_difference(3600.0, 1800.0) - -1800.0) < DBL_EPSILON);
	assert(fabs(seconds_difference(1800.0, 2160.0) - 360.0) < DBL_EPSILON);
	assert(fabs(seconds_difference(1800.0, 1800.0) - 0.0) < DBL_EPSILON);


	assert(fabs(hours_difference(1800.0, 3600.0) - 0.5) < DBL_EPSILON);
	assert(fabs(hours_difference(3600.0, 1800.0) - -0.5) < DBL_EPSILON);
	assert(fabs(hours_difference(1800.0, 2160.0) - 0.1) < DBL_EPSILON);
	assert(fabs(hours_difference(1800.0, 1800.0) -0.0) < DBL_EPSILON);


	assert(fabs(to_float_hours(0, 15, 0) - 0.25) < DBL_EPSILON);
	assert(fabs(to_float_hours(2, 45, 9) - 2.7525)< DBL_EPSILON);
	assert(fabs(to_float_hours(1, 0, 36) - 1.01) < DBL_EPSILON);


	assert(fabs(to_24_hour_clock(24) - 0) < DBL_EPSILON);
	assert(fabs( to_24_hour_clock(48) - 0) < DBL_EPSILON);
	assert(fabs( to_24_hour_clock(25) - 1) < DBL_EPSILON);
	assert(fabs( to_24_hour_clock(4) - 4) < DBL_EPSILON);
	assert(fabs(to_24_hour_clock(28.5) - 4.5) < DBL_EPSILON);
	assert(fabs(to_24_hour_clock(48.5) - 0.5) < DBL_EPSILON);


	assert(get_hours(3800) == 1);
	assert(get_minutes(3800) == 3);
	assert(get_seconds(3800) == 20);

	assert(get_hours(12573) == 3);
	assert(get_minutes(12573) == 29);
	assert(get_seconds(12573) == 33);

	assert(get_hours(13) == 0);
	assert(get_minutes(13) == 0);
	assert(get_seconds(13) == 13);

	assert(get_hours(63) == 0);
	assert(get_minutes(63) == 1);
	assert(get_seconds(63) == 3);

	assert(get_hours(7200) == 2);
	assert(get_minutes(7200) == 0);
	assert(get_seconds(7200) == 0);

	assert(fabs(time_to_utc(+0, 12.0) - 12.0) < DBL_EPSILON);
	assert(fabs(time_to_utc(+1, 12.0) - 11.0) < DBL_EPSILON);
	assert(fabs(time_to_utc(-1, 12.0) - 13.0) < DBL_EPSILON);
	assert(fabs(time_to_utc(-11, 18.0) -5.0) < DBL_EPSILON);
	assert(fabs(time_to_utc(-1, 0.0) - 1.0) < DBL_EPSILON);
	assert(fabs(time_to_utc(-1, 23.0) - 0.0) < DBL_EPSILON);
	assert(fabs(time_to_utc(-1, 23.5) - 0.5) < DBL_EPSILON);
	assert(fabs(time_to_utc(+1, 22.5) - 21.5) < DBL_EPSILON);


	assert(fabs(time_from_utc(+0, 12.0) - 12.0) < DBL_EPSILON);
	assert(fabs(time_from_utc(+1, 12.0) - 13.0) < DBL_EPSILON);
	assert(fabs(time_from_utc(-1, 12.0) - 11.0) < DBL_EPSILON);
	assert(fabs(time_from_utc(+6, 6.0) - 12.0) < DBL_EPSILON);
	assert(fabs(time_from_utc(-7, 6.0) - 23.0) < DBL_EPSILON);
	assert(fabs(time_from_utc(-1, 0.0) - 23.0) < DBL_EPSILON);
	assert(fabs(time_from_utc(-1, 23.0)- 22.0) < DBL_EPSILON);
	assert(fabs(time_from_utc(+1, 23.0) -0.0) < DBL_EPSILON);
}