//Ryan Andrews		Date: 4/1/14
//Class: CS 53		Section: B

#include "Hw7Functions.h"
using namespace std;

int main()
{
  const int WOOKIE_LENGTH = 8, LETTER_LENGTH = 10;
  wookie Wookies[WOOKIE_LENGTH]; 
    //Contains the names, weights, and heights of the wookies
  char Letters[LETTER_LENGTH] = {0}; 
    //Contains the letters that Ralph has
  
  Greeting();
  init_array(Wookies, WOOKIE_LENGTH);
  init_array(Letters, LETTER_LENGTH);
  ArraySort(Wookies, WOOKIE_LENGTH);
  ArraySort(Letters, LETTER_LENGTH);
  
  cout << endl << endl;
  
  ArrayOutput(Wookies, WOOKIE_LENGTH);
  
  cout << endl;
  
  ArrayOutput(Letters, LETTER_LENGTH);
  Goodbye();
  
  return 0;
}
