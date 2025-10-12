#include "extra-task-1.h"
#include <cmath>
#include <float.h>

int main() {
	// seconds difference
	assert(fabs((seconds_difference(1800.0, 3600.0)) - 1800.0) < DBL_EPSILON);
	assert(fabs((seconds_difference(3600.0, 1800.0)) + 1800.0) < DBL_EPSILON);
	assert(fabs((seconds_difference(1800.0, 2160.0)) - 360.0) < DBL_EPSILON);
	assert(fabs((seconds_difference(1800.0, 1800.0)) - 0.0) < DBL_EPSILON);
	assert(fabs((seconds_difference(2132.1, 3214.5)) - 1082.4) < DBL_EPSILON);
	assert(fabs((seconds_difference(4513.5, 2341.7)) + 2171.8) < DBL_EPSILON);
	// hours difference
	assert(fabs((hours_difference(1800.0, 3600.0)) - 0.5) < DBL_EPSILON);
	assert(fabs((hours_difference(3600.0, 1800.0)) + 0.5) < DBL_EPSILON);
	assert(fabs((hours_difference(1800.0, 2160.0)) - 0.1) < DBL_EPSILON);
	assert(fabs((hours_difference(1800.0, 1800.0)) - 0.0) < DBL_EPSILON);
	assert(fabs((hours_difference(2161.1, 4321.1)) - 0.6) < DBL_EPSILON);
	assert(fabs((hours_difference(5321.5, 2621.5)) + 0.75) < DBL_EPSILON);
	// to float hours
	assert((to_float_hours(0, 15, 0) - 0.25) < DBL_EPSILON);
	assert((to_float_hours(2, 45, 9) - 2.7525) < DBL_EPSILON);
	assert((to_float_hours(1, 0, 36) - 1.01) < DBL_EPSILON);
	assert((to_float_hours(3, 30, 18) - 3.505) < DBL_EPSILON);
	assert((to_float_hours(5, 27, 27) - 5.7575) < DBL_EPSILON);
	// to 24 hour clock
	assert(to_24_hour_clock(24) == 0);
	assert(to_24_hour_clock(48) == 0);
	assert(to_24_hour_clock(25) == 1);
	assert(to_24_hour_clock(4) == 4);
	assert(to_24_hour_clock(28.5) == 4.5);
	assert(to_24_hour_clock(55.5) == 7.5);
	assert(to_24_hour_clock(7.7) == 7.7);
	// get hours
	assert(get_hours(3800) == 1);
	assert(get_hours(1500) == 0);
	assert(get_hours(8000) == 2);
	assert(get_hours(5000) == 1);
}