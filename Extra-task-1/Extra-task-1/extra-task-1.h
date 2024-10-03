#ifndef EXTRA_TASK_1_H
#define EXTRA_TASK_1_H

double seconds_difference(double time_1, double time_2);

double hours_difference(double time_1, double time_2);

double to_float_hours(int hours, int minutes, int seconds);

double to_24_hour_clock(double hours);

int get_hourse(int seconds);

int get_minutes(int seconds);

int get_seconds(int seconds);

double time_to_utc(int utc_offset, double time);

double time_from_utc(int utc_offset, double time);
#endif // !EXTRA_TASK_1_H

