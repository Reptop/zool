#ifndef POKEMON_H
#define POKEMON_H 

#include <iostream> 
#include <cstring> 

using namespace std; 

class Pokemon {
	public:
	Pokmemon(); //contructor
	char* getName(); 
	char* getType(); 
	char* getNickname();
	private: 	
	char name[80];
	char type[20]; 
	char nickname[100]; 
};
#endif
