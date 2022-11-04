#include <iostream>
#include "extra-task-1.h"
int main() {
    /*  >>> seconds_difference(1800.0, 3600.0)
        1800.0

        >>> seconds_difference(3600.0, 1800.0)
        -1800.0

        >>> seconds_difference(1800.0, 2160.0)
        360.0

        >>> seconds_difference(1800.0, 1800.0)
        0.0
    */
    std::cout<<">>> seconds_difference(1800.0,3.600.0)\n"<<seconds_difference(1800,3600)<<std::endl;
    std::cout<<">>> seconds_difference(3600.0, 1800.0)\n"<<seconds_difference(3600,1800)<<std::endl;
    std::cout<<">>> seconds_difference(1800.0, 2160.0)\n"<<seconds_difference(1800,2160)<<std::endl;
    std::cout<<">>> seconds_difference(1800.0, 1800.0)\n"<<seconds_difference(1800,1800)<<std::endl;
    std::cout<<std::endl;

    /* >>> hours_difference(1800.0, 3600.0)
        0.5

        >>> hours_difference(3600.0, 1800.0)
        -0.5

        >>> hours_difference(1800.0, 2160.0)
        0.1

        >>> hours_difference(1800.0, 1800.0)
        0.0
    */
    std::cout<<">>> hours_difference(1800.0,3.600.0)\n"<<hours_difference(1800,3600)<<std::endl;
    std::cout<<">>> hours_difference(3600.0, 1800.0)\n"<<hours_difference(3600,1800)<<std::endl;
    std::cout<<">>> hours_difference(1800.0, 2160.0)\n"<<hours_difference(1800,2160)<<std::endl;
    std::cout<<">>> hours_difference(1800.0, 1800.0)\n"<<hours_difference(1800,1800)<<std::endl;
    std::cout<<std::endl;

    /*  >>> to_float_hours(0, 15, 0)
        0.25

        >>> to_float_hours(2, 45, 9)
        2.7525

        >>> to_float_hours(1, 0, 36)
        1.01
    */
    std::cout<<">>> to_float_hours(0, 15, 0)\n"<<to_float_hours(0,15,0)<<std::endl;
    std::cout<<">>> to_float_hours(2, 45, 9)\n"<<to_float_hours(2,45,9)<<std::endl;
    std::cout<<">>> to_float_hours(1, 0, 36)\n"<<to_float_hours(1,0,36)<<std::endl;
    std::cout<<std::endl;
/*  >>> to_24_hour_clock(24)
        0

        >>> to_24_hour_clock(48)
        0

        >>> to_24_hour_clock(25)
        1

        >>> to_24_hour_clock(4)
        4

        >>> to_24_hour_clock(28.5)
        4.5*/
    std::cout<<">>> to_24_hour_clock(24)\n"<<to_24_hour_clock(24)<<std::endl;
    std::cout<<">>> to_24_hour_clock(48)\n"<<to_24_hour_clock(48)<<std::endl;
    std::cout<<">>> to_24_hour_clock(25)\n"<<to_24_hour_clock(25)<<std::endl;
    std::cout<<">>> to_24_hour_clock(4)\n"<<to_24_hour_clock(4)<<std::endl;
    std::cout<<">>> to_24_hour_clock(28.5)\n"<<to_24_hour_clock(28.5)<<std::endl;
    std::cout<<std::endl;
    /*
     *     >>> get_hours(3800)
     */
    std::cout<<">>> get_hours(3800)\n"<<get_hours(3800)<<std::endl;

    /*
    *     >>> get_minutes(3800)
    */
    std::cout<<">>> get_minutes(3800)\n"<<get_minutes(3800)<<std::endl;

    /*
    *     >>> get_seconds(3800)
    */
    std::cout<<">>> get_seconds(3800)\n"<<get_seconds(3800)<<std::endl;
    std::cout<<std::endl;
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

    std::cout<<">>> time_to_utc(+0, 12.0)\n"<<time_to_utc(+0, 12.0)<<std::endl;
    std::cout<<">>> time_to_utc(+1, 12.0)\n"<<time_to_utc(+1, 12.0)<<std::endl;
    std::cout<<">>> time_to_utc(-1, 12.0)\n"<<time_to_utc(-1, 12.0)<<std::endl;
    std::cout<<">>> time_to_utc(-11, 18.0)\n"<<time_to_utc(-11, 18.0)<<std::endl;
    std::cout<<">>> time_to_utc(-1, 0.0)\n"<<time_to_utc(-1, 0.0)<<std::endl;
    std::cout<<">>> time_to_utc(-1, 23.0)\n"<<time_to_utc(-1, 23.0)<<std::endl;
    std::cout<<std::endl;

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
    std::cout<<">>> time_from_utc(+0, 12.0)\n"<<time_from_utc(+0, 12.0)<<std::endl;
    std::cout<<">>> time_from_utc(+1, 12.0)\n"<<time_from_utc(+1, 12.0)<<std::endl;
    std::cout<<">>> time_from_utc(-1, 12.0)\n"<<time_from_utc(-1, 12.0)<<std::endl;
    std::cout<<">>> time_from_utc(+6, 6.0)\n"<<time_from_utc(+6, 6.0)<<std::endl;
    std::cout<<">>> time_from_utc(-7, 6.0)\n"<<time_from_utc(-7, 6.0)<<std::endl;
    std::cout<<">>> time_from_utc(-1, 0.0)\n"<<time_from_utc(-1, 0.0)<<std::endl;
    std::cout<<">>> time_from_utc(-1, 23.0)\n"<<time_from_utc(-1, 23.0)<<std::endl;
    std::cout<<">>> time_from_utc(+1, 23.0)\n"<<time_from_utc(+1, 23.0)<<std::endl;
    std::cout<<std::endl;
    return 0;
}
