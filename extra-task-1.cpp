#include <cassert>
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
    return (time_2 - time_1) / 3600;
}

double to_float_hours(int hours, int minutes, int seconds)
{
    assert(hours >= 0 && minutes >= 0 && seconds >= 0);
    assert(minutes < 60 && seconds < 60);
    return hours + minutes / 60.0 + seconds / 3600.0;
}

double to_24_hour_clock(double hours)
{
    assert(hours >= 0);
    double intPart = 0;
    double doublePart = std::modf(hours, &intPart);
    return static_cast<int>(intPart) % 24 + doublePart;
}

int get_hours(int seconds)
{
    assert(seconds >= 0);
    return seconds / 3600;
}

int get_minutes(int seconds)
{
    assert(seconds >= 0);
    return seconds / 60 % 60;
}

int get_seconds(int seconds)
{
    assert(seconds >= 0);
    return seconds % 60;
}


double time_to_utc(int utc_offset, double time)
{
    assert(time >= 0);
    double dif = time - utc_offset;
    return dif >= 0 ? to_24_hour_clock(dif) : dif  + 24;
}

double time_from_utc(int utc_offset, double time)
{
    assert(time >= 0);
    double dif = time + utc_offset;
    return dif >= 0 ? to_24_hour_clock(dif) : dif + 24;
}


int main()
{
    // test seconds_difference
    assert(std::fabs(seconds_difference(1800.0, 3600.0) - 1800.0) < DBL_EPSILON);
    assert(std::fabs(seconds_difference(3600.0, 1800.0) + 1800.0) < DBL_EPSILON);
    assert(std::fabs(seconds_difference(1800.0, 2160.0) - 360.0) < DBL_EPSILON);
    assert(std::fabs(seconds_difference(1800.0, 1800.0)) < DBL_EPSILON);


    // test hours_difference
    assert(std::fabs(hours_difference(1800.0, 3600.0) - 0.5) < DBL_EPSILON);
    assert(std::fabs(hours_difference(3600.0, 1800.0) + 0.5) < DBL_EPSILON);
    assert(std::fabs(hours_difference(1800.0, 2160.0) - 0.1) < DBL_EPSILON);
    assert(std::fabs(hours_difference(1800.0, 1800.0)) < DBL_EPSILON);

    // test to_float_hours
    assert(std::fabs(to_float_hours(0, 15, 0) - 0.25) < DBL_EPSILON);
    assert(std::fabs(to_float_hours(2, 45, 9) - 2.7525) < DBL_EPSILON);
    assert(std::fabs(to_float_hours(1, 0, 36) - 1.01) < DBL_EPSILON);
    assert(std::fabs(hours_difference(1800.0, 1800.0)) < DBL_EPSILON);

    // test to_24_hour_clock
    assert(std::fabs(to_24_hour_clock(24)) < DBL_EPSILON);
    assert(std::fabs(to_24_hour_clock(48)) < DBL_EPSILON);
    assert(std::fabs(to_24_hour_clock(25) - 1) < DBL_EPSILON);
    assert(std::fabs(to_24_hour_clock(4) - 4) < DBL_EPSILON);
    assert(std::fabs(to_24_hour_clock(28.5) - 4.5) < DBL_EPSILON);


    // test time_to_utc
    assert(abs(time_to_utc(+0, 12.0) - 12.0) < DBL_EPSILON);
    assert(abs(time_to_utc(+1, 12.0) - 11.0) < DBL_EPSILON);
    assert(abs(time_to_utc(-1, 12.0) - 13.0) < DBL_EPSILON);
    assert(abs(time_to_utc(-11, 18.0) - 5.0) < DBL_EPSILON);
    assert(abs(time_to_utc(-1, 0.0) - 1.0) < DBL_EPSILON);
    assert(abs(time_to_utc(+12, 10.0) - 22.0) < DBL_EPSILON);
    assert(abs(time_to_utc(-1, 23.0)) < DBL_EPSILON);

    // test time_from_utc
    assert(abs(time_from_utc(+0, 12.0) - 12.0) < DBL_EPSILON);
    assert(abs(time_from_utc(+1, 12.0) - 13.0) < DBL_EPSILON);
    assert(abs(time_from_utc(-1, 12.0) - 11.0) < DBL_EPSILON);
    assert(abs(time_from_utc(+6, 6.0) - 12.0) < DBL_EPSILON);
    assert(abs(time_from_utc(-7, 6.0) - 23.0) < DBL_EPSILON);
    assert(abs(time_from_utc(-1, 0.0) - 23.0) < DBL_EPSILON);
    assert(abs(time_from_utc(-1, 23.0) - 22.0) < DBL_EPSILON);
    assert(abs(time_from_utc(+1, 23.0)) < DBL_EPSILON);

    return 0;
}