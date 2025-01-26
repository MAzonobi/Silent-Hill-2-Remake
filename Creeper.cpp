/* File: Creeper.cpp
Project Name: Silent Hill 2 Remake
Description: This file controls the implementation of the Creeper Class

*/

#include "Enemy.h"
#include "Creeper.h"
using namespace std;


// Name:  Creeper(string name, int health, int damage, string desc)
// Preconditions: None
// Postconditions: Can create a Creeper
Creeper::Creeper(string name, int hp, int damage, string desc) : Enemy(name, hp, damage, desc) {
     
}
    

// Name: SpecialAttack
// Preconditions: None
// Postconditions: Returns damage from special attack
int Creeper::SpecialAttack() {
    cout << "A Creeper takes a large bite out of you!" << endl;
    return CREEPER_SPECIAL; 

}



