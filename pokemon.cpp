#include <iostream> 
#include <cstring> 
#include "pokemon.h" 

Pokemon::Pokemon() {
  //this could be blank 
}

char* Pokemon::getName() {
  return name; 
}

char* Pokemon::getType(){
 return type; 
}

char* Pokemon::getNickname(){
  return nickname; 
  
}
