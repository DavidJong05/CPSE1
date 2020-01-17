#include "hwlib.hpp"

extern "C" void uart_put_char( char c ){

   hwlib::cout << c;

}

extern "C" void print_asciz( const char * s );

extern "C" void application();

extern "C" void convert_case();
 

int main( void ){ 
    
   // kill the watchdog
   WDT->WDT_MR = WDT_MR_WDDIS;
   
   namespace target = hwlib::target;      
      // wait for the PC console to start

   hwlib::wait_ms( 500 );

   application();
}