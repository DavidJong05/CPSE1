#include "hwlib.hpp"
#include "print_clock.hpp"

void print_clock::update_angles(const int & seconds, const int & minutes, const int & hours){
	seconds_angle = 360 - (seconds * 6);
	minutes_angle = 360 - (minutes * 6);
	hours_angle = (360 - ((hours * 30) + (minutes * 0.5)));
};