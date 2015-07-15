//Name: Brendan Wright & Ryan Andrews
//Date: 28 April 2014
//Class: CS53 Section B
//////////////////////////////////////
#ifndef HW10CLASSMATE_H
#define HW10CLASSMATE_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <string>
#include "hw10schoolyard.h"
#include "hw10trash.h"
#include "hw10chest.h"
using namespace std;

const int MAXTRASH = 10;
const int CHANCE = 2;
const int MAXPLOT = 24;
const int MINIQ = 50;
const int MAXIQ = 70;
const int IQRANGE  = MAXIQ - MINIQ;

//struct Chest;

//Classmate(const string name = "Bob")
//Descr: Constructor defaults name to Bob, places, sets random IQ
//Pre: None
//Post: Constructor defaults name to Bob, places, sets random IQ

//void go_to_school(const Schoolyard& school)
//Descr: Places classmate within range of schoolplot (0 - 24)
//Pre: Must be called within constructor
//Post: Places classmate within range of schoolplot (0 - 24)

//bool setIq(const int iq)
//Descr: Sets member variable equal to iq passed
//Pre: None
//Post: Sets member variable equal to iq passed

//int getIq()
//Decr: Returns the iq of object
//Pre: None
//Post: Returns the iq of object

//void move(const Schoolyard& school)
//Descr: Changes one coordinate of classmate's position within schoolplot
//       (0 - 24)
//Pre: None
//Post: Changes one coordinate of classmate's position within schoolplot
//       (0 - 24)

//friend ostream& operator<<(ostream& o, const Classmate& classmate)
//Decr: Outputs Classmate, showing name, position, and iq
//Pre: None
//Post: Outputs Classmate, showing name, position, and iq



class Classmate
{
  public:
    Classmate(Schoolyard& school, const string name = "Bob");
    void go_to_school(Schoolyard& school);
    bool setIq(const int iq);
    int getIq();
    void move(Schoolyard& school);
    void toDoor(Schoolyard& school);
    void toHoover(Schoolyard& school);
    void HooverGrade(Schoolyard& school);
    string getName()const {return m_name;}
    Trash getTrash(int index){return m_trash[index];}
    int getTotalVal()const {return m_totalVal;}
    friend ostream& operator<<(ostream& o, const Classmate& classmate);
    int abs(int Num){return (Num < 0 ? -Num : Num);}
    int getX(){return m_x_coord;}
    int getY(){return m_y_coord;}
    bool Graded(){return m_GotGrade;}
    bool getWeaponStatus() {return m_HasWeapon;}
    void moveWeapon(Schoolyard& school);
    void moveDefend(Schoolyard& school);
    int getLastMove() {return m_LastMove;}
    void setLastMove(int LastMove) {m_LastMove = LastMove;}
  private:
    string m_name;
    int m_x_coord;
    int m_y_coord;
    int m_iq;
    int m_numItems;
    int m_totalVal;
    int m_LastMove;
    bool m_GotGrade;
    Trash m_trash[MAXTRASH];
    bool m_HasWeapon;
};

#endif
