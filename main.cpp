#include "extra-task-1.h"


int main() {
    //Seconds_Difference Test
    assert(CompareDoubles2 (seconds_difference(1800.0, 3600.0), 1800.0));
    assert(CompareDoubles2 (seconds_difference(3600.0,1800.0), -1800.0));
    assert(CompareDoubles2 (seconds_difference(1800.0, 2160.0), 360.0));
    assert(CompareDoubles2 (seconds_difference(1800.0, 1800.0), 0.0));

    //Hours_Difference Test
    assert(CompareDoubles2(hours_difference(1800.0, 3600.0),0.5));
    assert(CompareDoubles2(hours_difference(3600.0, 1800.0), -0.5));
    assert(CompareDoubles2(hours_difference(1800.0, 2160.0),0.1));
    assert(CompareDoubles2(hours_difference(1800.0, 1800.0), 0.0));


    //To_float_hours Test
    assert(CompareDoubles2(to_float_hours(0,15,0),0.25));
    assert(CompareDoubles2(to_float_hours(2,45,9),2.7525));
    assert(CompareDoubles2(to_float_hours(1,0,36),1.01));

    return 0;
}