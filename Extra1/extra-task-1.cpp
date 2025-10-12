#include "extra-task-1.h"

double seconds_difference(double time_1, double time_2)
{
	return time_2 - time_1;
}

double hours_difference(double time_1, double time_2)
{
	return seconds_difference(time_1, time_2) / 3600.0;
}

double to_float_hours(int hours, int minutes, int seconds)
{
	assert(0 <= minutes && minutes < 60 && 0 <= seconds && seconds < 60);
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
    return to_24_hour_clock(seconds / 3600);
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
	assert(0.0 <= time && time < 24.0);
	double result = time - utc_offset;
    result = fmod(result, 24.0);
    if (result < 0)
        result += 24.0;
	return result;
}

double time_from_utc(int utc_offset, double time)
{
	assert(0.0 <= time && time < 24.0);
    double result = time + utc_offset;
    result = fmod(result, 24.0);
    if (result < 0)
        result += 24.0;
    return result;
}
