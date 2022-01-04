#include <bits/stdc++.h>
#include <map>
#include "room.h"
#include "item.h" 
using namespace std;

void initRooms(vector<Room*> *rooms);
void initializeItems(vector<Item*>* items); 
//vector<items> 
//I basically have to point to a class of it+ems 
//I need to use
//ASSOCIATE A ROOM WITH ITS OWN POSITION USING A MAP 

int main() {
  //variables for inputting if you want to delete or search by year
    bool run = true;
    char cmd[10]; 
    vector<Room*> rooms; 
    vector<Item*> items; 
    map <Room, int> t;
	cout << "If you're reading this, you will likely die within the 30 minutes." << endl;  
	cout << "You were kidnapped and are currently stranded in a random hallway" << endl;  
	cout << "To escape death, try and find a way out before your kidnapper comes back!" << endl; 
        cout << "\nYOUR ARE CURRENTLY IN THE POKEMON CENTER, RESTING YOUR POKEMON" << endl; 
        
	while (run) {
	cout << "\nWhat will you do?" << endl; 
	cout << "COMMANDS: DROP, BAG, POKEMON, QUIT, GO (NORTH WEST EAST SOUTH)" << endl; 
        cin >> cmd;   
        cin.clear(); 
        cin.ignore(10000, '\n'); 
        //add media 
        if (strcmp(cmd,"CATCH") == 0) {
           //catch(pass through pokemon vector) 
        }
	else if (strcmp(cmd, "BAG") == 0) {
        }
        else if (strcmp(cmd,"POKEMON") == 0) {
        
	}
	else if (strcmp(cmd, "GO") == 0) {
	        cout << "\nWhich direction? (NORTH, SOUTH, WEST, EAST)" << endl;
                cin >> cmd; 
                cin.ignore(10000, '\n');
                cin.clear(); 
                //go(pass through direction); 
                
	}
        else if (strcmp(cmd, "QUIT") == 0) {
             cout << "\nSee you next time..." << endl;  
             break;
        }
	else { 
		cout << "Invalid input, dawg" << endl;
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
  hall->setDescription((char*)("In the Pokemon Center, resting up."));
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
  garage -> setDescription((char*)("in the garage."));
  garage -> setId(13);
  temp.insert(pair<int, char*> (3, south));
  garage -> setExits(temp);
  garage->setItem(3/*shield*/);
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
  living -> setItem(4/*boots*/);
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
  office -> setDescription((char*)("in your office. No time to work."));
  office -> setId(9);
  temp.insert(pair<int, char*> (8, east));
  office -> setExits(temp);
  office -> setItem(1/*laptop*/);
  rooms -> push_back(office);
  temp.clear();
  
  Room* master = new Room();
  master -> setDescription((char*)("in the master bedroom."));
  master -> setId(10);
  temp.insert(pair<int, char*> (8, west));
  temp.insert(pair<int, char*> (14, north));
  temp.insert(pair<int, char*> (12, east));
  master -> setExits(temp);
  master -> setItem(2/*briefcase*/);
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
  balcony -> setDescription((char*)("on the balcony. You can see the spaceship!"));
  balcony -> setId(12);
  temp.insert(pair<int, char*> (10, west));
  balcony -> setExits(temp);
  balcony -> setItem(0);
  rooms -> push_back(balcony);
  temp.clear();
  
  Room* outside = new Room();
  outside -> setDescription((char*)("in the outside garden. No exit, but there is a lovely garden"));
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
