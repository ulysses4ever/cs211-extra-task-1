#include <cmath>
#include <assert.h>
#include <iostream>
double seconds_difference(double time_1, double time_2)
{
    return time_2 - time_1;
}

double hours_difference(double time_1, double time_2)
{
    return seconds_difference(time_1, time_2) / 3600.0;
}

double to_float_hours(int hours, int minutes, int seconds)
{
    return hours + (minutes / 60.0) + (seconds / 3600.0);
}

double to_24_hour_clock(double hours)
{
    return fmod(hours, 24.0);
}


    
int get_hours(int seconds) {
    return seconds / 3600;
}

int get_minutes(int seconds) {
    return (seconds % 3600) / 60;
}

int get_seconds(int seconds) {
    return seconds % 60;
}

double time_to_utc(int utc_offset, double time)
{
  
    return fmod((time - utc_offset), 24.0);
}

double time_from_utc(int utc_offset, double time)
{
    
    return fmod((time + utc_offset), 24.0);

}
const double eps = 10e-15;
int main() {



    assert(seconds_difference(1800.0, 3600.0) - 1800.0 < eps);
    assert(seconds_difference(3600.0, 1800.0) + 1800.0 < eps);
    assert(seconds_difference(1800.0, 2160) - 360.0 < eps);
    assert(seconds_difference(1800.0, 1800.0) - 0.0 < eps);


    assert(hours_difference(1800.0, 3600.0) - 0.5 < eps);
    assert(hours_difference(3600.0, 1800.0) - 0.5 < eps);
    assert(hours_difference(1800.0, 2160.0) - 0.1 < eps);
    assert(hours_difference(1800.0, 1800.0) - 0.0 < eps);


    assert(to_float_hours(0, 15, 0) - 0.25 < eps);
    assert(to_float_hours(2, 45, 9) - 2.7525 < eps);
    assert(to_float_hours(1, 0, 36) - 1.01 < eps);


    assert(to_24_hour_clock(24) - 0 < eps);
    assert(to_24_hour_clock(48) - 0 < eps);
    assert(to_24_hour_clock(25) - 1 < eps);
    assert(to_24_hour_clock(4) - 4 < eps);
    assert(to_24_hour_clock(28.5) - 4.5 < eps);


    assert(get_hours(3800) - 1 < eps);
    assert(get_minutes(3800) - 3 < eps);
    assert(get_seconds(3800) - 20 < eps);


    assert(time_from_utc(+0, 12.0) - 12.0 < eps);
    assert(time_from_utc(+1, 12.0) - 13.0 < eps);
    assert(time_from_utc(-1, 12.0) - 11.0 < eps);
    assert(time_from_utc(+6, 6.0) - 12.0 < eps);
    assert(time_from_utc(-1, 0.0) - 23.0 < eps);
    assert(time_from_utc(+1, 23.0) - 0.0 < eps);



    assert(time_to_utc(+0, 12.0) - 12.0 < eps);
    assert(time_to_utc(+1, 12.0) - 11.0 < eps);
    assert(time_to_utc(-1, 12.0) - 13.0 < eps);
    assert(time_to_utc(-11, 18.0) - 5.0 < eps);
    assert(time_to_utc(-1, 0.0) - 1.0 < eps);
    assert(time_to_utc(-1, 23.0) - 0.0 < eps);
    std::cout << "Tests ended successfully";
}
