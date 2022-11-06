#include <assert.h>
#include <cmath>

double seconds_difference(double time_1, double time_2)
{
    return time_2 - time_1;
    
    /*    
        Return the number of seconds later that a time in seconds
        time_2 is than a time in seconds time_1.
    */
}

double hours_difference(double time_1, double time_2)
{
    return (time_2 / 3600) - (time_1 / 3600);
    /*
        Return the number of hours later that a time in seconds
        time_2 is than a time in seconds time_1.
    */
}