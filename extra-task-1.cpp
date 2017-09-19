#include <iostream>
#include <cmath>
#include <cassert>

// Функция для сравнения вещественных чисел
double RealsAreEqual(double a, double b, double eps = 1.0e-6)
{
	return(abs(a - b) < eps);
}

// Вычисляет разницу в СЕКУНДАХ между time_2 и time_1
double seconds_difference(double time_1, double time_2)
{
	/*
	Return the number of seconds later that a time in seconds
	time_2 is than a time in seconds time_1.
	*/
	return (time_2 - time_1);
}

// Вычисляет разницу в ЧАСАХ между time_2 и time_1
double hours_difference(double time_1, double time_2)
{
	/*
		Return the number of hours later that a time in seconds
		time_2 is than a time in seconds time_1.
	*/
	return ((time_2 / 3600.0) - (time_1 / 3600.0));
}

// Переводит часы, минуты и секунды в часы
double to_float_hours(int hours, int minutes, int seconds)
{
    /*
        Return the total number of hours in the specified number
        of hours, minutes, and seconds.
    */
	assert((minutes >= 0) && (minutes < 60) && "to_float_hours, (minutes >= 0) && (minutes < 60)");
	assert((seconds >= 0) && (seconds < 60) && "to_float_hours, (seconds >= 0) && (seconds < 60)");
	return hours + (minutes / 60.0) + (seconds / 3600.0);
}

// Возвразает час, как показано на 24 - часовых часах
double to_24_hour_clock(double hours)
{
	/*
		hours is a number of hours since midnight. Return the
		hour as seen on a 24-hour clock.
	*/
	assert(hours >= 0 && "to_24_hour_clock, hours >= 0");
	while (hours >= 24)
	{
		hours -= 24;
	}
	return hours;
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

// Определяет целые часы по заданным секундам
int get_hours(int seconds)
{
	int res = 0;
	while (seconds <= 3600)
	{
		seconds -= 3600;
		res += 1;
	}
	return res;
}

// Определяет оставшиеся минуты по заданным секундам
int get_minutes(int seconds)
{
	int res = 0;
	while (seconds <= 3600)
		seconds -= 3600;

	while (seconds <= 60)
	{
		seconds -= 60;
		res += 1;
	}
	return res;
}

// Определяет оставшиеся секунды
int get_seconds(int seconds)
{
	int res = 0;
	while (seconds <= 3600)
		seconds -= 3600;

	while (seconds <= 60)
		seconds -= 60;

	return seconds;
}

// Переводит часы из UTC в местное
double time_to_utc(int utc_offset, double time)
{
    /*
        Return time at UTC+0, where utc_offset is the number of hours away from
        UTC+0.
    */
	double res = time - utc_offset;
	if (res >= 24)
		res -= 24;
	return (res);
}

double time_from_utc(int utc_offset, double time)
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
    */
	return 0;
}

int main()
{
	//-----------------------------seconds_difference--------------------------------
	/*
	Return the number of seconds later that a time in seconds
	time_2 is than a time in seconds time_1.

	>>> seconds_difference(1800.0, 3600.0)
	1800.0

	>>> seconds_difference(3600.0, 1800.0)
	-1800.0

	>>> seconds_difference(1800.0, 2160.0)
	360.0

	>>> seconds_difference(1800.0, 1800.0)
	0.0
	*/
	assert(RealsAreEqual(seconds_difference(1800.0, 3600.0), 1800.0) && "test-1.1");
	assert(RealsAreEqual(seconds_difference(3600.0, 1800.0), -1800.0) && "test-1.2");
	assert(RealsAreEqual(seconds_difference(1800.0, 2160.0), 360.0) && "test-1.3");
	assert(RealsAreEqual(seconds_difference(1800.0, 1800.0), 0.0) && "test-1.4");



	//-----------------------------hours_difference-----------------------------------
	/*
	Return the number of hours later that a time in seconds
	time_2 is than a time in seconds time_1.

	>>> hours_difference(1800.0, 3600.0)
	0.5

	>>> hours_difference(3600.0, 1800.0)
	-0.5

	>>> hours_difference(1800.0, 2160.0)
	0.1

	>>> hours_difference(1800.0, 1800.0)
	0.0
	*/
	assert(RealsAreEqual(hours_difference(1800.0, 3600.0), 0.5) && "test-2.1");
	assert(RealsAreEqual(hours_difference(3600.0, 1800.0), -0.5) && "test-2.2");
	assert(RealsAreEqual(hours_difference(1800.0, 2160.0), 0.1) && "test-2.3");
	assert(RealsAreEqual(hours_difference(1800.0, 1800.0), 0.0) && "test-2.4");



	//-------------------------------to_float_hours-------------------------------------
	/*
	Return the total number of hours in the specified number
	of hours, minutes, and seconds.

	Precondition: 0 <= minutes < 60  and  0 <= seconds < 60

	>>> to_float_hours(0, 15, 0)
	0.25

	>>> to_float_hours(2, 45, 9)
	2.7525

	>>> to_float_hours(1, 0, 36)
	1.01
	*/
	assert(RealsAreEqual(to_float_hours(0, 15, 0), 0.25) && "test-3.1");
	assert(RealsAreEqual(to_float_hours(2, 45, 9), 2,7525) && "test-3.2");
	assert(RealsAreEqual(to_float_hours(1, 0, 36), 1.01) && "test-3.3");



	//-------------------------------to_24_hour_clock-------------------------------------
	/*
	hours is a number of hours since midnight. Return the
	hour as seen on a 24-hour clock.

	Precondition: hours >= 0

	>>> to_24_hour_clock(24)
	0

	>>> to_24_hour_clock(48)
	0

	>>> to_24_hour_clock(25)
	1

	>>> to_24_hour_clock(4)
	4

	>>> to_24_hour_clock(28.5)
	4.5

	You may wish to inspect various function in <cmath> to work
	with integer and fractional part of a hours separately.
	*/
	assert(RealsAreEqual(to_24_hour_clock(24), 0) && "test-4.1");
	assert(RealsAreEqual(to_24_hour_clock(48), 0) && "test-4.2");
	assert(RealsAreEqual(to_24_hour_clock(25), 1) && "test-4.3");
	assert(RealsAreEqual(to_24_hour_clock(4), 4) && "test-4.4");
	assert(RealsAreEqual(to_24_hour_clock(28.5), 4.5) && "test-4.5");



	//-------------------------------time_to_utc-------------------------------------
	/*
	Return time at UTC+0, where utc_offset is the number of hours away from
	UTC+0.
	You may be interested in:
	https://en.wikipedia.org/wiki/Coordinated_Universal_Time

	>>> time_to_utc(+0, 12.0)
	12.0

	>>> time_to_utc(+1, 12.0)
	11.0

	>>> time_to_utc(-1, 12.0)
	13.0

	>>> time_to_utc(-11, 18.0)
	5.0

	>>> time_to_utc(-1, 0.0)
	1.0

	>>> time_to_utc(-1, 23.0)
	0.0
	*/	
	assert(RealsAreEqual(time_to_utc(+0, 12.0), 12.0) && "test-5.1");
	assert(RealsAreEqual(time_to_utc(+1, 12.0), 11.0) && "test-5.2");
	assert(RealsAreEqual(time_to_utc(-1, 12.0), 13.0) && "test-5.3");
	assert(RealsAreEqual(time_to_utc(-11, 18.0), 5.0) && "test-5.4");
	assert(RealsAreEqual(time_to_utc(-1, 0.0), 1.0) && "test-5.5");
	assert(RealsAreEqual(time_to_utc(-1, 23.0), 0.0) && "test-5.6");
}