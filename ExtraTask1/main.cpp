#include "extra-task-1.h"

int main() {
	assert(seconds_difference(1800.0, 3600.0) == 1800.0);
	assert(seconds_difference(3600.0, 1800.0) == -1800.0);
	assert(seconds_difference(1800.0, 2160.0) == 360.0);
	assert(seconds_difference(1800.0, 1800.0) == 0.0);

}