#ifndef _LOOKUP_HPP
#define _LOOKUP_HPP


/**
 * class loopkup
 * Stores all sinusses and cosinusses from the clock
 * An array with 360 values to get all data from a circle
 */
template< typename T, int N >
class lookup {
private:    
   std::array< T, N > values = {};

public: 
	/**
	 * fills the array with results
	 */
	template< typename F >
	constexpr lookup( F function ){
	  for( int i = 0; i < N; ++i ){
		  values[ i ] = function( 10 * i );
	  }
	}

	/**
	 * returns values from array
	 */
	constexpr T get( int n ) const {
	  return values[ n / 10 ];    
	}
};

#endif
