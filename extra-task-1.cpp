double seconds_difference(double time_1, double time_2)
{
    return (time_2 - time_1);
}

double hours_difference(double time_1, double time_2)
{
    return (fabs(time_2 - time_1)) / 3600.0; 
}

double to_float_hours(int hours, int minutes, int seconds)
{
    assert((minutes < 60) && (minutes >= 0));
	assert((seconds < 60) && (seconds >= 0));
	return (hours + (minutes / 60.0) + (seconds / 3600.0));  
}

double to_24_hour_clock(double hours)
{
    assert(hours >= 0);
	return fmod(hours, 24);
}

//Три новые функции
int get_hours(int sec)
{
	return sec / 3600;
}

int get_minutes(int sec)
{
	return (sec - (3600 * get_hours(sec))) / 60;
}

int get_seconds(int sec)
{
	return (sec - (3600 * get_hours(sec)) - (60 * get_minutes(sec)));
}

double time_to_utc(int utc_offset, double time)
{
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
