#ifndef _CURRENT_TIME_HPP
#define _CURRENT_TIME_HPP

/**
 * class current_time
 * Provides the current time
 * Updates the current time
 */
class current_time{
private:
	int seconds = 0;
	int minutes = 0;
	int hours = 0;
	int add_hours = 0;
	int add_minutes = 0;
public:
	current_time(){}
	
	int get_seconds();	
	int get_minutes();	
	int get_hours();
	
	/**
	 * Updates time with hwlib realtime clock data
	 */
	void update_time();
};


#endif
