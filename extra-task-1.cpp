#include<iostream>
#include<cassert>
#include<float.h>
using std::cout;
using std::endl;
double seconds_difference(double time_1, double time_2)
{
    return time_2 - time_1;
}

double hours_difference(double time_1, double time_2)
{
    return (time_2 - time_1)/3600;
   
}

double to_float_hours(int hours, int minutes, int seconds)
{
    assert(minutes >= 0 && minutes < 60);
    assert(seconds >= 0 && seconds < 60);
    auto temp = ((double)minutes * 60 + (double)seconds)/3600;
    auto hours_res = (double)hours + temp;
    return hours_res;
}

double to_24_hour_clock(double hours)
{
    return hours - (int)(hours / 24) * 24;;    
}


int get_hours(double seconds) 
{
    return (int)(seconds / 3600);
}
int get_minutes(double seconds) 
{
    return (int)((seconds - get_hours(seconds) * 3600) / 60);
}

int get_seconds(double seconds)
{
    return seconds - (int)(seconds / 60) * 60;
}

double time_to_utc(int utc_offset, double time)
{
    auto res = time - utc_offset;
    return res > 0 ? (int)res % 24 : 24 - ((int)(-1 * res) % 24);

    
}

double time_from_utc(int utc_offset, double time)
{
    auto res = time + utc_offset;
    return res > 0 ? (int)res % 24 : 24 - ((int)(-1 * res) % 24);

    
}

int main() {

    //task - 1
    assert(fabs(seconds_difference(1800.0, 3600.0) - 1800.0)  <= DBL_EPSILON);
    assert(fabs(seconds_difference(3600.0, 1800.0) ) - 1800.0 <= DBL_EPSILON);
    assert(fabs(seconds_difference(1800.0, 2160.0) - 360.0) <= DBL_EPSILON);
    assert(fabs(seconds_difference(1800.0, 1800.0)) <= DBL_EPSILON);
    
    //task - 2 
    assert(fabs(hours_difference(1800.0, 3600.0) - 0.5)  <= DBL_EPSILON);
    assert(fabs(hours_difference(3600.0, 1800.0)) - 0.5 <= DBL_EPSILON);
    assert(fabs(hours_difference(1800.0, 2160.0) - 0.1)  <= DBL_EPSILON);
    assert(fabs(hours_difference(1800.0, 1800.0)) <= DBL_EPSILON);
    
    //task - 3
    assert(fabs(to_float_hours(0, 15, 0) - 0.25) < DBL_EPSILON);
    assert(fabs(to_float_hours(2, 45, 9) - 2.7525) < DBL_EPSILON);
    assert(fabs(to_float_hours(1, 0, 36) - 1.01) < DBL_EPSILON);

    //task - 5
    assert(fabs(to_24_hour_clock(24)) < DBL_EPSILON);
    assert(fabs(to_24_hour_clock(48)) < DBL_EPSILON);
    assert(fabs(to_24_hour_clock(25) - 1) < DBL_EPSILON);
    assert(fabs(to_24_hour_clock(4) - 4) < DBL_EPSILON);
    assert(fabs(to_24_hour_clock(28.5) - 4.5) < DBL_EPSILON);

    //task - 6
    assert(get_hours(3800) == 1);
    assert(get_hours(7200) == 2);
    assert(get_minutes(3800) == 3);
    assert(get_seconds(3800) == 20);
    
    //task - 7
    assert(fabs(time_to_utc(+0, 12.0) - 12.0) <= DBL_EPSILON);
    assert(fabs(time_to_utc(+1, 12.0) - 11.0) <= DBL_EPSILON);
    assert(fabs(time_to_utc(-1, 12.0) - 13.0) <= DBL_EPSILON);
    assert(fabs(time_to_utc(-11, 18.0) - 5.0) <= DBL_EPSILON);
    assert(fabs(time_to_utc(-1, 0.0) - 1.0) <= DBL_EPSILON);
    assert(fabs(time_to_utc(-1, 23.0)) <= DBL_EPSILON);

    //task - 8
    
    assert(fabs(time_from_utc(+0, 12.0) - 12.0) <= DBL_EPSILON);
    assert(fabs(time_from_utc(+1, 12.0) - 13.0) <= DBL_EPSILON);
    assert(fabs(time_from_utc(-1, 12.0) - 11.0) <= DBL_EPSILON);
    assert(fabs(time_from_utc(+6, 6.0) - 12.0) <= DBL_EPSILON);
    assert(fabs(time_from_utc(-7, 6.0) - 23.0) <= DBL_EPSILON);
    assert(fabs(time_from_utc(-1, 0.0) - 23.0) <= DBL_EPSILON);
    assert(fabs(time_from_utc(-1, 23.0) - 22.0) <= DBL_EPSILON);
    assert(fabs(time_from_utc(+1, 23.0)) <= DBL_EPSILON);
}
