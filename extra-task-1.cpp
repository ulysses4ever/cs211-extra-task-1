#include <iostream>
#include <assert.h>
#include <cmath>
#include <cfloat> // DBL_EPSILON

using namespace std;

double seconds_difference(double time_1, double time_2)
{
	assert(time_1 >= 0 & time_2 >= 0);
	return time_2 - time_1;
    
    /*    
        Return the number of seconds later that a time in seconds
        time_2 is than a time in seconds time_1.
    */
}

double hours_difference(double time_1, double time_2)
{
	assert(time_1 >= 0 & time_2 >= 0);
	return (time_2 - time_1) / 3600.0;

    /*
        Return the number of hours later that a time in seconds
        time_2 is than a time in seconds time_1.
    */
}

double to_float_hours(int hours, int minutes, int seconds)
{
	assert(hours >= 0 & minutes >= 0 & minutes < 60 & seconds >= 0 & seconds < 60);
	return hours + minutes / 60.0 + seconds / 3600.0;

    /*
        Return the total number of hours in the specified number
        of hours, minutes, and seconds.

        Precondition: 0 <= minutes < 60  and  0 <= seconds < 60
    */
}

double to_24_hour_clock(double hours)
{
	assert(hours >= 0);
	return fmod(hours, 24);

    /*
        hours is a number of hours since midnight. Return the
        hour as seen on a 24-hour clock.
    */
}

int get_hours(int time)
{
	assert(time >= 0);
	return time / 3600;
}

int get_minutes(int time)
{
	assert(time >= 0);
	return time / 60 - 60 * get_hours(time);
}

int get_seconds(int time)
{
	assert(time >= 0);
	return time - (3600 * get_hours(time) + 60 * get_minutes(time));
}

/*
    Implement three functions
        * get_hours
        * get_minutes
        * get_seconds
    They are used to determine the hours part, minutes part and seconds part 
    of a time in seconds.
*/

double time_to_utc(int utc_offset, double time)
{
	assert(time >= 0);
	return (time - utc_offset < 0) ? time - utc_offset + 24 : fmod(time - utc_offset, 24);

    /*
        Return time at UTC+0, where utc_offset is the number of hours away from
        UTC+0.
        You may be interested in:
        https://en.wikipedia.org/wiki/Coordinated_Universal_Time
    */
}

double time_from_utc(int utc_offset, double time)
{
	assert(time >= 0);
	return (time + utc_offset < 0) ? time + utc_offset + 24 : fmod(time + utc_offset, 24);

    /*
        Return UTC time in time zone utc_offset.
    */
}

bool compare_double(double x, double y)
{
	return fabs(x - y) < DBL_EPSILON;
}

int main()
{
	// seconds_difference
	assert(compare_double(seconds_difference(1800.0, 3600.0), 1800.0));
	assert(compare_double(seconds_difference(3600.0, 1800.0), -1800.0));
	assert(compare_double(seconds_difference(1800.0, 2160.0), 360.0));
	assert(compare_double(seconds_difference(1800.0, 1800.0), 0.0));

	// hours_difference
	assert(compare_double(hours_difference(1800.0, 3600.0), 0.5));
	assert(compare_double(hours_difference(3600.0, 1800.0), -0.5));
	assert(compare_double(hours_difference(1800.0, 2160.0), 0.1));
	assert(compare_double(hours_difference(1800.0, 1800.0), 0.0));

	// to_float_hours
	assert(compare_double(to_float_hours(0, 15, 0), 0.25));
	assert(compare_double(to_float_hours(2, 45, 9), 2.7525));
	assert(compare_double(to_float_hours(1, 0, 36), 1.01));

	// to_24_hour_clock
	assert(compare_double(to_24_hour_clock(24), 0));
	assert(compare_double(to_24_hour_clock(48), 0));
	assert(compare_double(to_24_hour_clock(25), 1));
	assert(compare_double(to_24_hour_clock(4), 4));
	assert(compare_double(to_24_hour_clock(28.5), 4.5));

	// get_hours
	assert(get_hours(3800) == 1);

	// get_minutes
	assert(get_minutes(3800) == 3);

	// get_seconds
	assert(get_seconds(3800) == 20);

	// time_to_utc
	assert(compare_double(time_to_utc(+0, 12.0), 12.0));
	assert(compare_double(time_to_utc(+1, 12.0), 11.0));
	assert(compare_double(time_to_utc(-1, 12.0), 13.0));
	assert(compare_double(time_to_utc(-11, 18.0), 5.0));
	assert(compare_double(time_to_utc(-1, 0.0), 1.0));
	assert(compare_double(time_to_utc(-1, 23.0), 0.0));

	// time_from_utc
	assert(compare_double(time_from_utc(+0, 12.0), 12.0));
	assert(compare_double(time_from_utc(+1, 12.0), 13.0));
	assert(compare_double(time_from_utc(-1, 12.0), 11.0));
	assert(compare_double(time_from_utc(+6, 6.0), 12.0));
	assert(compare_double(time_from_utc(-7, 6.0), 23.0));
	assert(compare_double(time_from_utc(-1, 0.0), 23.0));
	assert(compare_double(time_from_utc(-1, 23.0), 22.0));
	assert(compare_double(time_from_utc(+1, 23.0), 0.0));

	cout << "Tests successfully!" << endl;
	system("pause");
}