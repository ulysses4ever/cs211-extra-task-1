#include <iostream>
#include <cmath>
#include <cassert>

using namespace std;

double seconds_difference(double time_1, double time_2)
{
	return time_2 - time_1;
}

double hours_difference(double time_1, double time_2)
{
	return (time_2 - time_1) / 3600;
}

double to_float_hours(int hours, int minutes, int seconds)
{
	return hours + minutes / 60.0 + seconds / 3600.0;
}

double to_24_hour_clock(double hours)
{
	return fmod (hours, 24);
}

int get_hours(int total_seconds)
{
	return total_seconds / 3600;
}

int get_minutes(int total_seconds)
{
	return total_seconds % 3600 / 60;
}

int get_seconds(int total_seconds)
{
	return total_seconds % 60;
}

double time_to_utc(int utc_offset, double time)
{
	return fmod (time - utc_offset + 24, 24);
}

double time_from_utc(int utc_offset, double time)
{
	return fmod (time + utc_offset + 24, 24);
}

int main()
{
	assert(seconds_difference(1800.0, 3600.0) - 1800.0 < DBL_EPSILON);
	assert(seconds_difference(3600.0, 1800.0) - -1800.0 < DBL_EPSILON);
	assert(seconds_difference(1800.0, 2160.0) - 360.0 < DBL_EPSILON);
	assert(seconds_difference(1800.0, 1800.0) - 0.0 < DBL_EPSILON);

	assert(hours_difference(1800.0, 3600.0) - 0.5 < DBL_EPSILON);
	assert(hours_difference(3600.0, 1800.0) - -0.5 < DBL_EPSILON);
	assert(hours_difference(1800.0, 2160.0) - 0.1 < DBL_EPSILON);
	assert(hours_difference(1800.0, 1800.0) - 0 < DBL_EPSILON);

	assert(to_float_hours(0, 15, 0) - 0.25 < DBL_EPSILON);
	assert(to_float_hours(2, 45, 9) - 2.7525 < DBL_EPSILON);
	assert(to_float_hours(1, 0, 36) - 1.01 < DBL_EPSILON);

	assert(to_24_hour_clock(24) - 0.0 < DBL_EPSILON);
	assert(to_24_hour_clock(48) - 0.0 < DBL_EPSILON);
	assert(to_24_hour_clock(25) - 1.0 < DBL_EPSILON);
	assert(to_24_hour_clock(4) - 4.0 < DBL_EPSILON);
	assert(to_24_hour_clock(28.5) - 4.5 < DBL_EPSILON);

	assert(get_hours(3800) == 1);
	assert(get_hours(2560) == 0);
	assert(get_hours(15500) == 4);

	assert(get_minutes(3800) == 3);
	assert(get_minutes(2560) == 42);
	assert(get_minutes(15500) == 18);

	assert(get_seconds(3800) == 20);
	assert(get_seconds(2560) == 40);
	assert(get_seconds(15500) == 20);

	assert(time_to_utc(+0, 12.0) - 12.0 < DBL_EPSILON);
	assert(time_to_utc(+1, 12.0) - 11.0 < DBL_EPSILON);
	assert(time_to_utc(-1, 12.0) - 13.0 < DBL_EPSILON);
	assert(time_to_utc(-11, 18.0) - 5.0 < DBL_EPSILON);
	assert(time_to_utc(-1, 0.0) - 1.0 < DBL_EPSILON);
	assert(time_to_utc(-1, 23.0) - 0.0 < DBL_EPSILON);

	assert(time_from_utc(+0, 12.0) - 12.0 < DBL_EPSILON);
	assert(time_from_utc(+1, 12.0) - 13.0 < DBL_EPSILON);
	assert(time_from_utc(-1, 12.0) - 11.0 < DBL_EPSILON);
	assert(time_from_utc(+6, 6.0) - 12.0 < DBL_EPSILON);
	assert(time_from_utc(-7, 6.0) - 23.0 < DBL_EPSILON);
	assert(time_from_utc(-1, 0.0) - 23.0 < DBL_EPSILON);
	assert(time_from_utc(-1, 23.0) - 22.0 < DBL_EPSILON);
	assert(time_from_utc(+1, 23.0) - 0.0 < DBL_EPSILON);


	cout << "Test successful" << endl;
}
