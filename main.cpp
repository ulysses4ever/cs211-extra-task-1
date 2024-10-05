#include <iostream>
using namespace std;
#include "extra-task-1.h";

void main()
{
    assert(seconds_difference(3600, 1800) == -1800);
    assert(hours_difference(1800.0, 3600.0) == 0.5);
    assert(to_float_hours(0, 15, 0) == 0.25);
    assert(to_24_hour_clock(25) == 1);
    assert(time_to_utc(+0, 12.0) == 12.0);
    assert(time_from_utc(+1, 12.0) == 13.0);
}