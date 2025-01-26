/* File: Plank.cpp
Project Name: Silent Hill 2 Remake
Description: This file controls the implementation of the Plank Class

*/

#include "Plank.h"
#include "Weapon.h"
#include <cstdlib>
using namespace std;


// Name: Plank(int damage)
// Description: Creates a new Plank
// Preconditions: None
// Postconditions: Can create a Plank
Plank::Plank(int damage) : Weapon(damage) {

}

// Name: SpecialAttack
// Preconditions: None
// Postconditions: Returns damage from special attack
int Plank::SpecialAttack() {

    int base_damage = GetDamage();
    int min_damage = 1;
    // Randomizes damage from minimum to base damage
    int random_damage = rand() % (base_damage - min_damage + 1) + min_damage;
    int SpecialAttack = random_damage + random_damage;

    cout << "You bash twice with your plank" << endl; 
    return SpecialAttack;

}

// Name: GetName()
// Preconditions: None
// Postconditions: Returns name of weapon (plank)
string Plank::GetName() {
    string plankName = "plank";
    return plankName;
    
}