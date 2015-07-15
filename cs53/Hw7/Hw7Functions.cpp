//Ryan Andrews		Date: 4/1/14
//Class: CS 53		Section: B

#include "Hw7Functions.h"
#include <iostream>
using namespace std;

void Greeting()
{
  cout << "Hello Ralphy! Let's get sorting!" << endl << endl;
  
  return;
}

void init_array(wookie Wookies[], const int WookieLength)
{
  const int WEIGHT_MIN = 12, WEIGHT_MAX = 78;
    //WEIGHT_MIN is the min value a wookie can weigh
    //WEIGHT_MAX is the max value a wookie can weigh
  const int HEIGHT_MIN = 10, HEIGHT_MAX = 34;
    //HEIGHT_MIN is the min height a wookie can be
    //HEIGHT_MAX is the max height a wookie can be
  
  srand(time(NULL));
  for (int i = 0; i < WookieLength; i++)
  {
    Wookies[i].m_Weight = rand()%(WEIGHT_MAX-WEIGHT_MIN+1)+WEIGHT_MIN;
    Wookies[i].m_Height = rand()%(HEIGHT_MAX-HEIGHT_MIN+1)+HEIGHT_MIN;
    cout << "What is the name of Wookie #" << i+1 << "?  ";
    cin >> Wookies[i].m_Name;
  }
  
  return;
}

void init_array(char Letters[], const int LetterLength)
{
  const int LETTER_MIN = 65, LETTER_MAX = 90; //ASCII Values
  
  srand(time(NULL));
  for (int i = 0; i < LetterLength; i++)
    Letters[i] = rand()%(LETTER_MAX-LETTER_MIN+1)+LETTER_MIN;
  
  return;
}

void Goodbye()
{
  cout << "\nThanks for using this program, Ralphy! See you later!" << endl;
  return;
}

bool operator > (const wookie Wookie1, const wookie Wookie2)
{
  int Wookie1Val, Wookie2Val;
  
  Wookie1Val = Wookie1.m_Weight + Wookie1.m_Height;
  Wookie2Val = Wookie2.m_Weight + Wookie2.m_Height;
  
  return (Wookie1Val > Wookie2Val);
}

ostream& operator << (ostream & os, const wookie & Wookie)
{
  os << Wookie.m_Name << " weighs " << Wookie.m_Weight << " oz and is "
     << Wookie.m_Height << " inches tall.";
  
  return os;
}
