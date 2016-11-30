#include <cassert>
#include <cmath>
#include <cfloat>

using namespace std;

// Returns the number of seconds later that a time in seconds
// time_2 is than a time in seconds time_1.
double seconds_difference(double time_1, double time_2)
{
	return(time_2 - time_1);
}

// Returns the number of hours later that a time in seconds
// time_2 is than a time in seconds time_1.
double hours_difference(double time_1, double time_2)
{
	return((time_2 - time_1) / 3600.0);
	}

// Returns the total number of hours in the specified number
// of hours, minutes, and seconds.
double to_float_hours(int hours, int minutes, int seconds)
{

	assert((seconds >= 0) && (seconds <= 60), "TO_FLOAT_HOURS: seconds out of range");
	assert((minutes >= 0) && (minutes <= 60), "TO_FLOAT_HOURS: minutes out of range");

	return(hours + (double)minutes / 60 + (double)seconds / 3600);
}

// Returns total number of hours since midnight 
// as seen on a 24-hour clock
double to_24_hour_clock(double hours)
{

	assert(hours >= 0, "TO_24_HOUR_CLOCK: hours out of range");

	return(int)trunc(hours) % 24 + hours - trunc(hours);
}

// Returns hour part of a time in seconds
int get_hours(int seconds)
{
	assert(seconds >= 0, "GET_HOURS: seconds out of range");
	return(seconds / 3600);
}

// Returns minute part of a time in seconds
int get_minutes(int seconds)
{
	assert(seconds >= 0, "GET_MINUTES: seconds out of range");
	return((seconds % 3600) / 60);
}

// Returns second part of a time in seconds
int get_seconds(int seconds)
{
	assert(seconds >= 0, "GET_SECONDS: seconds out of range");
	return((seconds % 3600) % 60);
}

// Returns time at UTC +0, where utc_offset is the number of hours away from UTC +0      
double time_to_utc(int utc_offset, double time)
{
	assert(time >= 0.0 && time < 24.00, "TIME_TO_UTC: time out of range");
	double t = time - utc_offset;
	double tm = (int)trunc(t) % 24 + t - trunc(t);
	if (tm < 0.0)
		tm += 24;
	return tm;
}

// Returns UTC time in time zone utc_offset.
double time_from_utc(int utc_offset, double time)
{
	assert(time >= 0.0 && time < 24.00, "TIME_FROM_UTC: time out of range");
	double t = time + utc_offset;
	double utc0time = (int)trunc(t) % 24 + t - trunc(t);
	if (utc0time < 0)
		utc0time += 24;
	return utc0time;
}

int main()
{

	// SECONDS_DIFFERENCE TESTS:
	assert(abs(seconds_difference(1800.0, 3600.0) - 1800.0) < DBL_EPSILON, "seconds_difference: test #1");
	assert(abs(seconds_difference(3600.0, 1800.0) - -1800.0) < DBL_EPSILON, "seconds_difference: test #2");
	assert(abs(seconds_difference(1800.0, 2160.0) - 360.0) < DBL_EPSILON, "seconds_difference: test #3");
	assert(abs(seconds_difference(1800.0, 1800.0) - 0.0) < DBL_EPSILON, "seconds_difference: test #4");

	// HOURS_DIFFERENCE TESTS:
	assert(abs(hours_difference(1800.0, 3600.0) - 0.5) < DBL_EPSILON, "hours_difference: test #1");
	assert(abs(hours_difference(3600.0, 1800.0) - -0.5) < DBL_EPSILON, "hours_difference: test #2");
	assert(abs(hours_difference(1800.0, 2160.0) - 0.1) < DBL_EPSILON, "hours_difference: test #3");
	assert(abs(hours_difference(1800.0, 1800.0) - 0.0) < DBL_EPSILON, "hours_difference: test #4");

	//TO_FLOAT_HOURS TESTS:
	assert(abs(to_float_hours(0, 15, 0) - 0.25) < DBL_EPSILON, "to_float_hours: test #1");
	assert(abs(to_float_hours(2, 45, 9) - 2.7525) < DBL_EPSILON, "to_float_hours: test #2");
	assert(abs(to_float_hours(1, 0, 36) - 1.01) < DBL_EPSILON, "to_float_hours: test #3");

	//TO_24_HOUR_CLOCK TESTS:
	assert(abs(to_24_hour_clock(24.0) - 0.0) < DBL_EPSILON, "to_24_hour_clock: test #1");
	assert(abs(to_24_hour_clock(48.0) - 0.0) < DBL_EPSILON, "to_24_hour_clock: test #2");
	assert(abs(to_24_hour_clock(25.0) - 1.0) < DBL_EPSILON, "to_24_hour_clock: test #3");
	assert(abs(to_24_hour_clock(4.0) - 4.0) < DBL_EPSILON, "to_24_hour_clock: test #4");
	assert(abs(to_24_hour_clock(28.5) - 4.5) < DBL_EPSILON, "to_24_hour_clock: test #5");

	//GET_HOURS TESTS:
	assert(get_hours(3600) == 1, "get_hours: test #1");
	assert(get_hours(9032) == 2, "get_hours: test #2");
	assert(get_hours(73) == 0, "get_hours: test #3");
	assert(get_hours(0) == 0, "get_hours: test #4");
	assert(get_hours(3800) == 1, "get_hours: test #5");

	//GET_MINUTES TESTS:
	assert(get_minutes(3800) == 3, "get_minutes: test #1");
	assert(get_minutes(3600) == 0, "get_minutes: test #2");
	assert(get_minutes(9032) == 30, "get_minutes: test #3");
	assert(get_minutes(73) == 1, "get_minutes: test #4");
	assert(get_minutes(0) == 0, "get_minutes: test #5");

	//GET_SECONDS TESTS:
	assert(get_seconds(3800) == 20, "get_seconds: test #1");
	assert(get_seconds(3600) == 0, "get_seconds: test #2");
	assert(get_seconds(9032) == 32, "get_seconds: test #3");
	assert(get_seconds(73) == 13, "get_seconds: test #4");
	assert(get_seconds(0) == 0, "get_seconds: test #5");

	//TIME_TO_UTC TESTS:
	assert(abs(time_to_utc(+0, 12.0) - 12.0) < DBL_EPSILON, "time_to_utc: test #1");
	assert(abs(time_to_utc(+1, 12.0) - 11.0) < DBL_EPSILON, "time_to_utc: test #2");
	assert(abs(time_to_utc(-1, 12.0) - 13.0) < DBL_EPSILON, "time_to_utc: test #3");
	assert(abs(time_to_utc(-11, 18.0) - 5.0) < DBL_EPSILON, "time_to_utc: test #4");
	assert(abs(time_to_utc(-1, 0.0) - 1.0) < DBL_EPSILON, "time_to_utc: test #5");
	assert(abs(time_to_utc(-1, 23.0) - 0.0) < DBL_EPSILON, "time_to_utc: test #6");
	assert(abs(time_to_utc(+7, 3.0) - 20.0) < DBL_EPSILON, "time_to_utc: test #7");
	
	//TIME_FROM_UTC TESTS:
	assert(abs(time_from_utc(+0, 12.0) - 12.0) < DBL_EPSILON, "time_from_utc: test #1");
	assert(abs(time_from_utc(+1, 12.0) - 13.0) < DBL_EPSILON, "time_from_utc: test #2");
	assert(abs(time_from_utc(-1, 12.0) - 11.0) < DBL_EPSILON, "time_from_utc: test #3");
	assert(abs(time_from_utc(+6, 6.0) - 12.0) < DBL_EPSILON, "time_from_utc: test #4");
	assert(abs(time_from_utc(-7, 6.0) - 23.0) < DBL_EPSILON, "time_from_utc: test #5");
	assert(abs(time_from_utc(-1, 0.0) - 23.0) < DBL_EPSILON, "time_from_utc: test #6");
	assert(abs(time_from_utc(-1, 23.0) - 22.0) < DBL_EPSILON, "time_from_utc: test #7");
	assert(abs(time_from_utc(+1, 23.0) - 0.0) < DBL_EPSILON, "time_from_utc: test #8");

}


