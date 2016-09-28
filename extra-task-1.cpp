#include <cmath>
#include <cassert>

double seconds_difference(double time_1, double time_2)
{
	// your implementation goes here...
	return time_2 - time_1;
}

double hours_difference(double time_1, double time_2)
{
	return (time_2 - time_1) / 3600.0;
}

double to_float_hours(int hours, int minutes, int seconds)
{
	assert(hours >= 0 && minutes >= 0 && seconds >= 0);
	return hours + minutes / 60.0 + seconds / 3600.0;
}

double to_24_hour_clock(double hours)
{
	assert(hours >= 0);
	double fractpart, intpart;
	fractpart = modf(hours, &intpart);
	int Fullhours = intpart;
	return  (Fullhours % 24) + fractpart;
}


int get_hours(int time_in_seconds) {
	return (time_in_seconds / 3600) % 24;
}

int get_minutes(int time_in_seconds) {
	return (time_in_seconds % 3600) / 60;
}

int get_seconds(int time_in_seconds) {
	return (time_in_seconds % 3600) % 60;
}

double time_to_utc(int utc_offset, double time)
{
	assert(time >= 0);
	double fractpart, intpart;
	fractpart = modf(time, &intpart);
	int Fullhours = intpart;
	return (24 + Fullhours - utc_offset) % 24 + fractpart;

	///return to_24_hour_clock();
}

double time_from_utc(int utc_offset, double time)
{

	assert(time >= 0);
	double fractpart, intpart;
	fractpart = modf(time, &intpart);
	int Fullhours = intpart;
	return (24 + Fullhours + utc_offset) % 24 + fractpart;
}
//

int main()
{
	assert(seconds_difference(1800.0, 3600.0) == 1800.0);
	assert(seconds_difference(3600.0, 1800.0) == -1800.0);
	assert(seconds_difference(1800.0, 2160.0) == 360.0);
	assert(seconds_difference(1800.0, 1800.0) == 0.0);
	
	//hours_difference
	assert(hours_difference(1800.0, 3600.0) == 0.5);
	assert(hours_difference(3600.0, 1800.0) == -0.5);
	assert(hours_difference(1800.0, 2160.0) == 0.1);
	assert(hours_difference(1800.0, 1800.0) == 0.0);
	
	//to_float_hours
	assert(to_float_hours(0, 15, 0) == 0.25);
	assert(to_float_hours(2, 45, 9) == 2.7525);
	assert(to_float_hours(1, 0, 36) == 1.01);

	//to_24_hour_clock
	assert(to_24_hour_clock(24) == 0.0);
	assert(to_24_hour_clock(48) == 0.0);
	assert(to_24_hour_clock(25) == 1.0);
	assert(to_24_hour_clock(4) == 4.0);
	assert(to_24_hour_clock(28.5) == 4.5);
	
	
	/*
	Implement three functions
	* get_hours
	* get_minutes
	* get_seconds
	They are used to determine the hours part, minutes part and seconds part
	of a time in seconds. E.g.:
	>>> get_hours(3800)
	1
	>>> get_minutes(3800)
	3
	>>> get_seconds(3800)
	20
	In other words, if 3800 seconds have elapsed since midnight,
	it is currently 01:03:20 (hh:mm:ss).
	*/
	assert(get_hours(3800) == 1);
	assert(get_minutes(3800) == 3);
	assert(get_seconds(3800) == 20);
	
	//double time_to_utc(int utc_offset, double time)
	assert(time_to_utc(+0, 12.0) == 12.0);
	assert(time_to_utc(+1, 12.0) == 11.0);
	assert(time_to_utc(-1, 12.0) == 13.0);
	assert(time_to_utc(-11, 18.0) == 5.0);
	assert(time_to_utc(-1, 0.0) == 1.0);
	assert(time_to_utc(-1, 23.0) == 0.0);


	//double time_from_utc(int utc_offset, double time)
	assert(time_from_utc(+0, 12.0) == 12.0);
	assert(time_from_utc(+1, 12.0) == 13.0);
	assert(time_from_utc(-1, 12.0) == 11.0);
	assert(time_from_utc(+6, 6.0) == 12.0);
	assert(time_from_utc(-7, 6.0) == 23.0);
	assert(time_from_utc(-1, 0.0) == 23.0);
	assert(time_from_utc(-1, 23.0) == 22.0);
	assert(time_from_utc(+1, 23.0) == 0.0);

}

