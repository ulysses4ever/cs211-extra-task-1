#include <iostream>;
#include <locale>;
#include <cassert>;
#include <cmath>;

using namespace std;

const double dbl_epsilon = 0.001;

/* Return the number of seconds later that a time in seconds
time_2 is than a time in seconds time_1. */
double seconds_difference(double time_1, double time_2)
{
	return (time_2 - time_1);
}

/* Return the number of hours later that a time in seconds
time_2 is than a time in seconds time_1. */
double hours_difference(double time_1, double time_2)
{
	return((time_2 - time_1) / 3600);

}

/* Return the total number of hours in the specified number
of hours, minutes, and seconds. */
double to_float_hours(int hours, int minutes, int seconds)
{
	return ((hours * 3600.0 + minutes * 60.0 + seconds) / 3600);
}

/* hours is a number of hours since midnight. Return the hour as seen on a 24-hour clock. */
double to_24_hour_clock(double hours)
{
	assert(hours >= 0);
	return fmod(hours + 24.0, 24);
}

/*
    Implement three functions
        * get_hours
        * get_minutes
        * get_seconds
    They are used to determine the hours part, minutes part and seconds part 
    of a time in seconds. E.g.:

    >>> get_hours(3800)
    1

    >>> get_minutes(3800)
    3

    >>> get_seconds(3800)
    20

    In other words, if 3800 seconds have elapsed since midnight, 
    it is currently 01:03:20 (hh:mm:ss).
*/

/* Return time at UTC+0, where utc_offset is the number of hours away from UTC+0. */
double time_to_utc(int utc_offset, double time)
{
	if (time > 12)
		return(time - utc_offset - 24);
	else
		return to_24_hour_clock((24 - (utc_offset + time)));
}
/* Return UTC time in time zone utc_offset. */
double time_from_utc(int utc_offset, double time)
{
    
	return to_24_hour_clock(24 + (time + utc_offset));
}

int main()
{
	std::locale::global(std::locale(""));

	// seconds_difference
	assert(abs(seconds_difference(1800.0, 3600.0) - 1800.0) < DBL_EPSILON);
	assert(abs(seconds_difference(3600.0, 1800.0) + 1800.0) < DBL_EPSILON);
	assert(abs(seconds_difference(1800.0, 2160.0) - 360.0) < DBL_EPSILON);
	assert(abs(seconds_difference(1800.0, 1800.0) - 0.0) < DBL_EPSILON);
	cout << "Tests for seconds_difference were successfully passed" << endl;

	// hours_difference
	assert(abs(hours_difference(1800.0, 3600.0) - 0.5) < DBL_EPSILON);
	assert(abs(hours_difference(3600.0, 1800.0) + 0.5) < DBL_EPSILON);
	assert(abs(hours_difference(1800.0, 2160.0) - 0.1) < DBL_EPSILON);
	assert(abs(hours_difference(1800.0, 1800.0) - 0.0) < DBL_EPSILON);
	cout << "Tests for hours_difference were successfully passed" << endl;

	// to_float_hours
	assert(abs(to_float_hours(0, 15, 0) - 0.25) < DBL_EPSILON);
	assert(abs(to_float_hours(2, 45, 9) - 2.7525) < DBL_EPSILON);
	assert(abs(to_float_hours(1, 0, 36) - 1.01) < DBL_EPSILON);
	cout << "Tests for to_float_hours were successfully passed" << endl;

	// to_24_hour_clock
	assert(abs(to_24_hour_clock(24) - 0) < DBL_EPSILON);
	assert(abs(to_24_hour_clock(48) - 0) < DBL_EPSILON);
	assert(abs(to_24_hour_clock(25) - 1) < DBL_EPSILON);
	assert(abs(to_24_hour_clock(4) - 4) < DBL_EPSILON);
	assert(abs(to_24_hour_clock(28.5) - 4.5) < DBL_EPSILON);
	cout << "Tests for to_24_hour_clock were successfully passed" << endl;

	// time_to_utc
	assert(abs(time_to_utc(+0, 12.0) - 12.0) < DBL_EPSILON);
	assert(abs(time_to_utc(+1, 12.0) - 11.0) < DBL_EPSILON);
	assert(abs(time_to_utc(-1, 12.0) - 13.0) < DBL_EPSILON);
	assert(abs(time_to_utc(-11, 18.0) - 5.0) < DBL_EPSILON);
	assert(abs(time_to_utc(-1, 0.0) - 1.0) < DBL_EPSILON);
	assert(abs(time_to_utc(-1, 23.0) - 0.0) < DBL_EPSILON);
	cout << "Tests for time_to_utc were successfully passed" << endl;

	// time_from_utc
	assert(abs(time_from_utc(+0, 12.0) - 12.0) < DBL_EPSILON);
	assert(abs(time_from_utc(+1, 12.0) - 13.0) < DBL_EPSILON);
	assert(abs(time_from_utc(-1, 12.0) - 11.0) < DBL_EPSILON);
	assert(abs(time_from_utc(+6, 6.0) - 12.0) < DBL_EPSILON);
	assert(abs(time_from_utc(-7, 6.0) - 23.0) < DBL_EPSILON);
	assert(abs(time_from_utc(-1, 0.0) - 23.0) < DBL_EPSILON);
	assert(abs(time_from_utc(-1, 23.0) - 22.0) < DBL_EPSILON);
	assert(abs(time_from_utc(+1, 23.0) - 0.0) < DBL_EPSILON);
	cout << "Tests for time_to_utc were successfully passed" << endl;
}