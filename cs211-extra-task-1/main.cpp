#include "extra-task-1.h"
#include <iostream>
#include <cassert>
#include <cmath>
#include <cfloat>

int main() {
	//seconds_difference assert
	assert(fabs(seconds_difference(1800.0, 3600.0) - 1800.0) < DBL_EPSILON);
	assert(fabs(seconds_difference(3600.0, 1800.0) - -1800.0) < DBL_EPSILON);
	assert(fabs(seconds_difference(1800.0, 2160.0) - 360.0) < DBL_EPSILON);
	assert(fabs(seconds_difference(1800.0, 1800.0) - 0.0) < DBL_EPSILON);

	//hours_difference
	assert(fabs(hours_difference(1800.0, 3600.0) - 0.5) < DBL_EPSILON);
	assert(fabs(hours_difference(3600.0, 1800.0) - -0.5) < DBL_EPSILON);
	assert(fabs(hours_difference(1800.0, 2160.0) - 0.1) < DBL_EPSILON);
	assert(fabs(hours_difference(1800.0, 1800.0) - 0.0) < DBL_EPSILON);

    // to_float_hours assert
    assert(fabs(to_float_hours(0, 15, 0) - 0.25) < DBL_EPSILON);
    assert(fabs(to_float_hours(2, 45, 9) - 2.7525) < DBL_EPSILON);
    assert(fabs(to_float_hours(1, 0, 36) - 1.01) < DBL_EPSILON);

    // to_24_hour_clock assert
    assert(fabs(to_24_hour_clock(24) - 0.0) < DBL_EPSILON);
    assert(fabs(to_24_hour_clock(48) - 0.0) < DBL_EPSILON);
    assert(fabs(to_24_hour_clock(25) - 1.0) < DBL_EPSILON);
    assert(fabs(to_24_hour_clock(4) - 4.0) < DBL_EPSILON);
    assert(fabs(to_24_hour_clock(28.5) - 4.5) < DBL_EPSILON);

    // get_hours assert
    assert(get_hours(3800) == 1);
    assert(get_hours(3600) == 1);
    assert(get_hours(7200) == 2);

    // get_minutes assert
    assert(get_minutes(3800) == 3);
    assert(get_minutes(3661) == 1);
    assert(get_minutes(7261) == 1);

    // get_seconds assert
    assert(get_seconds(3800) == 20);
    assert(get_seconds(3661) == 1);
    assert(get_seconds(7261) == 1);

    // time_to_utc assert
    assert(fabs(time_to_utc(0, 12.0) - 12.0) < DBL_EPSILON);
    assert(fabs(time_to_utc(1, 12.0) - 11.0) < DBL_EPSILON);
    assert(fabs(time_to_utc(-1, 12.0) - 13.0) < DBL_EPSILON);
    assert(fabs(time_to_utc(-11, 18.0) - 5.0) < DBL_EPSILON);
    assert(fabs(time_to_utc(-1, 0.0) - 1.0) < DBL_EPSILON);
    assert(fabs(time_to_utc(-1, 23.0) - 0.0) < DBL_EPSILON);

    // time_from_utc assert
    assert(fabs(time_from_utc(0, 12.0) - 12.0) < DBL_EPSILON);
    assert(fabs(time_from_utc(1, 12.0) - 13.0) < DBL_EPSILON);
    assert(fabs(time_from_utc(-1, 12.0) - 11.0) < DBL_EPSILON);
    assert(fabs(time_from_utc(+6, 6.0) - 12.0) < DBL_EPSILON);
    assert(fabs(time_from_utc(-7, 6.0) - 23.0) < DBL_EPSILON);
    assert(fabs(time_from_utc(-1, 0.0) - 23.0) < DBL_EPSILON);
    assert(fabs(time_from_utc(-1, 23.0) - 22.0) < DBL_EPSILON);
    assert(fabs(time_from_utc(+1, 23.0) - 0.0) < DBL_EPSILON);
}

