/* File: Game.cpp
Project Name: Silent Hill 2 Remake
Description: This file implements every file to create the main functionality of Silent Hill 2 Remake

*/


#include "Area.h" 
#include "Hero.h" 
#include "Creeper.h" 
#include "Mandarin.h" 
#include "Mannequin.h" 
#include "Weapon.h" 
#include "Plank.h"
#include "Chainsaw.h" 
#include "Shotgun.h"
#include "Game.h" 

#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;



// Name: Game(string filename) - Overloaded Constructor
// Preconditions: None
// Postconditions: Initializes all game variables to defaults (constants)
Game::Game(string filename) {
    m_filename = filename;
    m_myHero = nullptr;
    m_curEnemy = nullptr;
    m_curArea = START_AREA;

}

// Name: ~Game
  // Description: Destructor
  // Preconditions: None
  // Postconditions: Deallocates anything dynamically allocated
  //                 in Game (weapons, enemies, and map)
Game::~Game() {
    
    // Deallocates existing hero 
    if (m_myHero) {
        delete m_myHero;
        m_myHero = nullptr;
    }

    if (m_curEnemy) {
        delete m_curEnemy;
        m_curEnemy = nullptr;
    }

    int mapSize = m_myMap.size();

    // Deallocates each area in the map 
    for (int i = 0; i < mapSize; ++i) {
        delete m_myMap[i];
    }

    // Clear the vector to remove any pointers left over
    m_myMap.clear();  

}


// Name: LoadMap()
// Description: Dynamically creates areas and inserts them into
//              the m_myMap vector. Use getlines and delimiters.
// Precondition: m_filename is populated
// Postcondition: Map is populated with area objects.
void Game::LoadMap() {
    ifstream mapFile(m_filename);  
    if (!mapFile.is_open()) {
        cerr << "Error: Could not open map file " << m_filename << endl;
        return;
    }

    string idStr, name, desc, northStr, eastStr, southStr, westStr;

    // Processes each line in the map file
    while (getline(mapFile, idStr, DELIMITER)) {
        
        // Read the remaining fields separated by DELIMITER
        getline(mapFile, name, DELIMITER);
        getline(mapFile, desc, DELIMITER);
        getline(mapFile, northStr, DELIMITER);
        getline(mapFile, eastStr, DELIMITER);
        getline(mapFile, southStr, DELIMITER);
        getline(mapFile, westStr);

        // Converts IDs and directions from string to integers
        int id = stoi(idStr);
        int north = stoi(northStr);
        int east = stoi(eastStr);
        int south = stoi(southStr);
        int west = stoi(westStr);

       
        Area* area = new Area(id, name, desc, north, east, south, west);
        m_myMap.push_back(area);
    }

    mapFile.close();
}


// Name: HeroCreation()
// Preconditions: None
// Postconditions: m_myHero is populated (and m_name in m_myHero)
void Game::HeroCreation() {
    string heroName;
    
    cout << "Hero Name: ";
    getline(cin, heroName);  

    //New hero is created with the user's name and base health
    m_myHero = new Hero(heroName, HERO_HEALTH);

}


// Name: Look()
// Preconditions: None
// Postconditions: None
void Game::Look() {
    m_myMap[m_curArea]->PrintArea();
    if (m_curEnemy) {
        // Displays current area and enemy description
        cout << m_curEnemy->GetDesc() << endl;
    }else{
        cout << "It is peaceful here." << endl;
    }
    
}


// Name: StartGame()
// Preconditions: Input file must exist
// Postconditions: Map is loaded, User has chosen a hero to play with,
//                 prints the starting area, chooses a random enemy
//                 and calls action
void Game::StartGame() {

    cout << "Silent Hill Remake 2" << endl;

    // Calls each function needed for the game to begin
    LoadMap();
    HeroCreation();
    RandomEnemy();
    Look();
    Action();
}


// Name: Action()
// Preconditions: Everything in start has been completed
// Postconditions: Game continues until quit or player dies in during attack
void Game::Action() {
    bool isPlaying = true;
    
    while (isPlaying) {
        

        cout << "\nWhat would you like to do?" << endl;
        cout << "1. Look" << endl;
        cout << "2. Move" << endl;
        cout << "3. Attack Enemy" << endl;
        cout << "4. Improve Weapon" << endl;
        cout << "5. Check Stats" << endl;
        cout << "6. Quit" << endl;

        
        int choice;
        cout << "Enter choice: ";
        cin >> choice;

        // Handles each case for the 6 options in the Mainmenu
        switch (choice) {
            case 1:
                Look();
                break;

            case 2:
                Move();
                break;

            case 3:
                if (m_curEnemy) {
                    // If the hero is defeated, the game will end
                    bool heroAlive = Attack();
                    if (!heroAlive) {
                        isPlaying = false;
                    }
                }else{
                    cout << "There is nothing to attack here." << endl;
                }
                break;

            case 4:
                ImproveWeapon();
                break;

            case 5:
                Stats();
                break;

            case 6:
                cout << "Thank you for playing Silent Hill 2 Remake!" << endl;
                isPlaying = false;
                break;

            default:
                break;
        }
    }
}


// Name: RandomEnemy()
// Preconditions: None
// Postconditions: Populates m_curEnemy (sets to nullptr if nothing)
void Game::RandomEnemy() {
    
    // Clear any existing enemy
    if (m_curEnemy) {
        delete m_curEnemy;
        m_curEnemy = nullptr;
    }

    int enemyChoice = rand() % 4;

    // 25% chance of 1 of 3 enemies appearing or a peaceful area
    switch (enemyChoice) {
        case 1:
            m_curEnemy = nullptr;
            cout << "The area is peaceful." << endl;
            break;
        
        case 2:
            m_curEnemy = new Creeper(CREEPER_NAME, CREEPER_HEALTH, CREEPER_DAMAGE, CREEPER_DESC);
            cout << "A Creeper appears!" << endl;
            break;

        case 3:
            m_curEnemy = new Mandarin(MANDARIN_NAME, MANDARIN_HEALTH, MANDARIN_DAMAGE, MANDARIN_DESC);
            cout << "A Mandarin appears!" << endl;
            break;

        case 4:
            m_curEnemy = new Mannequin(MANNEQUIN_NAME, MANNEQUIN_HEALTH, MANNEQUIN_DAMAGE, MANNEQUIN_DESC);
            cout << "A Mannequin appears!" << endl;
            break;
    }

}


// Name: ImproveWeapon
// Preconditions: First checks to see if they have enough xp to improve.
//                If they have xp, for each COST_IMPROVEMENT, damage in the
//                weapon increases by one (permanently)
// Postconditions: m_curHero's weapon is improved
void Game::ImproveWeapon() {
    
    int heroExperience = m_myHero->GetExperience();
    int maxImprovements = heroExperience / COST_IMPROVEMENT;

    // Does not allow upgrade if there's not enough experience
    if (heroExperience < COST_IMPROVEMENT) {
        cout << "Not enough experience points to improve weapon. You need at least " << COST_IMPROVEMENT << " XP." << endl;
        return;
    }

    cout << "You are able to improve your weapon up to " << maxImprovements << " time(s) right now" << endl;

    int improveRequest = 0;

    // Continues to reprompt user for a valid upgrade number
    do {
        cout << "How many improvements would you like to make to your weapon? (Max " << maxImprovements << ")." << endl;
        cin >> improveRequest;

        if (improveRequest < 1 || improveRequest > maxImprovements) {
            cout << "Choose a number between 1 and " << maxImprovements << endl;

        }

    } while (improveRequest < 1 || improveRequest > maxImprovements);

    
    // Sets amount of improvements to the user's weapon
    m_myHero->ImproveWeapon(improveRequest);
    // Updates experience points to remaining amount
    m_myHero->SetExperience(heroExperience - (improveRequest * COST_IMPROVEMENT));
    cout << "Your weapon has been improved by " << improveRequest << " damage!" << endl;
}


// Name: Move()
// Preconditions: Must be valid move (area must exist)
// Postconditions: Displays area information and new monster
void Game::Move() {
    char direction;
    int newAreaID = -1;

    // Continues to prompt until a valid direction is chosen
    do {
        cout << "Which direction would you like to move? (N, E, S, W): ";
        cin >> direction;

        // Check if the entered direction leads to a valid area
        newAreaID = m_myMap[m_curArea]->CheckDirection(direction);

        if (newAreaID == -1) {
            cout << "This is not a possible exit. " << endl;
        }

    } while (newAreaID == -1);

    // Updates current area
    m_curArea = newAreaID;
    
    RandomEnemy();  
    Look();         
}



// Name: Attack
  // Description: Allows player to attack an enemy.
  // Preconditions: Must have enemy Enemy in current area
  // Postconditions: Checks to make sure that there is an enemy to fight.
  //                 Asks the user if they want to use a normal or special attack
  //                 Updates health(hp) as battle continues.
  //                 Both Hero and Enemy attack every round until
  //                 one or more has <= 0 health
  //                 May need to deallocate enemy Enemy to prevent memory leaks.
  //                 When either Enemy or Hero <= 0 health, calls ProcessBattle
  //                 Returns true if hero still alive else false
bool Game::Attack() {

    // Checks to see if there is an enemy to attack
    if (!m_curEnemy) {
        cout << "There is no enemy to attack here." << endl;
        return true;  
    }

    // While both Hero and Enemy are alive, the user is prompted to attack
    while (m_myHero->GetHealth() > 0 && m_curEnemy->GetHealth() > 0) {
        int choice;
        
        do {
            cout << "Choose your attack: " << endl; 
            cout << "1. Punch Enemy " << endl; 
            cout << "2. Use " << m_myHero->GetWeaponName() << endl;
            cin >> choice;

            if (choice != 1 && choice != 2) {
                cout << "Select 1 or 2 to attack " << endl;
            }

        } while (choice != 1 && choice != 2);

        int heroAttackDamage;
        if (choice == 1) {
            // Sets damage for "Punch Enemy"
            heroAttackDamage = m_myHero->Attack();
        }else{
            // Sets damage for the random weapon
            heroAttackDamage = m_myHero->SpecialAttack();
        }

        // Calculates damage to enemy
        int newEnemyHealth = m_curEnemy->GetHealth() - heroAttackDamage;
        m_curEnemy->SetHealth(newEnemyHealth);
        cout << "You dealt " << heroAttackDamage << " damage to the " << m_curEnemy->GetName() << "." << endl;

        // Display current health of both hero and enemy after hero attacks
        cout << "Hero Health: " << m_myHero->GetHealth() << endl;
        cout << m_curEnemy->GetName() << " Health: " << m_curEnemy->GetHealth() << endl;

        // Checks to see if the enemy is defeated
        if (m_curEnemy->GetHealth() <= 0) {
            cout << "You defeated the " << m_curEnemy->GetName() << "!" << endl;
            bool heroAlive = ProcessAttack(false, true);
            return heroAlive;  
        }

        // Calculates damage to Hero
        int enemyAttackDamage = m_curEnemy->Attack();
        int newHeroHealth = m_myHero->GetHealth() - enemyAttackDamage;
        m_myHero->SetHealth(newHeroHealth);
        cout << "The " << m_curEnemy->GetName() << " dealt " << enemyAttackDamage << " damage to you." << endl;

        // Display current health of both hero and enemy after enemy attack
        cout << "Hero Health: " << m_myHero->GetHealth() << endl;
        cout << m_curEnemy->GetName() << " Health: " << m_curEnemy->GetHealth() << endl;

        // Checks to see if the hero is defeated
        if (m_myHero->GetHealth() <= 0) {
            cout << "You have been defeated by the " << m_curEnemy->GetName() << "." << endl;
            bool heroAlive = ProcessAttack(true, false);
            return heroAlive;  
        }
    }
    
    return m_myHero->GetHealth() > 0;
}


// Name: Stats()
// Preconditions: None
// Postconditions: None
void Game::Stats() {
    cout << "Hero Stats:" << endl;
    cout << "Name: " << m_myHero->GetName() << endl;
    cout << "Health: " << m_myHero->GetHealth() << endl;
    cout << "Experience: " << m_myHero->GetExperience() << endl;
}


bool Game::ProcessAttack(bool enemyAlive, bool heroAlive) {
    if (!heroAlive && !enemyAlive) {

        // Both hero and enemy are defeated
        cout << "You defeated each other at the same time!." << endl;
        return false;

    }else if (heroAlive && !enemyAlive) {
        
        // Adds experience points if the hero wins
        cout << "You have earned " << EXPERIENCE_WIN << " experience points" << endl;
        m_myHero->SetExperience(m_myHero->GetExperience() + EXPERIENCE_WIN);
        m_myHero->SetHealth(HERO_HEALTH);  
        return true;

    }else{
        return false;
    }

}



