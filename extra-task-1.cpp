#include <cassert>
#include <cmath>
#include <cfloat>
#include <iostream>
    // 1) Разница во времени в секундах
    double seconds_difference(double time_1, double time_2) {
        return time_2 - time_1;
    }

    // 2) Разница во времени в часах
    double hours_difference(double time_1, double time_2) {
        return (time_2 - time_1) / 3600.0;
    }

    // 3) Конвертация часов, минут и секунд в часы с дробной частью
    double to_float_hours(int hours, int minutes, int seconds) {
        return hours + minutes / 60.0 + seconds / 3600.0;
    }

    // 4) Часы по 24-часовому формату
    double to_24_hour_clock(double hours) {
        return fmod(hours, 24.0);
    }

    // 5) Получение часов, минут и секунд из секунд с начала суток
    int get_hours(int seconds) {
        return seconds / 3600;
    }

    int get_minutes(int seconds) {
        return (seconds % 3600) / 60;
    }

    int get_seconds(int seconds) {
        return seconds % 60;
    }

    // 6) Конвертация времени в UTC
    double time_to_utc(int utc_offset, double time) {
        double utc_time = time - utc_offset;
        if (utc_time < 0) utc_time += 24;
        return fmod(utc_time, 24.0);
    }

    // 7)  Конвертация времени из UTC в локальное
    double time_from_utc(int utc_offset, double time) {
        double local_time = time + utc_offset;
        if (local_time < 0) local_time += 24;
        return fmod(local_time, 24.0);
    }


    int main() {
        // --- seconds_difference ---
        assert(fabs(seconds_difference(1800.0, 3600.0) - 1800.0) < DBL_EPSILON);
        assert(fabs(seconds_difference(3600.0, 1800.0) + 1800.0) < DBL_EPSILON);
        assert(fabs(seconds_difference(1800.0, 2160.0) - 360.0) < DBL_EPSILON);
        assert(fabs(seconds_difference(1800.0, 1800.0) - 0.0) < DBL_EPSILON);

        // --- hours_difference ---
        assert(fabs(hours_difference(1800.0, 3600.0) - 0.5) < DBL_EPSILON);
        assert(fabs(hours_difference(3600.0, 1800.0) + 0.5) < DBL_EPSILON);
        assert(fabs(hours_difference(1800.0, 2160.0) - 0.1) < DBL_EPSILON);
        assert(fabs(hours_difference(1800.0, 1800.0) - 0.0) < DBL_EPSILON);

        // --- to_float_hours ---
        assert(fabs(to_float_hours(0, 15, 0) - 0.25) < DBL_EPSILON);
        assert(fabs(to_float_hours(2, 45, 9) - 2.7525) < DBL_EPSILON);
        assert(fabs(to_float_hours(1, 0, 36) - 1.01) < DBL_EPSILON);

        // --- to_24_hour_clock ---
        assert(fabs(to_24_hour_clock(24) - 0.0) < DBL_EPSILON);
        assert(fabs(to_24_hour_clock(48) - 0.0) < DBL_EPSILON);
        assert(fabs(to_24_hour_clock(25) - 1.0) < DBL_EPSILON);
        assert(fabs(to_24_hour_clock(4) - 4.0) < DBL_EPSILON);
        assert(fabs(to_24_hour_clock(28.5) - 4.5) < DBL_EPSILON);

        // --- get_hours, get_minutes, get_seconds ---
        assert(get_hours(3800) == 1);
        assert(get_minutes(3800) == 3);
        assert(get_seconds(3800) == 20);

        // --- time_to_utc ---
        assert(fabs(time_to_utc(+0, 12.0) - 12.0) < DBL_EPSILON);
        assert(fabs(time_to_utc(+1, 12.0) - 11.0) < DBL_EPSILON);
        assert(fabs(time_to_utc(-1, 12.0) - 13.0) < DBL_EPSILON);
        assert(fabs(time_to_utc(-11, 18.0) - 5.0) < DBL_EPSILON);
        assert(fabs(time_to_utc(-1, 0.0) - 1.0) < DBL_EPSILON);
        assert(fabs(time_to_utc(-1, 23.0) - 0.0) < DBL_EPSILON);

        // --- time_from_utc ---
        assert(fabs(time_from_utc(+0, 12.0) - 12.0) < DBL_EPSILON);
        assert(fabs(time_from_utc(+1, 12.0) - 13.0) < DBL_EPSILON);
        assert(fabs(time_from_utc(-1, 12.0) - 11.0) < DBL_EPSILON);
        assert(fabs(time_from_utc(+6, 6.0) - 12.0) < DBL_EPSILON);
        assert(fabs(time_from_utc(-7, 6.0) - 23.0) < DBL_EPSILON);
        assert(fabs(time_from_utc(-1, 0.0) - 23.0) < DBL_EPSILON);
        assert(fabs(time_from_utc(-1, 23.0) - 22.0) < DBL_EPSILON);
        assert(fabs(time_from_utc(+1, 23.0) - 0.0) < DBL_EPSILON);

        std::cout << "Все тесты пройдены!" << std::endl;
        return 0;
    }

}
