#include <iostream>
#include <cmath>
#include <cassert>
#include <cfloat>

double seconds_difference(double time_1, double time_2) {
    return time_2 - time_1;
}

double hours_difference(double time_1, double time_2) {
    return (time_2 - time_1) / 3600.0;
}

double to_float_hours(int hours, int minutes, int seconds) {
    return hours + minutes / 60.0 + seconds / 3600.0;
}

double to_24_hour_clock(double hours) {
    double result = std::fmod(hours, 24.0);
    if (result < 0) {
        result += 24;
    }
    return result;
}

double time_to_utc(int utc_offset, double time) {
    return to_24_hour_clock(time - utc_offset);
}

double time_from_utc(int utc_offset, double time) {
    return to_24_hour_clock(time + utc_offset);
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




int main() {
    // Проверка функции seconds_difference
    assert(std::fabs(seconds_difference(1800.0, 3600.0) - 1800.0) < DBL_EPSILON);
    assert(std::fabs(seconds_difference(3600.0, 1800.0) + 1800.0) < DBL_EPSILON);
    assert(std::fabs(seconds_difference(1800.0, 2160.0) - 360.0) < DBL_EPSILON);
    assert(std::fabs(seconds_difference(1800.0, 1800.0)) < DBL_EPSILON);

    // Проверка функции hours_difference
    assert(std::fabs(hours_difference(1800.0, 3600.0) - 0.5) < DBL_EPSILON);
    assert(std::fabs(hours_difference(3600.0, 1800.0) + 0.5) < DBL_EPSILON);
    assert(std::fabs(hours_difference(1800.0, 2160.0) - 0.1) < DBL_EPSILON);
    assert(std::fabs(hours_difference(1800.0, 1800.0)) < DBL_EPSILON);

    // Проверка функции to_float_hours
    assert(std::fabs(to_float_hours(0, 15, 0) - 0.25) < DBL_EPSILON);
    assert(std::fabs(to_float_hours(2, 45, 9) - 2.7525) < DBL_EPSILON);
    assert(std::fabs(to_float_hours(1, 0, 36) - 1.01) < DBL_EPSILON);

    // Проверка функции to_24_hour_clock
    assert(std::fabs(to_24_hour_clock(24)) < DBL_EPSILON);
    assert(std::fabs(to_24_hour_clock(48)) < DBL_EPSILON);
    assert(std::fabs(to_24_hour_clock(25) - 1) < DBL_EPSILON);
    assert(std::fabs(to_24_hour_clock(4) - 4) < DBL_EPSILON);
    assert(std::fabs(to_24_hour_clock(28.5) - 4.5) < DBL_EPSILON);

    // Проверка функции get_hours
    assert(get_hours(3800) == 1);

    // Проверка функции get_minutes
    assert(get_minutes(3800) == 3);

    // Проверка функции get_seconds
    assert(get_seconds(3800) == 20);

    // Проверка функции time_to_utc
    assert(std::fabs(time_to_utc(+0, 12.0) - 12.0) < DBL_EPSILON);
    assert(std::fabs(time_to_utc(+1, 12.0) - 11.0) < DBL_EPSILON);
    assert(std::fabs(time_to_utc(-1, 12.0) - 13.0) < DBL_EPSILON);
    assert(std::fabs(time_to_utc(-11, 18.0) - 5.0) < DBL_EPSILON);
    assert(std::fabs(time_to_utc(-1, 0.0) - 1.0) < DBL_EPSILON);
    assert(std::fabs(time_to_utc(-1, 23.0)) < DBL_EPSILON);

    // Проверка функции time_from_utc
    assert(std::fabs(time_from_utc(+0, 12.0) - 12.0) < DBL_EPSILON);
    assert(std::fabs(time_from_utc(+1, 12.0) - 13.0) < DBL_EPSILON);
    assert(std::fabs(time_from_utc(-1, 12.0) - 11.0) < DBL_EPSILON);
    assert(std::fabs(time_from_utc(+6, 6.0) - 12.0) < DBL_EPSILON);
    assert(std::fabs(time_from_utc(-7, 6.0) - 23.0) < DBL_EPSILON);
    assert(std::fabs(time_from_utc(-1, 0.0) - 23.0) < DBL_EPSILON);
    assert(std::fabs(time_from_utc(-1, 23.0) - 22.0) < DBL_EPSILON);
    assert(std::fabs(time_from_utc(+1, 23.0)) < DBL_EPSILON);

    std::cout << "All tests passed!" << std::endl;

    // Примеры использования функций
    std::cout << "seconds_difference(1800.0, 3600.0): " << seconds_difference(1800.0, 3600.0) << std::endl;
    std::cout << "hours_difference(1800.0, 3600.0): " << hours_difference(1800.0, 3600.0) << std::endl;
    std::cout << "to_float_hours(2, 45, 9): " << to_float_hours(2, 45, 9) << std::endl;
    std::cout << "to_24_hour_clock(25): " << to_24_hour_clock(25) << std::endl;
    std::cout << "get_hours(3800): " << get_hours(3800) << std::endl;
    std::cout << "get_minutes(3800): " << get_minutes(3800) << std::endl;
    std::cout << "get_seconds(3800): " << get_seconds(3800) << std::endl;
    std::cout << "time_to_utc(+1, 12.0): " << time_to_utc(+1, 12.0) << std::endl;
    std::cout << "time_from_utc(-1, 12.0): " << time_from_utc(-1, 12.0) << std::endl;

    std::cout << "time_to_utc(+1, 12.0): " << time_to_utc(+1, 12.0) << std::endl; // Должно быть 11.0
    std::cout << "time_from_utc(+1, 12.0): " << time_from_utc(+1, 12.0) << std::endl; // Должно быть 13.0


    return 0;
}
