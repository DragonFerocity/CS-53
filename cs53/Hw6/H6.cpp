//Ryan Andrews          Date: March 5, 2014
//Class: CS 53
//Section: B

#include <iostream>
#include "Hw6Functions.h"

int main()
{
  int Option; //The menu option the user picks
  float pos_num = 0;
  
  do
  {
    do
    {
      cout << "  | MENU " << endl
           << "--|-----------------------------" << endl
           << "1 | Enter a positive number, x" << endl
           << "2 | Factorial of x" << endl
           << "3 | Nth root of x" << endl
           << "4 | Power of x, x^n" << endl
           << "5 | Exp(x)" << endl
           << "6 | Sinh(x)" << endl
           << "7 | Quit" << endl;
    
      cout << "Please choose an option: ";
      cin >> Option;
      
      if (Option <= 0 || Option > 7)
        cout << "That is not between 1-7!!" << endl << endl;
      else if (Option != 1 && Option != 7 && pos_num == 0)
        cout << "You must choose Option 1 first!!" << endl << endl;
          
    }while((Option <= 0 || Option > 7) || 
     (Option != 1 && Option != 7 && pos_num == 0));
  
    switch(Option)
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
    }
  }while(Option != 7);
  
  cout << "Have a nice day Ralph!" << endl;
  
  return 0;

}
