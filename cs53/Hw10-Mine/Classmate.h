//Ryan Andrews		Date: 4/23/14
//Class CS 53		Section: B

#ifndef CLASSMATE_H
#define CLASSMATE_H
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Schoolyard.h"
using namespace std;

//Defines the default values for a Classmate
//Pre: None
//Post: Initializes a Classmate with values

//Defines a classmate with a name given
//Pre: None
//Post: Initializes a classmate with values and the name that was passed

//Places the classmate somewhere in the schoolyard
//Pre: None
//Post: Sets m_Posx and m_Posy to a value in the schoolyard

//Sets the IQ to the value specified
//Pre: None
//Post: Changes the IQ to a new value_comp

//Returns the IQ of the classmate
//Pre: None
//Post: Returns the IQ of the classmate

//Overloads the operator to be able to output the a classmate to the screen
//Pre: None
//Post: Outputs a classmate

//Moves the classmate somewhere inside the yard
//Pre: None
//Post: Gives the classmate a new position

class Classmate
{
  private:
    int m_IQ;
    string m_Name;
    int m_Posx;
    int m_Posy;
		
  public:
    Classmate(Schoolyard& Yard, const string Name);
    void Place(Schoolyard& Yard);
    void SetIQ(const int IQ);
    int GetIQ();
    friend ostream& operator<<(ostream& os, Classmate& Mate);
    void Move(const int YardSize, Schoolyard& Yard);
};

#endif
