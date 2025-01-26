/* File: Chainsaw.cpp
Project Name: Silent Hill 2 Remake
Description: This file controls the implementation of the Chainsaw Class

*/

#include "Weapon.h"
#include "Chainsaw.h"
#include <cstdlib>
using namespace std;


// Name: Chainsaw(int damage)
// Preconditions: None
// Postconditions: Can create a Chainsaw
Chainsaw::Chainsaw(int damage) : Weapon(damage) {

}

// Name: SpecialAttack
// Preconditions: None
// Postconditions: Returns damage from special attack
int Chainsaw::SpecialAttack() {
    int base_damage = GetDamage();
    int min_damage = base_damage / 2;
    int max_damage = base_damage * 2.5;
    // Randomize special attack damage between max and min inclusively
    int special_damage = rand() % (max_damage - min_damage + 1) + min_damage;

    cout << "Your chainsaw shreds the enemy " << endl;
    return special_damage;
    
}


// Name: GetName()
// Preconditions: None
// Postconditions: Returns name of weapon (chainsaw)
string Chainsaw::GetName() {
    string chain = "chainsaw";
    return chain;

}
