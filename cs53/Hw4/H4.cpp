//Ryan Andrews		Date: February 18, 2014
//Class: CS 53
//Section: B

#include <iostream>
using namespace std;

int main()
{
  int Option; //The option that the user pickes from the menu
  float num_x = 0; //The value that the user enters for x, to work with
  int Factorial; //The factorial of num_x
  float x_0 = 20.0; //The intial guess of the fourth root of num_x
  float fourth_root; //Fourth root of num_x
  double Exp_x = 1; //Stores the value of e^x
  double Exp_x_power = 1; //Stores the value of x^i;
  do
  {
    do
    {
      cout << endl << endl
           << "| Menu" << endl
           << "|-------------------------------------" << endl
           << "| 1. Enter a positive real number, x" << endl
           << "| 2. Factorial of x" << endl
           << "| 3. Fourth root of x" << endl
           << "| 4. X-Ponential of x (Exp(x))" << endl
           << "| 5. Quit" << endl
           << endl << endl;
      cout << "Please pick an option:  ";
      cin >> Option;
      cout << endl;
      
      if (Option != 1 && !num_x)
        cout << "You must first enter a value of x to work with. "
             << "Please pick option 1." << endl << endl;
      
    }while (Option != 1 && !num_x);
    
    switch (Option)
    {
      case 1: 
        cout << "Please enter a positive, real number: x = ";
        cin >> num_x;
        break;
      case 2:
        Factorial = static_cast<int>(num_x);
        cout << num_x << "! = " << num_x << " * ";
        for (int i = Factorial-1; i > 1; i--)
        {
          cout << i << " * ";
          Factorial *= i;
        }
        cout << "1";
        cout << " = " << Factorial;
        break;
      case 3:
        fourth_root = ( (3*x_0) + (num_x/(x_0*x_0*x_0)) ) / 4;
        for (int n = 1; n <= 6; n++)
          fourth_root = ( (3*fourth_root) + 
            (num_x/(fourth_root*fourth_root*fourth_root)) ) / 4;
        cout << "The fourth root of " << num_x << " is " << fourth_root;
        break;
      case 4:
        Exp_x = 1;
        Exp_x_power = 1;
        for (int i = 1; i <= 6; i++)
        {
          Factorial = 1;
          for (int j = 1; j <= i; j++)
            Factorial *= j;
          Exp_x_power *= num_x;
          Exp_x += (Exp_x_power/Factorial);
        }
        cout << "e^x = " << Exp_x;
        break;
    }
  }while (Option != 5);
  
  return 0;
}
