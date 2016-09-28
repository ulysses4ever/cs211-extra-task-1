#include<cassert>
#include<cmath>
#include<cfloat>

//Returns the number of seconds later that a time in seconds
//time_2 is than a time in seconds time_1.
double seconds_difference(double time_1, double time_2)
{
	return time_2 - time_1;
}

//Returns the number of hours later that a time in seconds
//time_2 is than a time in seconds time_1.
double hours_difference(double time_1, double time_2)
{
	return seconds_difference(time_1, time_2) / 3600;
}

//Returns the total number of hours in the specified number
//of hours, minutes, and seconds.
double to_float_hours(int hours, int minutes, int seconds)
{
	//Precondition: 0 <= minutes < 60  and  0 <= seconds < 60
	assert(0 <= minutes && minutes < 60);
	assert(0 <= seconds && seconds < 60);

	return (hours + minutes / 60.0 + seconds / 3600.0);
}

//Returns the hour as seen on a 24 - hour clock (25 -> 1, 48 -> 0).
double to_24_hour_clock(double hours)
{
	//Precondition: hours >= 0
	assert(hours >= 0);
	
	return fmod(hours, 24);
}

//*
//    Implement three functions
//        * get_hours
//        * get_minutes
//        * get_seconds
//    They are used to determine the hours part, minutes part and seconds part 
//    of a time in seconds. E.g.:
//
//    >>> get_hours(3800)
//    1
//
//    >>> get_minutes(3800)
//    3
//
//    >>> get_seconds(3800)
//    20
//
//    In other words, if 3800 seconds have elapsed since midnight, 
//    it is currently 01:03:20 (hh:mm:ss).
//*/

//Determines the hours part of a time in seconds.
int get_hours(double seconds)
{
	assert(seconds >= 0);
	return (int) trunc(seconds / 3600);
}

//Determines the minutes part of a time in seconds.
int get_minutes(double seconds)
{
	assert(seconds >= 0);
	return (int) trunc(fmod(seconds, 3600) / 60);
}

//Determines the seconds part of a time in seconds.
int get_seconds(double seconds)
{
	assert(seconds >= 0);
	return (int) trunc(fmod(fmod(seconds, 60), 60));
}

//Return time at UTC + 0, where utc_offset is the number of hours away from
//        UTC+0.
double time_to_utc(int utc_offset, double time)
{
	return fmod(time - utc_offset, 24);
    /*
        >>> time_to_utc(-1, 23.0)
        0.0
    */
}
//
//double time_from_utc(int utc_offset, double time)
//{
//    /*
//        Return UTC time in time zone utc_offset.
//
//        >>> time_from_utc(+0, 12.0)
//        12.0
// 
//        >>> time_from_utc(+1, 12.0)
//        13.0
// 
//        >>> time_from_utc(-1, 12.0)
//        11.0
// 
//        >>> time_from_utc(+6, 6.0)
//        12.0
// 
//        >>> time_from_utc(-7, 6.0)
//        23.0
// 
//        >>> time_from_utc(-1, 0.0)
//        23.0
// 
//        >>> time_from_utc(-1, 23.0)
//        22.0
// 
//        >>> time_from_utc(+1, 23.0)
//        0.0
//    */
//}

int main()
{
	// Tests for seconds_difference
	assert(fabs(seconds_difference(1800.0, 3600.0) - 1800.0) < DBL_EPSILON);
	assert(fabs(seconds_difference(3600.0, 1800.0) + 1800.0) < DBL_EPSILON);
	assert(fabs(seconds_difference(1800.0, 2160.0) - 360.0) < DBL_EPSILON);
	assert(seconds_difference(1800.0, 1800.0) < DBL_EPSILON);

	// Tests for hours_difference
	assert(fabs(hours_difference(1800.0, 3600.0) - 0.5) < DBL_EPSILON);
	assert(fabs(hours_difference(3600.0, 1800.0) + 0.5) < DBL_EPSILON);
	assert(fabs(hours_difference(1800.0, 2160.0) - 0.1) < DBL_EPSILON);
	assert(hours_difference(1800.0, 1800.0) < DBL_EPSILON);

	// Tests for to_float_hours
	assert(fabs(to_float_hours(0, 15, 0) - 0.25) < DBL_EPSILON);
	assert(fabs(to_float_hours(2, 45, 9) - 2.7525) < DBL_EPSILON);
	assert(fabs(to_float_hours(1, 0, 36) - 1.01) < DBL_EPSILON);
	
	// Tests for to_24_hour_clock
	assert(to_24_hour_clock(24) < DBL_EPSILON);
	assert(to_24_hour_clock(48) < DBL_EPSILON);
	assert(fabs(to_24_hour_clock(25) - 1) < DBL_EPSILON);
	assert(fabs(to_24_hour_clock(4) - 4) < DBL_EPSILON);
	assert(fabs(to_24_hour_clock(28.5) - 4.5) < DBL_EPSILON);
	assert(fabs(to_24_hour_clock(47.50) - 23.5) < DBL_EPSILON);

	// Tests for get_hours
	assert(get_hours(3800) == 1);
	assert(get_hours(0) == 0);
	assert(get_hours(1900) == 0);
	assert(get_hours(4000) == 1);
	assert(get_hours(3599) == 0);
	assert(get_hours(3600) == 1);
	assert(get_hours(7200) == 2);

	// Tests for get_minutes
	assert(get_minutes(3800) == 3);
	assert(get_minutes(0) == 0);
	assert(get_minutes(60) == 1);
	assert(get_minutes(185) == 3);
	assert(get_minutes(3659) == 0);
	assert(get_minutes(3600) == 0);
	assert(get_minutes(3539) == 58);
	assert(get_minutes(7199) == 59);
	assert(get_minutes(59.99) == 0);

	// Tests for get_seconds
	assert(get_seconds(0) == 0);
	assert(get_seconds(13) == 13);
	assert(get_seconds(60) == 0);
	assert(get_seconds(71.9) == 11);
	assert(get_seconds(3600) == 0);
	assert(get_seconds(3650) == 50);

	// Tests for time_to_utc
	assert(fabs(time_to_utc(+0, 12.0) - 12.0) < DBL_EPSILON);
	assert(fabs(time_to_utc(+1, 12.0) - 11.0) < DBL_EPSILON);
	assert(time_to_utc(-1, 23.0) < DBL_EPSILON);
}