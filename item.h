#ifndef ITEMS_H
#define ITEMS_H 

#include <iostream> 
#include <cstring> 

using namespace std; 

class Item {
	public:
	Item(); //contructor
        void setName(char*); 
        char* getName();
	void setId(int);
        int getId(); 
	private: 	
	char* name; 
	int id; 
};
#endif

