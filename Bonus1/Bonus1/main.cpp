#include "extra-task-1.h"
#include <cassert>
#include <cmath>
#include <float.h>

int main() {
	// seconds difference
	assert((fabs(seconds_difference(1800.0, 3600.0)) - 1800.0) < DBL_EPSILON);
	assert((fabs(seconds_difference(3600.0, 1800.0)) - 1800.0) < DBL_EPSILON);
	assert((fabs(seconds_difference(1800.0, 2160.0)) - 360.0) < DBL_EPSILON);
	assert((fabs(seconds_difference(1800.0, 1800.0)) - 0.0) < DBL_EPSILON);
	assert((fabs(seconds_difference(2132.1, 3214.5)) - 1082.4) < DBL_EPSILON);
	assert((fabs(seconds_difference(4513.5, 2341.7)) - 2171.8) < DBL_EPSILON);
}