#include "extra-task-1.h"
#include <cassert>
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
}