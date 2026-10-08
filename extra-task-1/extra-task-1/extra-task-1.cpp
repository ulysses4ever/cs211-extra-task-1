#include "extra-task-1.h"

//Возвращает количество секунд, на сколько time_2 больше time_1
double seconds_difference(double time_1, double time_2)
{
    return (time_2 - time_1);
}

//Возвращает количество часов, на сколько time_2 больше time_1
double hours_difference(double time_1, double time_2)
{
    return seconds_difference(time_1, time_2) / 3600;
}

//Возвращает общее количество часов в указанном количестве часов, минут и секунд
double to_float_hours(int hours, int minutes, int seconds)
{
    assert((minutes >= 0) && (minutes < 60) && (seconds >= 0) && (seconds < 60));
    return (hours * 3600 + minutes * 60 + seconds) / 3600.0;
}

//Возвращает час так, как он отображается на 24-часовом циферблате
double to_24_hour_clock(double hours)
{
    return fmod(hours, 24);
}

//Возвращает часы с времени в секундах
int get_hours(int seconds)
{
    return (seconds / 3600);
}

//Возвращает минуты с времени в секундах
int get_minutes(int seconds)
{
    return ((seconds % 3600) / 60);
}

//Возвращает секунды с времени в секундах
int get_seconds(int seconds)
{
    return (seconds % 60);
}

//Возвращает время в UTC+0,
double time_to_utc(int utc_offset, double time)
{
    double res = to_24_hour_clock(time - utc_offset);
    if (res < 0)
        res += 24.0;
    return res;
}

//Возвращает время в часовом поясе utc_offset
double time_from_utc(int utc_offset, double time)
{
    double res = to_24_hour_clock(time + utc_offset);
    if (res < 0)
        res += 24.0;
    return res;
}
