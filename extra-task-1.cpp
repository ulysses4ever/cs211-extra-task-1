#include <iostream>
#include <cassert>
#include <cmath>
#include <cfloat>
using namespace std;

double seconds_difference(double time_1, double time_2)
{
    return time_2 - time_1;
}

void test_seconds_difference()
{
    assert(fabs(seconds_difference(1800.0, 3600.0) - 1800.0) < DBL_EPSILON);
    assert(fabs(seconds_difference(3600.0, 1800.0) + 1800.0) < DBL_EPSILON);
    assert(fabs(seconds_difference(1800.0, 2160.0) - 360.0) < DBL_EPSILON);
    assert(fabs(seconds_difference(1800.0, 1800.0)) < DBL_EPSILON);
}

double hours_difference(double time_1, double time_2)
{
    return (time_2 - time_1) / 3600.0;
}

void test_hours_difference()
{
    assert(fabs(hours_difference(1800.0, 3600.0) - 0.5) < DBL_EPSILON);
    assert(fabs(hours_difference(3600.0, 1800.0) + 0.5) < DBL_EPSILON);
    assert(fabs(hours_difference(1800.0, 2160.0) - 0.1) < DBL_EPSILON);
    assert(fabs(hours_difference(1800.0, 1800.0)) < DBL_EPSILON);
}

double to_float_hours(int hours, int minutes, int seconds)
{
    return hours + minutes / 60.0 + seconds / 3600.0;
}

void test_to_float_hours()
{
    assert(fabs(to_float_hours(0, 15, 0) - 0.25) < DBL_EPSILON);
    assert(fabs(to_float_hours(2, 45, 9) - 2.7525) < DBL_EPSILON);
    assert(fabs(to_float_hours(1, 0, 36) - 1.01) < DBL_EPSILON);
}

double to_24_hour_clock(double hours)
{
    return fmod(hours, 24.0);
}

void test_to_24_hour_clock()
{
    assert(fabs(to_24_hour_clock(24) - 0) < DBL_EPSILON);
    assert(fabs(to_24_hour_clock(48) - 0) < DBL_EPSILON);
    assert(fabs(to_24_hour_clock(25) - 1) < DBL_EPSILON);
    assert(fabs(to_24_hour_clock(4) - 4) < DBL_EPSILON);
    assert(fabs(to_24_hour_clock(28.5) - 4.5) < DBL_EPSILON);
}

int get_hours(int seconds)
{
    return seconds / 3600;
}

int get_minutes(int seconds)
{
    return (seconds % 3600) / 60;
}

int get_seconds(int seconds)
{
    return seconds % 60;
}

void test_get_time_parts()
{
    assert(get_hours(3800) == 1);
    assert(get_minutes(3800) == 3);
    assert(get_seconds(3800) == 20);
}

double time_to_utc(int utc_offset, double time)
{
    return fmod((24 + time - utc_offset), 24.0);
}

void test_time_to_utc()
{
    assert(fabs(time_to_utc(+0, 12.0) - 12.0) < DBL_EPSILON);
    assert(fabs(time_to_utc(+1, 12.0) - 11.0) < DBL_EPSILON);
    assert(fabs(time_to_utc(-1, 12.0) - 13.0) < DBL_EPSILON);
    assert(fabs(time_to_utc(-11, 18.0) - 5.0) < DBL_EPSILON);
    assert(fabs(time_to_utc(-1, 0.0) - 1.0) < DBL_EPSILON);
    assert(fabs(time_to_utc(-1, 23.0) - 0.0) < DBL_EPSILON);
}

double time_from_utc(int utc_offset, double time)
{
    return fmod((24 + time + utc_offset), 24.0);
}

void test_time_from_utc()
{
    assert(fabs(time_from_utc(+0, 12.0) - 12.0) < DBL_EPSILON);
    assert(fabs(time_from_utc(+1, 12.0) - 13.0) < DBL_EPSILON);
    assert(fabs(time_from_utc(-1, 12.0) - 11.0) < DBL_EPSILON);
    assert(fabs(time_from_utc(+6, 6.0) - 12.0) < DBL_EPSILON);
    assert(fabs(time_from_utc(-7, 6.0) - 23.0) < DBL_EPSILON);
    assert(fabs(time_from_utc(-1, 0.0) - 23.0) < DBL_EPSILON);
    assert(fabs(time_from_utc(-1, 23.0) - 22.0) < DBL_EPSILON);
    assert(fabs(time_from_utc(+1, 23.0) - 0.0) < DBL_EPSILON);
}

int main()
{
    setlocale(LC_ALL, "RUSSIAN");

    test_seconds_difference();
    test_hours_difference();
    test_to_float_hours();
    test_to_24_hour_clock();
    test_get_time_parts();
    test_time_to_utc();
    test_time_from_utc();

    cout << "Тесты прошли успешно" << endl;

    return 0;
}
