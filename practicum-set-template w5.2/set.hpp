
#ifndef _SET_HPP
#define _SET_HPP

#include <iostream>
#include <array>

template<typename T, unsigned int size>
class set{
private:
	std::array<T, size> data = {};
	int used = 0;
public:
	set(){};

	void add( T n ){
		if(used != size){
			if(!contains(n)){
				data[used++] = n;
			}
		}
	}

	void remove(T n){
		int w = 0;
		for( int i = 0; i <= used; ++i ){
			data[ w ] = data[ i ];
			if( data[ w ] != n ){
				++w;
			}
		}
		used = --w;
	}

	bool contains( T n){
		for(int i =0; i < used; i++){
			if(data[i] == n){return true;}
		}
		return false;
	}
	
	template<typename S, unsigned int N>
	friend std::ostream& operator<<(std::ostream & output, const set<S,N> & set);

};

template<typename S, unsigned int N>
std::ostream& operator<<(std::ostream & output, const set<S,N> & set){
			output << "[";
		for(int i=0; i< set.used; i++){
			output <<set.data[i];
			if(i != set.used-1){output << ",";}
		}
		output<<"]";
		return output;
}
#endif 