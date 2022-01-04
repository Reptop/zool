#include <iostream> 
#include <cstring> 
#include "item.h" 

Item::Item() {
  //this could be blank 
}

//getters and setters 
char* Item::getName() {
 return name; 
}

void Item::setName(char* inputName) {
  name = inputName; 
}

int Item::getId() {
  return id;  
}

void Item::setId(int inputID){
 id = inputID; 
}


