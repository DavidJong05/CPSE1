
#include "set.hpp"


void set::add( int n ){
	if(used < 10){
		if(!contains(n)){
			data[used++] = n;
		}
	}
}

void set::remove( int n ){
	int w = 0;
	for( int i = 0; i <= used; ++i ){
		data[ w ] = data[ i ];
		if( data[ w ] != n ){
			++w;
		}
	}
	used = --w;
}

bool set::contains(int n){
	for(int i =0; i <= used; i++){
		if(data[i] == n){return true;}
	}
	return false;
}
