#include <cassert>
#include <iostream>
#include <cmath>
#include <cfloat>

using std::cout;

double seconds_difference(double time_1, double time_2)
{
	return time_2 - time_1;
}

double hours_difference(double time_1, double time_2)
{
    return seconds_difference(time_1, time_2) / 3600.f;
}

double to_float_hours(int hours, int minutes, int seconds)
{
    return hours + minutes / 60. + seconds / 3600.f;
}

double to_24_hour_clock(double hours)
{
	double int_part_double;
	double float_part = modf(hours, &int_part_double);
	int int_part_int = static_cast<int>(int_part_double);
    return (static_cast<double>(int_part_int % 24)) + float_part;
}

/*
    Implement three functions
        * get_hours
        * get_minutes
        * get_seconds
    They are used to determine the hours part, minutes part and seconds part 
    of a time in seconds. E.g.:

    >>> get_hours(3800)
    1

    >>> get_minutes(3800)
    3

    >>> get_seconds(3800)
    20

    In other words, if 3800 seconds have elapsed since midnight, 
    it is currently 01:03:20 (hh:mm:ss).
*/

double get_hours(double seconds)
{
	double int_part_double;
	modf(seconds, &int_part_double);
	int int_part = static_cast<int>(int_part_double);
	return (static_cast<double>(int_part / 3600));
}

double get_minutes(double seconds)
{
	double int_part_double;
	modf(seconds, &int_part_double);
	int int_part = static_cast<int>(int_part_double);
	int_part -= 3600 * get_hours(seconds);
	return (static_cast<double>(int_part / 60));
}

double get_seconds(double seconds)
{
	double int_part_double;
	modf(seconds, &int_part_double);
	int int_part = static_cast<int>(int_part_double);
	int_part -= (3600 * get_hours(seconds) + 60 * get_minutes(seconds));
	return (static_cast<double>(int_part));
}

double time_to_utc(int utc_offset, double time)
{
    double int_part_double;
    double float_part = modf(time, &int_part_double);
    int int_part = static_cast<int>(int_part_double);
    return (static_cast<double>((24 + int_part - utc_offset) % 24) + float_part);
}

double time_from_utc(int utc_offset, double time)
{
	double int_part_double;
    double float_part = modf(time, &int_part_double);
    int int_part = static_cast<int>(int_part_double);
    return (static_cast<double>((24 + int_part + utc_offset) % 24) + float_part);
}

int main()
{
	// task 1
	assert(fabs(seconds_difference(1800.0, 3600.0) - 1800.0) < DBL_EPSILON);
	assert(fabs(seconds_difference(3600.0, 1800.0) + 1800.0) < DBL_EPSILON);
	assert(fabs(seconds_difference(1800.0, 2160.0) - 360.0) < DBL_EPSILON);
	assert(fabs(seconds_difference(1800.0, 1800.0)) < DBL_EPSILON);
	
	// task 2
	assert(fabs(hours_difference(1800.0, 3600.0) - .5) < DBL_EPSILON);
	assert(fabs(hours_difference(3600.0, 1800.0) + .5) < DBL_EPSILON);
	assert(fabs(hours_difference(1800.0, 2160.0) - .1) < DBL_EPSILON);
	assert(fabs(hours_difference(1800.0, 1800.0)) < DBL_EPSILON);
	
	// task 3
	assert(fabs(to_float_hours(0, 15, 0) - .25) < DBL_EPSILON);
	assert(fabs(to_float_hours(2, 45, 9) - 2.7525) < DBL_EPSILON);
	assert(fabs(to_float_hours(1, 0, 36) - 1.01) < DBL_EPSILON);
	
	// task 4
	assert(fabs(to_24_hour_clock(24)) < DBL_EPSILON);
	assert(fabs(to_24_hour_clock(48)) < DBL_EPSILON);
	assert(fabs(to_24_hour_clock(25) - 1.) < DBL_EPSILON);
	assert(fabs(to_24_hour_clock(4) - 4.) < DBL_EPSILON);
	assert(fabs(to_24_hour_clock(28.5) - 4.5) < DBL_EPSILON);
	
	// task 5
	assert(fabs(get_hours(3800) - 1.) < DBL_EPSILON);
	assert(fabs(get_minutes(3800) - 3.) < DBL_EPSILON);
	assert(fabs(get_seconds(3800) - 20.) < DBL_EPSILON);
	
	// task 6
	assert(fabs(time_to_utc(+0, 12.0) - 12.) < DBL_EPSILON);
	assert(fabs(time_to_utc(+1, 12.0) - 11.) < DBL_EPSILON);
	assert(fabs(time_to_utc(-1, 12.0) - 13.) < DBL_EPSILON);
	assert(fabs(time_to_utc(-11, 18.0) - 5.) < DBL_EPSILON);
	assert(fabs(time_to_utc(-1, 0.) - 1.) < DBL_EPSILON);
	assert(fabs(time_to_utc(-1, 23.0) - 0.) < DBL_EPSILON);
	
	// task 7
	assert(fabs(time_from_utc(+0, 12.0) - 12.) < DBL_EPSILON);
	assert(fabs(time_from_utc(+1, 12.0) - 13.) < DBL_EPSILON);
	assert(fabs(time_from_utc(-1, 12.0) - 11.) < DBL_EPSILON);
	assert(fabs(time_from_utc(+6, 6.0) - 12.) < DBL_EPSILON);
	assert(fabs(time_from_utc(-7, 6.0) - 23.) < DBL_EPSILON);
	assert(fabs(time_from_utc(-1, .0) - 23.) < DBL_EPSILON);
	assert(fabs(time_from_utc(-1, 23.0) - 22.) < DBL_EPSILON);
	assert(fabs(time_from_utc(+1, 23.0) - 0.) < DBL_EPSILON);
	
	return 0;
}

