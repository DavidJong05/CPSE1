#include "set.hpp"

#define CATCH_CONFIG_MAIN 
#include <catch2/catch.hpp>
#include <ostream>

/*
Test adding ints to the array
*/
TEST_CASE( "set, add(), contains" ){
	set list;
	list.add( 1 );
	list.add( 2 );
	list.add( 3 );
	list.add( 4 );
	list.add( 5 );
	list.add( 5 ); //checks if a value won't get added twice
	list.add( 6 );
	list.add( 7 );
	list.add( 8 );
	list.add( 9 );
	list.add( 10 );
	list.add( 11 ); //checks if the add function protects against overloading
	std::cout << list << std::endl;
	REQUIRE( list.contains(1) == true );   
	REQUIRE( list.contains(2) == true );   
	REQUIRE( list.contains(3) == true );   
	REQUIRE( list.contains(4) == true );   
	REQUIRE( list.contains(5) == true );    
	REQUIRE( list.contains(6) == true );    
	REQUIRE( list.contains(7) == true );    
	REQUIRE( list.contains(8) == true );    
	REQUIRE( list.contains(9) == true );    
	REQUIRE( list.contains(10) == true );    
	REQUIRE( list.contains(11) == false );    
}

/*
Tests removing an int from the array
*/
TEST_CASE( "set, remove(), contains()" ){
	set list;
	list.add( 1 );
	list.add( 2 );
	list.add( 3 );
	list.add( 4 );
	list.add( 5 );
	list.remove( 5 );
	std::cout << list << std::endl;
	REQUIRE( list.contains(5) == false ); 
	REQUIRE( list.contains(1) == true );  
	REQUIRE( list.contains(2) == true );   
	REQUIRE( list.contains(3) == true );      
}