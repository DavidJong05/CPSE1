#include "hwlib.hpp"
#include "current_time.hpp"


int current_time::get_seconds(){
	return seconds;
};

int current_time::get_minutes(){
	return minutes;
};

int current_time::get_hours(){
	return hours;
};

void current_time::update_time(){
	unsigned int time_us = hwlib::now_us();
	unsigned int time_s = (time_us / 1'000'000);
	seconds = (time_s % 60);
	minutes =  ((add_minutes + (time_s / 60)) % 60);
	hours = ((add_hours + ((time_s + (add_minutes * 60)) / 3600)) % 12);
};