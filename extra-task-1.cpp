#include <assert.h>

//Return the number of seconds later that a time in seconds
double seconds_difference(double time_1, double time_2)
{
	return time_2 - time_1;
}

//Return the number of hours later that a time in seconds
double hours_difference(double time_1, double time_2)
{
	return (time_2 - time_1) / 3600.0;
}

//Return the total number of hours in the specified number of hours, minutes, and seconds.
double to_float_hours(int hours, int minutes, int seconds)
{
	assert(0.0 <= minutes < 60.0 && 0.0 <= seconds < 60.0);
	return (hours * 3600.0 + minutes * 60.0 + seconds) / 3600.0;


}


//Return the hour as seen on a 24 - hour clock.
double to_24_hour_clock(double hours)
{
	assert(hours >= 0);
	if (hours >= 0 && hours <= 23)
	{
		return hours;
	}
	else return hours - 24.0 * (int)(hours / 24);
	
}


/*Implement three functions
		* get_hours
		* get_minutes
		* get_seconds*/

int get_hours(double seconds)
{
	assert(seconds >= 0);
	return (int)(seconds / 3600);
}

int get_minutes(double seconds)
{
	assert(seconds >= 0);
	if (seconds >= 3600)
	{
		return (int)((seconds - 3600) / 60);
	}
	else return (int)(seconds / 60);
}

int get_seconds(double seconds)
{
	assert(seconds >= 0);
	return seconds - 3600.0 * get_hours(seconds) - 60.0 * get_minutes(seconds);

}


//Return time at UTC+0, where utc_offset is the number of hours away from UTC + 0.
double time_to_utc(int utc_offset, double time)
{
	if (time + (-1) * utc_offset >= 24)
	{
		return time + (-1) * utc_offset - 24;
	}
	else return time + (-1) * utc_offset;
	
}


//Return UTC time in time zone utc_offset.
double time_from_utc(int utc_offset, double time)
{
	if (time + utc_offset >= 24)
	{
		return time + utc_offset - 24;
	}
	else if (time + utc_offset < 0)
		return 24 + time + utc_offset;
	else
		return time + utc_offset;
}
