#include <iostream>
#include <cfloat>
#include <cmath>
#include <cassert>

using namespace std;

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
	/*
        Return the total number of hours in the specified number
        of hours, minutes, and seconds.

        Precondition: 0 <= minutes < 60  and  0 <= seconds < 60

    */
    assert((minutes >= 0) && (minutes < 60));
    assert((seconds >= 0) && (seconds < 60));

    return hours + minutes / 60.0 + seconds / 3600.0;
}

double to_24_hour_clock(double hours)
{
    /*
        hours is a number of hours since midnight. Return the
        hour as seen on a 24-hour clock.

        Precondition: hours >= 0
    */
	assert(hours >= 0);
	return fmod(hours, 24);
}


int get_hours(int time){
	assert(time >= 0);
	return time/3600;
}

int get_minutes(int time){
	assert(time >= 0);
	return (time - get_hours(time)*3600) / 60;
}

int get_seconds(int time){
	assert(time>= 0);
	//it doesn't looks good
	return time - get_hours(time)*3600 - get_minutes(time)*60;
}

double time_to_utc(int utc_offset, double time)
{
        //Return time at UTC+0, where utc_offset is the number of hours away from UTC+0.
	assert((utc_offset >= -12) && ((utc_offset <= 14)));
	return to_24_hour_clock(time + 24 - utc_offset);

}

double time_from_utc(int utc_offset, double time)
{
    
        //Return UTC time in time zone utc_offset.
	assert((utc_offset >= -12) && ((utc_offset <= 14)));
	return to_24_hour_clock(time + 24 + utc_offset);
}

bool equals(double d1, double d2){
	return fabs(d1 - d2) < DBL_EPSILON;
}

int main(){
	// seconds_difference()
	assert("Test 0" && equals(seconds_difference(1800.0, 3600.0), 1800.0));
	assert("Test 1" && equals(seconds_difference(3600.0, 1800.0), -1800.0));
	assert("Test 2" && equals(seconds_difference(1800.0, 2160.0), 360.0));
	assert("Test 3" && equals(seconds_difference(1800.0, 1800.0), 0.0));

	// hours_difference()
	assert("Test 4" && equals(hours_difference(1800.0, 3600.0), 0.5));
	assert("Test 5" && equals(hours_difference(3600.0, 1800.0), -0.5));
	assert("Test 6" && equals(hours_difference(1800.0, 2160.0), 0.1));
	assert("Test 7" && equals(hours_difference(1800.0, 1800.0), 0.0));

	// to_float_hours()
	assert("Test 8" && equals(to_float_hours(0, 15, 0), 0.25));
	assert("Test 9" && equals(to_float_hours(2, 45, 9), 2.7525));
	assert("Test 10" && equals(to_float_hours(1, 0, 36), 1.01));

	// to_24_hour_clock()
	assert("Test 11" && equals( to_24_hour_clock(24), 0.0));
	assert("Test 12" && equals( to_24_hour_clock(48), 0.0));
	assert("Test 13" && equals( to_24_hour_clock(25), 1.0));
	assert("Test 14" && equals( to_24_hour_clock(4), 4.0));
	assert("Test 15" && equals( to_24_hour_clock(28.5), 4.5));

	// get_hours()
	assert("Test 16" && (get_hours(3800) == 1));

	// get_minutes()
	assert("Test 17" && (get_minutes(3800) == 3));

	// get_seconds()
	assert("Test 18" && (get_seconds(3800) == 20));

	// time_to_utc()
	assert("Test 19" && equals(time_to_utc(+0, 12.0), 12.0));
	assert("Test 20" && equals(time_to_utc(+1, 12.0), 11.0));
	assert("Test 21" && equals(time_to_utc(-1, 12.0), 13.0));
	assert("Test 22" && equals(time_to_utc(-11, 18.0), 5.0));
	assert("Test 23" && equals(time_to_utc(-1, 0.0), 1.0));
	assert("Test 24" && equals(time_to_utc(-1, 23.0), 0.0));

	// time_from_utc()
	assert("Test 25" && equals(time_from_utc(+0, 12.0), 12.0));
	assert("Test 26" && equals(time_from_utc(+1, 12.0), 13.0));
	assert("Test 27" && equals(time_from_utc(-1, 12.0), 11.0));
	assert("Test 28" && equals(time_from_utc(+6, 6.0), 12.0));
	assert("Test 29" && equals(time_from_utc(-7, 6.0), 23.0));
	assert("Test 30" && equals(time_from_utc(-1, 0.0), 23.0));
	assert("Test 31" && equals(time_from_utc(-1, 23.0), 22.0));
	assert("Test 32" && equals(time_from_utc(+1, 23.0), 0.0));

	cout << "Tests are completed successfully" << endl;

	return 0;
}
