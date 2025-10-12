#include "extra-task-1.h"
#include "float.h"
#include <assert.h>
int main()
{
	/* > seconds_difference(1800.0, 3600.0)
		 1800.0

		 >> > seconds_difference(3600.0, 1800.0)
		 - 1800.0

		 >> > seconds_difference(1800.0, 2160.0)
		 360.0

		 >> > seconds_difference(1800.0, 1800.0)
		 0.0*/

	assert(fabs(seconds_difference(1800.0, 3600.0) - 1800.0) < DBL_EPSILON);
	assert(fabs(seconds_difference(3600.0, 1800.0) + 1800.0) < DBL_EPSILON);
	assert(fabs(seconds_difference(1800.0, 2160.0) - 360.0) < DBL_EPSILON);
	assert(fabs(seconds_difference(1800.0, 1800.0)) < DBL_EPSILON);

	/*>> > hours_difference(1800.0, 3600.0)
		0.5

		>> > hours_difference(3600.0, 1800.0)
		- 0.5

		>> > hours_difference(1800.0, 2160.0)
		0.1

		>> > hours_difference(1800.0, 1800.0)
		0.0*/

	assert(fabs(hours_difference(1800.0, 3600.0) - 0.5) < DBL_EPSILON);
	assert(fabs(hours_difference(3600.0, 1800.0) + 0.5) < DBL_EPSILON);
	assert(fabs(hours_difference(1800.0, 2160.0) - 0.1) < DBL_EPSILON);
	assert(fabs(hours_difference(1800.0, 1800.0)) < DBL_EPSILON);

	/*>> > to_float_hours(0, 15, 0)
		0.25

		>> > to_float_hours(2, 45, 9)
		2.7525

		>> > to_float_hours(1, 0, 36)
		1.01*/

	assert(fabs(to_float_hours(0, 15, 0) - 0.25) < DBL_EPSILON);
	assert(fabs(to_float_hours(2, 45, 9) - 2.7525) < DBL_EPSILON);
	assert(fabs(to_float_hours(1, 0, 36) - 1.01) < DBL_EPSILON);

	/*>> > to_24_hour_clock(24)
		0

		>> > to_24_hour_clock(48)
		0

		>> > to_24_hour_clock(25)
		1

		>> > to_24_hour_clock(4)
		4

		>> > to_24_hour_clock(28.5)
		4.5*/

	assert(fabs(to_24_hour_clock(24)) < DBL_EPSILON);
	assert(fabs(to_24_hour_clock(48)) < DBL_EPSILON);
	assert(fabs(to_24_hour_clock(25) - 1) < DBL_EPSILON);
	assert(fabs(to_24_hour_clock(4) - 4) < DBL_EPSILON);
	assert(fabs(to_24_hour_clock(28.5) - 4.5) < DBL_EPSILON);
}

