#ifndef _PRINT_CLOCK_HPP
#define _PRINT_CLOCK_HPP


/**
 *  class print_clock
 *  Prints the clock
 *  Calculates the angles from all three clock hands
 */
class print_clock {
private:
	int       	seconds_angle = 360;
	int			minutes_angle = 360;
	int			hours_angle   = 360;
	hwlib::xy	clock_xy;
public:
	print_clock(hwlib::xy & clock_xy):
		clock_xy(clock_xy)
	{}
	/**
	 * Updates angles from all three clock hands
	 * Each hand is measured with 360 degrees
	 */
	void update_angles(const int & seconds, const int & minutes, const int & hours);
	
	/**
	 * Prints the whole clock with points and clock hands
	 * 12 points for each hour
	 */
	void print(auto & display, const auto & sinusses, const auto & cosinusses){
		display.clear();
		for( int j = 0; j <= 360; j += 30 ){ // 12 times looping
			display.write( hwlib::xy( sinusses.get(j), cosinusses.get(j) ) );
		}
		hwlib::line(clock_xy, hwlib::xy( sinusses.get(hours_angle),   cosinusses.get(hours_angle))).draw( display );
		hwlib::line(clock_xy, hwlib::xy( sinusses.get(minutes_angle),   cosinusses.get(minutes_angle))).draw( display );
		hwlib::line(clock_xy, hwlib::xy( sinusses.get(seconds_angle),   cosinusses.get(seconds_angle))).draw( display );
		display.flush();
	};
};


#endif
