/* File: Mandarin.cpp
Project Name: Silent Hill 2 Remake
Description: This file controls the implementation for the Mandarin Class

*/


#include "Enemy.h"
#include "Mandarin.h"
using namespace std;


// Name: Mandarin(string name, int health, int damage, string desc)
// Preconditions: None
// Postconditions: Can create a Mandarin
Mandarin::Mandarin(string name, int hp, int damage, string desc) : Enemy(name, hp, damage, desc) {
    
}


// Name: SpecialAttack
// Preconditions: None
// Postconditions: Returns damage from special attack
int Mandarin::SpecialAttack() {
    cout << "A Mandarin hammers you with their large arms" << endl;
    return MANDARIN_SPECIAL;
}






