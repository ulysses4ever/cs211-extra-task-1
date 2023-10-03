#include <cassert>
#include <cmath>

double seconds_difference(double time_1, double time_2)
{
    return time_2 - time_1;
    /*    
        Return the number of seconds later that a time in seconds
        time_2 is than a time in seconds time_1.
            
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

double hours_difference(double time_1, double time_2)
{
    return (time_2 - time_1) / 3600.0;
    /*
        Return the number of hours later that a time in seconds
        time_2 is than a time in seconds time_1.

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

double to_float_hours(int hours, int minutes, int seconds)
{
    assert(0 <= minutes < 60 && 0<= seconds<60);
    return hours + minutes / 60.0 + seconds / 3600.0;
    /*
        Return the total number of hours in the specified number
        of hours, minutes, and seconds.

        Precondition: 0 <= minutes < 60  and  0 <= seconds < 60

        >>> to_float_hours(0, 15, 0)
        0.25

        >>> to_float_hours(2, 45, 9)
        2.7525

        >>> to_float_hours(1, 0, 36)
        1.01
    */
}


int main(){

}
