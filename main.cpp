#include <iostream>
#include <assert.h>
#include "extra-task-1.h"


int main() {
    assert(seconds_difference(1800.0, 3600.0) == 1800.0);
    assert(seconds_difference(3600.0, 1800.0) == -1800.0);
    assert(seconds_difference(1800.0, 2160.0) == 360);
    assert(seconds_difference(1800.0, 1800.0) == 0.0);


    assert(hours_difference(1800.0, 3600.0) == 0.5);
    assert(hours_difference(3600.0, 1800.0) == -0.5);
    assert(hours_difference(1800.0, 2160.0) == 0.1);
    assert(hours_difference(1800.0, 1800.0) == 0.0);


    assert(to_24_hour_clock(24) == 0);
    assert(to_24_hour_clock(48) == 0);
    assert(to_24_hour_clock(25) == 1);
    assert(to_24_hour_clock(4) == 4);
    assert(to_24_hour_clock(28.5) == 4.5);


    assert(get_hours(3800) == 1);
    assert(get_minutes(3800) == 3);
    assert(get_seconds(3800) == 20);


    assert(time_to_utc(+0, 12.0) == 12.0);
    assert(time_to_utc(+1, 12.0) == 11.0);
    assert(time_to_utc(-1, 12.0) == 13.0);
    assert(time_to_utc(-11, 18.0) == 5.0);
    assert(time_to_utc(-1, 0.0) == 1.0);
    assert(time_to_utc(-1, 23.0 == 0.0));
    assert(time_to_utc(+12, 23.0) == 11.0);


}