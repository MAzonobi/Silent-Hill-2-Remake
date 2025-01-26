/* File: Hero.cpp
Project Name: Silent Hill 2 Remake
Description: This file handles the implementation for the Hero Class

*/

#include <iostream>
#include <string>
#include <cstdlib>
#include "Weapon.h"
#include "Plank.h"
#include "Shotgun.h"
#include "Chainsaw.h"
#include "Hero.h"
using namespace std;


// Name: Hero(string name, int health) - Overloaded Constructor
// Preconditions: None
// Postconditions: Used to populate hero
Hero::Hero(string name, int health) : m_name(name), m_health(health), m_experience(0), m_weapon(nullptr) {
    RandomWeapon();

}

// Name: ~Hero Destructor
// Preconditions: None
// Postconditions: Used to deallocate anything dynamically allocated
Hero::~Hero() {
    delete m_weapon;

}

// Name: Attack()
// Preconditions: None
// Postconditions: Returns damage
int Hero::Attack() {

    if (m_weapon) {
        return m_weapon->Attack();

    }else{
        return WEAPON_BASE;

    }
}


// Name: GetName()
// Preconditions: None
// Postconditions: Returns the current name
string Hero::GetName() {
    return m_name;

}


// Name: SetName()
// Preconditions: None
// Postconditions: Updates m_name
void Hero::SetName(string name) {
    m_name = name;

}


// Name: GetHealth()
// Preconditions: None
// Postconditions: Returns the health of the hero
int Hero::GetHealth() {
    return m_health;

}

// Name: SetHealth(int)
// Preconditions: None
// Postconditions: Updates m_health of the hero
void Hero::SetHealth(int health) {
    m_health = health;

}

// Name: GetExperience()
// Preconditions: None
// Postconditions: Returns the experience of the hero
int Hero::GetExperience() {
    return m_experience;

}

// Name: SetExperience(int)
// Preconditions: None
// Postconditions: Updates m_experience of the hero
void Hero::SetExperience(int experience) {
    m_experience = experience; 
    
}

// Name: RandomWeapon
// Preconditions: Called when hero is instantiated
// Postconditions: Updates m_weapon to point at random weapon
void Hero::RandomWeapon() {

    // Uses 1 in 3 chance to assign a weapon to the hero
    int weapon_choice =  rand() % 3;
    delete m_weapon; 

    if (weapon_choice == 0) {
        m_weapon = new Plank(WEAPON_BASE);
        cout << "You start with a Plank" << endl; 


    }else if (weapon_choice == 1) {
        m_weapon = new Chainsaw(WEAPON_BASE);
        cout << "You start with a Chainsaw" << endl;

    }else{
        m_weapon = new Shotgun(WEAPON_BASE);
        cout << "You start with a Shotgun" << endl;

    }

}


// Name: ImproveWeapon()
// Preconditions: None
// Postconditions: Increases m_weapon and decreases m_experience
void Hero::ImproveWeapon(int increase) {
    if (m_weapon && m_experience >= 3) {
        int improvement = m_experience / 3;
        m_weapon->ImproveWeapon(improvement);
        // sets remaining experience points to m_experience
        m_experience %= 3;

    }
} 


// Name: SpecialAttack()
// Description: Calls the weapon's special attack
// Preconditions: None
// Postconditions: Used to attack an enemy using the weapon's special attack
int Hero::SpecialAttack() {
    if (m_weapon) {
        return m_weapon->SpecialAttack();

    }else{
        return 0;

    }

}


// Name: GetWeaponName()
// Preconditions: None
// Postconditions: Returns the name of the weapon held by the hero
string Hero::GetWeaponName() {
    if (m_weapon) {
        return m_weapon->GetName();

    }else{
        return "No weapon";

    }
}


// Name: Overloaded <<
// Preconditions: None
// Postconditions: Returns an ostream with output of hero
ostream& operator<<(ostream& cout, Hero& hero) {
    cout << "Hero: " << hero.GetName() << endl;
    cout   << "Health: " << hero.GetHealth() << endl;
    return cout;
}

