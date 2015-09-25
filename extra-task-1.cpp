#include <cassert>
#include <cmath>
#include <cfloat>

const double day = 24.0;

bool areEquals(double x, double y) {
	return fabs(x - y) < DBL_EPSILON;
}

double seconds_difference(double time_1, double time_2)
{
	return time_2 - time_1;
}

double hours_difference(double time_1, double time_2)
{
	return (time_2 / 3600) - (time_1 / 3600);
}

double to_float_hours(int hours, int minutes, int seconds)
{
	assert((minutes >= 0) && (minutes < 60));
	assert((seconds >= 0) && (seconds < 60));
	return hours + (double(minutes) / 60) + (double(seconds) / 3600);
}

double to_24_hour_clock(double hours)
{
	assert(hours >= 0);
	return (int)hours % 24 + (hours - trunc(hours));
}

int get_hours(int seconds) {
	assert(seconds >= 0);
	return seconds / 3600;
}

int get_minutes(int seconds) {
	assert(seconds >= 0);
	return (seconds / 60) % 60;
}

int get_seconds(int seconds) {
	assert(seconds >= 0);
	return seconds % 60;
}

double time_to_utc(int utc_offset, double time)
{
	assert((utc_offset <= 14) && (utc_offset >= -12));
	assert((trunc(time) >= 0) && (trunc(time) <= 23));
	double mins = time - trunc(time);
	double newT = trunc(time) - utc_offset;
	return newT > 0 ? (int)newT % 24 + mins : day + (int)newT % 24 + mins;
}

double time_from_utc(int utc_offset, double time)
{
	assert((utc_offset <= 14) && (utc_offset >= -12));
	assert((trunc(time) >= 0) && (trunc(time) <= 23));
	double mins = time - trunc(time);
	double newT = trunc(time) + utc_offset;
	return newT > 0 ? (int)newT % 24 + mins : day + (int)newT % 24 + mins;
}

int main() {
	//seconds_difference tests
	assert(areEquals(seconds_difference(1800.0, 3600.0), 1800.0) && ("test #1.1"));
	assert(areEquals(seconds_difference(3600.0, 1800.0), -1800.0) && ("test #1.2"));
	assert(areEquals(seconds_difference(1800.0, 2160.0), 360.0) && ("test #1.3"));
	assert(areEquals(seconds_difference(1800.0, 1800.0), 0.0) && ("test #1.4"));

	//hours_difference tests
	assert(areEquals(hours_difference(1800.0, 3600.0), 0.5) && ("test #2.1"));
	assert(areEquals(hours_difference(3600.0, 1800.0), -0.5) && ("test #2.2"));
	assert(areEquals(hours_difference(1800.0, 2160.0), 0.1) && ("test #2.3"));
	assert(areEquals(hours_difference(1800.0, 1800.0), 0.0) && ("test #2.4"));

	//to_float_hours tests
	assert(areEquals(to_float_hours(0, 15, 0), 0.25) && ("test #3.1"));
	assert(areEquals(to_float_hours(2, 45, 9), 2.7525) && ("test #3.2"));
	assert(areEquals(to_float_hours(1, 0, 36), 1.01) && ("test #3.3"));

	//to_24_hour_clock tests
	assert(areEquals(to_24_hour_clock(24), 0) && ("test #4.1"));
	assert(areEquals(to_24_hour_clock(48), 0) && ("test #4.2"));
	assert(areEquals(to_24_hour_clock(25), 1) && ("test #4.3"));
	assert(areEquals(to_24_hour_clock(4), 4) && ("test #4.4"));
	assert(areEquals(to_24_hour_clock(28.5), 4.5) && ("test #4.5"));

	//get_hours tests
	assert((get_hours(3800) == 1) && ("test #5.1"));
	assert((get_hours(2400) == 0) && ("test #5.2"));
	assert((get_hours(10000) == 2) && ("test #5.3"));

	//get_minutes tests
	assert((get_minutes(3800) == 3) && ("test #6.1"));
	assert((get_minutes(50) == 0) && ("test #6.2"));
	assert((get_minutes(70) == 1) && ("test #6.3"));

	//get_seconds tests
	assert((get_seconds(3800) == 20) && ("test #7.1"));
	assert((get_seconds(0) == 0) && ("test #7.2"));
	assert((get_seconds(1) == 1) && ("test #7.3"));

	//time_to_utc tests
	assert(areEquals(time_to_utc(0, 12.0), 12.0) && ("test #8.1"));
	assert(areEquals(time_to_utc(1, 12.0), 11.0) && ("test #8.2"));
	assert(areEquals(time_to_utc(-1, 12.0), 13.0) && ("test #8.3"));
	assert(areEquals(time_to_utc(-11, 18.0), 5.0) && ("test #8.4"));
	assert(areEquals(time_to_utc(-1, 0.0), 1.0) && ("test #8.5"));
	assert(areEquals(time_to_utc(-1, 23.0), 0.0) && ("test #8.6"));

	//time_from_utc tests
	assert(areEquals(time_from_utc(0, 12.0), 12.0) && ("test #9.1"));
	assert(areEquals(time_from_utc(1, 12.0), 13.0) && ("test #9.2"));
	assert(areEquals(time_from_utc(-1, 12.0), 11.0) && ("test #9.3"));
	assert(areEquals(time_from_utc(6, 6.0), 12.0) && ("test #9.4"));
	assert(areEquals(time_from_utc(-7, 6.0), 23.0) && ("test #9.5"));
	assert(areEquals(time_from_utc(-1, 0.0), 23.0) && ("test #9.6"));
	assert(areEquals(time_from_utc(-1, 23.0), 22.0) && ("test #9.7"));
	assert(areEquals(time_from_utc(1, 23.0), 0.0) && ("test #9.8"));
}