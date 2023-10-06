#include <cassert>
#include <iostream>

//Return the number of seconds later that a time in seconds
//time_2 is than a time in seconds time_1.
double seconds_difference(double time_1, double time_2)
{
    return time_2 - time_1;
}

//Return the number of hours later that a time in seconds
//time_2 is than a time in seconds time_1.
double hours_difference(double time_1, double time_2)
{
    return (time_2 - time_1) / 3600;
}

//Return the total number of hours in the specified number
//of hours, minutes, and seconds.
//Precondition: 0 <= minutes < 60  and  0 <= seconds < 60
double to_float_hours(int hours, int minutes, int seconds)
{
    assert(0 <= minutes && minutes < 60);
    assert(0 <= seconds && seconds < 60);
    return hours + minutes / 60.0 + seconds / 3600.0;
}

//hours is a number of hours since midnight. Return the
//hour as seen on a 24-hour clock.
//Precondition: hours >= 0
double to_24_hour_clock(double hours)
{
    assert(hours >= 0);
    return  hours - (((int)hours / 24) * 24);
    /*
        - You may wish to inspect various function in <cmath> to work
        with integer and fractional part of a hours separately.
        - No
    */
}

/*
    Implement three functions
        * get_hours
        * get_minutes
        * get_seconds
    They are used to determine the hours part, minutes part and seconds part 
    of a time in seconds. E.g.:

    In other words, if 3800 seconds have elapsed since midnight, 
    it is currently 01:03:20 (hh:mm:ss).
*/

int get_hours(int seconds) {
    return seconds / 3600;
}
int get_minutes(int seconds) {
    return (seconds / 60) % 60;
}

int get_seconds(int seconds) {
    return seconds % 60;
}

double time_to_utc(int utc_offset, double time)
{
    return (time - utc_offset >= 24) ? (time - utc_offset - 24) : (time - utc_offset < 0) ? (time - utc_offset + 24) : (time - utc_offset);
    /*
        Return time at UTC+0, where utc_offset is the number of hours away from
        UTC+0.
        You may be interested in:
        https://en.wikipedia.org/wiki/Coordinated_Universal_Time


    */
}

double time_from_utc(int utc_offset, double time)
{
    return (time + utc_offset >= 24) ? (time + utc_offset - 24) : (time + utc_offset < 0) ? (24 + time + utc_offset) : (time + utc_offset);
    /*
        Return UTC time in time zone utc_offset.


    */
}

const double DOUBLE_EPS = 1e-7;

int main() {
    std::cout << "hello! main function contains asserts only!" << std::endl;
    //seconds_difference test
    assert(abs(seconds_difference(1800.0, 3600.0) - 1800.0) < DOUBLE_EPS);
    assert(abs(seconds_difference(3600.0, 1800.00) - -1800.0) < DOUBLE_EPS);
    assert(abs(seconds_difference(1800.0, 2160.0) - 360.0) < DOUBLE_EPS);
    assert(abs(seconds_difference(1800.0, 1800.0) - 0.0) < DOUBLE_EPS);

    //hours_difference
    assert(abs(hours_difference(1800.0, 3600.0) - 0.5) < DOUBLE_EPS);
    assert(abs(hours_difference(3600.0, 1800.0) - -0.5) < DOUBLE_EPS);
    assert(abs(hours_difference(1800.0, 2160.0) - 0.1) < DOUBLE_EPS);
    assert(abs(hours_difference(1800.0, 1800.0) - 0.0) < DOUBLE_EPS);

    //to_float_hours
    assert(abs(to_float_hours(0, 15, 0) - 0.25) < DOUBLE_EPS);
    assert(abs(to_float_hours(2, 45, 9) - 2.7525) < DOUBLE_EPS);
    assert(abs(to_float_hours(1, 0, 36) - 1.01) < DOUBLE_EPS);

    //to_24_hour_clock
    assert(abs(to_24_hour_clock(24) - 0) < DOUBLE_EPS);
    assert(abs(to_24_hour_clock(48) - 0) < DOUBLE_EPS);
    assert(abs(to_24_hour_clock(25) - 1) < DOUBLE_EPS);
    assert(abs(to_24_hour_clock(4) - 4) < DOUBLE_EPS);
    assert(abs(to_24_hour_clock(28.5) - 4.5) < DOUBLE_EPS);

    //get_hours, get_minutes, get_seconds test
    assert(get_hours(3800) == 1);
    assert(get_minutes(3800) == 3);
    assert(get_seconds(3800) == 20);

    //time_to_utc test

    assert(abs(time_to_utc(+0, 12.0) - 12.0) < DOUBLE_EPS);
    assert(abs(time_to_utc(+1, 12.0) - 11.0) < DOUBLE_EPS);
    assert(abs(time_to_utc(-1, 12.0) - 13.0) < DOUBLE_EPS);
    assert(abs(time_to_utc(-11, 18.0) - 5.0) < DOUBLE_EPS);
    assert(abs(time_to_utc(-1, 0.0) - 1.0) < DOUBLE_EPS);
    assert(abs(time_to_utc(-1, 23.0) - 0.0) < DOUBLE_EPS);
    assert(abs(time_to_utc(-5, 3.0) - 8) < DOUBLE_EPS);

    //time_from_utc test
    assert(abs(time_from_utc(+0, 12.0) - 12.0) < DOUBLE_EPS);
    assert(abs(time_from_utc(+1, 12.0) - 13.0) < DOUBLE_EPS);
    assert(abs(time_from_utc(-1, 12.0) - 11.0) < DOUBLE_EPS);
    assert(abs(time_from_utc(+6, 6.0) - 12.0) < DOUBLE_EPS);
    assert(abs(time_from_utc(-7, 6.0) - 23.0) < DOUBLE_EPS);
    assert(abs(time_from_utc(-1, 0.0) - 23.0) < DOUBLE_EPS);
    assert(abs(time_from_utc(-1, 23.0) - 22.0) < DOUBLE_EPS);
    assert(abs(time_from_utc(+1, 23.0) - 0.0) < DOUBLE_EPS);
}