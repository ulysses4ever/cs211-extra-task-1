#include "extra-task-1.h"
#include <iostream>
#include <assert.h>
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	cout << "����� seconds_difference:\n";
	assert(DBL_EPSILON > fabs(seconds_difference(1800.0, 3600.0) - 1800.0));
	assert(DBL_EPSILON > fabs(seconds_difference(3600.0, 1800.0) - -1800.0));
	assert(DBL_EPSILON > fabs(seconds_difference(1800.0, 2160.0) - 360.0));
	assert(DBL_EPSILON > fabs(seconds_difference(1800.0, 1800.0) - 0.0));
	cout << "����� ��������." << endl;

	cout << "����� hours_difference:\n";
	assert(DBL_EPSILON > fabs(hours_difference(1800.0, 3600.0) - 0.5));
	assert(DBL_EPSILON > fabs(hours_difference(3600.0, 1800.0) - -0.5));
	assert(DBL_EPSILON > fabs(hours_difference(1800.0, 2160.0) - 0.1));
	assert(DBL_EPSILON > fabs(hours_difference(1800.0, 1800.0) - 0.0));
	cout << "����� ��������." << endl;

	cout << "����� to_float_hours:\n";
	assert(DBL_EPSILON > fabs(to_float_hours(0, 15, 0) - 0.25));
	assert(DBL_EPSILON > fabs(to_float_hours(2, 45, 9) - 2.7525));
	assert(DBL_EPSILON > fabs(to_float_hours(1, 0, 36) - 1.01));
	cout << "����� ��������." << endl;

	cout << "����� to_24_hour_clock:\n";
	assert(DBL_EPSILON > fabs(to_24_hour_clock(24) - 0));
	assert(DBL_EPSILON > fabs(to_24_hour_clock(48) - 0));
	assert(DBL_EPSILON > fabs(to_24_hour_clock(25) - 1));
	assert(DBL_EPSILON > fabs(to_24_hour_clock(4) - 4));
	assert(DBL_EPSILON > fabs(to_24_hour_clock(28.5) - 4.5));
	cout << "����� ��������." << endl;

	cout << "����� get_hours, get_minutes, get_seconds:\n";
	assert(get_hours(3800) == 1);
	assert(get_minutes(3800) == 3);
	assert(get_seconds(3800) == 20);
	cout << "����� ��������." << endl;

	cout << "����� time_to_utc:\n";
	assert(DBL_EPSILON > fabs(time_to_utc(+0, 12.0) - 12.0));
	assert(DBL_EPSILON > fabs(time_to_utc(+1, 12.0) - 11.0));
	assert(DBL_EPSILON > fabs(time_to_utc(-1, 12.0) - 13.0));
	assert(DBL_EPSILON > fabs(time_to_utc(-11, 18.0) - 5.0));
	assert(DBL_EPSILON > fabs(time_to_utc(-1, 0.0) - 1.0));
	assert(DBL_EPSILON > fabs(time_to_utc(-1, 23.0) - 0.0));
	cout << "����� ��������." << endl;

	cout << "����� time_from_utc:\n";
	assert(DBL_EPSILON > fabs(time_from_utc(+0, 12.0) - 12.0));
	assert(DBL_EPSILON > fabs(time_from_utc(+1, 12.0) - 13.0));
	assert(DBL_EPSILON > fabs(time_from_utc(-1, 12.0) - 11.0));
	assert(DBL_EPSILON > fabs(time_from_utc(+6, 6.0) - 12.0));
	assert(DBL_EPSILON > fabs(time_from_utc(-7, 6.0) - 23.0));
	assert(DBL_EPSILON > fabs(time_from_utc(-1, 0.0) - 23.0));
	assert(DBL_EPSILON > fabs(time_from_utc(-1, 23.0) - 22.0));
	assert(DBL_EPSILON > fabs(time_from_utc(+1, 23.0) - 0.0));
	cout << "����� ��������." << endl;
}
/*
����� seconds_difference:
����� ��������.
����� hours_difference:
����� ��������.
����� to_float_hours:
����� ��������.
����� to_24_hour_clock:
����� ��������.
����� get_hours, get_minutes, get_seconds:
����� ��������.
����� time_to_utc:
����� ��������.
����� time_from_utc:
����� ��������.
*/