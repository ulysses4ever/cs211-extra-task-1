#include <iostream>
#include <assert.h>

double seconds_difference(double time_1, double time_2)
{
	return time_2 - time_1;
    
    /*    
        Return the number of seconds later that a time in seconds
        time_2 is than a time in seconds time_1.
            
        
    */
}

double hours_difference(double time_1, double time_2)
{
	return (time_2 - time_1)/3600;
    /*
        Return the number of hours later that a time in seconds
        time_2 is than a time in seconds time_1.
            
    */
}

double to_float_hours(int hours, int minutes, int seconds)
{
	assert((minutes>=0) & (minutes < 60));
	assert((hours >= 0) & (hours < 60));
	return hours + (minutes * 60 + seconds) / 3600;
    /*
        Return the total number of hours in the specified number
        of hours, minutes, and seconds.

        Precondition: 0 <= minutes < 60  and  0 <= seconds < 60

     
    */
}

double to_24_hour_clock(double hours)
{	
	assert(hours>=0);
	int newhours=hours;
	while (newhours >= 24) newhours -= 24;
	return newhours;
    /*
        hours is a number of hours since midnight. Return the
        hour as seen on a 24-hour clock.

        Precondition: hours >= 0

        
        You may wish to inspect various function in <cmath> to work
        with integer and fractional part of a hours separately.
        
    */
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

int get_hours(int sec)
{
	int count = 0;
	while (sec>=3600)
	{
		sec = sec - 3600;
		count += 1;
	}
	return count;
}

int get_minutes(int sec)
{
	int hours = get_hours(sec);
	int count = 0;
	sec -= 3600 * hours;
	while (sec >=60)
	{
		sec = sec - 60;
		count += 1;
	}
	return count;
}

int get_seconds(int sec)
{
	int hours = get_hours(sec);
	int count = 0;
	int minutes = get_minutes(sec);
	sec -= 3600 * hours+minutes*60;
	while (sec > 0)
	{
		sec = sec - 1;
		count += 1;
	}
	return count;
}


double time_to_utc(int utc_offset, double time)
{
	return (time - utc_offset) >=24 ? time - utc_offset -24 : time - utc_offset;
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
}

double time_from_utc(int utc_offset, double time)
{
	return (time + utc_offset) >= 24 ? time + utc_offset - 24 : time + utc_offset;
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
}

void main()
{	//����� 1 �������
	assert((seconds_difference(1800.0, 3600.0)-1800.0) < DBL_EPSILON);
	assert((seconds_difference(3600.0, 1800.0)- -1800.0) < DBL_EPSILON);
	assert((seconds_difference(1800.0, 2160.0) - 360.0) < DBL_EPSILON);
	assert((seconds_difference(1800.0, 1800.0) - 0.0)<DBL_EPSILON);
	//����� 2 �������
	assert((hours_difference(1800.0, 3600.0)-0.5)< DBL_EPSILON);
	assert((hours_difference(3600.0, 1800.0) - -0.5)< DBL_EPSILON);
	assert((hours_difference(1800.0, 2160.0) - 0.1)< DBL_EPSILON);
	assert((hours_difference(1800.0, 1800.0) - 0.0)< DBL_EPSILON);
	//����� 3 �������
	assert((to_float_hours(0, 15, 0)-0.25)< DBL_EPSILON);
	assert((to_float_hours(2, 45, 9)-2.7525)<DBL_EPSILON);
	assert((to_float_hours(1, 0, 36)-1.01)<DBL_EPSILON);
	//����� 4 �������
	assert((to_24_hour_clock(24) - 0) < DBL_EPSILON);
	assert((to_24_hour_clock(48) - 0) < DBL_EPSILON);
	assert((to_24_hour_clock(25) - 1) < DBL_EPSILON);
	assert((to_24_hour_clock(4) - 4) < DBL_EPSILON);
	assert((to_24_hour_clock(28.5) - 4.5) < DBL_EPSILON);
	//����� 5,6,7 �������
	assert(get_hours(3800)==1);
	assert(get_minutes(3800)==3);
	assert(get_seconds(3800)==20);
	//����� 8 �������
	assert((time_to_utc(+0, 12.0)-12.0)< DBL_EPSILON);
	assert((time_to_utc(+1, 12.0)-11.0)< DBL_EPSILON);
	assert((time_to_utc(-1, 12.0)-13.0)< DBL_EPSILON);
	assert((time_to_utc(-11, 18.0)-5.0)< DBL_EPSILON);
	assert((time_to_utc(-1, 0.0) - 1.0) < DBL_EPSILON);
	assert((time_to_utc(-1, 23.0) - 0.0) < DBL_EPSILON);
	//����� 9 �������
	assert((time_from_utc(+0, 12.0) - 12.0) < DBL_EPSILON);
	assert((time_from_utc(+1, 12.0) - 13.0) < DBL_EPSILON);
	assert((time_from_utc(-1, 12.0) - 11.0) < DBL_EPSILON);
	assert((time_from_utc(+6, 6.0) - 12.0) < DBL_EPSILON);
	assert((time_from_utc(-7, 6.0) - 23.0) < DBL_EPSILON);
	assert((time_from_utc(-1, 0.0) - 23.0) < DBL_EPSILON);
	assert((time_from_utc(-1, 23.0) - 22.0) < DBL_EPSILON);
	assert((time_from_utc(+1, 23.0) - 0.0) < DBL_EPSILON);
	std::cout << "Tests completed"<<std::endl;
	system("pause");
}
