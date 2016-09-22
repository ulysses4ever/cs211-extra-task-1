#include <iostream>
#include <cassert>
#include <cmath>

const double Eps = DBL_EPSILON;

/* Returns the number of seconds later that a time in seconds time_2 is than a time in seconds time_1.*/
double seconds_difference(double time_1, double time_2)
{
	return time_2 - time_1;
}

/* Returns the number of hours later that a time in seconds time_2 is than a time in seconds time_1.*/
double hours_difference(double time_1, double time_2)
{
	double res;
	res = time_2 - time_1;
	res /= 3600;
	return res;
}

/* Returns the total number of hours in the specified number of hours, minutes, and seconds.*/
double to_float_hours(int hours, int minutes, int seconds)
{
	assert(minutes >= 0 && minutes < 60);
	assert(seconds >= 0 && seconds < 60);
	double res;
	res = hours + minutes / 60.0 + seconds / 3600.0;
	return res;
}

/* Returns the hour as seen on a 24-hour clock.*/
double to_24_hour_clock(double hours)
{
	assert(hours >= 0);
	int h_int;
	double h_double;
	h_int = trunc(hours);
	h_double = hours - h_int;
	h_int = h_int % 24;
	return h_int + h_double;
}

/*determines the hours part of a time in seconds*/
int get_hours(int seconds)
{
	return seconds / 3600;
}

/*determines the minutes part of a time in seconds*/
int get_minutes(int seconds)
{
	return (seconds % 3600) / 60;
}

/*determines the seconds part of a time in seconds*/
int get_seconds(int seconds)
{
	return seconds % 60;
}

/*Returns time at UTC+0, where utc_offset is the number of hours away from UTC+0.*/
double time_to_utc(int utc_offset, double time)
{
	int time_int = trunc(time);
	double time_double = time - time_int;
	double res;
	res = (time_int - utc_offset) % 24;
	
	return res + time_double;
}
	
	

/*double time_from_utc(int utc_offset, double time)
{
	/*
	Return UTC time in time zone utc_offset.

	>>> time_from_utc(+0, 12.0)
	12.0

	>>> time_from_utc(+1, 12.0)
	13.0

	>>> time_from_utc(-1, 12.0)
	11.0

	>>> time_from_utc(+6, 6.0)
	12.0

	>>> time_from_utc(-7, 6.0)
	23.0

	>>> time_from_utc(-1, 0.0)
	23.0

	>>> time_from_utc(-1, 23.0)
	22.0

	>>> time_from_utc(+1, 23.0)
	0.0
	
}*/

int main()
{
	/*seconds_difference tests*/
	assert(fabs(seconds_difference(1800.0, 3600.0) - 1800.0) < Eps);
	assert(fabs(seconds_difference(3600.0, 1800.0) - -1800.0) < Eps);
	assert(fabs(seconds_difference(1800.0, 2160.0) - 360.0) < Eps);
	assert(fabs(seconds_difference(1800.0, 1800.0)) < Eps);

	/*hours_difference tests*/
	assert(fabs(hours_difference(1800.0, 3600.0) - 0.5) < Eps);
	assert(fabs(hours_difference(3600.0, 1800.0) - -0.5) < Eps);
	assert(fabs(hours_difference(1800.0, 2160.0) - 0.1) < Eps);
	assert(fabs(hours_difference(1800.0, 1800.0)) < Eps);


	/*to_float_hours tests*/
	assert(fabs(to_float_hours(0, 15, 0) - 0.25) < Eps);
	assert(fabs(to_float_hours(2, 45, 9) - 2.7525) < Eps);
	assert(fabs(to_float_hours(1, 0, 36) - 1.01) < Eps);

	/*to_24_hour_clock tests*/
	assert(fabs(to_24_hour_clock(24)) < Eps);
	assert(fabs(to_24_hour_clock(48)) < Eps);
	assert(fabs(to_24_hour_clock(25) - 1) < Eps);
	assert(fabs(to_24_hour_clock(4) - 4) < Eps);
	assert(fabs(to_24_hour_clock(28.5) - 4.5) < Eps);

	/*get_hours tests*/
	assert(get_hours(3800) == 1);
	assert(get_hours(3859) == 1);
	assert(get_hours(7200) == 2);
	assert(get_hours(8000) == 2);

	/*get_minutes tests*/
	assert(get_minutes(3800) == 3);
	assert(get_minutes(3690) == 1);
	assert(get_minutes(7200) == 0);
	assert(get_minutes(3785) ==3);

	/*get_seconds tests*/
	assert(get_seconds(3800) == 20);
	assert(get_seconds(3785) == 5);
	assert(get_seconds(7379) == 59);
	assert(get_seconds(400) == 40);

	/*time_to_utc tests*/
	assert(abs(time_to_utc(+0, 12.0) - 12.0) < Eps);
	assert(abs(time_to_utc(+1, 12.0) - 11.0) < Eps);
	assert(abs(time_to_utc(-1, 12.0) - 13.0) < Eps);
	assert(abs(time_to_utc(-11, 18.0) - 5.0) < Eps);
	assert(abs(time_to_utc(-1, 0.0) - 1.0) < Eps);
	assert(abs(time_to_utc(-1, 23.0)) < Eps);
}