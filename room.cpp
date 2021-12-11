#include <iostream> 
#include <cstring> 
#include "room.h"

using namespace std;

Room::Room() {
  //I could maybe use this contructor function but idk what to use this for tbh 
}

char* Room::getDesc() {
  return desc; 
}

char* Room::getExit(){
  return &exit; 
}

char* Room::getName() {
  return name; 
}
