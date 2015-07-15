//Name: Brendan Wright & Ryan Andrews
//Date: 28 April 2014
//Class: CS53 Section B
//////////////////////////////////////
#ifndef HW10SCHOOLYARD_H
#define HW10SCHOOLYARD_H

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MAX = 25;

//Schoolyard(const int yardSize = 20, const int buildSize = 5);
//Descr: Set's the values of the constructor to the defined values when created
//Pre: None
//Post: Initializes schoolyard


//Descr: Constructor that defaults size of yard and school
//Pre: None
//Post: Constructor that defaults size of yard and school

//Descr: Returns size of yard to calling object
//Pre: None
//Post: Returns size of yard to calling object

//Descr: Returns size of school to calling object
//Pre: None
//Post: Returns size of school to calling object

//Descr: Outputs schoolyard to screen
//Pre: None
//Post: Outputs schoolyard to screen

//Decr: Builds school from constructor
//Pre: None
//Post: Builds school from constructor

class Schoolyard
{
  public:
    Schoolyard(const int yardSize = 20, const int buildSize = 5);
    short getYard_size()const {return m_Yard_size;}
    short getBuild_size()const {return m_School_size;}
    char getPlot(const int num1, const int num2)const;
    void setPlot(const int num1, const int num2, const char Val);
    void setNumTrash(const int numTrash) {m_NumTrash_Left = numTrash;}
    int getNumTrash()const {return m_NumTrash_Left;}
    void setHooverX(int hooverX) {m_hooverX = hooverX;}
    void setHooverY(int hooverY) {m_hooverY = hooverY;}
    int getHooverX()const {return m_hooverX;}
    int getHooverY()const {return m_hooverY;}
    friend ostream& operator<<(ostream& os, Schoolyard& Yard);
  private:
    void buildSchool();  
    char m_schoolPlot[MAX][MAX];
    short m_Yard_size;
    short m_School_size; //for school building
    int m_NumTrash_Left;
    int m_hooverX;
    int m_hooverY;
};



#endif