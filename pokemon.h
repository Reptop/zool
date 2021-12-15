#ifndef POKEMON_H
#define POKEMON_H 

#include <iostream> 
#include <cstring> 

using namespace std; 

class Pokemon {
	public:
	Pokemon(); //contructor
        char* setName(char n[80]); 
        char* getName();
	char* getType();
        char* setType(); 
	char* getNickname();
        char* setNickname(); 
	private: 	
	char name[80];
	char type[20]; 
	char nickname[100]; 
};
#endif

