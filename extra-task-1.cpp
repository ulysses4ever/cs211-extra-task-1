#include <assert.h>
#include <float.h>
#include <cmath>

/// <summary>
/// Return the number of seconds later that a time in seconds
///time_2 is than a time in seconds time_1.
/// </summary>
inline double seconds_difference(double time_1, double time_2)
{
	return time_2 - time_1;
}

/// <summary>
/// Return the number of hours later that a time in seconds
///time_2 is than a time in seconds time_1.
/// </summary>
inline double hours_difference(double time_1, double time_2)
{
	return seconds_difference(time_1, time_2) / 3600;
}

/// <summary>
/// Return the total number of hours in the specified number
/// of hours, minutes, and seconds.
/// </summary>
inline double to_float_hours(int hours, int minutes, int seconds)
{
	assert(minutes >= 0 && minutes < 60 && seconds >= 0 && seconds < 60);
	return hours + minutes / 60.0 + seconds / 3600.0;
}

/// <summary>
/// hours is a number of hours since midnight. Return the
/// hour as seen on a 24 - hour clock.
/// </summary>
inline double to_24_hour_clock(double hours)
{
	assert(hours >= 0);
	return (int)hours % 24 + hours - floor(hours);
}

/// <summary>
/// returns number of hours passed after the closest midnight
/// </summary>
inline int get_hours(int seconds)
{
	assert(seconds >= 0);
	return seconds / 3600 % 24;
}

/// <summary>
/// returns number of minutes passed after the closest integer number of hours
/// </summary>
inline int get_minutes(int seconds)
{
	assert(seconds >= 0);
	return seconds / 60 % 60;
}

/// <summary>
/// returns number of seconds passed after the closest integer number of minutes
/// </summary>
inline int get_seconds(int seconds)
{
	assert(seconds >= 0);
	return seconds % 60;
}

/// <summary>
/// Return time at UTC+0, where utc_offset is the number of hours away from
/// UTC + 0.
/// </summary>
inline double time_to_utc(int utc_offset, double time)
{
	assert(fabs(utc_offset) < 24 && time >= 0 && time < 24);
	double raw_time{ time - utc_offset };
	return ((int)(raw_time) % 24) + raw_time - floor(raw_time);
}

double time_from_utc(int utc_offset, double time)
{
	/*
		Return UTC time in time zone utc_offset.

		>>> time_from_utc(+0, 12.0)
		12.0

		>>> time_from_utc(+1, 12.0)
		13.0

		>>> time_from_utc(-1, 12.0)
		11.0

		>>> time_from_utc(+6, 6.0)
		12.0

		>>> time_from_utc(-7, 6.0)
		23.0

		>>> time_from_utc(-1, 0.0)
		23.0

		>>> time_from_utc(-1, 23.0)
		22.0

		>>> time_from_utc(+1, 23.0)
		0.0
	*/
	return 0;
}

int main()
{
	// Тесты функции seconds_difference
	assert(fabs(seconds_difference(1800.0, 3600.0) - 1800.0) < DBL_EPSILON);
	assert(fabs(seconds_difference(3600.0, 1800.0) - (-1800.0)) < DBL_EPSILON);
	assert(fabs(seconds_difference(1800.0, 2160.0) - 360.0) < DBL_EPSILON);
	assert(fabs(seconds_difference(1800.0, 1800.0) - 0.0) < DBL_EPSILON);

	// Тесты функции hours_difference
	assert(fabs(hours_difference(1800.0, 3600.0) - 0.5) < DBL_EPSILON);
	assert(fabs(hours_difference(3600.0, 1800.0) - (-0.5)) < DBL_EPSILON);
	assert(fabs(hours_difference(1800.0, 2160.0) - 0.1) < DBL_EPSILON);
	assert(fabs(hours_difference(1800.0, 1800.0) - 0.0) < DBL_EPSILON);

	// Тесты функции to_float_hours
	assert(fabs(to_float_hours(0, 15, 0) - 0.25) < DBL_EPSILON);
	assert(fabs(to_float_hours(2, 45, 9) - 2.7525) < DBL_EPSILON);
	assert(fabs(to_float_hours(1, 0, 36) - 1.01) < DBL_EPSILON);

	// Тесты функции to_24_hour_clock
	assert(fabs(to_24_hour_clock(24) - 0) < DBL_EPSILON);
	assert(fabs(to_24_hour_clock(48) - 0) < DBL_EPSILON);
	assert(fabs(to_24_hour_clock(25) - 1) < DBL_EPSILON);
	assert(fabs(to_24_hour_clock(4) - 4) < DBL_EPSILON);
	assert(fabs(to_24_hour_clock(28.5) - 4.5) < DBL_EPSILON);

	// Тесты функции get_hours
	assert(get_hours(3800) == 1);
	assert(get_hours(7200) == 2);
	assert(get_hours(90000) == 1);
	assert(get_hours(0) == 0);

	// Тесты функции get_minutes
	assert(get_minutes(3800) == 3);
	assert(get_minutes(100) == 1);
	assert(get_minutes(7200) == 0);
	assert(get_minutes(19500) == 25);

	// Тесты функции get_seconds
	assert(get_seconds(3800) == 20);
	assert(get_seconds(250) == 10);
	assert(get_seconds(7200) == 0);
	assert(get_seconds(19500) == 0);
	assert(get_seconds(90942) == 42);

	// Тесты функции time_to_utc
	assert(fabs(time_to_utc(+0, 12.0) - 12.0) < DBL_EPSILON);
	assert(fabs(time_to_utc(+1, 12.0) - 11.0) < DBL_EPSILON);
	assert(fabs(time_to_utc(-1, 12.0) - 13.0) < DBL_EPSILON);
	assert(fabs(time_to_utc(-11, 18.0) - 5.0) < DBL_EPSILON);
	assert(fabs(time_to_utc(-1, 0.0) - 1.0) < DBL_EPSILON);
	assert(fabs(time_to_utc(-1, 23.0) - 0.0) < DBL_EPSILON);
}