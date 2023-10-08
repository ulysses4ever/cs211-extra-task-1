#pragma once
#include <iostream>
#include <cassert>
//���������� ������� ����� ��������� time_2 � time_1
double seconds_difference(double, double);
//���������� ������� ����� ��������� time_2 � time_1 � �����
double hours_difference(double, double);
//���������� ����� � �����
double to_float_hours(int, int, int);
//���������� ���� �� 24 ������� �����
double to_24_hour_clock(double);
//���������� ������� ����� � ��������
int get_hours(int);
//���������� �������� ����� � ��������
int get_minutes(int);
//���������� �������� �����
int get_seconds(int);
////���������� ����� � UTC+0
double time_to_utc(int, double);
//���������� ����� � UTC � ��������� ������ �����
double time_from_utc(int, double);