//Author: Raed Kabir 
//Date: December 17th, 2021 
//This is ZUUL or as I say it, zool. the story is kinda like a horror game. your goal is to find a weapon to defend yourself 

#include <bits/stdc++.h>
#include <map>
#include "room.h"
#include "item.h" 
using namespace std;

//function protos
void initRooms(vector<Room*> *rooms);
void initializeItems(vector<Item*>* items);
void printRoom(vector<Room*>* rooms, vector<Item*>* items, int currentRoom);
void printInventory(vector<Item*>* items, vector<int> invtry);
void getItem(vector<Room*>* rooms, vector<Item*>* items,vector<int>* invtry, int currentRoom, char name[]);
void dropItem(vector<Room*>* rooms, vector<Item*>* items, vector<int>* invtry, int currentRoom, char name[]);
int move(vector<Room*>* rooms, int currentRoom, char direction[]); //so we can actually move 


int main() {
    bool run = true;
    char input[60]; 
    vector<Room*> roomList; 
    vector<Item*> itemList; 
    vector<int> inventory;
    int currentRoom = 1;
  
  //adding rooms and items
  initRooms(&roomList);
  initializeItems(&itemList);
  
	cout << "If you're reading this, you will likely die within the next 30 minutes." << endl;  
	cout << "You were kidnapped and are currently stranded in a random hallway in a random house" << endl;  
	cout << "To escape death, try and find a way out before your kidnapper comes back!" << endl; 
        cout << "\nGood Luck, player" << endl; 
        
	while (run) {
        cout << endl << "You currently are ";
        printRoom(&roomList, &itemList, currentRoom);
	cout << "COMMANDS: DROP, GET, INVENTORY, QUIT, GO" << endl; 
        cin >> input;   
        cin.clear(); 
        cin.ignore(10000, '\n'); 
        if (strcmp(input,"INVENTORY") == 0) {
            if (inventory.size() != 0) {
	        cout << endl << "You have: ";
	        printInventory(&itemList, inventory);
                } 
                else {
	            cout << endl << "Your inventory is empty." << endl;
                }
        }
	else if (strcmp(input, "GET") == 0) {
            //get item from that room
            cout << "What item would you like to get: " << endl;
            cin >> input;
            cin.clear();
            cin.ignore(10000, '\n');
            getItem(&roomList, &itemList, &inventory, currentRoom, input);
        }
        else if (strcmp(input,"DROP") == 0) {
            cout << "What would you like to drop?" << endl;
            cin >> input;
            cin.clear();
            cin.ignore(10000, '\n');
            dropItem(&roomList, &itemList, &inventory, currentRoom, input);
	}
	else if (strcmp(input, "GO") == 0) {
	        cout << "\nWhich direction? (north, south, west, east)" << endl;
                cin >> input; 
                cin.clear();
                cin.ignore(10000, '\n');
            if (move(&roomList, currentRoom, input) == 0) {
	        cout << endl << "There is nothing in that direction" << endl;
            } 
              else {
	          currentRoom = move(&roomList, currentRoom, input);
              }
                
	}
        else if (strcmp(input, "QUIT") == 0) {
             cout << "\nSee you next time..." << endl;  
             break;
        }
	else { 
		cout << "Invalid input, dawg" << endl;
	}
      
     for (int i = 0; i < inventory.size(); ++i){ 
        if (inventory[i] == 4) {
          //win condition 
          cout << "Your katana will keep you safe. Go and slice that kidnapper up!" << endl; 
          cout << "You win :)" << endl;
          run = false; 
        }
      }

      for (int i = 0; i < inventory.size(); ++i){ 
        if (inventory[i] == 2 || inventory[i] == 1) {
          //lose condition 
          cout << "Why would you ever need that man..." << endl; 
          cout << "you are dead" << endl;
          run = false; 
        }
      }
    }
  }


void initRooms(vector<Room*> *rooms) {

  //desc for exits
  char* north = (char*)("north");
  char* south = (char*)("south");
  char* east = (char*)("east");
  char* west = (char*)("west");

  //initialize temporary map for exits
  map<int, char*> temp;

  //make rooms:
  Room* hall  = new Room();
  hall->setDescription((char*)("standing in a dark hallway, you are scared."));
  hall->setId(1);
  temp.insert(pair<int, char*> (2, east));
  temp.insert(pair<int, char*> (3, north));
  temp.insert(pair<int, char*> (4, south));
  hall->setExits(temp);
  hall->setItem(0);
  rooms->push_back(hall);
  temp.clear();
  
  Room* coat = new Room();
  coat->setDescription((char*)("in the coat room."));
  coat->setId(4);
  temp.insert(pair<int, char*> (1, north));
  coat->setExits(temp);
  coat->setItem(0);
  rooms->push_back(coat);
  temp.clear();
  
  Room* dinner = new Room();
  dinner->setDescription((char*)("in the dining room."));
  dinner->setId(3);
  temp.insert(pair<int, char*> (1, south));
  temp.insert(pair<int, char*> (13, north));
  dinner->setExits(temp);
  dinner->setItem(0);
  rooms->push_back(dinner);
  temp.clear();
  
  Room* garage = new Room();
  garage -> setDescription((char*)("in the garage. wait, YOUR KIDNAPPER IS HERE. RUN!!!"));
  garage -> setId(13);
  temp.insert(pair<int, char*> (3, south));
  garage -> setExits(temp);
  garage->setItem(0);
  rooms->push_back(garage);
  temp.clear();
  
  Room* living = new Room();
  living -> setDescription((char*)("in the living room, fun fact: you can't die in this room"));
  living -> setId(2);
  temp.insert(pair<int, char*> (1, west));
  temp.insert(pair<int, char*> (5, north));
  temp.insert(pair<int, char*> (8, south));
  temp.insert(pair<int, char*> (6, east));
  living -> setExits(temp);
  living -> setItem(4/*katana*/);
  rooms -> push_back(living);
  temp.clear();
  
  Room* bath = new Room();
  bath -> setDescription((char*)("in the bathroom."));
  bath -> setId(5);
  temp.insert(pair<int, char*> (2, south));
  bath -> setExits(temp);
  bath -> setItem(5/*flashlight*/);
  rooms -> push_back(bath);
  temp.clear();
  
  Room* guest = new Room();
  guest -> setDescription((char*)("in the guest bedroom."));
  guest -> setId(6);
  temp.insert(pair<int, char*> (2, west));
  temp.insert(pair<int, char*> (7, north));
  guest -> setExits(temp);
  guest -> setItem(0);
  rooms -> push_back(guest);
  temp.clear();
  
  Room* closet = new Room();
  closet -> setDescription((char*)("in the closet. Dead end!"));
  closet -> setId(7);
  temp.insert(pair<int, char*> (6, south));
  closet -> setExits(temp);
  closet -> setItem(0);
  rooms -> push_back(closet);
  temp.clear();
  
  Room* inhall = new Room();
  inhall -> setDescription((char*)("in the inner hallway."));
  inhall -> setId(8);
  temp.insert(pair<int, char*> (2, north));
  temp.insert(pair<int, char*> (9, west));
  temp.insert(pair<int, char*> (10, east));
  temp.insert(pair<int, char*> (11, south));
  inhall -> setExits(temp);
  rooms -> push_back(inhall);
  temp.clear();
  
  Room* office = new Room();
  office -> setDescription((char*)("in an office. No time to work."));
  office -> setId(9);
  temp.insert(pair<int, char*> (8, east));
  office -> setExits(temp);
  office -> setItem(1/*tennis*/);
  rooms -> push_back(office);
  temp.clear();
  
  Room* master = new Room();
  master -> setDescription((char*)("in the master bedroom."));
  master -> setId(10);
  temp.insert(pair<int, char*> (8, west));
  temp.insert(pair<int, char*> (14, north));
  temp.insert(pair<int, char*> (12, east));
  master -> setExits(temp);
  master -> setItem(2/*poke_ball*/);
  rooms -> push_back(master);
  temp.clear();
  
  Room* secret = new Room();
  secret -> setDescription((char*)("in a secret room. You shouldn't be here!"));
  secret -> setId(14);
  temp.insert(pair<int, char*> (10, south));
  secret -> setExits(temp);
  secret -> setItem(0);
  rooms -> push_back(secret);
  temp.clear();
  
  Room* balcony = new Room();
  balcony -> setDescription((char*)("on the balcony. You hate the view"));
  balcony -> setId(12);
  temp.insert(pair<int, char*> (10, west));
  balcony -> setExits(temp);
  balcony -> setItem(3 /*shield*/);
  rooms -> push_back(balcony);
  temp.clear();
  
  Room* outside = new Room();
  outside -> setDescription((char*)("in the outside garden. No exit, but who knew my kidnapper is a great gardener"));
  outside -> setId(11);
  temp.insert(pair<int, char*> (8, north));
  temp.insert(pair<int, char*> (15, east));
  outside -> setExits(temp);
  outside -> setItem(0);
  rooms -> push_back(outside);
  temp.clear();
  
  Room* shed = new Room();
  shed -> setDescription((char*)("in the outside shed."));
  shed -> setId(15);
  temp.insert(pair<int, char*> (11, west));
  shed -> setExits(temp);
  shed -> setItem(0);
  rooms -> push_back(shed);
  temp.clear();

}

int move(vector<Room*>* rooms, int currentRoom, char direction[]) {
  vector<Room*>::iterator i;
  for(i = rooms->begin(); i != rooms->end(); i++) {
    //find current room
    if (currentRoom == (*i)->getId()) {
      map<int, char*> exits;
      exits = *(*i) -> getExits();
      //get exits
      map<int, char*>::const_iterator m;
      for (m = exits.begin(); m != exits.end(); ++m) {
	if (strcmp(m -> second, direction) == 0) {
	  //int move will be the room player is going to
	  return m -> first;
	}
      }
    }
  }
  return 0;
}
//flash light: 5, katana: 4, shield: 3 poke_ball: 2 ball: 1
void initializeItems(vector<Item*>* items) {
  Item* sword = new Item();
  sword -> setName((char*)("katana"));
  sword -> setId(4);
  items -> push_back(sword);

  Item* light = new Item();
  light -> setName((char*)("flashlight"));
  light -> setId(5);
  items -> push_back(light);

  Item* ball = new Item();
  ball -> setName((char*)("tennis ball"));
  ball -> setId(1);
  items -> push_back(ball);

  Item* poke_ball = new Item();
  poke_ball  -> setName((char*)("pokeball"));
  poke_ball  -> setId(2);
  items -> push_back(poke_ball);

  Item* ck = new Item();
  ck -> setName((char*)("shield"));
  ck -> setId(3);
  items -> push_back(ck);
}


//print room function
void printRoom(vector<Room*>* rooms, vector<Item*>* items, int currentRoom)
{
  vector<Room*>::iterator r;
  vector<Item*>::iterator i;
  for (r = rooms->begin(); r != rooms->end(); r++) {
    if (currentRoom == (*r)->getId()) {
      cout << (*r)->getDescription() << endl;
      cout << "  Exits: ";
      //exits
      for (map<int, char*>::const_iterator it = (*r) -> getExits() -> begin(); it != (*r) -> getExits() -> end(); it++) {
	//printing exits
	cout << it -> second << " ";
      }
      cout << endl;
      //do items
      cout << "  Items in this room: ";
      int itemCount = 0; //for "no item" message
      for (i = items->begin(); i != items->end(); i++) {
	if ((*r)->getItem() == (*i)->getId()) {
	  //print spcific item
	  cout << (*i)->getName();
	  itemCount++;
	}
      }
      if (itemCount == 0) {
	cout << "no items in here." << endl;
      } else {
      cout << endl;
      }
    }
  }
}

void printInventory(vector<Item*>* items, vector<int> inventory) {
  vector<Item*>::iterator i;
  for (i = items->begin(); i != items->end(); i++) {
    for (int a = 0; a < inventory.size(); a++) {
      if (inventory[a] == (*i) -> getId()) {
	cout << (*i) -> getName() << " ";
      }
    }
  }
  cout << endl;
}

void dropItem(vector<Room*>* rooms, vector<Item*>* items, vector<int>* invtry, int currentRoom, char name[]) {
  int counter;
  vector<Room*>::iterator r;
  vector<Item*>::iterator i;
  vector<int>::iterator iv;
  for(r = rooms->begin(); r != rooms->end(); r++) { //go through rooms
    //if in currentRoom
    if(currentRoom == (*r) -> getId()) {
      //if no items in the room (item limit per room: one)
      if ((*r) -> getItem() == 0) {
	for (i = items->begin(); i != items->end(); i++) { //go through items
	  //if item exists 
	  if (strcmp((*i) -> getName(), name) == 0) { 
	    for (iv = invtry -> begin(); iv != invtry -> end(); iv++) { //go through inventory
	      //if item is in inventory
	      if ((*iv) == (*i) -> getId()) {
		cout << endl << "Dropped " << (*i) -> getName() << "." << endl;
		//set item in current room
		(*r) -> setItem((*i) -> getId());
		//remove item from inventory
		iv = invtry -> erase(iv);
		return;
	      }
	    }
	  }
	  else if (counter == items -> size() - 1) {
	    cout << endl << "No such item in your inventory." << endl;
	  }
	  counter++;
	}
      }
      else {
	cout << endl << "There is an item in the room already!" << endl;
      }
    }
  }
}

void getItem(vector<Room*>* rooms, vector<Item*>* items,vector<int>* invtry, int currentRoom, char name[]) {
  vector<Room*>::iterator r;
  vector<Item*>::iterator i;
  for (r = rooms->begin(); r != rooms->end(); r++) {
    if (currentRoom == (*r) -> getId()) {
      for (i = items->begin(); i != items->end(); i++) {
	//if item is in the room
	if (((*r) -> getItem() == (*i) -> getId()) && (strcmp((*i) -> getName(), name) == 0)) {
	  //add to inventory
	  invtry -> push_back((*i) -> getId());
	  //set no item in room
	  (*r) -> setItem(0);
	  cout << endl << "Picked up " << (*i) -> getName() << "." << endl;
	  return;
	}
      }
    } 
  }
  cout << "There is no such item in here." << endl;
}
