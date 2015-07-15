//Ryan Andrews		Date: 4/23/14
//Class CS 53		Section: B

#include "Classmate.h"
//#include "Schoolyard.h"
using namespace std;

int main()
{
	srand(time('\0'));
  
  const int YARD_SIZE = 20;
  const int SCHOOL_SIZE = 5;
  Schoolyard TheSchool(YARD_SIZE,SCHOOL_SIZE);
  Classmate Ralph(TheSchool, "Ralph");
  char g;
  
  for (int i = 0; i < 500; i++)
  {
    Ralph.Move(YARD_SIZE, TheSchool);
    cout << TheSchool;
    cout << Ralph << endl;
    cin.get(g);
  }
	
  return 0;
}