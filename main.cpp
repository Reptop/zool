#include <bits/stdc++.h>
#include <map>
#include "room.h"
#include "pokemon.h" 
using namespace std;

void listPokemon(vector<Pokemon*> *owo);
void initRooms(vector<Room*> *rooms); 
//vector<items> 
//I basically have to point to a class of it+ems 
//I need to use
//ASSOCIATE A ROOM WITH ITS OWN POSITION USING A MAP 

int main() {
  //variables for inputting if you want to delete or search by year
    bool run = true;
    char cmd[10]; 
    vector<Room*> rooms; 
    vector<Pokemon*> poke; 
    map <Room, int> t;
	cout << "If you're reading this, you will likely die within the 30 minutes." << endl;  
	cout << "You were kidnapped and are stranded in a random hallway" << endl;  
	cout << "To escape death, try and find a way out before your kidnapper comes back!" << endl; 
        cout << "\nYOUR ARE CURRENTLY IN THE POKEMON CENTER, RESTING YOUR POKEMON" << endl; 
        
	while (run) {
	cout << "\nWhat will you do?" << endl; 
	cout << "COMMANDS: CATCH, BAG, POKEMON, QUIT, GO (NORTH WEST EAST SOUTH)" << endl; 
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

void listPokemon(vector<Pokemon*> *owo) {
	for (vector<Pokemon*>::iterator iter = owo->begin(); iter != owo->end(); ++iter) {
            cout << "NAME: " << (*iter)->getName(); 
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
  bath -> setItem(5/*tp*/);
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


