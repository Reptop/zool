#ifndef POKEMON_H
#define POKEMON_H 

#include <iostream> 
#include <cstring> 

using namespace std; 

class Pokemon {
	public:
	Pokemon(); //contructor
        void setName(char*); 
        char* getName();
	void setID(int);
        int getID(); 
	private: 	
	char* name; 
	int id; 
};
#endif

