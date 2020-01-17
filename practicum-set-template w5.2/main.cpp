#include "set.hpp"

#define CATCH_CONFIG_MAIN 
#include <catch2/catch.hpp>


/*
Tests adding ints to an int array
*/
TEST_CASE( "Test adding ints to an int array" ){
	set<int,12> vI;
	vI.add(1);
	vI.add(2);
	vI.add(123);
	vI.add(1234);
	vI.add(34);
	std::cout << vI<< std::endl;
	REQUIRE( vI.contains(1) == true);   
	REQUIRE( vI.contains(2) == true);   
	REQUIRE( vI.contains(123) == true);   
	REQUIRE( vI.contains(1234) == true);   
	REQUIRE( vI.contains(34) == true);   
}

/*
Tests adding removing an int from int array
*/
TEST_CASE( "Tests removing int from int array" ){
	set<int,12> vI2;
	vI2.add(42);
	vI2.add(2);
	vI2.add(10);
	vI2.add(15);
	vI2.add(35);
	vI2.remove(42);
	std::cout << vI2<< std::endl;
	REQUIRE( vI2.contains(42) == false);   
	REQUIRE( vI2.contains(2) == true);   
	REQUIRE( vI2.contains(10) == true);   
	REQUIRE( vI2.contains(15) == true);   
	REQUIRE( vI2.contains(35) == true);   
}


/*
Tests adding floats to an float array
*/
TEST_CASE("Test adding floats to float array"){
	set<float,5> vF;
	vF.add(6723.2);
	vF.add(555.0);
	vF.add(33.3);
	vF.add(1.1);
	vF.add(10.00);
	vF.add(5.5); //overflow array test
	std::cout << vF << std::endl;
	REQUIRE(vF.contains(6723.2) == true);
	REQUIRE(vF.contains(555.0) == true);
	REQUIRE(vF.contains(33.3) == true);
	REQUIRE(vF.contains(1.1) == true);
	REQUIRE(vF.contains(10.00) == true);
	REQUIRE(vF.contains(5.5) == false);
}

/*
Tests adding chars to an chars array
*/
TEST_CASE("check max from char array"){
	set<char,3> vC;
	vC.add('a');
	vC.add('b');
	vC.add('C');
	std::cout << vC << std::endl;
	REQUIRE(vC.contains('a') == true);
	REQUIRE(vC.contains('b') == true);
	REQUIRE(vC.contains('C') == true);
}

