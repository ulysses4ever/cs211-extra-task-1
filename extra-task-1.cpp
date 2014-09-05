#include <iostream>
#include <assert.h>
#include <cmath>
#include <float.h>

using namespace std;

double seconds_difference(double time_1, double time_2);
double hours_difference(double time_1, double time_2);
double to_float_hours(int hours, int minutes, int seconds);
double to_24_hour_clock(double hours);
unsigned get_hours(unsigned seconds);
unsigned get_minutes(unsigned seconds);
unsigned get_seconds(unsigned seconds);
double time_to_utc(int utc_offset, double time);
double time_from_utc(int utc_offset, double time);


int main(){
  
  // seconds_difference
  assert(fabs(seconds_difference(1800.0, 3600.0) - 1800.0) <  DBL_EPSILON);
  assert(fabs(seconds_difference(3600.0, 1800.0) - -1800.0) <  DBL_EPSILON);
  assert(fabs(seconds_difference(1800.0, 2160.0) - 360.0) <  DBL_EPSILON);
  assert(fabs(seconds_difference(1800.0, 1800.0) - 0.0) <  DBL_EPSILON);
  
  // hours_difference
  assert(fabs(hours_difference(1800.0, 3600.0) - 0.5) <  DBL_EPSILON);
  assert(fabs(hours_difference(3600.0, 1800.0) - -0.5) <  DBL_EPSILON);
  assert(fabs(hours_difference(1800.0, 2160.0) - 0.1) <  DBL_EPSILON);
  assert(fabs(hours_difference(1800.0, 1800.0) - 0.0) <  DBL_EPSILON);
  
  // to_float_hours
  assert(fabs(to_float_hours(0, 15, 0) - 0.25) <  DBL_EPSILON);
  assert(fabs(to_float_hours(2, 45, 9) - 2.7525) <  DBL_EPSILON);
  assert(fabs(to_float_hours(1, 0, 36) - 1.01) <  DBL_EPSILON);
  
  // to_24_hour_clock
  assert(fabs(to_24_hour_clock(24) - 0) <  DBL_EPSILON);
  assert(fabs(to_24_hour_clock(48) - 0) <  DBL_EPSILON);
  assert(fabs(to_24_hour_clock(25) - 1) <  DBL_EPSILON);
  assert(fabs(to_24_hour_clock(4) - 4) <  DBL_EPSILON);
  assert(fabs(to_24_hour_clock(28.5) - 4.5) <  DBL_EPSILON);
  
  // get_hours
  assert(fabs(get_hours(3800) - 1) <  DBL_EPSILON);
  
  // get_minutes
  assert(fabs(get_minutes(3800) - 3) <  DBL_EPSILON);
  
  // get_seconds
  assert(fabs(get_seconds(3800) - 20) <  DBL_EPSILON);
  
  // time_to_utc        
  assert(fabs(time_to_utc(+0, 12.0) - 12.0) <  DBL_EPSILON);       
  assert(fabs(time_to_utc(+1, 12.0) - 11.0) <  DBL_EPSILON);
  assert(fabs(time_to_utc(-1, 12.0) - 13.0) <  DBL_EPSILON);
  assert(fabs(time_to_utc(-11, 18.0) - 5.0) <  DBL_EPSILON);
  assert(fabs(time_to_utc(-1, 0.0) - 1.0) <  DBL_EPSILON);
  assert(fabs(time_to_utc(-1, 23.0) - 0.0) <  DBL_EPSILON);
  
  // time_from_utc
  assert(fabs(time_from_utc(+0, 12.0) - 12.0) <  DBL_EPSILON);
  assert(fabs(time_from_utc(+1, 12.0) - 13.0) <  DBL_EPSILON);
  assert(fabs(time_from_utc(-1, 12.0) - 11.0) <  DBL_EPSILON);
  assert(fabs(time_from_utc(+6, 6.0) - 12.0) <  DBL_EPSILON);
  assert(fabs(time_from_utc(-7, 6.0) - 23.0) <  DBL_EPSILON);
  assert(fabs(time_from_utc(-1, 0.0) - 23.0) <  DBL_EPSILON);
  assert(fabs(time_from_utc(-1, 23.0) - 22.0) <  DBL_EPSILON);
  assert(fabs(time_from_utc(+1, 23.0) - 0.0) <  DBL_EPSILON);
  
  
  return 0;        
}


double seconds_difference(double time_1, double time_2){
  
    return time_2 - time_1;
}

double hours_difference(double time_1, double time_2){
  
    return (time_2 - time_1) / 3600.0;
}

double to_float_hours(int hours, int minutes, int seconds){
  
  if(minutes < 0 || minutes >= 60) {cerr << "incorect minutes\n"; return -1;}
  if(seconds < 0 || seconds >= 60) {cerr << "incorect seconds\n"; return -1;}
  
  return (3600 * hours + 60 * minutes + seconds) / 3600.0;
}

double to_24_hour_clock(double hours){
  
  if(hours < 0) {cerr << "incorect hours"; return -1;}
  
  return fmod(hours, 24.0);
}

unsigned get_hours(unsigned seconds){
  
  return seconds/3600.0;  
}

unsigned get_minutes(unsigned seconds){
  
  return (seconds%3600)/60;  
}

unsigned get_seconds(unsigned seconds){
  
  return (seconds%3600)%60;  
}

double time_to_utc(int utc_offset, double time){
  
  if(utc_offset < -13 || utc_offset > 13) {cerr << "incorect utc_offset"; return -1;}
  if(time < 0.0 || time >= 24.0) {cerr << "incorect time"; return -1;}
  
  return fmod(time - utc_offset, 24.0);
}

double time_from_utc(int utc_offset, double time){
  
  if(utc_offset < -13 || utc_offset > 13) {cerr << "incorect utc_offset"; return -1;}
  if(time < 0.0 || time >= 24.0) {cerr << "incorect time"; return -1;}
  
  double reg = fmod(time + utc_offset, 24.0);
  
  return (reg < 0.0)? reg + 24.0 : reg;
}
