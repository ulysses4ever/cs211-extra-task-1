#include <iostream>
#include "cs211-extra-task-1/extra-task-1.h"

int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	
	double time_1, time_2, hours_double, time;
	int hours, minutes, seconds, utc_offset;

	std::cout << "Seconds difference\nEnter the first value: ";
	std::cin >> time_1;
	std::cout << "Enter the second value: ";
	std::cin >> time_2;
	std::cout << "Result: " << seconds_difference(time_1, time_2) << std::endl;
	std::cout << std::endl;

	std::cout << "Hours difference\nEnter the first value: ";
	std::cin >> time_1;
	std::cout << "Enter the second value: ";
	std::cin >> time_2;
	std::cout << "Result: " << hours_difference(time_1, time_2) << std::endl;
	std::cout << std::endl;

	std::cout << "To float hours\nEnter the number of hours: ";
	std::cin >> hours;
	std::cout << "Enter the number of minutes: ";
	std::cin >> minutes;
	std::cout << "Enter the number of seconds: ";
	std::cin >> seconds;
	std::cout << "Result: " << to_float_hours(hours, minutes, seconds);
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "To 24 hour clock\nEnter the number of hours: ";
	std::cin >> hours_double;
	std::cout << "Result: " << to_24_hour_clock(hours_double);
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Determine the hours part, minutes part and seconds part of a time in seconds\nEnter the number of seconds: ";
	std::cin >> seconds;
	std::cout << "Result: " << get_hours(seconds) << ":" << get_minutes(seconds) << ":" << get_seconds(seconds);
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Time to utc\nEnter UTC time zone: ";
	std::cin >> utc_offset;
	std::cout << "Enter the time: ";
	std::cin >> time;
	std::cout << "Result: " << time_to_utc(utc_offset, time) << std::endl;
	std::cout << std::endl;

	std::cout << "Time from utc\nEnter UTC time zone: ";
	std::cin >> utc_offset;
	std::cout << "Enter the time: ";
	std::cin >> time;
	std::cout << "Result: " << time_from_utc(utc_offset, time) << std::endl;
	std::cout << std::endl;

	return 0;
}
