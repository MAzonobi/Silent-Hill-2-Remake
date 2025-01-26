/* File: Weapon.cpp
Project Name: Silent Hill 2 Remake
Description: This file is the implementation of the parent Class Weapon

*/

#include "Weapon.h"
using namespace std;


// Name: Weapon(int damage) - Overloaded constructor
// Preconditions: None
// Postconditions: Can be used to populate weapon or child classes
Weapon::Weapon(int damage) : m_damage(damage) {

}

// Name: ~Weapon - Virtual Destructor
// Preconditions: None
// Postconditions: Nothing to deallocate
Weapon::~Weapon() {

}

// Name: Attack()
// Preconditions: None
// Postconditions: Returns damage
int Weapon::Attack() {
    cout << "You do " << m_damage << " points of damage" << endl;
    return m_damage;

}

// Name: GetDamage()
// Preconditions: None
// Postconditions: Returns damage
int Weapon::GetDamage() {
    return m_damage;

}

// Name: ImproveWeapon(int)
// Preconditions: None
// Postconditions: Increases m_damage of this weapon by the value passed
void Weapon::ImproveWeapon(int increase) {
    m_damage += increase;

}

