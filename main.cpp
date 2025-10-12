#include "assert.h"
#include "extra-task-1.h"
int main() {
	//проверка поиска разницы секунд
	assert(seconds_difference(1000.5,300.3) == -700.2);
	assert(seconds_difference(300.5, 500) == 199.5);
	//проверка поиска разницы часов
	assert(hours_difference(1800.0, 3600.0) == 0.5);
	assert(hours_difference(3600.0, 1800.0) == -0.5);
	//перевод секунд, минут и часов в часы
	assert(to_float_hours(0, 15, 0) == 0.25);
	assert(to_float_hours(2, 45, 9) == 2.7525);
	//перевод в часы в течение дня 
	assert(to_24_hour_clock(24) == 0);
	assert(to_24_hour_clock(25) == 1);
	assert(to_24_hour_clock(28.5) == 4.5);
	//поиск количества часов в секундах 
	assert(get_hours(3800) == 1);
	assert(get_hours(9000) == 2);
	//поиск количества минут после вычета часов в секундах 
	assert(get_minutes(3800) == 3);
	assert(get_minutes(9000) == 30);
	//поиск количества секунд после вычета часов и минут в секундах 
	assert(get_seconds(3800) == 20);
	assert(get_seconds(9000) == 0);
	//Перевод в всемирное координированное время
	assert(time_to_utc(+1, 12.3) == 11.3);
	assert(time_to_utc(-11, 18.5) == 5.5);
	//Перевод из всемирное координированное время
	assert(time_from_utc(-7, 6.7) == 23.7);
	assert(time_from_utc(-1, 23.82) == 22.82);
}