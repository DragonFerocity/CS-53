//Name: Brendan Wright & Ryan Andrews
//Date: 28 April 2014
//Class: CS53 Section B
//////////////////////////////////////

#include "hw10schoolyard.h"
#include "hw10classmate.h"
#include "hw10trash.h"
using namespace std;

int main()
{
	srand(time('\0'));

  const int YARD_SIZE = 20;
  const int SCHOOL_SIZE = 5;
  Schoolyard TheSchool(YARD_SIZE,SCHOOL_SIZE);
  
  Classmate Ralph(TheSchool, "Ralphie");
  Classmate Possum(TheSchool, "Possum");
  
  cout << Ralph << endl;
  Ralph.move(TheSchool);
  cout << Ralph << endl;
	
  return 0;
}