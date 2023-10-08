#pragma once

//���������� ���������� ������ ������, ����� ����� � �������� time_2 ������ ������� � �������� time_1
double seconds_difference(double time_1, double time_2);

//���������� ���������� ����� ������, ����� ����� � �������� time_2 ������ ������� � �������� time_1
double hours_difference(double time_1, double time_2);

//���������� ����� ���������� ����� � ��������� ���������� �����, ����� � ������
double to_float_hours(int hours, int minutes, int seconds);

//���������� �����, ���������� �� 24 - ������� �����
double to_24_hour_clock(double hours);

//����� ������������ ������� ����� ������� 
int get_hours(int seconds);

//����� ������������ �������� ����� ������� 
int get_minutes(int seconds);

//����� ������������ ��������� ����� ������� 
int get_seconds(int seconds);

//���������� ����� � UTC+0, ��� utc_offset - ���������� �����, ���������� �� UTC + 0
double time_to_utc(int utc_offset, double time);

//���������� ����� UTC � ������� ����� utc_offset
double time_from_utc(int utc_offset, double time);