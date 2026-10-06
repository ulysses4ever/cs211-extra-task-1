#include <iostream>
#include <cassert>
#include <cmath>
#include <cfloat>
#include "extra-task-1.h"

using namespace std;

int main()
{
    /*
    Return the number of seconds later that a time in seconds
    time_2 is than a time in seconds time_1.

    >>> seconds_difference(1800.0, 3600.0)
    1800.0

    >>> seconds_difference(3600.0, 1800.0)
    -1800.0

    >>> seconds_difference(1800.0, 2160.0)
    360.0

    >>> seconds_difference(1800.0, 1800.0)
    0.0
    */

    assert(fabs(seconds_difference(1800.0, 3600.0) - 1800.0) <= DBL_EPSILON);
    assert(fabs(seconds_difference(3600.0, 1800.0) - ( - 1800.0)) <= DBL_EPSILON);
    assert(fabs(seconds_difference(1800.0, 2160.0) - 360.0) <= DBL_EPSILON);
    assert(fabs(seconds_difference(1800.0, 1800.0) - 0.0) <= DBL_EPSILON);
    cout << "seconds_difference() completed" << "\n";

    /*
    Return the number of hours later that a time in seconds
    time_2 is than a time in seconds time_1.

    >>> hours_difference(1800.0, 3600.0)
    0.5

    >>> hours_difference(3600.0, 1800.0)
    -0.5

    >>> hours_difference(1800.0, 2160.0)
    0.1

    >>> hours_difference(1800.0, 1800.0)
    0.0
    */

    assert(fabs(hours_difference(1800.0, 3600.0) - 0.5) <= DBL_EPSILON);
    assert(fabs(hours_difference(3600.0, 1800.0) - (-0.5)) <= DBL_EPSILON);
    assert(fabs(hours_difference(1800.0, 2160.0) - 0.1) <= DBL_EPSILON);
    assert(fabs(hours_difference(1800.0, 1800.0) - 0.0) <= DBL_EPSILON);
    cout << "hours_difference() completed" << "\n";

    /*
    Return the total number of hours in the specified number
    of hours, minutes, and seconds.

    Precondition: 0 <= minutes < 60  and  0 <= seconds < 60

    >>> to_float_hours(0, 15, 0)
    0.25

    >>> to_float_hours(2, 45, 9)
    2.7525

    >>> to_float_hours(1, 0, 36)
    1.01
    */

    assert(fabs(to_float_hours(0, 15, 0) - 0.25) <= DBL_EPSILON);
    assert(fabs(to_float_hours(2, 45, 9) - 2.7525) <= DBL_EPSILON);
    assert(fabs(to_float_hours(1, 0, 36) - 1.01) <= DBL_EPSILON);
    cout << "to_float_hours() completed" << "\n";

    /*
    hours is a number of hours since midnight. Return the
    hour as seen on a 24-hour clock.

    Precondition: hours >= 0

    >>> to_24_hour_clock(24)
    0

    >>> to_24_hour_clock(48)
    0

    >>> to_24_hour_clock(25)
    1

    >>> to_24_hour_clock(4)
    4

    >>> to_24_hour_clock(28.5)
    4.5
    */

    assert(fabs(to_24_hour_clock(24) - 0) <= DBL_EPSILON);
    assert(fabs(to_24_hour_clock(48) - 0) <= DBL_EPSILON);
    assert(fabs(to_24_hour_clock(25) - 1) <= DBL_EPSILON);
    assert(fabs(to_24_hour_clock(4) - 4) <= DBL_EPSILON);
    assert(fabs(to_24_hour_clock(28.5) - 4.5) <= DBL_EPSILON);
    cout << "to_24_hour_clock() completed" << "\n";

    /*
    >>> get_hours(3800)
    1

    >>> get_minutes(3800)
    3

    >>> get_seconds(3800)
    20
    */

    assert(get_hours(3800) == 1);
    assert(get_minutes(3800) == 3);
    assert(get_seconds(3800) == 20);
    cout << "get_hours(), get_minutes(), get_seconds() completed" << "\n";

    /*
    Return time at UTC+0, where utc_offset is the number of hours away from
    UTC+0.
    You may be interested in:
    https://en.wikipedia.org/wiki/Coordinated_Universal_Time

    >>> time_to_utc(+0, 12.0)
    12.0

    >>> time_to_utc(+1, 12.0)
    11.0

    >>> time_to_utc(-1, 12.0)
    13.0

    >>> time_to_utc(-11, 18.0)
    5.0

    >>> time_to_utc(-1, 0.0)
    1.0

    >>> time_to_utc(-1, 23.0)
    0.0
    */

    assert(fabs(time_to_utc(+0, 12.0) - 12.0) <= DBL_EPSILON);
    assert(fabs(time_to_utc(+1, 12.0) - 11.0) <= DBL_EPSILON);
    assert(fabs(time_to_utc(-1, 12.0) - 13.0) <= DBL_EPSILON);
    assert(fabs(time_to_utc(-11, 18.0) - 5.0) <= DBL_EPSILON);
    assert(fabs(time_to_utc(-1, 0.0) - 1.0) <= DBL_EPSILON);
    assert(fabs(time_to_utc(-1, 23.0) - 0.0) <= DBL_EPSILON);
    cout << "time_to_utc() completed" << "\n";

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

    assert(fabs(time_from_utc(+0, 12.0) - 12.0) <= DBL_EPSILON);
    assert(fabs(time_from_utc(+1, 12.0) - 13.0) <= DBL_EPSILON);
    assert(fabs(time_from_utc(-1, 12.0) - 11.0) <= DBL_EPSILON);
    assert(fabs(time_from_utc(+6, 6.0) - 12.0) <= DBL_EPSILON);
    assert(fabs(time_from_utc(-7, 6.0) - 23.0) <= DBL_EPSILON);
    assert(fabs(time_from_utc(-1, 0.0) - 23.0) <= DBL_EPSILON);
    assert(fabs(time_from_utc(-1, 23.0) - 22.0) <= DBL_EPSILON);
    assert(fabs(time_from_utc(+1, 23.0) - 0.0) <= DBL_EPSILON);
    cout << "time_from_utc() completed" << "\n";
}