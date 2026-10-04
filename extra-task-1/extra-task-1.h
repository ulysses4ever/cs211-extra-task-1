// Возвращает разницу time_2 - time_1 в секундах.
double seconds_difference(double time_1, double time_2);
void test_seconds_difference();
// Возвращает разницу time_2 - time_1 в часах.
double hours_difference(double time_1, double time_2);
void test_hours_difference();
// Переводит часы, минуты и секунды в общее количество часов.
double to_float_hours(int hours, int minutes, int seconds);
void test_to_float_hours();
// Возвращает время в часах в диапазоне [0, 24).
double to_24_hour_clock(double hours);
void test_to_24_hour_clock();
// Возвращает количество полных часов в заданном количестве секунд.
int get_hours(int seconds);
// Возвращает минутную часть времени в секундах.
int get_minutes(int seconds);
// Возвращает секундную часть времени в секундах.
int get_seconds(int seconds);

void test_get_hours();
void test_get_minutes();
void test_get_seconds();
// Переводит местное время в часах из пояса utc_offset в UTC+0.
double time_to_utc(int utc_offset, double time);
void test_time_to_utc();
// Переводит время UTC+0 в часах в пояс utc_offset.
double time_from_utc(int utc_offset, double time);
void test_time_from_utc();