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
        assert(std::fabs(hours_difference(1800.0, 3600.0) - 0.5) < DBL_EPSILON);
        assert((hours_difference(3600.0, 1800.0) + 0.5) < DBL_EPSILON);
        assert(std::fabs(hours_difference(1800.0, 2160.0) - 0.1) < DBL_EPSILON);
        assert(hours_difference(1800.0, 1800.0) == 0.0);
    }

    {
        // функция to_float_hours

    }

    return 0;
}
