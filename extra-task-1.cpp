#include <iostream>
#include <locale>
#include <math.h>
#include <assert.h>
#include <float.h>

using namespace std;

//Return the number of seconds later that a time in seconds
//        time_2 is than a time in seconds time_1.
double seconds_difference(double time_1, double time_2){
    
    return time_2 - time_1;
}

//Return the number of hours later that a time in seconds
//        time_2 is than a time in seconds time_1.
double hours_difference(double time_1, double time_2){
    
    return seconds_difference(time_1, time_2) / 3600;
}

//Return the total number of hours in the specified number
//        of hours, minutes, and seconds.
double to_float_hours(int hours, int minutes, int seconds){
    
    return hours + minutes * 1.0 / 60 + seconds * 1.0 / 3600;
}

//hours is a number of hours since midnight. Return the
//        hour as seen on a 24-hour clock.
double to_24_hour_clock(double hours){
    
    return hours - 24 * floor(hours / 24);
}

//Return number of integer hours in the seconds
int get_hours(int seconds){

    return floor(seconds / 3600);
}

//Return number of integer minutes in the seconds (without hours)
int get_minutes(int seconds){
    
    return float((seconds - get_hours(seconds) * 3600) / 60);
}

////Return number of integer seconds (without hours and minutes)
int get_seconds(int seconds){
    
    return seconds - get_hours(seconds) * 3600 - get_minutes(seconds) * 60;
}

//Return time at UTC+0, where utc_offset is the number of hours away from
//        UTC+0.
double time_to_utc(int utc_offset, double time){
    
    return  to_24_hour_clock(time - utc_offset);
}

//Return UTC time in time zone utc_offset.
double time_from_utc(int utc_offset, double time){
    
    return  to_24_hour_clock(time + utc_offset);

}

//Returns True if the numbers x, y do not differ by more than eps
bool are_equal(double x, double y, double eps){
    
    assert(eps > 0);
    return fabs(x - y) <= eps;
}



int main() {
    
	std::locale::global(std::locale(""));
    
    
    cout << "Test seconds_difference: ";
    assert(are_equal(seconds_difference(1800.0, 3600.0), 1800.0, DBL_EPSILON) && "seconds_difference: test1");
    assert(are_equal(seconds_difference(3600.0, 1800.0), -1800.0, DBL_EPSILON) && "seconds_difference: test2");
    assert(are_equal(seconds_difference(1800.0, 2160.0), 360.0, DBL_EPSILON) && "seconds_difference: test3");
    assert(are_equal(seconds_difference(1800.0, 1800.0), 0.0, DBL_EPSILON) && "seconds_difference: test4");
    cout << "success;" << endl;
    
    
    cout << "Test hours_difference: ";
    assert(are_equal(hours_difference(1800.0, 3600.0), 0.5, DBL_EPSILON) && "hours_difference: test1");
    assert(are_equal(hours_difference(3600.0, 1800.0), -0.5, DBL_EPSILON) && "hours_difference: test2");
    assert(are_equal(hours_difference(1800.0, 2160.0), 0.1, DBL_EPSILON) && "hours_difference: test3");
    assert(are_equal(hours_difference(1800.0, 1800.0), 0.0, DBL_EPSILON) && "hours_difference: test4");
    cout << "success;" << endl;
    
    
    cout << "Test to_float_hours: ";
    assert(are_equal(to_float_hours(0, 15, 0), 0.25, DBL_EPSILON) && "to_float_hours: test1");
    assert(are_equal(to_float_hours(2, 45, 9), 2.7525, DBL_EPSILON) && "to_float_hours: test2");
    assert(are_equal(to_float_hours(1, 0, 36), 1.01, DBL_EPSILON) && "to_float_hours: test3");
    cout << "success;" << endl;
    
    
    cout << "Test to_24_hour_clock: ";
    assert(are_equal(to_24_hour_clock(24), 0, DBL_EPSILON) && "to_24_hour_clock: test1");
    assert(are_equal(to_24_hour_clock(48), 0, DBL_EPSILON) && "to_24_hour_clock: test2");
    assert(are_equal(to_24_hour_clock(25), 1, DBL_EPSILON) && "to_24_hour_clock: test3");
    assert(are_equal(to_24_hour_clock(4), 4, DBL_EPSILON) && "to_24_hour_clock: test4");
    assert(are_equal(to_24_hour_clock(28.5), 4.5, DBL_EPSILON) && "to_24_hour_clock: test5");
    cout << "success;" << endl;
    

    cout << "Test get_hours: ";
    assert(are_equal(get_hours(3800), 1, DBL_EPSILON) && "get_hours: test1");
    assert(are_equal(get_hours(100), 0, DBL_EPSILON) && "get_hours: test2");
    assert(are_equal(get_hours(10799), 2, DBL_EPSILON) && "get_hours: test3");
    cout << "success;" << endl;
    
    
    cout << "Test get_minutes: ";
    assert(are_equal(get_minutes(3800), 3, DBL_EPSILON) && "get_minutes: test1");
    assert(are_equal(get_minutes(100), 1, DBL_EPSILON) && "get_minutes: test2");
    assert(are_equal(get_minutes(10799), 59, DBL_EPSILON) && "get_minutes: test3");
    cout << "success;" << endl;
    
    
    cout << "Test get_seconds: ";
    assert(are_equal(get_seconds(3800), 20, DBL_EPSILON) && "get_seconds: test1");
    assert(are_equal(get_seconds(100), 40, DBL_EPSILON) && "get_seconds: test2");
    assert(are_equal(get_seconds(10799), 59, DBL_EPSILON) && "get_seconds: test3");
    cout << "success;" << endl;
    
    
    cout << "Test time_to_utc: ";
    assert(are_equal(time_to_utc(+0, 12.0), 12.0, DBL_EPSILON) && "time_to_utc: test1");
    assert(are_equal(time_to_utc(+1, 12.0), 11.0, DBL_EPSILON) && "time_to_utc: test2");
    assert(are_equal(time_to_utc(-1, 12.0), 13.0, DBL_EPSILON) && "time_to_utc: test3");
    assert(are_equal(time_to_utc(-11, 18.0), 5.0, DBL_EPSILON) && "time_to_utc: test4");
    assert(are_equal(time_to_utc(-1, 0.0), 1.0, DBL_EPSILON) && "time_to_utc: test5");
    assert(are_equal(time_to_utc(-1, 23.0), 0.0, DBL_EPSILON) && "time_to_utc: test6");
    assert(are_equal(time_to_utc(+1, 0.0), 23.0, DBL_EPSILON) && "time_to_utc: test7");
    cout << "success;" << endl;

    cout << "Test time_from_utc: ";
    assert(are_equal(time_from_utc(+0, 12.0), 12.0, DBL_EPSILON) && "time_from_utc: test1");
    assert(are_equal(time_from_utc(+1, 12.0), 13.0, DBL_EPSILON) && "time_from_utc: test2");
    assert(are_equal(time_from_utc(-1, 12.0), 11.0, DBL_EPSILON) && "time_from_utc: test3");
    assert(are_equal(time_from_utc(+6, 6.0), 12.0, DBL_EPSILON) && "time_from_utc: test4");
    assert(are_equal(time_from_utc(-7, 6.0), 23.0, DBL_EPSILON) && "time_from_utc: test5");
    assert(are_equal(time_from_utc(-1, 0.0), 23.0, DBL_EPSILON) && "time_from_utc: test6");
    assert(are_equal(time_from_utc(-1, 23.0), 22.0, DBL_EPSILON) && "time_from_utc: test7");
    assert(are_equal(time_from_utc(+1, 23.0), 0.0, DBL_EPSILON) && "time_from_utc: test8");
    cout << "success;" << endl;
}
