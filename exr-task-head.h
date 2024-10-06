#pragma once
///#ifndef EXR_TASK_HEAD_H
///#define EXR_TASK_HEAD_H


double seconds_difference(double time_1, double time_2);

double hours_difference(double time_1, double time_2);

double to_float_hours(int hours, int minutes, int seconds);

double to_24_hour_clock(double hours);

double time_to_utc(int utc_offset, double time);

double time_from_utc(int utc_offset, double time);

double get_hours(double time_in_seconds);

double get_minutes(double time_in_seconds);

double get_seconds(double time_in_seconds);

/*EXR_TASK_HEAD_H
#endif*/
