#include "extra-task-1.h"

int main()
{
	//������� 1
	{
		/*
		Return the number of seconds later that a time in seconds
        time_2 is than a time in seconds time_1.
		*/
		//���� 1
		{
			assert(seconds_difference(1800.0, 3600.0)== 1800.0);
		}
		//���� 2
		{
			assert(seconds_difference(3600.0, 1800.0)== -1800.0);
		}
		//���� 3
		{
			assert(seconds_difference(1800.0, 2160.0)== 360.0);
		}
		//���� 4
		{
			assert(seconds_difference(1800.0, 1800.0)== 0.0);
		}
		/*
		>>> seconds_difference(1800.0, 3600.0)
		1800.0

		>>> seconds_difference(3600.0, 1800.0)
		-1800.0

		>>> seconds_difference(1800.0, 2160.0)
		360.0

		>>> seconds_difference(1800.0, 1800.0)
		0.0
		*/
	}
	//������� 2
	{
		/*
		Return the number of hours later that a time in seconds
		time_2 is than a time in seconds time_1.
		*/
		//���� 1
		{
			assert(hours_difference(1800.0, 3600.0)==0.5);
		}
		//���� 2
		{
			assert(hours_difference(3600.0, 1800.0)==-0.5);
		}
		//���� 3
		{
			assert(hours_difference(1800.0, 2160.0)==0.1);
		}
		//���� 4
		{
			assert(hours_difference(1800.0, 1800.0)==0.0);
		}
		/*
		>>> hours_difference(1800.0, 3600.0)
		0.5

		>>> hours_difference(3600.0, 1800.0)
		-0.5

		>>> hours_difference(1800.0, 2160.0)
		0.1

		>>> hours_difference(1800.0, 1800.0)
		0.0
		*/
	}
	//������� 3
	{
		/*
		Return the total number of hours in the specified number
		of hours, minutes, and seconds.
		*/
		//���� 1
		{
			assert(to_float_hours(0, 15, 0)==0.25);
		}
		//���� 2
		{
			assert(to_float_hours(2, 45, 9)==2.7525);
		}
		//���� 3
		{
			assert(to_float_hours(1, 0, 36)==1.01);
		}
		/*
		 >>> to_float_hours(0, 15, 0)
		0.25

		>>> to_float_hours(2, 45, 9)
		2.7525

		>>> to_float_hours(1, 0, 36)
		1.01
		*/
	}
	//������� 4
	{
		/*
		hours is a number of hours since midnight. Return the
        hour as seen on a 24-hour clock.
		*/
		//���� 1
		{
			assert(to_24_hour_clock(24)==0);
		}
		//���� 2
		{
			assert(to_24_hour_clock(48)==0);
		}
		//���� 3
		{
			assert(to_24_hour_clock(25)==1);
		}
		//���� 4
		{
			assert(to_24_hour_clock(4)==4);
		}
		//���� 5
		{
			assert(to_24_hour_clock(28.5)==4.5);
		}
		/*
		>>> to_24_hour_clock(24)
		0

		>>> to_24_hour_clock(48)
		0

		>>> to_24_hour_clock(25)
		1

		>>> to_24_hour_clock(4)
		4

		>>> to_24_hour_clock(28.5)
		4.5
		*/
	}
	//������� get_hours,get_minutes,get_seconds
	{
		/*
		 Implement three functions
		* get_hours
		* get_minutes
		* get_seconds
		They are used to determine the hours part, minutes part and seconds part
		of a time in seconds. E.g.:

		In other words, if 3800 seconds have elapsed since midnight,
		it is currently 01:03:20 (hh:mm:ss).
		*/
		//���� 1
		{
			assert(get_hours(3800)==1);
		}
		//���� 2
		{
			assert(get_minutes(3800)==3);
		}
		//���� 3
		{
			assert(get_seconds(3800)==20);
		}
		/*
		>>> get_hours(3800)
		1

		>>> get_minutes(3800)
		3

		>>> get_seconds(3800)
		20
		*/
	}
	//������� 5
	{
		/*
		Return time at UTC+0, where utc_offset is the number of hours away from
		UTC+0.
		*/
		//���� 1
		{
			assert(time_to_utc(+0, 12.0)==12.0);
		}
		//���� 2
		{
			assert(time_to_utc(+1, 12.0)==11.0);
		}
		//���� 3
		{
			assert(time_to_utc(-1, 12.0)==13.0);
		}
		//���� 4
		{
			assert(time_to_utc(-11, 18.0)==5.0);
		}
		//���� 5
		{
			assert(time_to_utc(-1, 0.0)==1.0);
		}
		//���� 6
		{
			assert(time_to_utc(-1, 23.0)==0.0);
		}
		/*
		>>> time_to_utc(+0, 12.0)
		12.0

		>>> time_to_utc(+1, 12.0)
		11.0

		>>> time_to_utc(-1, 12.0)
		13.0

		>>> time_to_utc(-11, 18.0)
		5.0

		>>> time_to_utc(-1, 0.0)
		1.0

		>>> time_to_utc(-1, 23.0)
		0.0
		*/
	}
	//������� 6
	{
		/*
		Return UTC time in time zone utc_offset.
		*/
		//���� 1
		{
			assert(time_from_utc(+0, 12.0)==12.0);
		}
		//���� 2
		{
			assert(time_from_utc(+1, 12.0)==13.0);
		}
		//���� 3
		{
			assert(time_from_utc(-1, 12.0)==11.0);
		}
		//���� 4
		{
			assert(time_from_utc(+6, 6.0)==12.0);
		}
		//���� 5
		{
			assert(time_from_utc(-7, 6.0)==23.0);
		}
		//���� 6
		{
			assert(time_from_utc(-1, 0.0)==23.0);
		}
		//���� 7
		{
			assert(time_from_utc(-1, 23.0)==22.0);
		}
		//���� 8
		{
			assert(time_from_utc(+1, 23.0)==0.0);
		}
		/*

		>>> time_from_utc(+0, 12.0)
		12.0

		>>> time_from_utc(+1, 12.0)
		13.0

		>>> time_from_utc(-1, 12.0)
		11.0

		>>> time_from_utc(+6, 6.0)
		12.0

		>>> time_from_utc(-7, 6.0)
		23.0

		>>> time_from_utc(-1, 0.0)
		23.0

		>>> time_from_utc(-1, 23.0)
		22.0

		>>> time_from_utc(+1, 23.0)
		0.0
		*/
	}
	system("pause");
}