#include <cmath>
#include <assert.h>
#include <cfloat>

/// <summary>
///  Return the number of seconds later that a time in seconds
///  time_2 is than a time in seconds time_1.
/// </summary>
/// <param name="time_1"></param>
/// <param name="time_2"></param>
/// <returns></returns>
double seconds_difference(double time_1, double time_2)
{
	return time_2 - time_1;
}
/// <summary>
/// Return the number of hours later that a time in seconds
/// time_2 is than a time in seconds time_1.
/// </summary>
/// <param name="time_1"></param>
/// <param name="time_2"></param>
/// <returns></returns>
double hours_difference(double time_1, double time_2)
{
	return (time_2 - time_1) / 3600.0;
}
/// <summary>
/// Return the total number of hours in the specified number
/// of hours, minutes, and seconds.
/// </summary>
/// <param name="hours"></param>
/// <param name="minutes"></param>
/// <param name="seconds"></param>
/// <returns></returns>
double to_float_hours(int hours, int minutes, int seconds)
{
	assert(minutes >= 0);
	assert(minutes < 60);
	assert(seconds >= 0);
	assert(seconds < 60);
	return hours + minutes / 60.0 + seconds / 3600.0;

}
/// <summary>
/// hours is a number of hours since midnight. Return the
/// hour as seen on a 24 - hour clock.
/// </summary>
/// <param name="hours"></param>
/// <returns></returns>
double to_24_hour_clock(double hours)
{
	assert(hours >= 0);
	return fmod(hours, 24.0);

}

/// <summary>
/// determine the hours part of a time in seconds.
/// </summary>
/// <param name="seconds"></param>
/// <returns></returns>
int get_hours(int seconds)
{
	return seconds / 3600;
}
/// <summary>
/// determine the minutes part of a time in seconds.
/// </summary>
/// <param name="seconds"></param>
/// <returns></returns>
int get_minutes(int seconds)
{
	return (seconds % 3600) / 60;
}
/// <summary>
/// determine the seconds part of a time in seconds.
/// </summary>
/// <param name="seconds"></param>
/// <returns></returns>
int get_seconds(int seconds)
{
	return seconds % 60;
}

/// <summary>
/// Return time at UTC+0, where utc_offset is the number of hours away from UTC + 0.
/// </summary>
/// <param name="utc_offset"></param>
/// <param name="time"></param>
/// <returns></returns>
double time_to_utc(int utc_offset, double time)
{
	return fmod(time - utc_offset + 24.0, 24.0);
}
/// <summary>
/// Return UTC time in time zone utc_offset.
/// </summary>
/// <param name="utc_offset"></param>
/// <param name="time"></param>
/// <returns></returns>
double time_from_utc(int utc_offset, double time)
{
	return fmod(time + utc_offset + 24.0, 24.0);
}

int main()
{
	// Тесты для seconds_difference
	assert(fabs(seconds_difference(1800.0, 3600.0) - 1800.0) < DBL_EPSILON);
	assert(fabs(seconds_difference(3600.0, 1800.0) - (-1800.0)) < DBL_EPSILON);
	assert(fabs(seconds_difference(1800.0, 2160.0) - 360.0) < DBL_EPSILON);
	assert(fabs(seconds_difference(1800.0, 1800.0) - 0.0) < DBL_EPSILON);

	// Тесты для hours_difference
	assert(fabs(hours_difference(1800.0, 3600.0) - 0.5) < DBL_EPSILON);
	assert(fabs(hours_difference(3600.0, 1800.0) - (-0.5)) < DBL_EPSILON);
	assert(fabs(hours_difference(1800.0, 2160.0) - 0.1) < DBL_EPSILON);
	assert(fabs(hours_difference(1800.0, 1800.0) - 0.0) < DBL_EPSILON);

	// Тесты для to_float_hours
	assert(fabs(to_float_hours(0, 15, 0) - 0.25) < DBL_EPSILON);
	assert(fabs(to_float_hours(2, 45, 9) - 2.7525) < DBL_EPSILON);
	assert(fabs(to_float_hours(1, 0, 36) - 1.01) < DBL_EPSILON);

	// Тесты для to_24_hour_clock
	assert(fabs(to_24_hour_clock(24) - 0) < DBL_EPSILON);
	assert(fabs(to_24_hour_clock(48) - 0) < DBL_EPSILON);
	assert(fabs(to_24_hour_clock(25) - 1) < DBL_EPSILON);
	assert(fabs(to_24_hour_clock(4) - 4) < DBL_EPSILON);
	assert(fabs(to_24_hour_clock(28.5) - 4.5) < DBL_EPSILON);

	// Тесты для get_hours, get_minutes, get_seconds
	assert(get_hours(3800) == 1);
	assert(get_minutes(3800) == 3);
	assert(get_seconds(3800) == 20);

	// Тесты для time_from_utc
	assert(fabs(time_from_utc(0, 12.0) - 12.0) < DBL_EPSILON);
	assert(fabs(time_from_utc(1, 12.0) - 13.0) < DBL_EPSILON);
	assert(fabs(time_from_utc(-1, 12.0) - 11.0) < DBL_EPSILON);
	assert(fabs(time_from_utc(6, 6.0) - 12.0) < DBL_EPSILON);
	assert(fabs(time_from_utc(-7, 6.0) - 23.0) < DBL_EPSILON);
	assert(fabs(time_from_utc(-1, 0.0) - 23.0) < DBL_EPSILON);
	assert(fabs(time_from_utc(-1, 23.0) - 22.0) < DBL_EPSILON);
	assert(fabs(time_from_utc(1, 23.0) - 0.0) < DBL_EPSILON);

	// Тесты для time_to_utc
	assert(fabs(time_to_utc(0, 12.0) - 12.0) < DBL_EPSILON);
	assert(fabs(time_to_utc(1, 12.0) - 11.0) < DBL_EPSILON);
	assert(fabs(time_to_utc(-1, 12.0) - 13.0) < DBL_EPSILON);
	assert(fabs(time_to_utc(-11, 18.0) - 5.0) < DBL_EPSILON);
	assert(fabs(time_to_utc(-1, 0.0) - 1.0) < DBL_EPSILON);
	assert(fabs(time_to_utc(-1, 23.0) - 0.0) < DBL_EPSILON);
}