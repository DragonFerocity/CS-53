//Ryan Andrews		Date: 4/1/14
//Class: CS 53		Section: B

#ifndef HW7FUNCTION_H
#define HW7FUNCTIONS_H
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct wookie
{
  string m_Name;
  int m_Weight;
  int m_Height;
};

//Displays a greeting to the user
//Pre: None
//Post: Outputs a greeting to the screen
void Greeting();
//Inputs random values for the m_Height, and m_Weight pieces for each piece of
//	the Wookie array and asks the user for a name for each Wookie
//Pre: None
//Post: The Wookie array has a value for each sub-part
void init_array(wookie Wookies[], const int WookieLength);
//Inputs random capital letters into each piece of the Letters array
//Pre: None
//Post: The Letters array has values in it
void init_array(char Letters[], const int LetterLength);
//Displays a goodbye message to the user
//Pre: None
//Post: Outputs a goodbye to the screen
void Goodbye();
//Compares the m_Weight + m_Height of the first wookie to the other
//Pre: None
//Post: Returns true or false
bool operator > (const wookie Wookie1, const wookie Wookie2);
//Tells the program how to output a wookie to the screen
//Pre: None
//Post: Outputs the value of a wookie to the screen
ostream& operator << (ostream & os, const wookie & Wookie);
//Swaps the two given values' places
//Pre: None
//Post: None
template <typename T>
void Swap(T & Item1, T & Item2)
{
  T OldValue = Item1;
  Item1 = Item2;
  Item2 = OldValue;
  
  return;
}
//Sorts the values in the array least to greatest by switching their places
//Pre: Array[0] to Array[x] must be valid data and '>' must be defined for T
//Post: The array of letters or wookies is sorted least to greatest
template <typename T>
void ArraySort(T Array[], const int ArrayLength)
{
  short Index, Position = 0;
  
  for (Index = 0; Index < ArrayLength-1; Index++)
  {
    Position = Index+1;
    while (Array[Position-1] > Array[Position] && Position > 0)
    {
      Swap(Array[Position-1],Array[Position]);
      Position -= 1;
    }
  }
  return;
}
//Outputs the value of each piece of the array to the screen
//Array[0] to Array[x] must be valid data and '<<' must defined for T
//Post: Outputs the two array to the screen
template <typename T>
void ArrayOutput(T Array[], const int ArrayLength)
{
  for (int i = 0; i < ArrayLength; i++)
    cout << Array[i] << endl;
  return;
}

#endif
