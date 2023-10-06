#include <iostream>
#include <assert.h>

double seconds_difference(double time_1, double time_2)
{
    return time_2 - time_1;
}

double hours_difference(double time_1, double time_2)
{
    return (time_2 - time_1) / 3600.0;
}

double to_float_hours(int hours, int minutes, int seconds)
{
    assert(minutes >= 0 && minutes <= 60);
    assert(seconds >= 0 && seconds <= 60);

    return hours + (minutes / 60.0) + (seconds / 3600.0);
}

double to_24_hour_clock(double hours)
{
    assert(hours >= 0);

    double minutes = hours - floor(hours);
    int hrs = floor(hours);

    return (hrs % 24 + minutes);
}

int get_hours(int sec) {
    return (sec / 3600) % 4;
}

int get_minutes(int sec) {
    return (sec % 3600) / 60;
}

int get_seconds(int sec) {
    return sec % 60;
}

double time_to_utc(int utc_offset, double time)
{
    double t = time - utc_offset;

    if (t < 0) {
        t += 24;
    }
    else if (t >= 24) {
        t -= 24;
    }

    return t;
}

double time_from_utc(int utc_offset, double time)
{
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
    return 1;
}

void main() {
    double eps = DBL_EPSILON;

    //Test task 1
    assert(abs(seconds_difference(1800.0, 3600.0) - 1800.0) < eps);
    assert(abs(seconds_difference(3600.0, 1800.0) - -1800.0) < eps);
    assert(abs(seconds_difference(1800.0, 2160.0) - 360.0) < eps);
    assert(abs(seconds_difference(1800.0, 1800.0)) < eps);

    //Test task 2
    assert(abs(hours_difference(1800.0, 3600.0) - 0.5) < eps);
    assert(abs(hours_difference(3600.0, 1800.0) - -0.5) < eps);
    assert(abs(hours_difference(1800.0, 2160.0) - 0.1) < eps);
    assert(abs(hours_difference(1800.0, 1800.0)) < eps);

    //Test task 3
    assert(abs(to_float_hours(0, 15, 0) - 0.25) < eps);
    assert(abs(to_float_hours(2, 45, 9) - 2.7525) < eps);
    assert(abs(to_float_hours(1, 0, 36) - 1.01) < eps);

    //Test task 4
    assert(abs(to_24_hour_clock(24)) < eps);
    assert(abs(to_24_hour_clock(48)) < eps);
    assert(abs(to_24_hour_clock(25) - 1) < eps);
    assert(abs(to_24_hour_clock(4) - 4) < eps);
    assert(abs(to_24_hour_clock(28.5) - 4.5) < eps);

    //Test task 5
    assert(get_hours(3800) == 1);
    assert(get_minutes(3800) == 3);
    assert(get_seconds(3800) == 20);

    //Test task 6
    assert(abs(time_to_utc(0, 12.0) - 12.0) < eps);
    assert(abs(time_to_utc(+1, 12.0) - 11.0) < eps);
    assert(abs(time_to_utc(-1, 12.0) - 13.0) < eps);
    assert(abs(time_to_utc(-11, 18.0) - 5.0) < eps);
    assert(abs(time_to_utc(-1, 0.0) - 1.0) < eps);
    assert(abs(time_to_utc(-1, 23.0)) < eps);
}
