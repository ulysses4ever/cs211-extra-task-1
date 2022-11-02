double seconds_difference(double time_1, double time_2)
{
        return time_2 - time_1;
}

double hours_difference(double time_1, double time_2)
{
        return seconds_difference(time_1, time_2) / 60 / 60;
}

double to_float_hours(int hours, int minutes, int seconds)
{
    assert((0 <= minutes) && (60 > minutes));
    assert((0 <= seconds) && (60 > seconds));
    return hours + minutes / 60.0 + seconds / 60.0 / 60.0;
}

double to_24_hour_clock(double hours)
{
    return ((int)trunc(hours) % 24) + (hours - trunc(hours));
}

int get_hours(int seconds);

int get_minutes(int seconds);

int get_seconds(int seconds);

double time_to_utc(int utc_offset, double time)
{
    return to_24_hour_clock(time - utc_offset + 24);
}

double time_from_utc(int utc_offset, double time)
{
    return to_24_hour_clock(time + utc_offset + 24);
}