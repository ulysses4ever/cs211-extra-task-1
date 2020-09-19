#include <iostream>
#include "extra-task-1.h"
#include "assert.h"
#include "math.h"
using namespace std;

int main()
{ 
    /*
    Return the number of seconds later that a time in seconds
        time_2 is than a time in seconds time_1.
    */
    assert(fabs(seconds_difference(1800.0, 3600.0) - 1800.0) < DBL_EPSILON);
    assert(fabs(seconds_difference(3600.0, 1800.0)+1800.0) < DBL_EPSILON);
    assert(fabs(seconds_difference(1800.0, 2160.0)-360.0) < DBL_EPSILON);
    assert(fabs(seconds_difference(1800.0, 1800.0)-0.0) < DBL_EPSILON);

    cout << "all test for function seconds_difference have been passed" << endl;
    /*
     Return the number of hours later that a time in seconds
        time_2 is than a time in seconds time_1.
    */

    assert(fabs(hours_difference(1800.0, 3600.0)-0.5) < DBL_EPSILON);
    assert(fabs(hours_difference(3600.0, 1800.0)+ 0.5) < DBL_EPSILON);
    assert(fabs(hours_difference(1800.0, 2160.0)-0.1) < DBL_EPSILON);
    assert(fabs(hours_difference(1800.0, 1800.0)- 0.0) < DBL_EPSILON);

    cout << "all test for function hours_difference have been passed" << endl;

    /*
    Return the number of hours later that a time in seconds
        time_2 is than a time in seconds time_1.
    */
    assert(fabs(to_float_hours(0, 15, 0) - 0.25) < DBL_EPSILON);
    assert(fabs(to_float_hours(2, 45, 9)-2.7525) < DBL_EPSILON);
    assert(fabs(to_float_hours(1, 0, 36)- 1.01) < DBL_EPSILON);

    cout << "all test for function to_float_hours  have been passed" << endl;
    /*
     hours is a number of hours since midnight. Return the
        hour as seen on a 24-hour clock.

    */
    assert(fabs(to_24_hour_clock(0)-0)<DBL_EPSILON);
    assert(fabs(to_24_hour_clock(48)-0) < DBL_EPSILON);
    assert(fabs(to_24_hour_clock(24)-0) < DBL_EPSILON);
    assert(fabs(to_24_hour_clock(25)-1) < DBL_EPSILON);
    assert(fabs(to_24_hour_clock(4)-4) < DBL_EPSILON);
    assert(fabs(to_24_hour_clock(28.5)-4.5) < DBL_EPSILON);

    cout << "all test for function to_24_hour_clock have been passed" << endl;

    cout << "vfdvfdv";

}