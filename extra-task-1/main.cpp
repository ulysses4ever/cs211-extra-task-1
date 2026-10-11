#include "extra-task-1.h"
#include <iostream>
#include <cassert>
using namespace std;

bool almost_equal(double a, double b)
{
    return fabs(a - b) < DBL_EPSILON;
}

void main(){
    setlocale(LC_ALL, "");

    // seconds_difference
    assert(almost_equal(seconds_difference(1800.0, 3600.0), 1800.0));
    assert(almost_equal(seconds_difference(3600.0, 1800.0), -1800.0));
    assert(almost_equal(seconds_difference(1800.0, 2160.0), 360.0));
    assert(almost_equal(seconds_difference(1800.0, 1800.0), 0.0));


    // hours_difference
    assert(almost_equal(hours_difference(1800.0, 3600.0), 0.5));
    assert(almost_equal(hours_difference(3600.0, 1800.0), -0.5));
    assert(almost_equal(hours_difference(1800.0, 2160.0), 0.1));
    assert(almost_equal(hours_difference(1800.0, 1800.0), 0.0));


    // to_float_hours
    assert(almost_equal(to_float_hours(0, 15, 0), 0.25));
    assert(almost_equal(to_float_hours(2, 45, 9), 2.7525));
    assert(almost_equal(to_float_hours(1, 0, 36), 1.01));


    // to_24_hour_clock
    assert(almost_equal(to_24_hour_clock(24), 0));
    assert(almost_equal(to_24_hour_clock(48), 0));
    assert(almost_equal(to_24_hour_clock(25), 1));
    assert(almost_equal(to_24_hour_clock(4), 4));
    assert(almost_equal(to_24_hour_clock(28.5), 4.5));


    // get_hours / get_minutes / get_seconds
    assert(get_hours(3800) == 1);
    assert(get_minutes(3800) == 3);
    assert(get_seconds(3800) == 20);


    // time_to_utc
    assert(almost_equal(time_to_utc(+0, 12.0), 12.0));
    assert(almost_equal(time_to_utc(+1, 12.0), 11.0));
    assert(almost_equal(time_to_utc(-1, 12.0), 13.0));
    assert(almost_equal(time_to_utc(-11, 18.0), 5.0));
    assert(almost_equal(time_to_utc(-1, 0.0), 1.0));
    assert(almost_equal(time_to_utc(-1, 23.0), 0.0));


    // time_from_utc
    assert(almost_equal(time_from_utc(+0, 12.0), 12.0));
    assert(almost_equal(time_from_utc(+1, 12.0), 13.0));
    assert(almost_equal(time_from_utc(-1, 12.0), 11.0));
    assert(almost_equal(time_from_utc(+6, 6.0), 12.0));
    assert(almost_equal(time_from_utc(-7, 6.0), 23.0));
    assert(almost_equal(time_from_utc(-1, 0.0), 23.0));
    assert(almost_equal(time_from_utc(-1, 23.0), 22.0));
    assert(almost_equal(time_from_utc(+1, 23.0), 0.0));

    cout << "Все тесты прошли!" << endl;
}