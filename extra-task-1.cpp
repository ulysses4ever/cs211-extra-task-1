#include <iostream>
#include <cfloat>
#include <cassert>

//функция, которая считает разницу во времени
double seconds_difference(double time_1, double time_2)
{
    return time_2 - time_1;
}

//функция, которая считает разницу в часах
double hours_difference(double time_1, double time_2)
{
    return (time_1 - time_2) / 3600.0;
}

//функция, которая переводит время в часы
double to_float_hours(int hours, int minutes, int seconds)
{
    return hours + minutes / 60.0 + seconds / 3600.0;
}

//функция, которая переводит часы в 24-формат
double to_24_hour_clock(double hours)
{ 
    return  floor(hours) % 24 + (hours - floor(hours));
}
//функция, которая из времени вернет челую часть часов
int get_hours(int seconds) {
    return seconds / 3600;
}

//функция, которая из времени вернет челую часть минут
int get_minutes(int seconds) {
    return seconds % 3600 / 60;
}

//функция, которая из времени вернет секунды
int get_seconds(int seconds) {
    return seconds % 60;
}

//перевод в UTC
double time_to_utc(int utc_offset, double time)
{
    double res = time - utc_offset;
    if (res < 0) {
        res += 24;
    }
    else if (res >= 24) {
        res -= 24;
    }
    return res;
}

//перевод из UTC
double time_from_utc(int utc_offset, double time)
{
    double res = time + utc_offset;
    if (res < 0) {
        res += 24;
    }
    else if (res >= 24) {
        res -= 24;
    }
    return res;
}

//тесты
int main() {
    double const eps = DBL_EPSILON;
    // Тесты для seconds_difference
    assert(fabs(seconds_difference(1800.0, 3600.0) - 1800.0) < eps);
    assert(fabs(seconds_difference(3600.0, 1800.0) + 1800.0) < eps);
    assert(fabs(seconds_difference(1800.0, 2160.0) - 360.0) < eps);
    assert(fabs(seconds_difference(1800.0, 1800.0) - 0.0) < eps);
    std::cout << "функция seconds_difference прошла тесты!\n";

    // Тесты для hours_difference
    assert(fabs(hours_difference(1800.0, 3600.0) - 0.5) < eps);
    assert(fabs(hours_difference(3600.0, 1800.0) + 0.5) < eps);
    assert(fabs(hours_difference(1800.0, 2160.0) - 0.1) < eps);
    assert(fabs(hours_difference(1800.0, 1800.0) - 0.0) < eps);
    std::cout << "функция seconds_difference прошла тесты!\n";

    // Тесты для to_float_hours
    assert(fabs(to_float_hours(0, 15, 0) - 0.25) < eps);
    assert(fabs(to_float_hours(2, 45, 9) - 2.7525) < eps);
    assert(fabs(to_float_hours(1, 0, 36) - 1.01) < eps);
    std::cout << "функция seconds_difference прошла тесты!\n";

    // Тесты для to_24_hour_clock
    assert(fabs(to_24_hour_clock(24) - 0.0) < eps);
    assert(fabs(to_24_hour_clock(48) - 0.0) < eps);
    assert(fabs(to_24_hour_clock(25) - 1.0) < eps);
    assert(fabs(to_24_hour_clock(4) - 4.0) < eps);
    assert(fabs(to_24_hour_clock(28.5) - 4.5) < eps);
    std::cout << "функция seconds_difference прошла тесты!\n";

    // Тесты для get_hours, get_minutes, get_seconds
    assert(get_hours(3800) == 1);
    assert(get_minutes(3800) == 3);
    assert(get_seconds(3800) == 20);
    std::cout << "функция seconds_difference прошла тесты!\n";
    
    // Тесты для time_to_utc
    assert(fabs(time_to_utc(0, 12.0) - 12.0) < eps);
    assert(fabs(time_to_utc(1, 12.0) - 11.0) < eps);
    assert(fabs(time_to_utc(-1, 12.0) - 13.0) < eps);
    assert(fabs(time_to_utc(-11, 18.0) - 5.0) < eps);
    assert(fabs(time_to_utc(-1, 0.0) - 1.0) < eps);
    assert(fabs(time_to_utc(-1, 23.0) - 0.0) < eps);
    std::cout << "функция seconds_difference прошла тесты!\n";

    // Тесты для time_from_utc
    assert(fabs(time_from_utc(0, 12.0) - 12.0) < eps);
    assert(fabs(time_from_utc(1, 12.0) - 13.0) < eps);
    assert(fabs(time_from_utc(-1, 12.0) - 11.0) < eps);
    assert(fabs(time_from_utc(6, 6.0) - 12.0) < eps);
    assert(fabs(time_from_utc(-7, 6.0) - 23.0) < eps);
    assert(fabs(time_from_utc(-1, 0.0) - 23.0) < eps);
    assert(fabs(time_from_utc(-1, 23.0) - 22.0) < eps);
    assert(fabs(time_from_utc(1, 23.0) - 0.0) < eps);
    std::cout << "функция seconds_difference прошла тесты!\n";

    std::cout << "\nВсе тесты пройдены!";
}
