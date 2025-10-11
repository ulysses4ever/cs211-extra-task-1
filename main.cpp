#include "extra-task-1.h"


int main() {
    //Seconds_Difference Test
    assert(CompareDoubles2 (seconds_difference(1800.0, 3600.0), 1800.0));
    assert(CompareDoubles2 (seconds_difference(3600.0,1800.0), -1800.0));
    assert(CompareDoubles2 (seconds_difference(1800.0, 2160.0), 360.0));
    assert(CompareDoubles2 (seconds_difference(1800.0, 1800.0), 0.0));

    //Hours_Difference Test
    assert(CompareDoubles2(hours_difference(1800.0, 3600.0),0.5));
    assert(CompareDoubles2(hours_difference(3600.0, 1800.0), -0.5));
    assert(CompareDoubles2(hours_difference(1800.0, 2160.0),0.1));
    assert(CompareDoubles2(hours_difference(1800.0, 1800.0), 0.0));


    //To_float_hours Test
    assert(CompareDoubles2(to_float_hours(0,15,0),0.25));
    assert(CompareDoubles2(to_float_hours(2,45,9),2.7525));
    assert(CompareDoubles2(to_float_hours(1,0,36),1.01));


    //To_24_hour_clock Test
    assert(CompareDoubles2(to_24_hour_clock(24),0));
    assert(CompareDoubles2(to_24_hour_clock(48),0));
    assert(CompareDoubles2(to_24_hour_clock(25),1));
    assert(CompareDoubles2(to_24_hour_clock(4),4));
    assert(CompareDoubles2(to_24_hour_clock(28.5),4.5));


    //Get hours, minutes and seconds parts from seconds Test
    assert(get_hours(3800) == 1);
    assert(get_minutes(3800) == 3);
    assert(get_seconds(3800) == 20);


    //Time_to_utc Test
    assert(CompareDoubles2(time_to_utc(+0, 12.0), 12.0));
    assert(CompareDoubles2(time_to_utc(+1, 12.0), 11.0));
    assert(CompareDoubles2(time_to_utc(-1, 12.0), 13.0));
    assert(CompareDoubles2(time_to_utc(-11, 18.0), 5.0));
    assert(CompareDoubles2(time_to_utc(-1, 0.0), 1.0));
    assert(CompareDoubles2(time_to_utc(-1, 23.0),0.0));

    return 0;
}
