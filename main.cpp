#include "extra-task-1.h"

int main(int argc, const char * argv[])
{
    
    // MARK: - seconds_difference
    assert(are_equal(seconds_difference(1800.0, 3600.0), 1800.0));
    assert(are_equal(seconds_difference(3600.0, 1800.0), -1800.0));
    assert(are_equal(seconds_difference(1800.0, 2160.0), 360.0));
    assert(are_equal(seconds_difference(1800.0, 1800.0), 0.0));
    
    // MARK: - hours_difference
    assert(are_equal(hours_difference(1800.0, 3600.0), 0.5));
    assert(are_equal(hours_difference(3600.0, 1800.0), -0.5));
    assert(are_equal(hours_difference(1800.0, 2160.0), 0.1));
    assert(are_equal(hours_difference(1800.0, 1800.0), 0.0));
    
    // MARK: - to_float_hours
    assert(are_equal(to_float_hours(0, 15, 0), 0.25));
    assert(are_equal(to_float_hours(2, 45, 9), 2.7525));
    assert(are_equal(to_float_hours(1, 0, 36), 1.01));
    
    // MARK: - to_24_hour_clock
    assert(are_equal(to_24_hour_clock(24), 0));
    assert(are_equal(to_24_hour_clock(48), 0));
    assert(are_equal(to_24_hour_clock(25), 1));
    assert(are_equal(to_24_hour_clock(4), 4));
    assert(are_equal(to_24_hour_clock(28.5), 4.5));
    
    // MARK: - get_hours
    assert(get_hours(3800) == 1);
    assert(get_hours(7300) == 2);
    assert(get_hours(4500) == 1);
    
    // MARK: - get_minutes
    assert(get_minutes(3800) == 3);
    assert(get_minutes(5000) == 23);
    assert(get_minutes(8000) == 13);
    
    // MARK: - get_seconds
    assert(get_seconds(3800) == 20);
    assert(get_seconds(4000) == 40);
    assert(get_seconds(60) == 0);
    
    // MARK: - time_to_utc
    assert(are_equal(time_to_utc(+0, 12.0), 12.0));
    assert(are_equal(time_to_utc(+1, 12.0), 11.0));
    assert(are_equal(time_to_utc(-1, 12.0), 13.0));
    assert(are_equal(time_to_utc(-11, 18.0), 5.0));
    assert(are_equal(time_to_utc(-1, 0.0), 1.0));
    assert(are_equal(time_to_utc(-1, 23.0), 0.0));
    
    // MARK: - time_from_utc
    assert(are_equal(time_from_utc(+0, 12.0), 12.0));
    assert(are_equal(time_from_utc(+1, 12.0), 13.0));
    assert(are_equal(time_from_utc(-1, 12.0), 11.0));
    assert(are_equal(time_from_utc(+6, 6.0), 12.0));
    assert(are_equal(time_from_utc(-7, 6.0), 23.0));
    assert(are_equal(time_from_utc(-1, 0.0), 23.0));
    assert(are_equal(time_from_utc(-1, 23.0), 22.0));
    assert(are_equal(time_from_utc(+1, 23.0), 0.0));
    
    return 0;
}
