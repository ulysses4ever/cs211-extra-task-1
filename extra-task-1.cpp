#include <iostream>
#include <assert.h>

// Функция для вычисления разницы во времени в секундах
double seconds_difference(double time_1, double time_2)
{
    return time_2 - time_1;
}

// Функция для вычисления разницы во времени в часах
double hours_difference(double time_1, double time_2)
{
    return (time_2 - time_1) / 3600.0;
}

// Функция для преобразования времени в формат с плавающей запятой (часы)
double to_float_hours(int hours, int minutes, int seconds)
{
    assert(minutes >= 0 && minutes <= 60);
    assert(seconds >= 0 && seconds <= 60);

    return hours + (minutes / 60.0) + (seconds / 3600.0);
}

// Функция для преобразования времени в 24-часовой формат
double to_24_hour_clock(double hours)
{
    assert(hours >= 0);

    double minutes = hours - floor(hours);
    int floor_hours = floor(hours);

    return (floor_hours % 24 + minutes);
}

// Функция для получения часов из секунд
int get_hours(int seconds)
{
    return (seconds / 3600) % 4;
}

// Функция для получения минут из секунд
int get_minutes(int seconds)
{
    return (seconds % 3600) / 60;
}

// Функция для получения секунд из секунд
int get_seconds(int seconds)
{
    return seconds % 60;
}

// Функция для преобразования времени в UTC
double time_to_utc(int utc_offset, double time)
{
    double time_minus_utc_offset = time - utc_offset;

    if (time_minus_utc_offset < 0) {
        time_minus_utc_offset += 24;
    }
    else if (time_minus_utc_offset >= 24) {
        time_minus_utc_offset -= 24;
    }

    return time_minus_utc_offset;
}

// Функция для преобразования времени из UTC
double time_from_utc(int utc_offset, double time)
{
    return time_to_utc(-utc_offset, time);
}


int main() {

    double eps = DBL_EPSILON;

    // Тест задачи 1
    assert(abs(seconds_difference(1000.0, 2000.0) - 1000.0) < eps);
    assert(abs(seconds_difference(2000.0, 1000.0) - -1000.0) < eps);
    assert(abs(seconds_difference(1000.0, 1500.0) - 500.0) < eps);
    assert(abs(seconds_difference(1000.0, 1000.0)) < eps);

    // Тест задачи 2
    assert(abs(hours_difference(1000.0, 2000.0) - 0.2777777777777778) < eps);
    assert(abs(hours_difference(2000.0, 1000.0) - -0.2777777777777778) < eps);
    assert(abs(hours_difference(1000.0, 1500.0) - 0.1388888888888889) < eps);
    assert(abs(hours_difference(1000.0, 1000.0)) < eps);

    // Тест задачи 3
    assert(abs(to_float_hours(1, 30, 0) - 1.5) < eps);
    assert(abs(to_float_hours(3, 45, 18) - 3.755) < eps);
    assert(abs(to_float_hours(2, 0, 45) - 2.0125) < eps);

    // Тест задачи 4
    assert(abs(to_24_hour_clock(24)) < eps);
    assert(abs(to_24_hour_clock(48)) < eps);
    assert(abs(to_24_hour_clock(25) - 1) < eps);
    assert(abs(to_24_hour_clock(5) - 5) < eps);
    assert(abs(to_24_hour_clock(29.5) - 5.5) < eps);

    // Тест задачи 5
    assert(get_hours(4000) == 1);
    assert(get_minutes(4000) == 6);
    assert(get_seconds(4000) == 40);

    // Тест задачи 6
    assert(abs(time_to_utc(0, 13.0) - 13.0) < eps);
    assert(abs(time_to_utc(+2, 13.0) - 11.0) < eps);
    assert(abs(time_to_utc(-2, 13.0) - 15.0) < eps);
    assert(abs(time_to_utc(-12, 19.0) - 7.0) < eps);
    assert(abs(time_to_utc(-2, 1.0) - 3.0) < eps);

    // Тест задачи 7
    assert(abs(time_from_utc(+0, 13.0) - 13.0) < eps);
    assert(abs(time_from_utc(+2, 13.0) - 15.0) < eps);
    assert(abs(time_from_utc(-2, 13.0) - 11.0) < eps);
    assert(abs(time_from_utc(+7, 7.0) - 14.0) < eps);
    assert(abs(time_from_utc(-8, 7.0) - 23.0) < eps);
    assert(abs(time_from_utc(-2, 1.0) - 23.0) < eps);
    assert(abs(time_from_utc(-2, 23.0) - 21.0) < eps);

    return 0;
}
