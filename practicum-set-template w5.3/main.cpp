#include "set.hpp"

#define CATCH_CONFIG_MAIN 
#include <catch2/catch.hpp>

/*
Test the max value function in an int array
*/
TEST_CASE( "check max from int array" ){
	set<int,12> vI;
	vI.add(1);
	vI.add(2);
	vI.add(123);
	vI.add(1234);
	vI.add(34);
	std::cout << vI<< std::endl;
	std::cout << vI.max()<< std::endl;
	REQUIRE( vI.max() == 1234);   
}

/*
Test the max value function in an float array
*/
TEST_CASE("check max from float array"){
	set<float,5> vF;
	vF.add(6723.0);
	vF.add(555.0);
	vF.add(33.3);
	vF.add(1.1);
	vF.add(10.00);
	vF.add(5.5); //overflow array test
	std::cout << vF<< std::endl;
	std::cout << vF.max()<< std::endl;
	REQUIRE(vF.max() == 6723.0);
}

/*
Test the max value function in an char array
*/
TEST_CASE("check max from char array"){
	set<char,3> vC;
	vC.add('a');
	vC.add('b');
	vC.add('C');
	std::cout << vC<< std::endl;
	std::cout << vC.max()<< std::endl;
	REQUIRE(vC.max() == 'b');
}

