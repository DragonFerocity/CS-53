//Ryan Andrews		Date: March 5, 2014
//Class: CS 53
//Section: B

#include <iostream>
#include "Hw6Functions.h"
using namespace std;

int main()
{
  int Option;
  float pos_num = 0; //The positive number the user enters
  
  do
  {
    cout << endl << end;
         << "|Menu" << endl
         << "|-------------------------------------" << endl
         << "|1. Enter a positive number x" << endl
         << "|2. Factorial (of integer part) of x" << endl
         << "|3. Nth root of x" << endl
         << "|4. x to the n power" << endl
         << "|5. Exponention of x" << endl
         << "|6. Sinh(x)" << endl
         << "|7. Quit" << endl
         << endl << endl;
         
    cout << "Please pick an option: ";
    cin >> Option;
    cout << endl;
    
    if (Option != 1 && !pos_num)
      cout << "x is not defined yet. Please pick option 1!" << endl;

    switch(pos_num)
    {
      case 1:
        pos_num = EnterPosNum();
        break;
      case 2: 
        GetFactorial(pos_num);
        break;
      case 3:
        GetNthRoot(pos_num);
        break;
      case 4:
        GetNthPower(pos_num);
        break;
      case 5:
        GetExponential(pos_num);
        break;
      case 6:
        GetSinhx(pos_num);
        break;
      case 7:
        cout << "I hope this helps you get smarter, Ralphy!"
             << endl << "Have a nice day!"
             << endl << endl;
        break;
      default:
        cout << "I'm sorry, that option doesn't exist!"
             << endl << "Please pick a number between 1 and 7!"
             << endl << endl;
    }
  
  }while((Option != 1 && !pos_num) || (Option != 7));
  
  return 0;
}
