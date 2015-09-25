#include <cassert>
#include <cmath>	
const double EPS = 0.0000001;

// Tests for seconds_difference function.

			assert(abs(seconds_difference(1800.0, 3600.0) - 1800.0) < EPS) && "test-1");
			assert(abs(seconds_difference(3600.0, 1800.0) - 1800.0) < EPS) && "test-2");
			assert(abs(seconds_difference(1800.0, 3600.0) - 360.0) < EPS) && "test-3");
			assert(abs(seconds_difference(1800.0, 3600.0) - 0.0) < EPS) && "test-4");

// Tests for hours_difference function.

			assert(abs(hours_difference(1800.0, 3600.0) - 0.5) < EPS) && "test-5");
			assert(abs(hours_difference(1800.0, 3600.0) - 0.5) < EPS) && "test-6");
			assert(abs(hours_difference(1800.0, 3600.0) - 0.1) < EPS) && "test-7");
			assert(abs(hours_difference(1800.0, 3600.0) - 0.0) < EPS) && "test-8");
			
// Tests for to_float_hours function.
  		assert(abs(to_float_hours(0, 15, 0) - 0.25) < EPS) && "test-9");
		  assert(abs(to_float_hours(2, 45, 9) - 2.7525) < EPS) && "test-10");
		  assert(abs(to_float_hours(1, 0, 36) - 1.01) < EPS) && "test-11");

// Tests for to_24_hour_clock function.

      assert(abs(to_24_hour_clock(24) - 0.0) < EPS) && "test-12");
    	assert(abs(to_24_hour_clock(48) - 0) < EPS) && "test-13");
    	assert(abs(to_24_hour_clock(25) - 1.0) < EPS) && "test-14");
    	assert(abs(to_24_hour_clock(4) - 4) < EPS) && "test-15");
    	assert(abs(to_24_hour_clock(28.5) - 4.5) < EPS) && "test-16");
    	
// Tests for get_hours/minutes/seconds functions.

      assert(abs(get_hours(3800) == 1) && "test-17");
	    assert(abs(get_minutes(3800) == 3) && "test-18");
	    assert(abs(get_seconds(3800) == 20) && "test-19");
	    
	    
// Tests for time_to_utc function.	    
  		assert(abs(time_to_utc(+0, 12.0) - 12.0) < EPS) && "test-20");
  		assert(abs(time_to_utc(+1, 12.0) - 11.0) < EPS) && "test-21");
  		assert(abs(time_to_utc(-1, 12.0) - 13.0) < EPS) && "test-22");
  		assert(abs(time_to_utc(-11, 18.0) - 5.0) < EPS) && "test-23");
  		assert(abs(time_to_utc(-1, 0.0) - 1.0) < EPS) && "test-24");
  		assert(abs(time_to_utc(-1, 23.0) - 0.0) < EPS) && "test-25");
  	    
// Tests for time_from_utc function.	    	    

  		assert(abs(time_to_utc(+0, 12.0) - 12.0) < EPS) && "test-26");
  		assert(abs(time_to_utc(+1, 12.0) - 13.0) < EPS) && "test-27");
  		assert(abs(time_to_utc(-1, 12.0) - 11.0) < EPS) && "test-28");
  		assert(abs(time_to_utc(+6, 6.0) - 23.0) < EPS) && "test-29");
  		assert(abs(time_to_utc(-1, 0.0) - 23.0) < EPS) && "test-30");
  		assert(abs(time_to_utc(-1, 23.0) - 22.0) < EPS) && "test-31");
  		assert(abs(time_to_utc(+1, 23.0) - 0.0) < EPS) && "test-32");
