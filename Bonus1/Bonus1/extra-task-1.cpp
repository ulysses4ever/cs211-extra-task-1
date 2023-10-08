#include "bonus.h"
#include <cassert>
#include <corecrt_math.h>

double seconds_difference(double time_1, double time_2)
{
	return time_2 - time_1;
}

double hours_difference(double time_1, double time_2)
{
	return (time_2 - time_1) / 3600;
}

double to_float_hours(int hours, int minutes, int seconds)
{
	assert(0 <= minutes && minutes < 60 && 0 <= seconds && seconds < 60);

	return hours + (minutes / 60.0) + (seconds / 3600.0);
}

double to_24_hour_clock(double hours)
{
	assert(hours >= 0);
	double result;
	int Hours = (int)hours;
	double hoursOnClock = hours - Hours;
	result = Hours % 24 + hoursOnClock;

	return result;
}


int get_hours(int seconds)
{
	return seconds / 3600;
}


int get_minutes(int seconds)
{
	return (seconds % 3600) / 60;
}

int get_seconds(int seconds)
{
	return ((seconds % 3600) % 60) % 60;
}


double time_to_utc(int utc_offset, double time)
{
	return fmod(time - utc_offset, 24.0);
}

double time_from_utc(int utc_offset, double time)
{
	return to_24_hour_clock((time + utc_offset) > 0 ? (time + utc_offset) : 24 + (time + utc_offset));
}
