#include <cassert>

#include <cmath>

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
	return fmod(hours, 24.0);
}

// * get_hours

int get_hours(int seconds)
{
	return seconds / 3600;
}

// * get_minutes

int get_minutes(int seconds)
{
	return (seconds % 3600) / 60;
}

// * get_seconds

int get_seconds(int seconds)
{
	return (seconds % 3600) % 60;
}


double time_to_utc(int utc_offset, double time)
{
	if ((time - utc_offset) < 0)
		return time - utc_offset + 24.0;
	else return fmod(time - utc_offset, 24.0);
}

double time_from_utc(int utc_offset, double time)
{
	if ((time + utc_offset) < 0)
		return time + utc_offset + 24.0;
	else return fmod(time + utc_offset, 24.0);
}

int main()
{
	// тесты к seconds_difference
	assert(seconds_difference(1800.0, 3600.0)==1800.0 && "test-1.1");

	assert(seconds_difference(3600.0, 1800.0) == -1800.0 && "test-1.2");

	assert(seconds_difference(1800.0, 2160.0) == 360.0 && "test-1.3");

	assert(seconds_difference(1800.0, 1800.0) == 0.0 && "test-1.4");

	// тесты к hours_difference

	assert(hours_difference(1800.0, 3600.0) == 0.5 && "test-2.1");

	assert(hours_difference(3600.0, 1800.0) == -0.5 && "test-2.2");

	assert(hours_difference(1800.0, 2160.0) == 0.1 && "test-2.3");

	assert(hours_difference(1800.0, 1800.0) == 0.0 && "test-2.4");

	// тесты к to_float_hours

	assert(to_float_hours(0, 15, 0) == 0.25 && "test-3.1");

	assert(to_float_hours(2, 45, 9) == 2.7525 && "test-3.2");

	assert(to_float_hours(1, 0, 36) == 1.01 && "test-3.3");

	// тесты к to_24_hour_clock

	assert(to_24_hour_clock(24) == 0 && "test-4.1");

	assert(to_24_hour_clock(48) == 0 && "test-4.2");

	assert(to_24_hour_clock(25) == 1 && "test-4.3");

	assert(to_24_hour_clock(4) == 4 && "test-4.4");

	assert(to_24_hour_clock(28.5) == 4.5 && "test-4.5");

   // тесты к get_hours / get_minutes / get_seconds

	assert(get_hours(3800) == 1 && "test-5.1");

	assert(get_minutes(3800) == 3 && "test-5.2");

	assert(get_seconds(3800) == 20 && "test-5.3");

	// тесты к time_to_utc
	assert(time_to_utc(+0, 12.0) == 12.0 && "test-6.1");

	assert(time_to_utc(+1, 12.0) == 11.0 && "test-6.2");

	assert(time_to_utc(-1, 12.0) == 13.0 && "test-6.3");

	assert(time_to_utc(-11, 18.0) == 5.0 && "test-6.4");

	assert(time_to_utc(-1, 0.0) == 1.0 && "test-6.5");

	assert(time_to_utc(-1, 23.0) == 0.0 && "test-6.6");

	// тесты к time_from_utc
	assert(time_from_utc(+0, 12.0) == 12.0 && "test-7.1");

	assert(time_from_utc(+1, 12.0) == 13.0 && "test-7.2");

	assert(time_from_utc(-1, 12.0) == 11.0 && "test-7.3");

	assert(time_from_utc(+6, 6.0) == 12.0 && "test-7.4");

	assert(time_from_utc(-7, 6.0) == 23.0 && "test-7.5");

	assert(time_from_utc(-1, 0.0) == 23.0 && "test-7.6");

	assert(time_from_utc(-1, 23.0) == 22.0 && "test-7.7");

	assert(time_from_utc(+1, 23.0) == 0.0 && "test-7.8");

} 
