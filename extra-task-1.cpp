#include<cmath>
double seconds_difference(double time_1, double time_2)
{
    // your implementation goes here...
	return time_2 - time_1;
    /*    
        Return the number of seconds later that a time in seconds
        time_2 is than a time in seconds time_1.
    */

}

double hours_difference(double time_1, double time_2)
{
	return (time_2 - time_1) / 3600;
    /*
        Return the number of hours later that a time in seconds
        time_2 is than a time in seconds time_1.
    */
}

double to_float_hours(int hours, int minutes, int seconds)
{
	return hours + minutes / 60.0 + seconds / 3600.0;
    /*
        Return the total number of hours in the specified number
        of hours, minutes, and seconds.

        Precondition: 0 <= minutes < 60  and  0 <= seconds < 60
    */
}

double to_24_hour_clock(double hours)
{
	double t = trunc(hours);
	return remainder(t, 24) + hours - t;
    /*
        hours is a number of hours since midnight. Return the
        hour as seen on a 24-hour clock.
    */
}

/*
    Implement three functions
        * get_hours
        * get_minutes
        * get_seconds
    They are used to determine the hours part, minutes part and seconds part 
    of a time in seconds.

    If 3800 seconds have elapsed since midnight, 
    it is currently 01:03:20 (hh:mm:ss).
*/

int get_hours(int sec)
{
	return sec / 3600;
}

int get_minutes(int sec)
{
	int t = sec % 3600;
	return t / 60;
}

int get_seconds(int sec)
{
	int t = sec % 3600;
	return t % 60;
}

double time_to_utc(int utc_offset, double time)
{
	return int(trunc(time - utc_offset)) % 24;
    /*
        Return time at UTC+0, where utc_offset is the number of hours away from
        UTC+0.
        You may be interested in:
        https://en.wikipedia.org/wiki/Coordinated_Universal_Time
    */
}

double time_from_utc(int utc_offset, double time)
{
	return (int(trunc(time + utc_offset)) + 24) % 24;
    /*
        Return UTC time in time zone utc_offset.
    */
}

#include <cassert>
#include <cfloat>
using namespace std;

int main()
{
	// seconds_difference
		assert(fabs(seconds_difference(1800, 3600) - 1800) < DBL_EPSILON && "test-1-1");
		assert(fabs(seconds_difference(3600, 1800) - -1800) < DBL_EPSILON && "test-1-2");
		assert(fabs(seconds_difference(1800, 2160) - 360) < DBL_EPSILON && "test-1-3");
		assert(fabs(seconds_difference(1800, 1800)) < DBL_EPSILON && "test-1-4");
	// hours_difference
		assert(fabs(hours_difference(1800, 3600) - 0.5) < DBL_EPSILON && "test-2-1");
		assert(fabs(hours_difference(3600, 1800) - -0.5) < DBL_EPSILON && "test-2-2");
		assert(fabs(hours_difference(1800, 2160) - 0.1) < DBL_EPSILON && "test-2-3");
		assert(fabs(hours_difference(1800, 1800)) < DBL_EPSILON && "test-2-4");
	// to_float_hours
		assert(fabs(to_float_hours(0, 15, 0) - 0.25) < DBL_EPSILON && "test-3-1");
		assert(fabs(to_float_hours(2, 45, 9) - 2.7525) < DBL_EPSILON && "test-3-2");
		assert(fabs(to_float_hours(1, 0, 36) - 1.01) < DBL_EPSILON && "test-3-3");
	// to_24_hour_clock
		assert(fabs(to_24_hour_clock(24)) < DBL_EPSILON && "test-4-1");
		assert(fabs(to_24_hour_clock(48)) < DBL_EPSILON && "test-4-2");
		assert(fabs(to_24_hour_clock(25) - 1) < DBL_EPSILON && "test-4-3");
		assert(fabs(to_24_hour_clock(4) - 4) < DBL_EPSILON && "test-4-4");
		assert(fabs(to_24_hour_clock(28.5) - 4.5) < DBL_EPSILON && "test-4-5");
	// get_hours
		assert(fabs(get_hours(3800)) == 1 && "test-5-1");
	// get_minutes
		assert(fabs(get_minutes(3800)) == 3 && "test-6-1");
	// get_seconds
		assert(fabs(get_seconds(3800)) == 20 && "test-7-1");
	// time_to_utc
		assert(fabs(time_to_utc(0, 12) - 12) < DBL_EPSILON && "test-8-1");
		assert(fabs(time_to_utc(1, 12) - 11) < DBL_EPSILON && "test-8-2");
		assert(fabs(time_to_utc(-1, 12) - 13) < DBL_EPSILON && "test-8-3");
		assert(fabs(time_to_utc(-11, 18) - 5) < DBL_EPSILON && "test-8-4");
		assert(fabs(time_to_utc(-1, 0) - 1) < DBL_EPSILON && "test-8-5");
		assert(fabs(time_to_utc(-1, 23)) < DBL_EPSILON && "test-8-6");
	// time_from_utc
		assert(fabs(time_from_utc(0, 12) - 12) < DBL_EPSILON && "test-9-1");
		assert(fabs(time_from_utc(1, 12) - 13) < DBL_EPSILON && "test-9-2");
		assert(fabs(time_from_utc(-1, 12) - 11) < DBL_EPSILON && "test-9-3");
		assert(fabs(time_from_utc(6, 6) - 12) < DBL_EPSILON && "test-9-4");
		assert(fabs(time_from_utc(-7, 6) - 23) < DBL_EPSILON && "test-9-5");
		assert(fabs(time_from_utc(-1, 0) - 23) < DBL_EPSILON && "test-9-6");
		assert(fabs(time_from_utc(-1, 23) - 22) < DBL_EPSILON && "test-9-7");
		assert(fabs(time_from_utc(1, 23)) < DBL_EPSILON && "test-9-8");
}
	
