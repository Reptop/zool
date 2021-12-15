#include <bits/stdc++.h>
#include <map>
#include "room.h"
#include "pokemon.h" 
using namespace std;
void catchh(vector<Room*> *owo);
void initPoke();
void test(vector<Room*> *owo); 
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
	cout << "Welcome to the world of Pokemon, where humans and pokemon live together" << endl;  
	cout << "You currently have 150 pokemon in your pokedex, however, you are missing mewtwo" << endl;  
	cout << "Your goal is to catch mewtwo, you will first need a master ball, so go get one and catch that pokemon!" << endl; 
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
            catchh(&rooms);  
        }
	else if (strcmp(cmd, "BAG") == 0) {
          test(&rooms);  
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

void catchh(vector<Room*> *owo) {
	for (vector<Room*>::iterator iter = owo->begin(); iter != owo->end(); ++iter) {
            cout << "NAME: " << (*iter)->getName(); 
	}
}

void test(vector<Room*> *owo) {
  Room *hi = new Room(); 
  cout <<"\nDEBUG MENU" << endl;  
  cout << "Enter Room name" << endl; 
  cin >> hi->getName();
  cin.clear(); 
  cout << "Enter test description" << endl; 
  cin >> hi->getDesc(); 
  cin.clear();
  cout << "Enter test exit" << endl;
  cin >> hi->getExit(); 
  cin.clear();
  owo->push_back(hi); 
}

void initPoke() {
  Pokemon *test = new Pokemon();
  test->setName("helo");
  test->getName();
}
