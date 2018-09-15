#include <assert.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <iostream>

using namespace std;


/*Return the number of seconds later that a time in seconds
time_2 is than a time in seconds time_1.*/
double seconds_difference(double time_1, double time_2)
{
	return time_2 - time_1;
}

/* Return the number of hours later that a time in seconds
time_2 is than a time in seconds time_1.*/
double hours_difference(double time_1, double time_2)
{
	return seconds_difference(time_1, time_2) / 3600.0;
}

/*Return the total number of hours in the specified number
        of hours, minutes, and seconds.*/
double to_float_hours(int hours, int minutes, int seconds)
{
	assert(minutes >= 0 && minutes < 60);
	assert(seconds >= 0 && seconds < 60);
	
	return hours + minutes / 60.0 + seconds / 3600.0;
}

/*hours is a number of hours since midnight. Return the
        hour as seen on a 24-hour clock.*/
double to_24_hour_clock(double hours)
{
	assert(hours >= 0);
	double nhours;
	nhours = modf(hours, &hours);
	int t = trunc(hours);
	
	return t % 24 + nhours;
}

/*Determines a hours part in time in seconds*/
double get_hours(double seconds)
{
	assert(seconds >= 0);
	int to_hours = trunc(seconds);

	return to_hours / 3600;
}

/*Determines a minutes part in time in seconds*/
double get_minutes(double seconds)
{
	int to_minutes = trunc(seconds - get_hours(seconds)*3600);

	return to_minutes / 60;
}

/*Determines a seconds part in time in seconds*/
double get_seconds(double seconds)
{
	int to_seconds = trunc(seconds - get_minutes(seconds) * 60 - get_hours(seconds)*3600);
	return to_seconds;
}

/*Return time at UTC+0, where utc_offset is the number of hours away from
        UTC+0.*/
double time_to_utc(int utc_offset, double time)
{
	assert(utc_offset >= -24 && utc_offset <= 24);
	time -= utc_offset;
	time >= 24.0 ? time -= 24.0 : time < 0.0 ? time += 24.0 : false;

	return time;
}

/*Return UTC time in time zone utc_offset.*/
double time_from_utc(int utc_offset, double time)
{
	return time_to_utc(-utc_offset, time);
}

int main()
{
	/*Task 1 Return the number of seconds later that a time in seconds
	time_2 is than a time in seconds time_1.*/
	assert(fabs(seconds_difference(1800.0, 3600.0) - 1800.0) < DBL_EPSILON);
	assert(fabs(seconds_difference(3600.0, 1800.0) + 1800.0) < DBL_EPSILON);
	assert(fabs(seconds_difference(1800.0, 2160.0) - 360.0) < DBL_EPSILON);
	assert(fabs(seconds_difference(1800.0, 1800.0)) < DBL_EPSILON);
	cout << "Task 1 Check Complete" << endl;

	/*Task 2 Return the number of hours later that a time in seconds
        time_2 is than a time in seconds time_1.*/
	assert(fabs(hours_difference(1800.0, 3600.0) - 0.5) < DBL_EPSILON);
	assert(fabs(hours_difference(3600.0, 1800.0) + 0.5) < DBL_EPSILON);
	assert(fabs(hours_difference(1800.0, 2160.0) - 0.1) < DBL_EPSILON);
	assert(fabs(hours_difference(1800.0, 1800.0)) < DBL_EPSILON);
	cout << "Task 2 Check Complete" << endl;

	/*Task 3 Return the total number of hours in the specified number
        of hours, minutes, and seconds.*/
	assert(fabs(to_float_hours(0, 15, 0) - 0.25) < DBL_EPSILON);
	assert(fabs(to_float_hours(2, 45, 9) - 2.7525) < DBL_EPSILON);
	assert(fabs(to_float_hours(1, 0, 36) - 1.01) < DBL_EPSILON);
	cout << "Task 3 Check Complete" << endl;

	/*Task 4 hours is a number of hours since midnight. Return the
        hour as seen on a 24-hour clock.*/
	assert(fabs(to_24_hour_clock(24)) < DBL_EPSILON);
	assert(fabs(to_24_hour_clock(48)) < DBL_EPSILON);
	assert(fabs(to_24_hour_clock(25) - 1.0) < DBL_EPSILON);
	assert(fabs(to_24_hour_clock(4) - 4.0) < DBL_EPSILON);
	assert(fabs(to_24_hour_clock(28.5) - 4.5) < DBL_EPSILON);
	cout << "Task 4 Check Complete" << endl;

	/*Task 5 Implement three functions
        * get_hours
        * get_minutes
        * get_seconds
    They are used to determine the hours part, minutes part and seconds part 
    of a time in seconds.*/
	assert(fabs(get_hours(3800) - 1.0) < DBL_EPSILON);
	assert(fabs(get_minutes(3800) - 3.0) < DBL_EPSILON);
	assert(fabs(get_seconds(3800) - 20.0) < DBL_EPSILON);
	cout << "Task 5 Check Complete" << endl;

	/*Task 6 Return time at UTC+0, where utc_offset is the number of hours away from
        UTC+0.*/
	assert(fabs(time_to_utc(+0, 12.0) - 12.0) < DBL_EPSILON);
	assert(fabs(time_to_utc(+1, 12.0) - 11.0) < DBL_EPSILON);
	assert(fabs(time_to_utc(-1, 12.0) - 13.0) < DBL_EPSILON);
	assert(fabs(time_to_utc(-11, 18.0) - 5.0) < DBL_EPSILON);
	assert(fabs(time_to_utc(-1, 0.0) - 1.0) < DBL_EPSILON);
	assert(fabs(time_to_utc(-1, 23.0)) < DBL_EPSILON);
	cout << "Task 6 Check Complete" << endl;

	/*Task 7 Return UTC time in time zone utc_offset.*/
	assert(fabs(time_from_utc(+0, 12.0) - 12.0) < DBL_EPSILON);
	assert(fabs(time_from_utc(+1, 12.0) - 13.0) < DBL_EPSILON);
	assert(fabs(time_from_utc(-1, 12.0) - 11.0) < DBL_EPSILON);
	assert(fabs(time_from_utc(+6, 6.0) -12.0) < DBL_EPSILON);
	assert(fabs(time_from_utc(-7, 6.0) - 23.0) < DBL_EPSILON);
	assert(fabs(time_from_utc(-1, 0.0) -23.0) < DBL_EPSILON);
	assert(fabs(time_from_utc(-1, 23.0) - 22.0) < DBL_EPSILON);
	assert(fabs(time_from_utc(+1, 23.0)) < DBL_EPSILON);
	cout << "Task 7 Check Complete" << endl;

	system("pause");
	//Very Good Committing
}
