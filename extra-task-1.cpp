#include <iostream>
#include <cassert>
#include <cmath>

using namespace std;

bool AreEqual(double a, double b)
{
	return abs(a - b) < DBL_EPSILON;
}

double seconds_difference(double time_1, double time_2)
{
	assert(time_1 >= 0.0);
	assert(time_2 >= 0.0);

	return time_2 - time_1;	
}

double hours_difference(double time_1, double time_2)
{
	assert(time_1 >= 0.0);
	assert(time_2 >= 0.0);

	return (time_2 - time_1) / 3600;
}


double to_float_hours(int hours, int minutes, int seconds)
{
	assert(hours >= 0);
	assert((0 <= minutes) && (minutes <= 60));
	assert((0 <= seconds) && (seconds <= 60));

	return hours + minutes / 60.0 + seconds / 3600.0;
}

double to_24_hour_clock(double hours)
{
	assert(hours >= 0.0);

	return ((int)trunc(hours)) % 24 + (hours - trunc(hours));
}

double get_hours(double seconds)
{
	assert(seconds >= 0);

	seconds = (int)seconds % 86400;
	return trunc(seconds / 3600);
}


double get_minutes(double seconds)
{
	assert(seconds >= 0);

	seconds = (int)seconds % 86400;
	return trunc((seconds - get_hours(seconds) * 3600) / 60);
}


double get_seconds(double seconds)
{
	assert(seconds >= 0);

	seconds = (int)seconds % 86400;
	return seconds - get_hours(seconds) * 3600 - get_minutes(seconds) * 60;
}


double time_to_utc(int utc_offset, double time)
{
	assert((0.0 <= time) && (time <= 24.0));

	return ((int)(time - utc_offset) % 24) + (time - trunc(time));
}

double time_from_utc(int utc_offset, double time)
{
	assert((0.0 <= time) && (time <= 24.0));

	return (int)(24 + (time + utc_offset)) % 24 + (time - trunc(time));
}

int main()
{
    // Tests for seconds_difference
	assert(AreEqual(seconds_difference(1800.0, 3600.0), 1800.0));
	assert(AreEqual(seconds_difference(3600.0, 1800.0), -1800.0));
	assert(AreEqual(seconds_difference(1800.0, 2160.0), 360.0));
	assert(AreEqual(seconds_difference(1800.0, 1800.0), 0.0));

	// Tests for hours_difference
	assert(AreEqual(hours_difference(1800.0, 3600.0), 0.5));
	assert(AreEqual(hours_difference(3600.0, 1800.0), -0.5));
	assert(AreEqual(hours_difference(1800.0, 2160.0), 0.1));
	assert(AreEqual(hours_difference(1800.0, 1800.0), 0.0));

	// Tests for to_float_hours
	assert(AreEqual(to_float_hours(0, 15, 0), 0.25));
	assert(AreEqual(to_float_hours(2, 45, 9), 2.7525));
	assert(AreEqual(to_float_hours(1, 0, 36), 1.01));

	// Tests for to_24_hour_clock
	assert(AreEqual(to_24_hour_clock(24), 0));
	assert(AreEqual(to_24_hour_clock(48), 0));
	assert(AreEqual(to_24_hour_clock(25), 1));
	assert(AreEqual(to_24_hour_clock(4), 4));
	assert(AreEqual(to_24_hour_clock(28.5), 4.5));

	// Tests for "get" functions
	assert(AreEqual(get_seconds(3800), 20));
	assert(AreEqual(get_minutes(3800), 3));
	assert(AreEqual(get_hours(3800), 1));
	assert(AreEqual(get_seconds(1000000), 40));
	assert(AreEqual(get_minutes(1000000), 46));
	assert(AreEqual(get_hours(1000000), 13));

	// Tests for time_to_utc
	assert(AreEqual(time_to_utc(+0, 12.0), 12.0));
	assert(AreEqual(time_to_utc(+1, 12.0), 11.0));
	assert(AreEqual(time_to_utc(-1, 12.0), 13.0));
	assert(AreEqual(time_to_utc(-11, 18.0), 5.0));
	assert(AreEqual(time_to_utc(-1, 0.0), 1.0));
	assert(AreEqual(time_to_utc(-1, 23.0), 0.0));

	assert(AreEqual(time_to_utc(-1, 12.3), 13.3));
	assert(AreEqual(time_to_utc(+1, 12.3), 11.3));

	// Tests for time_from_utc
	assert(AreEqual(time_from_utc(+0, 12.0), 12.0));
	assert(AreEqual(time_from_utc(+1, 12.0), 13.0));
	assert(AreEqual(time_from_utc(-1, 12.0), 11.0));
	assert(AreEqual(time_from_utc(+6, 6.0), 12.0));
	assert(AreEqual(time_from_utc(-7, 6.0), 23.0));
	assert(AreEqual(time_from_utc(-1, 0.0), 23.0));
	assert(AreEqual(time_from_utc(-1, 23.0), 22.0));
    assert(AreEqual(time_from_utc(+1, 23.0), 0.0));

	assert(AreEqual(time_from_utc(-7, 6.2), 23.2));
	assert(AreEqual(time_from_utc(+6, 6.3), 12.3));
}