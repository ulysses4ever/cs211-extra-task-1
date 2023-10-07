#include "extra-task-1.h"
#include <cassert>

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
	assert(0 <= minutes && minutes < 60);
	assert(0 <= seconds && seconds < 60);
	return (double)hours + (double)(minutes / 60.0) + (double)(seconds / 3600.0);
}

double to_24_hour_clock(double hours)
{
	assert(hours >= 0);
	return (hours - 12 * (int)(hours / 12));
}

int get_hours(int seconds)
{
	return seconds / 3600;
}

int get_minutes(int seconds)
{
	return (seconds - (get_hours(seconds) * 3600)) / 60;
}

int get_seconds(int seconds)
{
	return seconds - (get_hours(seconds) * 3600) - (get_minutes(seconds) * 60);
}

double time_to_utc(int utc_offset, double time)
{
	double utc_time = time - utc_offset;
	while (utc_time < 0) {
		utc_time += 24;
	}
	while (utc_time >= 24) {
		utc_time -= 24;
	}
	return utc_time;
}

double time_from_utc(int utc_offset, double time)
{
	double local_time = time + utc_offset;
	while (local_time < 0) {
		local_time += 24;
	}
	while (local_time >= 24) {
		local_time -= 24;
	}
	return local_time;
}
