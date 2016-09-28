#include <cassert>
#include <cmath>

const double DBL_EPS = 0.000000000001;


double seconds_difference(double time_1, double time_2)
{
    /*
        Return the number of seconds later that a time in seconds
        time_2 is than a time in seconds time_1.
    */
	return time_2 - time_1;
}

double hours_difference(double time_1, double time_2)
{
    /*
        Return the number of hours later that a time in seconds
        time_2 is than a time in seconds time_1.
    */
	return (time_2 - time_1) / 3600.0;
}

double to_float_hours(int hours, int minutes, int seconds)
{
    /*
        Return the total number of hours in the specified number
        of hours, minutes, and seconds.
        Precondition: 0 <= minutes < 60  and  0 <= seconds < 60
    */
	assert(0 <= minutes < 60);
	assert(0 <= seconds < 60);

	return hours + minutes / 60.0 + seconds / 3600.0;

}

double to_24_hour_clock(double hours)
{
    /*
        hours is a number of hours since midnight. Return the
        hour as seen on a 24-hour clock.
        Precondition: hours >= 0
        You may wish to inspect various function in <cmath> to work
        with integer and fractional part of a hours separately.
    */
	assert(hours >= 0);
    int countFullDays = floor(hours)/24;
	return hours - countFullDays * 24;
}

/*
    Implement three functions
        * get_hours
        * get_minutes
        * get_seconds
    They are used to determine the hours part, minutes part and seconds part
    of a time in seconds. E.g.:

    In other words, if 3800 seconds have elapsed since midnight,
    it is currently 01:03:20 (hh:mm:ss).
*/

int get_hours(long seconds)
{
    assert(seconds >= 0);
    return seconds / 3600;
}

int get_minutes(long seconds)
{
    assert(seconds >= 0);
    return (seconds / 60) % 60;;
}

int get_seconds(long seconds)
{
    assert(seconds >= 0);
    return seconds % 60;
}

double time_to_utc(int utc_offset, double time)
{
    /*
        Return time at UTC+0, where utc_offset is the number of hours away from
        UTC+0.
        You may be interested in:
        https://en.wikipedia.org/wiki/Coordinated_Universal_Time
    */
    assert(std::abs(utc_offset) <= 12);

    double absTime = 48 + time - utc_offset;
    return to_24_hour_clock(absTime);
}

double time_from_utc(int utc_offset, double time)
{
    /*
        Return UTC time in time zone utc_offset.
    */
    return time_to_utc(-utc_offset, time);
}


int main(){
        //seconds_difference
        assert(fabs(seconds_difference(1800.0, 3600.0) - 1800.0)  < DBL_EPS && "test-1");
        assert(fabs(seconds_difference(3600.0, 1800.0) + 1800.0)  < DBL_EPS && "test-2");
        assert(fabs(seconds_difference(1800.0, 2160.0) -  360.0)  < DBL_EPS && "test-3");
        assert(fabs(seconds_difference(1800.0, 1800.0)         )  < DBL_EPS&& "test-4");

        //hours_difference
        assert(fabs(hours_difference(1800.0, 3600.0) - 0.5)  < DBL_EPS && "test-5");
        assert(fabs(hours_difference(3600.0, 1800.0) + 0.5)  < DBL_EPS && "test-6");
        assert(fabs(hours_difference(1800.0, 2160.0) - 0.1)  < DBL_EPS && "test-7");
        assert(fabs(hours_difference(1800.0, 1800.0)      )  < DBL_EPS && "test-8");

        //to_float_hours
        assert(fabs(to_float_hours(0, 15, 0) -  0.25) < DBL_EPS && "test-9");
        assert(fabs(to_float_hours(2, 45, 9) -  2.7525) < DBL_EPS && "test-10");
        assert(fabs(to_float_hours(1, 0, 36) -  1.01) < DBL_EPS && "test-11");

        //to_24_hour_clock
        assert(fabs(to_24_hour_clock(24)) < DBL_EPS && "test-12");
        assert(fabs(to_24_hour_clock(48)) < DBL_EPS && "test-13");
        assert(fabs(to_24_hour_clock(25) - 1) < DBL_EPS && "test-14");
        assert(fabs(to_24_hour_clock(4) - 4) < DBL_EPS && "test-15");
        assert(fabs(to_24_hour_clock(28.5) - 4.5) < DBL_EPS && "test-16");

        //get_hours , minutes, seconds
        assert(1 == get_hours(3800) && "test-17");
        assert(3 == get_minutes(3800) && "test-18");
        assert(20 == get_seconds(3800) && "test-19");

        //time_to_utc
        assert(fabs(time_to_utc(+0, 12.0) -  12.0) < DBL_EPS && "test-20");
        assert(fabs(time_to_utc(+1, 12.0) -  11.0) < DBL_EPS && "test-21");
        assert(fabs(time_to_utc(-1, 12.0) -  13.0) < DBL_EPS && "test-22");
        assert(fabs(time_to_utc(-11, 18.0) -  5.0) < DBL_EPS && "test-23");
        assert(fabs(time_to_utc(-1, 0.0) -  1.0) < DBL_EPS && "test-24");

        //time_from_utc
        assert(fabs(time_from_utc(+0, 12.0) -  12.0) < DBL_EPS && "test-26");
        assert(fabs(time_from_utc(+1, 12.0) -  13.0) < DBL_EPS && "test-27");
        assert(fabs(time_from_utc(-1, 12.0) -  11.0) < DBL_EPS && "test-28");
        assert(fabs(time_from_utc(+6, 6.0) -  12.0) < DBL_EPS && "test-29");
        assert(fabs(time_from_utc(-7, 6.0) -  23.0) < DBL_EPS && "test-30");
        assert(fabs(time_from_utc(-1, 0.0) -  23.0) < DBL_EPS && "test-31");
        assert(fabs(time_from_utc(-1, 23.0) -  22.0) < DBL_EPS && "test-32");
        assert(fabs(time_from_utc(+1, 23.0)         ) < DBL_EPS && "test-33");
}
