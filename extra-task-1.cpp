#include "Extra.h"
#include <assert.h>
double seconds_difference(double time_1, double time_2)
{
    return (time_2 - time_1);
}

double hours_difference(double time_1, double time_2)
{
    return (fabs(time_2 - time_1)) / 3600.0; 
}

double to_float_hours(int hours, int minutes, int seconds)
{
    assert((minutes < 60) && (minutes >= 0));
	assert((seconds < 60) && (seconds >= 0));
	return (hours + (minutes / 60.0) + (seconds / 3600.0));  
}

double to_24_hour_clock(double hours)
{
    assert(hours >= 0);
	return fmod(hours, 24);
}

//Три новые функции
int get_hours(int sec)
{
	return sec / 3600;
}

int get_minutes(int sec)
{
	return (sec - (3600 * get_hours(sec))) / 60;
}

int get_seconds(int sec)
{
	return (sec - (3600 * get_hours(sec)) - (60 * get_minutes(sec)));
}

double time_to_utc(int utc_offset, double time)
{
    return time - utc_offset >= 24 ? fmod(time - utc_offset, 24) : time - utc_offset;
}

double time_from_utc(int utc_offset, double time)
{
	double a = time;
	if (time + utc_offset < 0)
		a += 24;
	return a + utc_offset >= 24 ? fmod(a + utc_offset, 24) : a + utc_offset;
}
