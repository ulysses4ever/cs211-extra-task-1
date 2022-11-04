//
// Created by maxim on 04.11.2022.
//

#ifndef STUDENT_EXTRA_TASK_1_H
#define STUDENT_EXTRA_TASK_1_H


double seconds_difference(double time_1, double time_2);

double hours_difference(double time_1, double time_2);

double to_float_hours(int hours, int minutes, int seconds);

double to_24_hour_clock(double hours);

int get_hours(double time);

int get_minutes(double time);

double get_seconds(double time);

double time_to_utc(int utc_offset, double time);

double time_from_utc(int utc_offset, double time);
#endif //STUDENT_EXTRA_TASK_1_H
