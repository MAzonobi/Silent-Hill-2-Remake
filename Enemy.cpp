/* File: Enemy.cpp
Project Name: Silent Hill 2 Remake
Description: This file is the implementation of the parent class "Enemy"

*/

#include "Enemy.h"


// Name: Enemy(string name, int hp, int damage, string desc)
// Preconditions: None
// Postconditions: Used to populate child class data
Enemy::Enemy(string name, int hp, int damage, string desc) : m_name(name), m_health(hp), m_damage(damage), m_desc(desc) {
    
}
    

// Name: Enemy Destructor
// Preconditions: None
// Postconditions: Does nothing but cannot be omitted
Enemy::~Enemy() {

}

// Name: Attack()
// Preconditions: None
// Postconditions: Returns damage
int Enemy::Attack() {
    cout << m_name << " attacks!" << endl;
    return m_damage;
}


// Name: GetName()
// Preconditions: None
// Postconditions: Returns enemy name
string Enemy::GetName() {
    return m_name;

}


// Name: GetHealth
// Preconditions: None
// Postconditions: Returns enemy health
int Enemy::GetHealth() {
    return m_health;
}

// Name: SetHealth
// Preconditions: None
// Postconditions: Updates enemy health
void Enemy::SetHealth(int health) {
    m_health = health;

}

// Name: GetDamage
// Preconditions: None
// Postconditions: Returns enemy damage
int Enemy::GetDamage() {
    return m_damage;
    
}

// Name: GetDesc
// Preconditions: None
// Postconditions: Returns the description of the enemy
string Enemy::GetDesc() {
    return m_desc;

}

// Name: Overloaded <<
// Preconditions: None
// Postconditions: returns an ostream with output of enemy
ostream& operator<<(ostream& cout, Enemy& enemy) {
    cout << "Enemy: " << enemy.GetName() << endl;
    cout << "Health: " << enemy.GetHealth() << endl;
    cout << "Damage: " << enemy.GetDamage() << endl;
    cout << "Description: " << enemy.GetDesc() << endl;

    return cout;
}




