//Ryan Andrews		Date: 4/23/14
//Class CS 53		Section: B

#ifndef SCHOOLYARD_H
#define SCHOOLYARD_H
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//Initializes a schoolyard variable with the values specified
//Pre: None
//Post: Initializes the schoolyard

//Outputs a schoolyard to the screen
//Pre: None
//Post: Outpus a schoolyard

//Get's the horizontal (x) size of the yard
//Pre: None
//Post: Returns the x size of the yard

//Get's the vertical (y) size of the yard
//Pre: None
//Post: Returns the y size of the yard

//Get's the horizontal (x) size of the School building
//Pre: None
//Post: Returns the x size of the school building

//Get's the vertical (y) size of the school building
//Pre: None
//Post: Returns the x size of the school building

class Schoolyard
{
  private:
    char m_Yard[25][25];
    short m_YardSize_X;
    short m_YardSize_Y;
    short m_SchoolSize_X;
    short m_SchoolSize_Y;
    void BuildSchool();
	public:
    Schoolyard(int YardSize, int SchoolSize);
    friend ostream& operator<<(ostream& os, Schoolyard& Yard);
    short GetYardSize_X();
    short GetYardSize_Y();
    short GetSchoolSize_X();
    short GetSchoolSize_Y();
};

#endif