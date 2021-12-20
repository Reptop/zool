
#include <iostream>
#include <cstring>
#include <map>
#include "room.h"

using namespace std;

Room::Room() {
	//dont want to use this 
}

//getters and setters for description, exits, items in room 
char* Room::getDescription()
{
  return description;
}

map<int,char*>* Room::getExits() {
  return &exits;
}

int Room::getId() {
  return id;
}

int Room::getItem() {
  return item;
}

//setters
void Room::setDescription(char* newDescription) {
  description = newDescription;
}

void Room::setExits(map<int, char*> newExits) {
  exits = newExits;
}

void Room::setId(int newId) {
  id = newId;
}

void Room::setItem(int newItem) {
  item = newItem;
}
