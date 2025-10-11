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

    return 0;
}