//Ryan Andrews          Date: March 5, 2014
//Class: CS 53
//Section: B

#ifndef HW6FUNCTIONS_H
#define HW6FUNCTIONS_H
using namespace std;

//Prompts the user to enter a number
//Pre: None
//Post: Returns the entered number
float EnterPosNum();
//Calculates the factorial of pos_num
//Pre: None
//Post: None
void GetFactorial(const float pos_num);
//Calculates the nth root of pos_num
//Pre: x must be positive for even roots
//Post: None
void GetNthRoot(const float pos_num);
//Calculates the nth power of pos_num
//Pre: None
//Post: None
void GetNthPower(const float pos_num);
//Calculates the Exponential of pos_num (e^x)
//Pre: None
//Post: None
void GetExponential(const float pos_num);
//Calculates the Sinh(pos_num)
//Pre: None
//Post: None
void GetSinhx(const float pos_num);
//Calculates pos_nu, to a power
//Pre: None
//Post: Returns pos_num to the passed power
float PowerOfX(const float pos_num, const int Power);
//Calculates the factorial of pos_num
//Pre: None
//Post: Returns the factorial of pos_num
float FindFactorial(const float pos_num);

#endif
