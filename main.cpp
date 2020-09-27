#include <iostream>
#include <assert.h>
#include "extra-task-1.h"
#include <cmath>

using namespace std;

void main() {
	
	//Func 1
    /*
        Return the number of seconds later that a time in seconds
        time_2 is than a time in seconds time_1.
    */
    assert(fabs(seconds_difference(1800.0, 3600.0) - 1800) < DBL_EPSILON);
    assert(fabs(seconds_difference(1800.0, 3600.0) - 1800) < DBL_EPSILON);
    assert(fabs(seconds_difference(1800.0, 2160.0) - 360) < DBL_EPSILON);
    assert(fabs(seconds_difference(1800.0, 1800.0) - 0) < DBL_EPSILON);

    //Func 2
    /*
        Return the number of hours later that a time in seconds
        time_2 is than a time in seconds time_1.
    */
    assert(fabs(hours_difference(1800.0, 3600.0) - 0.5) < DBL_EPSILON);
    assert(fabs(hours_difference(1800.0, 3600.0) - 0.5) < DBL_EPSILON);
    assert(fabs(hours_difference(1800.0, 2160.0) - 0.1) < DBL_EPSILON);
    assert(fabs(hours_difference(1800.0, 1800.0) - 0) < DBL_EPSILON);

    //Func 3
    /*
        Return the total number of hours in the specified number
        of hours, minutes, and seconds.
    */
    assert(fabs(to_float_hours(0, 15, 0) - 0.25) < DBL_EPSILON);
    assert(fabs(to_float_hours(2, 45, 9) - 2.7525) < DBL_EPSILON);
    assert(fabs(to_float_hours(1, 0, 36) - 1.01) < DBL_EPSILON);

    //Func 4
     /*
        hours is a number of hours since midnight. Return the
        hour as seen on a 24-hour clock.
    */
    assert(fabs(to_24_hour_clock(24) - 0) < DBL_EPSILON);
    assert(fabs(to_24_hour_clock(48) - 0) < DBL_EPSILON);
    assert(fabs(to_24_hour_clock(25) - 1) < DBL_EPSILON);
    assert(fabs(to_24_hour_clock(4) - 4) < DBL_EPSILON);
    assert(fabs(to_24_hour_clock(28.5) - 4.5) < DBL_EPSILON);

    //Extra Funcc
    assert(get_hours(3800) == 1);
    assert(get_minutes(3800) == 3);
    assert(get_seconds(3800) == 20);

    //Func 5
    /*
        Return time at UTC+0, where utc_offset is the number of hours away from
        UTC+0.
    */
    assert(fabs(time_to_utc(+0, 12.0) - 12.0) < DBL_EPSILON);
    assert(fabs(time_to_utc(+1, 12.0) - 11.0) < DBL_EPSILON);
    assert(fabs(time_to_utc(-1, 12.0) - 13.0) < DBL_EPSILON);
    assert(fabs(time_to_utc(-11, 18.0) - 5.0) < DBL_EPSILON);
    assert(fabs(time_to_utc(-1, 0.0) - 1.0) < DBL_EPSILON);
    assert(fabs(time_to_utc(-1, 23.0) - 0.0) < DBL_EPSILON);

    //Func 6
    /*
        Return UTC time in time zone utc_offset.

        >>> time_from_utc(+0, 12.0)
        12.0

        >>> time_from_utc(+1, 12.0)
        13.0

        >>> time_from_utc(-1, 12.0)
        11.0

        >>> time_from_utc(+6, 6.0)
        12.0

        >>> time_from_utc(-7, 6.0)
        23.0

        >>> time_from_utc(-1, 0.0)
        23.0

        >>> time_from_utc(-1, 23.0)
        22.0

        >>> time_from_utc(+1, 23.0)
        0.0
    */
    assert(fabs(time_from_utc(+0, 12.0) - 12) < DBL_EPSILON);
    assert(fabs(time_from_utc(+1, 12.0) - 13) < DBL_EPSILON);
    assert(fabs(time_from_utc(-1, 12.0) - 11) < DBL_EPSILON);
    assert(fabs(time_from_utc(+6, 6.0) - 12) < DBL_EPSILON);
    assert(fabs(time_from_utc(-7, 6.0) - 23) < DBL_EPSILON);
    assert(fabs(time_from_utc(-1, 0.0) - 23) < DBL_EPSILON);
    assert(fabs(time_from_utc(-1, 23.0) - 22) < DBL_EPSILON);
    assert(fabs(time_from_utc(+1, 23.0) - 0) < DBL_EPSILON);
}