#include <iostream>
#include <cfloat>
#include <cmath>
#include <cassert>
using namespace std;

/*Return the number of seconds later that a time in seconds
time_2 is than a time in seconds time_1.*/
double seconds_difference(double time_1, double time_2)
{
	return time_2 - time_1;
}


/*Return the number of hours later that a time in seconds
time_2 is than a time in seconds time_1.*/
double hours_difference(double time_1, double time_2)
{
	return seconds_difference(time_1, time_2) / 3600.0;
}

/*
Return the total number of hours in the specified number
of hours, minutes, and seconds.
*/
double to_float_hours(int hours, int minutes, int seconds)
{
	return hours + seconds / 3600.0 + (minutes * 60 / 3600.0);

}

/*
hours is a number of hours since midnight. Return the
hour as seen on a 24-hour clock.

*/
double to_24_hour_clock(double hours)
{
	return ((int)trunc(hours)) % 24 + (hours - trunc(hours));
}

/*
Implement three functions
* get_hours
* get_minutes
* get_seconds
They are used to determine the hours part, minutes part and seconds part
of a time in seconds. E.g.:
*/

int get_hours(int seconds) {

	return seconds / 3600 % 24;
}

int get_seconds(int seconds) {

	return seconds % 60;
}

int get_minutes(int seconds) {

	return seconds / 60 % 60;
}

/*
Return time at UTC+0, where utc_offset is the number of hours away from
UTC+0.
*/
double time_to_utc(int utc_offset, double time)
{

	return fmod(time - utc_offset, 24);

}

/*
Return UTC time in time zone utc_offset.
*/
double time_from_utc(int utc_offset, double time)
{

	return fmod(time + utc_offset + 24, 24);

}

bool equal(double a, double b) {
	return fabs(a - b) < DBL_EPSILON;
}

int main() {

	cout << "The tests for the first programm:" << endl;
	assert(equal(seconds_difference(1800.0, 3600.0), 1800.0) && "test 1.1");
	assert(equal(seconds_difference(3600.0, 1800.0), -1800.0) && "test 1.2");
	assert(equal(seconds_difference(1800.0, 2160.0), 360.0) && "test 1.3");
	assert(equal(seconds_difference(1800.0, 1800.0), 0.0) && "test 1.4");
	cout << "The first test complied!" << endl << endl;

	cout << "The tests for the second programm:" << endl;
	assert(equal(hours_difference(1800.0, 3600.0), 0.5) && "test 2.1");
	assert(equal(hours_difference(3600.0, 1800.0), -0.5) && "test 2.2");
	assert(equal(hours_difference(1800.0, 2160.0), 0.1) && "test 2.3");
	assert(equal(hours_difference(1800.0, 1800.0), 0.0) && "test 2.4");
	cout << "The second test complied!" << endl << endl;

	cout << "The tests for the third programm:" << endl;
	assert(equal(to_float_hours(0, 15, 0), 0.25) && "test 3.1");
	assert(equal(to_float_hours(2, 45, 9), 2.7525) && "test 3.2");
	assert(equal(to_float_hours(1, 0, 36), 1.01) && "test 3.3");
	cout << "The third test complied!" << endl << endl;

	cout << "The tests for the fourth programm:" << endl;
	assert(equal(to_24_hour_clock(24), 0) && "test 4.1");
	assert(equal(to_24_hour_clock(48), 0) && "test 4.2");
	assert(equal(to_24_hour_clock(25), 1) && "test 4.3");
	assert(equal(to_24_hour_clock(4), 4) && "test 4.4");
	assert(equal(to_24_hour_clock(28.5), 4.5) && "test 4.5");
	cout << "The fourth test complied!" << endl << endl;

	cout << "The tests for the fifth programm:" << endl;
	assert(equal(get_hours(3800), 1) && "test 5.1.1");
	assert(equal(get_hours(7200), 2) && "test 5.1.2");
	assert(equal(get_hours(10000), 2) && "test 5.1.3");
	cout << "The fifth test complied!" << endl << endl;


	cout << "The tests for the sixth programm:" << endl;
	assert(equal(get_seconds(3800), 20) && "test 5.3.1");
	assert(equal(get_seconds(7600), 40) && "test 5.3.1");
	assert(equal(get_seconds(5023), 43) && "test 5.3.1");
	cout << "The sixth test complied!" << endl << endl;


	cout << "The tests for the seventh programm:" << endl;
	assert(equal(get_minutes(3600), 0) && "test 5.2.1");
	assert(equal(get_minutes(3800), 3) && "test 5.2.2");
	assert(equal(get_minutes(3700), 1) && "test 5.2.3");
	cout << "The seventh test complied!" << endl << endl;

	cout << "The tests for the eighth programm:" << endl;
	assert(equal(time_to_utc(+0, 12.0), 12) && "test 6.1");
	assert(equal(time_to_utc(+1, 12.0), 11) && "test 6.2");
	assert(equal(time_to_utc(-1, 12.0), 13) && "test 6.3");
	assert(equal(time_to_utc(-11, 18.0), 5) && "test 6.4");
	assert(equal(time_to_utc(-1, 0.0), 1) && "test 6.5");
	assert(equal(time_to_utc(-1, 23.0), 0) && "test 6.6");

	cout << "The tests for the ninth programm:" << endl;
	assert(equal(time_from_utc(+0, 12.0), 12) && "test 7.1");
	assert(equal(time_from_utc(+1, 12.0), 13) && "test 7.2");
	assert(equal(time_from_utc(-1, 12.0), 11) && "test 7.3");
	assert(equal(time_from_utc(+6, 6.0), 12) && "test 7.4");
	assert(equal(time_from_utc(-7, 6.0), 23) && "test 7.5");
	assert(equal(time_from_utc(-1, 0.0), 23) && "test 7.6");
	assert(equal(time_from_utc(-1, 23.0), 22) && "test 7.7");

	cout << "The ninth test complied!" << endl << endl;
	cout << "The eighth test complied!" << endl << endl;
	cout << "Tests Complied!" << endl;
	system("pause");
	return 0;
}