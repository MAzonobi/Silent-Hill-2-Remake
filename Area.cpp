/* File: Area.cpp
Project Name: Silent Hill 2 Remake
Description: This file controls the implementation of the Area Class

*/

#include "Area.h"
using namespace std;


//Name: Area (Overloaded Constructor)
//Precondition: Must have valid input for each part of a area
//Postcondition: Creates a new area
Area::Area(int id, string name, string desc, int north, int east, int south, int west) 
    : m_ID(id), m_name(name), m_desc(desc) {
    m_direction[0] = north;
    m_direction[1] = east;
    m_direction[2] = south;
    m_direction[3] = west;

}

//Name: GetName
//Precondition: Must have valid area
//Postcondition: Returns area name as string
string Area::GetName() {
    return m_name;

}

//Name: GetID
//Precondition: Must have valid area
//Postcondition: Returns area id as int
int Area::GetID() {
    return m_ID;

}

//Name: GetDesc
//Precondition: Must have valid area
//Postcondition: Returns area desc as string
string Area::GetDesc() {
    return m_desc;

}

//Name: CheckDirection
//Precondition: Must have valid area
//Postcondition: Returns id of area in that direction if the exit exists
int Area::CheckDirection(char myDirection) {
    // Ensures that lowercase and uppercase are valid for direction
    switch (myDirection) {
        case 'n':
        case 'N':
            return m_direction[n];
            break;

        case 'e':
        case 'E':
            return m_direction[e];
            break;

        case 's':
        case 'S':
            return m_direction[s];
            break;

        case 'w':
        case 'W':
            return m_direction[w];
            break;

        default:
            return -1;  
    }

}

//Name: PrintArea
//Precondition: Area must be complete
//Postcondition: Outputs the area name, area desc, then possible exits
void Area::PrintArea() {

    char escape;
    cout << m_name << endl << endl;
    cout << m_desc << endl;
    
    //Iterates through to find and display proper exit
    for (int i = 0; i < 4; i++) {

        if (m_direction[0] != -1) {
            escape = 'N';
        }

        if (m_direction[1] != -1) {
            escape = 'E';
        }

        if (m_direction[2] != -1) {
            escape = 'S';
        }
        
        if (m_direction[3] != -1) {
            escape = 'W';
        }
    }
    
    cout << "Possible exits: " << escape << endl;
    
    cout << endl;
}

