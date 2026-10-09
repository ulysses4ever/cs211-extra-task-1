double seconds_difference(double time_1, double time_2)
{
    return time_2 - time_1;
}

double hours_difference(double time_1, double time_2)
{
    return (time_2 - time_1) / 3600.0;
}

double to_float_hours(int hours, int minutes, int seconds)
{
    return hours + minutes / 60.0 + seconds / 3600.0;
}

double to_24_hour_clock(double hours)
{
    return std::fmod(hours, 24.0);
}

int get_hours(double seconds)
{
    return static_cast<int>(seconds / 3600) % 24;
}

int get_minutes(double seconds)
{
    return static_cast<int>(seconds / 60) % 60;
}

int get_seconds(double seconds)
{
    return static_cast<int>(seconds) % 60;
}

double time_to_utc(int utc_offset, double time)
{
    return to_24_hour_clock(time - utc_offset);
}

double time_from_utc(int utc_offset, double time)
{
    return to_24_hour_clock(time + utc_offset);
}
