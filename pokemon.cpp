#include <iostream> 
#include <cstring> 
#include "pokemon.h" 

Pokemon::Pokemon() {
  //this could be blank 
}

char* Pokemon::setName(char n[80]) {
  n = name; 
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
