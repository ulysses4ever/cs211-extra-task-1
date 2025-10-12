#include <assert.h>
#include <cmath>

double seconds_difference(double time_1, double time_2)
{
	assert(time_1 > 0 && time_2 > 0);
	return time_2 - time_1;
}

double hours_difference(double time_1, double time_2)
{
	assert(time_1 > 0 && time_2 > 0);
	return (time_2 - time_1) / 3600.0;
}

double to_float_hours(int hours, int minutes, int seconds)
{
	assert(minutes >= 0 && minutes < 60 && seconds >= 0 && seconds < 60);
	return hours + minutes / 60.0 + seconds / 3600.0;
}

double to_24_hour_clock(double hours)
{
	assert(hours >= 0);
	return fmod(hours, 24.0);
}

int get_hours(int seconds)
{
	assert(seconds >= 0);
	return seconds / 3600;
}

int get_minutes(int seconds)
{
	assert(seconds >= 0);
	return (seconds % 3600) / 60;
}

int get_seconds(int seconds)
{
	assert(seconds >= 0);
	return seconds % 60;
}

double time_to_utc(int utc_offset, double time)
{
	double res = time - utc_offset;
	if (res < 0)
		res += 24;

	return fmod(res, 24.0);
}

double time_from_utc(int utc_offset, double time)
{
	double res = time + utc_offset;
	if (res < 0)
		res += 24;

	return fmod(res, 24.0);
}
