#include "extra-task-1.h"

int main() {

    {
        // функция seconds_difference
        assert(seconds_difference(1800.0, 3600.0) == 1800.0);
        assert(seconds_difference(3600.0, 1800.0) == -1800.0);
        assert(seconds_difference(1800.0, 2160.0) == 360.0);
        assert(seconds_difference(1800.0, 1800.0) == 0.0);
    }

    {
        // функция hours_difference
        assert(std::fabs(hours_difference(1800.0, 3600.0)) - 0.5 < DBL_EPSILON);
        assert(std::fabs(hours_difference(3600.0, 1800.0)) - 0.5 < DBL_EPSILON);
        assert(std::fabs(hours_difference(1800.0, 2160.0)) - 0.1 < DBL_EPSILON);
        assert(hours_difference(1800.0, 1800.0) < DBL_EPSILON);
    }

    {
        // функция to_float_hours
        assert(std::fabs(to_float_hours(0, 15, 0)) - 0.25 < DBL_EPSILON);
        assert(std::fabs(to_float_hours(2, 45, 9)) - 2.7525 < DBL_EPSILON);
        assert(std::fabs(to_float_hours(1, 0, 36)) - 1.01 < DBL_EPSILON);
    }

    {
        // функция to_24_hour_clock
        assert(to_24_hour_clock(24) == 0);
        assert(to_24_hour_clock(48) == 0);
        assert(to_24_hour_clock(25) == 1);
        assert(to_24_hour_clock(4) == 4);
        assert(std::fabs(to_24_hour_clock(28.5)) - 4.5 < DBL_EPSILON);
    }

    {
        // функции get_hours, get_minutes, get_seconds
        assert(std::fabs(get_hours(3800) - 1) < DBL_EPSILON);
        assert(std::fabs(get_minutes(3800) - 3) < DBL_EPSILON);
        assert(std::fabs(get_seconds(3800) - 20) < DBL_EPSILON);
    }

    {
        // функция time_to_utc
        assert(std::fabs(time_to_utc(+0, 12.0) - 12.0) < DBL_EPSILON);
        assert(std::fabs(time_to_utc(+1, 12.0) - 11.0) < DBL_EPSILON);
        assert(std::fabs(time_to_utc(-1, 12.0) - 13.0) < DBL_EPSILON);
        assert(std::fabs(time_to_utc(-11, 18.0) - 5.0) < DBL_EPSILON);
        assert(std::fabs(time_to_utc(-1, 0.0) - 1.0) < DBL_EPSILON);
        assert(std::fabs(time_to_utc(-1, 23.0)) < DBL_EPSILON);
    }

    {
        // функция time_from_utc
        assert(std::fabs(time_from_utc(+0, 12.0) - 12.0) < DBL_EPSILON);
        assert(std::fabs(time_from_utc(+1, 12.0) - 13.0) < DBL_EPSILON);
        assert(std::fabs(time_from_utc(-1, 12.0) - 11.0) < DBL_EPSILON);
        assert(std::fabs(time_from_utc(+6, 6.0) - 12.0) < DBL_EPSILON);
        assert(std::fabs(time_from_utc(-7, 6.0) - 23.0) < DBL_EPSILON);
        assert(std::fabs(time_from_utc(-1, 0.0) - 23.0) < DBL_EPSILON);
        assert(std::fabs(time_from_utc(-1, 23.0) - 22.0) < DBL_EPSILON);
        assert(std::fabs(time_from_utc(+1, 23.0)) < DBL_EPSILON);
    }

    return 0;
}
