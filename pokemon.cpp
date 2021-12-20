#include <iostream> 
#include <cstring> 
#include "pokemon.h" 

Pokemon::Pokemon() {
  //this could be blank 
}

//getters and setters 
char* Pokemon::getName() {
 return name; 
}

void Pokemon::setName(char* inputName) {
  name = inputName; 
}

int Pokemon::getID() {
  return id;  
}

void Pokemon::setID(int inputID){
 id = inputID; 
}


