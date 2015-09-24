#include <cmath>
#include <cassert>
#include <cfloat>
#include <stdexcept>

using namespace std;

/*
	Returns the number of seconds later that a time in seconds
	time_2 is than a time in seconds time_1.
*/
double seconds_difference(double time_1, double time_2)
{
	return time_2 - time_1;
}

/*
	Returns the number of hours later that a time in seconds
	time_2 is than a time in seconds time_1.
*/
double hours_difference(double time_1, double time_2)
{
	return (time_2 - time_1) / 3600;
}

/*
	Returns the total number of hours in the specified number
	of hours, minutes, and seconds.
*/
double to_float_hours(int hours, int minutes, int seconds)
{
	if (minutes < 0 || minutes >= 60)
		throw std::range_error("Minutes should be in a range [0, 60).");

	if (seconds < 0 || seconds >= 60)
		throw std::range_error("Seconds should be in a range [0, 60).");

	if (hours < 0)
		throw std::range_error("Hours should be greater than or equal to 0.");

	return hours + static_cast<double>(minutes) / 60 + static_cast<double>(seconds) / 3600;    
}

/*	
	Returns the hour as seen on a 24-hour clock.
	Parameter hours is a number of hours since midnight.
*/
double to_24_hour_clock(double hours)
{
	if (hours < 0)
		throw std::range_error("Hours should be greater than or equal to 0.");

	return fmod(hours, 24);
}

/*
	Determines the hours part of a time in seconds.
*/
int get_hours(double seconds)
{
	if (seconds < 0)
		throw std::range_error("Seconds should be greater than or equal to 0.");

	return static_cast<int>(seconds) / 3600;
}

/*
	Determines the minutes part of a time in seconds.
*/
int get_minutes(double seconds)
{
	if (seconds < 0)
		throw std::range_error("Seconds should be greater than or equal to 0.");

	return (static_cast<int>(seconds) / 60) % 60;
}

/*
	Determines the seconds part of a time in seconds.
*/
int get_seconds(double seconds)
{
	if (seconds < 0)
		throw std::range_error("Seconds should be greater than or equal to 0.");

	return static_cast<int>(seconds) % 60;
}

/*
	Returns time at UTC+0, where utc_offset is the number of hours away from
	UTC+0.
*/
double time_to_utc(int utc_offset, double time)
{
	if (utc_offset < -12 || utc_offset > +14)
		throw std::range_error("UTC offset should be in a range [-12, +14].");

	if (time < 0 || time >= 24)
		throw std::range_error("time value should be in a range [0, 24).");

	return to_24_hour_clock(time - utc_offset + 24);
}

/*
	Returns UTC time in time zone utc_offset.
*/
double time_from_utc(int utc_offset, double time)
{
	if (utc_offset < -12 || utc_offset > +14)
		throw std::range_error("UTC offset should be in a range [-12, +14].");

	if (time < 0 || time >= 24)
		throw std::range_error("time value should be in a range [0, 24).");

	return to_24_hour_clock(time + utc_offset + 24);
}

int main()
{
	// seconds_difference checking
	assert(fabs(seconds_difference(1800.0, 3600.0) - 1800.0) < DBL_EPSILON);
	assert(fabs(seconds_difference(3600.0, 1800.0) + 1800.0) < DBL_EPSILON);
	assert(fabs(seconds_difference(1800.0, 2160.0) - 360.0) < DBL_EPSILON);
	assert(fabs(seconds_difference(1800.0, 1800.0) - 0.0) < DBL_EPSILON);
	
	// to_float_hours checking
	assert(fabs(to_float_hours(0, 15, 0) - 0.25) < DBL_EPSILON);
	assert(fabs(to_float_hours(2, 45, 9) - 2.7525) < DBL_EPSILON);
	assert(fabs(to_float_hours(1, 0, 36) - 1.01) < DBL_EPSILON);

	// hours_difference checking
	assert(fabs(hours_difference(1800.0, 3600.0) - 0.5) < DBL_EPSILON);
	assert(fabs(hours_difference(3600.0, 1800.0) + 0.5) < DBL_EPSILON);
	assert(fabs(hours_difference(1800.0, 2160.0) - 0.1) < DBL_EPSILON);
	assert(fabs(hours_difference(1800.0, 1800.0) - 0.0) < DBL_EPSILON);

	// to_24_hour_clock checking
	assert(fabs(to_24_hour_clock(24) - 0) < DBL_EPSILON);
	assert(fabs(to_24_hour_clock(48) - 0) < DBL_EPSILON);
	assert(fabs(to_24_hour_clock(25) - 1) < DBL_EPSILON);
	assert(fabs(to_24_hour_clock(4) - 4) < DBL_EPSILON);
	assert(fabs(to_24_hour_clock(28.5) - 4.5) < DBL_EPSILON);

	// get_hours, get_minutes, get_seconds checking
	assert(get_hours(3800) == 1);
	assert(get_minutes(3800) == 3);
	assert(get_seconds(3800) == 20);

	// time_to_utc checking
	assert(fabs(time_to_utc(+0, 12.0) - 12.0) < DBL_EPSILON);
	assert(fabs(time_to_utc(+1, 12.0) - 11.0) < DBL_EPSILON);
	assert(fabs(time_to_utc(-1, 12.0) - 13.0) < DBL_EPSILON);
	assert(fabs(time_to_utc(-11, 18.0) - 5.0) < DBL_EPSILON);
	assert(fabs(time_to_utc(-1, 0.0) - 1.0) < DBL_EPSILON);
	assert(fabs(time_to_utc(-1, 23.0) - 0.0) < DBL_EPSILON);

	// time_from_utc checking
	assert(fabs(time_from_utc(+0, 12.0) - 12.0) < DBL_EPSILON);
	assert(fabs(time_from_utc(+1, 12.0) - 13.0) < DBL_EPSILON);
	assert(fabs(time_from_utc(-1, 12.0) - 11.0) < DBL_EPSILON);
	assert(fabs(time_from_utc(+6, 6.0) - 12.0) < DBL_EPSILON);
	assert(fabs(time_from_utc(-7, 6.0) - 23.0) < DBL_EPSILON);
	assert(fabs(time_from_utc(-1, 0.0) - 23.0) < DBL_EPSILON);
	assert(fabs(time_from_utc(-1, 23.0) - 22.0) < DBL_EPSILON);
	assert(fabs(time_from_utc(+1, 23.0) - 0.0) < DBL_EPSILON);
}
