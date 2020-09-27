#include <iostream>
#include <cassert>
#include <cmath>

using namespace std;

double seconds_difference(double time_1, double time_2)
{
	return time_2 - time_1;
    /*    
        Return the number of seconds later that a time in seconds
        time_2 is than a time in seconds time_1. */
            
    
}

double hours_difference(double time_1, double time_2)
{
    /*
        Return the number of hours later that a time in seconds
        time_2 is than a time in seconds time_1.  */
            
	return (time_2 - time_1) / 3600.0;

}

double to_float_hours(int hours, int minutes, int seconds)
{
    /*
        Return the total number of hours in the specified number
        of hours, minutes, and seconds.   */

	 assert((hours >= 0) && (hours <= 60) && (minutes >= 0) && (minutes <= 60));
	 return hours + minutes / 60.0 + seconds / 3600.0;
    
  
}

double to_24_hour_clock(double hours)
{
    /*
        hours is a number of hours since midnight. Return the
        hour as seen on a 24-hour clock.       
    */

	assert(hours >= 0);
	return fmod(hours, 24.0); //ðåøåíèå ñ fmod
}

/*
    Implement three functions
        * get_hours
        * get_minutes
        * get_seconds
    They are used to determine the hours part, minutes part and seconds part 
    of a time in seconds. E.g.:
	*/
int get_hours(int seconds)
{
	return seconds / 3600;
}

int get_minutes(int seconds)
{
	return (seconds - get_hours(seconds) * 3600) / 60;
}

int get_seconds(int seconds)
{
	return (seconds - get_hours(seconds) * 3600 - get_minutes(seconds) * 60);
}

double time_to_utc(int utc_offset, double time)
{
    /*
        Return time at UTC+0, where utc_offset is the number of hours away from
        UTC+0.
        */

		return (time - utc_offset < 0) ? time - utc_offset + 24 : fmod(time - utc_offset, 24);
}

double time_from_utc(int utc_offset, double time)
{
    /*
        Return UTC time in time zone utc_offset.   */
		assert(time >= 0);
		return (time + utc_offset < 0) ? (time + utc_offset + 24) : fmod(time + utc_offset, 24);
}
       

int main()
{
	//seconds difference
	assert(seconds_difference(1800.0, 3600.0) == 1800.0);
	assert(seconds_difference(3600.0, 1800.0) == -1800.0);
	assert(seconds_difference(1800.0, 2160.0) == 360.0);
	assert(seconds_difference(1800.0, 1800.0) == 0.0);
	//hours difference

	assert(hours_difference(1800.0, 3600.0) == 0.5);
	assert(hours_difference(3600.0, 1800.0) == -0.5);
	assert(hours_difference(1800.0, 2160.0) == 0.1);
	assert(hours_difference(1800.0, 1800.0) == 0.0);
	
	//to float hours
	assert(to_float_hours(0, 15, 0) == 0.25);
	assert(to_float_hours(2, 45, 9) == 2.7525);
	assert(to_float_hours(1, 0, 36) == 1.01);
	
	//to24hour_clock
	assert(to_24_hour_clock(24) == 0);
	assert(to_24_hour_clock(48) == 0);
	assert(to_24_hour_clock(25) == 1);
	assert(to_24_hour_clock(4) == 4);
	assert(to_24_hour_clock(28.5) == 4.5);
	assert(to_24_hour_clock(9) == 9);
	assert(to_24_hour_clock(28) == 4);
	
	//time_to_utc
	assert(time_to_utc(+0, 12.0) == 12.0);
	assert(time_to_utc(+1, 12.0) == 11.0);
	assert(time_to_utc(-1, 12.0) == 13.0);
	assert(time_to_utc(-11, 18.0) == 5.0);
	assert(time_to_utc(-1, 0.0) == 1.0);
	assert( time_to_utc(-1, 23.0) == 0.0);
	
	//time_from_utc
	assert(time_from_utc(+0, 12.0) == 12.0);
	assert(time_from_utc(+1, 12.0) == 13.0);
	assert(time_from_utc(-1, 12.0) == 11.0);
	assert(time_from_utc(+6, 6.0) == 12.0);
	assert(time_from_utc(-7, 6.0) == 23.0);
	assert(time_from_utc(-1, 0.0) == 23.0);
	assert(time_from_utc(-1, 23.0) == 22.0);
	assert(time_from_utc(+1, 23.0) == 0.0);

}