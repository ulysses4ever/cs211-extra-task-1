#include <iostream>
#include <locale>
#include <math.h>
#include <assert.h>
#include <float.h>

using namespace std;

double seconds_difference(double time_1, double time_2){
    
    return time_2 - time_1;
    
}

double hours_difference(double time_1, double time_2){
    
    return seconds_difference(time_1, time_2) / 3600;
}

double to_float_hours(int hours, int minutes, int seconds){
    
    return hours + minutes * 1.0 / 60 + seconds * 1.0 / 3600;
}

double to_24_hour_clock(double hours){
    
    return hours - 24 * floor(hours / 24);
}

int get_hours(int seconds){

    return floor(seconds / 3600);
}


int get_minutes(int seconds){
    
    return float((seconds - get_hours(seconds) * 3600) / 60);
}

int get_seconds(int seconds){
    
    return seconds - get_hours(seconds) * 3600 - get_minutes(seconds) * 60;
}


double time_to_utc(int utc_offset, double time){
    
    return  to_24_hour_clock(time - utc_offset);
}

double time_from_utc(int utc_offset, double time)
{
    /*
        Return UTC time in time zone utc_offset.

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
