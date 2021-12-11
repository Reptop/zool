#ifndef ROOM_H
#define ROOM_H
#include <iostream> 
#include <cstring> 

using namespace std; 

class Room{ 
	public:
	Room(); //contructor
	char* getName();
        char* getExit(); 
        char* getDesc(); 
	private:	
	char desc[100]; 
        char name[100]; 
        char exit;

};
#endif
