#include <bits/stdc++.h>
#include <map>
#include "room.h"
#include "pokemon.h" 
using namespace std; 

void catchh(vector<Pokemon*> owo);

int main() {
  //variables for inputting if you want to delete or search by year
    bool run = true;
    char cmd[10]; 
    vector<Room*> rooms; 
    vector<Pokemon*> poke; 

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
		cout << "test";
        }
	else if (strcmp(cmd, "BAG") == 0) {

        }
        else if (strcmp(cmd,"POKEMON") == 0) {
        
	}
	else if (strcmp(cmd, "GO") == 0) {
		//figure out go function 
	}
        else if (strcmp(cmd, "QUIT") == 0) {
             cout << "See you next time..."; 
             break;
        }
	else { 
		cout << "Invalid input, dawg" << endl;
	}	
    }

}

void catchh(vector<Pokemon*> *owo) {
	for (vector<Pokemon*>::iterator iter = owo->begin(); iter != owo->end(); ++iter) {

	}
}
