/* File: Shotgun.cpp
Projedct Name: Silent Hill 2 Remake
Description: This file controls the implementation of the Shotgun Class

*/

#include "Shotgun.h"
#include "Weapon.h"
#include <cstdlib>
using namespace std;


// Name: Shotgun(int damage)
// Preconditions: None
// Postconditions: Can create a Shotgun
Shotgun::Shotgun(int damage) : Weapon(damage) {

}


// Name: SpecialAttack
// Preconditions: None
// Postconditions: Returns damage from special attack
int Shotgun::SpecialAttack() {
    
    int base_damage = GetDamage();
    int min_damage = 1;
    int max_damage = base_damage * 2;
    // Shotgun damage is randomized between min and max damage
    int special_damage = rand() % (max_damage - min_damage + 1) + min_damage;

    cout << "You fire both barrels of the shotgun" << endl;
    return special_damage;


}


// Name: GetName()
// Preconditions: None
// Postconditions: Returns name of weapon (shotgun)
string Shotgun::GetName() {
    string shotgun = "shotgun";
    return shotgun;

}




