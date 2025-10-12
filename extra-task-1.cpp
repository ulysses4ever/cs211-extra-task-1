double seconds_difference(double time_1, double time_2)
{
    // Returns the number of seconds later that time_2 is than time_1
    return time_2 - time_1;
}

double hours_difference(double time_1, double time_2)
{
    // Returns the number of hours later that time_2 is than time_1
    return (time_2 - time_1) / 3600.0;
}

double to_float_hours(int hours, int minutes, int seconds)
{
    // Returns the total number of hours in the specified hours, minutes, and seconds
    // Precondition: 0 <= minutes < 60 and 0 <= seconds < 60
    return hours + minutes / 60.0 + seconds / 3600.0;
}

double to_24_hour_clock(double hours)
{
    // Returns the hour as seen on a 24-hour clock
    // Precondition: hours >= 0
    return fmod(hours, 24.0);
}

// Returns the hours part of a time in seconds
int get_hours(int seconds)
{
    return seconds / 3600;
}

// Returns the minutes part of a time in seconds
int get_minutes(int seconds)
{
    return (seconds % 3600) / 60;
}

// Returns the seconds part of a time in seconds
int get_seconds(int seconds)
{
    return seconds % 60;
}

double time_to_utc(int utc_offset, double time)
{
    // Returns time at UTC+0, given a local time and UTC offset
    double utc_time = fmod(time - utc_offset, 24.0);
    if (utc_time < 0) utc_time += 24.0;
    return utc_time;
}

double time_from_utc(int utc_offset, double time)
{
    // Returns local time in time zone utc_offset, given a UTC time
    double local_time = fmod(time + utc_offset, 24.0);
    if (local_time < 0) local_time += 24.0;
    return local_time;
}
