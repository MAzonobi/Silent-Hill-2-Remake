/* File: Mannequin.cpp
Project Name: Silent Hill 2 Remake
Description: This file controls the implementation fo the Mannequin Class

*/

#include "Enemy.h"
#include "Mannequin.h"
using namespace std;

// Name: Mannequin(string name, int health, int damage, string desc)
// Preconditions: None
// Postconditions: Creates a new Mannequin
Mannequin::Mannequin(string name, int health, int damage, string desc) : Enemy(name, health, damage, desc) {
    
}

// Name: SpecialAttack
// Preconditions: None
// Postconditions: Returns damage from special attack
int Mannequin::SpecialAttack(){
    cout << "The mannequin smashes with their kick!" << endl;
    return MANNEQUIN_SPECIAL;
}

