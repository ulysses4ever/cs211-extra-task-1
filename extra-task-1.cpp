#include <iostream>
#include <cfloat>
#include <cassert>

double hours_difference(double time_1, double time_2)
{
    return (time_1 - time_2) / 3600;
}

double hours_difference(double time_1, double time_2)
{
    return hours + minutes / 60 + seconds / 3600;
}

double to_float_hours(int hours, int minutes, int seconds)
{
    return hours + minutes / 60 + seconds / 3600;
}

double to_24_hour_clock(double hours)
{ 
    return  (int)hours % 24 + hours - (int)hours;
}

int get_hours(int seconds) {
    return seconds / 3600;
}

int get_minutes(int seconds) {
    return seconds % 3600 / 60;
}

int get_seconds(int seconds) {
    return seconds % 60;
}

double time_to_utc(int utc_offset, double time)
{
    double res = time - utc_offset;
    return res < 24 ? res : res - 24;
}

double time_from_utc(int utc_offset, double time)
{
    /*
        Return UTC time in time zone utc_offset.

        >>> time_from_utc(+0, 12.0)
        12.0
 
        >>> time_from_utc(+1, 12.0)
        13.0
 
        >>> time_from_utc(-1, 12.0)
        11.0
 
        >>> time_from_utc(+6, 6.0)
        12.0
 
        >>> time_from_utc(-7, 6.0)
        23.0
 
        >>> time_from_utc(-1, 0.0)
        23.0
 
        >>> time_from_utc(-1, 23.0)
        22.0
 
        >>> time_from_utc(+1, 23.0)
        0.0
    */
}
int main() {
    double const eps = DBL_EPSILON;
    // Тесты для seconds_difference
    assert(fabs(seconds_difference(1800.0, 3600.0) - 1800.0) < eps);
    assert(fabs(seconds_difference(3600.0, 1800.0) + 1800.0) < eps);
    assert(fabs(seconds_difference(1800.0, 2160.0) - 360.0) < eps);
    assert(fabs(seconds_difference(1800.0, 1800.0) - 0.0) < eps);
    std::cout << "функция seconds_difference прошла тесты!\n";

    // Тесты для hours_difference
    std::cout << "\nTesting hours_difference...";
    assert(fabs(hours_difference(1800.0, 3600.0) - 0.5) < eps);
    assert(fabs(hours_difference(3600.0, 1800.0) + 0.5) < eps);
    assert(fabs(hours_difference(1800.0, 2160.0) - 0.1) < eps);
    assert(fabs(hours_difference(1800.0, 1800.0) - 0.0) < eps);
    std::cout << "hours_difference tests passed!";
    std::cout << "функция seconds_difference прошла тесты!\n";

    // Тесты для to_float_hours
    std::cout << "\nTesting to_float_hours...";
    assert(fabs(to_float_hours(0, 15, 0) - 0.25) < eps);
    assert(fabs(to_float_hours(2, 45, 9) - 2.7525) < eps);
    assert(fabs(to_float_hours(1, 0, 36) - 1.01) < eps);
    std::cout << "to_float_hours tests passed!";
    std::cout << "функция seconds_difference прошла тесты!\n";

    // Тесты для to_24_hour_clock
    std::cout << "\nTesting to_24_hour_clock...";
    assert(fabs(to_24_hour_clock(24) - 0.0) < eps);
    assert(fabs(to_24_hour_clock(48) - 0.0) < eps);
    assert(fabs(to_24_hour_clock(25) - 1.0) < eps);
    assert(fabs(to_24_hour_clock(4) - 4.0) < eps);
    assert(fabs(to_24_hour_clock(28.5) - 4.5) < eps);
    std::cout << "to_24_hour_clock tests passed!";
    std::cout << "функция seconds_difference прошла тесты!\n";

    // Тесты для get_hours, get_minutes, get_seconds
    std::cout << "\nTesting get_hours, get_minutes, get_seconds...";
    assert(get_hours(3800) == 1);
    assert(get_minutes(3800) == 3);
    assert(get_seconds(3800) == 20);
    std::cout << "get_hours/get_minutes/get_seconds tests passed!";
    std::cout << "функция seconds_difference прошла тесты!\n";
    
    // Тесты для time_to_utc
    std::cout << "\nTesting time_to_utc...";
    assert(fabs(time_to_utc(0, 12.0) - 12.0) < eps);
    assert(fabs(time_to_utc(1, 12.0) - 11.0) < eps);
    assert(fabs(time_to_utc(-1, 12.0) - 13.0) < eps);
    assert(fabs(time_to_utc(-11, 18.0) - 5.0) < eps);
    assert(fabs(time_to_utc(-1, 0.0) - 1.0) < eps);
    assert(fabs(time_to_utc(-1, 23.0) - 0.0) < eps);
    std::cout << "time_to_utc tests passed!";
    std::cout << "функция seconds_difference прошла тесты!\n";


}
