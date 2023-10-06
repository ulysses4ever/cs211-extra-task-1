#include <iostream>
#include <assert.h>
#include <cmath>

double seconds_difference(double time_1, double time_2)
{
    return time_2 - time_1;

}

double hours_difference(double time_1, double time_2)
{
    return seconds_difference(time_1, time_2) / 3600.0;
}

double to_float_hours(int hours, int minutes, int seconds)
{
    assert(minutes >= 0 && minutes <= 60);
    assert(seconds >= 0 && seconds <= 60);

    return hours + minutes / 60.0 + seconds / 3600.0;
}

double to_24_hour_clock(double hours)
{
    assert(hours >= 0);

    double mins = hours - floor(hours);
    int inthour = floor(hours);
    return (inthour % 24 + mins);
}

int get_hours(int seconds) {
    return (seconds / 3600) % 24;
}

int get_minutes(int seconds) {
    return (seconds % 3600) / 60;
}

int get_seconds(int seconds) {
    return seconds % 60;
}


double time_to_utc(int utc_offset, double time)
{
    return 1;
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
}

double time_from_utc(int utc_offset, double time)
{
    return 1;
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
}


void main() {

    assert(abs(seconds_difference(1800.0, 3600.0) - 1800.0) < DBL_EPSILON);
    assert(abs(seconds_difference(3600.0, 1800.0) - -1800.0) < DBL_EPSILON);
    assert(abs(seconds_difference(1800.0, 2160.0) - 360.0) < DBL_EPSILON);
    assert(abs(seconds_difference(1800.0, 1800.0)) < DBL_EPSILON);

    assert(abs(hours_difference(1800.0, 3600.0) - 0.5) < DBL_EPSILON);
    assert(abs(hours_difference(3600.0, 1800.0) - -0.5) < DBL_EPSILON);
    assert(abs(hours_difference(1800.0, 2160.0) - 0.1) < DBL_EPSILON);
    assert(abs(hours_difference(1800.0, 1800.0)) < DBL_EPSILON);

    assert(abs(to_float_hours(0, 15, 0) - 0.25) < DBL_EPSILON);
    assert(abs(to_float_hours(2,45,9) - 2.7525) < DBL_EPSILON);
    assert(abs(to_float_hours(1, 0, 36) - 1.01) < DBL_EPSILON);

    assert(abs(to_24_hour_clock(24)) < DBL_EPSILON);
    assert(abs(to_24_hour_clock(48)) < DBL_EPSILON);
    assert(abs(to_24_hour_clock(25)-1) < DBL_EPSILON);
    assert(abs(to_24_hour_clock(4)-4) < DBL_EPSILON);
    assert(abs(to_24_hour_clock(28.5)-4.5) < DBL_EPSILON);

    assert(get_hours(3800) == 1);
    assert(get_minutes(3800) == 3);
    assert(get_seconds(3800) == 20);

    assert(get_hours(7199) == 1);
    assert(get_minutes(7199) == 59);
    assert(get_seconds(7199) == 59);

}