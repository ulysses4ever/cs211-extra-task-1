#include <cassert>
#include <cfloat>
#include <iostream>
#include <cmath>

double seconds_difference(double time_1, double time_2)
{
    assert(time_1 >= 0 && time_2 >= 0);

    return time_2 - time_1;
}

double hours_difference(double time_1, double time_2)
{

    assert(time_1 >= 0 && time_2 >= 0);

    return seconds_difference(time_1, time_2) / 3600;

}

double to_float_hours(int hours, int minutes, int seconds)
{
    assert(hours >= 0 && minutes >= 0 && minutes < 60 && seconds >= 0 && seconds < 60);

    return hours + (static_cast<double>(minutes) / 60 + static_cast<double>(seconds) / 3600);

}

double to_24_hour_clock(double hours)
{
    assert(hours >= 0);

    return hours - (static_cast<int>(hours) / 24) * 24.0;
}

int get_hours(double time_1)
{
    assert(time_1 >= 0);

    return static_cast<int>(time_1) / 3600;
}

int get_minutes(double time_1)
{
    assert(time_1 >= 0);

    return (static_cast<int>(time_1) - get_hours(time_1) * 3600) / 60;
}

int get_seconds(double time_1)
{
    assert(time_1 >= 0);

    return (static_cast<int>(time_1) - get_hours(time_1) * 3600) - get_minutes(time_1) * 60;
}



int countNumInDouble(double a, int b)
{
    return static_cast<int>(a) / b;
}


double time_to_utc(int utc_offset, double time)
{
    assert(time >= 0);

    double newTime = time - utc_offset;

    if (newTime < 0)
    {
        return 24 + newTime;
    }
    else
        return newTime - countNumInDouble(newTime, 24) * 24.0;



}

double time_from_utc(int utc_offset, double time)
{
    assert(time >= 0);

    double newTime = time + utc_offset;

    if (newTime < 0)
    {
        return 24 + newTime;
    }
    else
        return newTime - countNumInDouble(newTime, 24) * 24.0;
}


int main()
{
    assert(fabs(seconds_difference(1800, 3600) - 1800) < DBL_EPSILON);
    assert(fabs(seconds_difference(3600, 1800) + 1800) < DBL_EPSILON);
    assert(fabs(seconds_difference(1800, 2160) - 360) < DBL_EPSILON);
    assert(fabs(seconds_difference(1800, 1800) - 0) < DBL_EPSILON);

    assert(fabs(hours_difference(1800, 3600) - 0.5) < DBL_EPSILON);
    assert(fabs(hours_difference(3600, 1800) + 0.5) < DBL_EPSILON);
    assert(fabs(hours_difference(1800, 2160) - 0.1) < DBL_EPSILON);
    assert(fabs(hours_difference(1800, 1800) - 0) < DBL_EPSILON);

    assert(fabs(to_float_hours(0, 15, 0) - 0.25) < DBL_EPSILON);
    assert(fabs(to_float_hours(2, 45, 9) - 2.7525) < DBL_EPSILON);
    assert(fabs(to_float_hours(1, 0, 36) - 1.01) < DBL_EPSILON);

    assert(fabs(to_24_hour_clock(24) - 0) < DBL_EPSILON);
    assert(fabs(to_24_hour_clock(48) - 0) < DBL_EPSILON);
    assert(fabs(to_24_hour_clock(25) - 1) < DBL_EPSILON);
    assert(fabs(to_24_hour_clock(4) - 4) < DBL_EPSILON);
    assert(fabs(to_24_hour_clock(28.5) - 4.5) < DBL_EPSILON);

    assert(fabs(time_to_utc(0, 12) - 12) < DBL_EPSILON);
    assert(fabs(time_to_utc(1, 12) - 11) < DBL_EPSILON);
    assert(fabs(time_to_utc(-1, 12) - 13) < DBL_EPSILON);
    assert(fabs(time_to_utc(-11, 18) - 5) < DBL_EPSILON);
    assert(fabs(time_to_utc(-1, 0) - 1) < DBL_EPSILON);
    assert(fabs(time_to_utc(-1, 23) - 0) < DBL_EPSILON);

    assert(fabs(time_from_utc(0, 12) - 12) < DBL_EPSILON);
    assert(fabs(time_from_utc(1, 12) - 13) < DBL_EPSILON);
    assert(fabs(time_from_utc(-1, 12) - 11) < DBL_EPSILON);
    assert(fabs(time_from_utc(6, 6) - 12) < DBL_EPSILON);
    assert(fabs(time_from_utc(-7, 6) - 23) < DBL_EPSILON);
    assert(fabs(time_from_utc(-1, 0) - 23) < DBL_EPSILON);
    assert(fabs(time_from_utc(-1, 23) - 22) < DBL_EPSILON);
    assert(fabs(time_from_utc(1, 23) - 0) < DBL_EPSILON);

    return 0;
}





