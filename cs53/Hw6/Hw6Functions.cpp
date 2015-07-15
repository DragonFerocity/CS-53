//Ryan Andrews		Date: March 5, 2014
//Class: CS 53
//Section: B

#include <iostream>
#include "Hw6Functions.h"
using namespace std;

float EnterPosNum()
{
  float pos_num;
  do
  {
    cout << "Please enter a positive number: ";
    cin >> pos_num;
    
    if (pos_num <= 0)
      cout << "Please enter a positive number!!" << endl << endl;
  
  }while(pos_num <= 0);
  
  return pos_num;
}

void GetFactorial(const float pos_num)
{
  int Factorial = 0;
  
  Factorial = FindFactorial(pos_num);
  
  cout << "The factorial of " << pos_num << " is : " << Factorial << endl;

  return;
}

void GetNthRoot(const float pos_num)
{
  int N; //The root of pos_num to find (ie. Square root, cube root, etc...)
  const int InitialGuess = 20; //value of the initial guess of the root of pos_num
  float RootX = InitialGuess; //The value of the Nth root of x
  const int Iterations = 8;
  
  do
  {
    cout << "What value of N, the root, would you like to find? ";
    cin >> N;
  
    if (N <= 1)
      cout << "Please enter a number greater than 1!" << endl;
  }while(N <= 1);
  
  for (int i = 0; i < Iterations; i++)
    RootX = ( (N-1)*pos_num + RootX/PowerOfX(pos_num,N-1) ) / N;
    
  cout << "The " << N;
  
  if (N == 2)
    cout << "nd ";
  else if (N == 3)
    cout << "rd ";
  else
    cout << "th ";
    
  cout << "root of " << pos_num << " is: " << RootX << endl;
  
  return;
}

void GetNthPower(float pos_num)
{
  int Power; //The power to take pos_num to
  float pos_num_original = pos_num; //Original value of pos_num
  
  do
  {
    cout << "What power of " << pos_num << " would you like to find? ";
    cin >> Power;
    
    if (Power < 0)
      cout << "Please enter a value greater than 0!" << endl << endl;
  }while(Power < 0);
  
  if (Power > 1)
    pos_num = PowerOfX(pos_num,Power);
  
  cout << pos_num_original << " to the " << Power << " power is: " << pos_num 
       << endl;
  
  return;
}

void GetExponential(const float pos_num)
{
  const int Iterations = 10; //number of times to repeat the formula
  float Exponential = 1; //e^pos_num power
  
  for (int i = 1; i < Iterations; i++)
    Exponential += (PowerOfX(pos_num,i)/FindFactorial(i));
  
  cout << "The exponential of " << pos_num << " is: " << Exponential << endl;
  
  return;
}

void GetSinhx(const float pos_num)
{
  const int Iterations = 5; //number of times to repeat formula
  long Sinhx = 1;
  
  for (int i = 1; i < Iterations; i += 2)
    Sinhx = (PowerOfX(pos_num,i)/FindFactorial(pos_num));
    
  cout << "Sinh(x) = " << Sinhx << endl;
  
  return;
}

float PowerOfX(float pos_num, const int Power)
{
  float pos_num_Orig = pos_num;
  for (int i = 0; i < Power; i++)
    pos_num *= pos_num_Orig;
  
  if (Power == 0)
    pos_num = 1;
    
  return pos_num;
}

float FindFactorial(const float pos_num)
{
  int Factorial = 1;
  
  for (int i = 1; i <= static_cast<int>(pos_num); i++)
    Factorial *= i;
    
  if (Factorial == 0)
    Factorial = 1;
        
  return Factorial;
}
            
