#include <assert.h>
#include <cfloat>
#include <cmath>

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
    assert(minutes >= 0);
    assert(minutes < 60);
    assert(seconds >= 0);
    assert(seconds < 60);
    return (double)hours + ((double)minutes*60 + (double)seconds)/3600;
}

double to_24_hour_clock(double hours)
{
    double intP;
    double fractP = modf(hours, &intP);
    long intpart = intP;
    return intpart % 24 + fractP;
}

double get_hours(double time_1)
{
    return (long)floor(time_1) / 3600;
}

double get_minutes(double time_1)
{
    return ((long)floor(time_1) % 3600) / 60;
}

double get_seconds(double time_1)
{
    return (long)floor(time_1) % 60;
}

double time_to_utc(int utc_offset, double time)
{
    return (24 + (long)time - utc_offset) % 24;
}

double time_from_utc(int utc_offset, double time)
{
    return (24 + (long)time + utc_offset) % 24;
}

int main()
{
    // I'M NOT RESPONSIBLE FOR ALL THE DBL_EPSILON COMPARISONS HERE

    //seconds_difference tests
    assert(fabs(seconds_difference(1800.0, 3600.0) - 1800.0) < DBL_EPSILON);
    assert(fabs(seconds_difference(3600.0, 1800.0) + 1800.0) < DBL_EPSILON);
    assert(fabs(seconds_difference(1800.0, 2160.0) - 360.0) < DBL_EPSILON);
    assert(fabs(seconds_difference(1800.0, 1800.0)) < DBL_EPSILON);

    //hours_difference tests
    assert(fabs(hours_difference(1800.0, 3600.0) - 0.5) < DBL_EPSILON);
    assert(fabs(hours_difference(3600.0, 1800.0) + 0.5) < DBL_EPSILON);
    assert(fabs(hours_difference(1800.0, 2160.0) - 0.1) < DBL_EPSILON);
    assert(fabs(hours_difference(1800.0, 1800.0)) < DBL_EPSILON);

    //to_float_hours tests
    assert(fabs(to_float_hours(0, 15, 0) - 0.25) < DBL_EPSILON);
    assert(fabs(to_float_hours(2, 45, 9) - 2.7525) < DBL_EPSILON);
    assert(fabs(to_float_hours(1, 0, 36) - 1.01) < DBL_EPSILON);

    //to_24_hour_clock tests
    assert(fabs(to_24_hour_clock(24)) < DBL_EPSILON);
    assert(fabs(to_24_hour_clock(48)) < DBL_EPSILON);
    assert(fabs(to_24_hour_clock(25) - 1.0) < DBL_EPSILON);
    assert(fabs(to_24_hour_clock(4) - 4.0) < DBL_EPSILON);
    assert(fabs(to_24_hour_clock(28.5) - 4.5) < DBL_EPSILON);

    /*get_hours
     * get_minutes
     * get_seconds tests */
    assert(fabs(get_hours(3800.0) - 1.0) < DBL_EPSILON);
    assert(fabs(get_minutes(3800.0) - 3.0) < DBL_EPSILON);
    assert(fabs(get_seconds(3800.0) - 20.0) < DBL_EPSILON);

    //time_to_utc tests
    assert(fabs(time_to_utc(+0, 12.0) - 12.0) < DBL_EPSILON);
    assert(fabs(time_to_utc(+1, 12.0) - 11.0) < DBL_EPSILON);
    assert(fabs(time_to_utc(-1, 12.0) - 13.0) < DBL_EPSILON);
    assert(fabs(time_to_utc(-11, 18.0) - 5.0) < DBL_EPSILON);
    assert(fabs(time_to_utc(-1, 0.0) - 1.0) < DBL_EPSILON);
    assert(fabs(time_to_utc(-1, 23.0) - 0.0) < DBL_EPSILON);

    //time_from_utc_tests
    assert(fabs(time_from_utc(+0, 12.0) - 12.0) < DBL_EPSILON);
    assert(fabs(time_from_utc(+1, 12.0) - 13.0) < DBL_EPSILON);
    assert(fabs(time_from_utc(-1, 12.0) - 11.0) < DBL_EPSILON);
    assert(fabs(time_from_utc(+6, 6.0) - 12.0) < DBL_EPSILON);
    assert(fabs(time_from_utc(-7, 6.0) - 23.0) < DBL_EPSILON);
    assert(fabs(time_from_utc(-1, 0.0) - 23.0) < DBL_EPSILON);
    return 0;
}