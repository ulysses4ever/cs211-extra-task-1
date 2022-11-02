#include<assert.h>
#include<iostream>
#include<cmath>

double seconds_difference(double time_1, double time_2)
{
    return time_2 - time_1;
}

double hours_difference(double time_1, double time_2)
{
    return seconds_difference(time_1, time_2) / 3600;
}

double to_float_hours(int hours, int minutes, int seconds)
{
    assert(0 <= minutes && minutes < 60);
    assert(0 <= seconds && seconds < 60);
    return hours + minutes / 60.0 + seconds / 3600.0;
}

double to_24_hour_clock(double hours)
{
    assert(hours >= 0);
    return fmod(hours, 24);
}

int get_hours(int seconds) {
    return fmod(seconds / 3600, 24);
}

int get_minutes(int seconds) {
    return (seconds / 60) % 60;
}

int get_seconds(int seconds) {
    return seconds % 60;
}

double time_to_utc(int utc_offset, double time)
{
    return fmod(time - utc_offset, 24);
}

double time_from_utc(int utc_offset, double time)
{
    double _0time = fmod(time + utc_offset, 24);
    return _0time < 0 ? 24 + _0time : _0time;
}

int main() {

	double eps = DBL_EPSILON;

	assert(fabs(seconds_difference(1800.0, 3600.0) - 1800.0) < eps);
	assert(fabs(seconds_difference(3600.0, 1800.0) - -1800.0) < eps);
	assert(fabs(seconds_difference(1800.0, 2160.0) - 360.0) < eps);
	assert(fabs(seconds_difference(1800.0, 1800.0) - 0.0) < eps);

	assert(fabs(hours_difference(1800.0, 3600.0) - 0.5) < eps);
	assert(fabs(hours_difference(3600.0, 1800.0) - -0.5) < eps);
	assert(fabs(hours_difference(1800.0, 2160.0) - 0.1) < eps);
	assert(fabs(hours_difference(1800.0, 1800.0) - 0.0) < eps);

	assert(fabs(to_float_hours(0, 15, 0) - 0.25) < eps);
	assert(fabs(to_float_hours(2, 45, 9) - 2.7525) < eps);
	assert(fabs(to_float_hours(1, 0, 36) - 1.01) < eps);

	assert(fabs(to_24_hour_clock(24) - 0.0) < eps);
	assert(fabs(to_24_hour_clock(48) - 0.0) < eps);
	assert(fabs(to_24_hour_clock(25) - 1.0) < eps);
	assert(fabs(to_24_hour_clock(4) - 4.0) < eps);
	assert(fabs(to_24_hour_clock(28.5) - 4.5) < eps);

	assert(get_hours(3800) == 1);
	assert(get_minutes(3800) == 3);
	assert(get_seconds(3800) == 20);

	assert(fabs(time_to_utc(0, 12.0) - 12.0) < eps);
	assert(fabs(time_to_utc(1, 12.0) - 11.0) < eps);
	assert(fabs(time_to_utc(-1, 12.0) - 13.0) < eps);
	assert(fabs(time_to_utc(-1, 0.0) - 1.0) < eps);
	assert(fabs(time_to_utc(-1, 23.0) - 0.0) < eps);

	assert(fabs(time_from_utc(0, 12.0) - 12.0) < eps);
	assert(fabs(time_from_utc(1, 12.0) - 13.0) < eps);
	assert(fabs(time_from_utc(-1, 12.0) - 11.0) < eps);
	assert(fabs(time_from_utc(-7, 6.0) - 23.0) < eps);
	assert(fabs(time_from_utc(-1, 0.0) - 23.0) < eps);
	assert(fabs(time_from_utc(-1, 23.0) - 22.0) < eps);
	assert(fabs(time_from_utc(1, 23.0) - 0.0) < eps);



	return 0;

}