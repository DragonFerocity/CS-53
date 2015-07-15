//Ryan Andrews		Date: 4/23/14
//Class CS 53		Section: B

#include "Classmate.h"
#include "Schoolyard.h"
using namespace std;

int main()
{
	srand(time('\0'));

  Classmate Ralph("Ralphie");
  const int YARD_SIZE = 15;
  const int SCHOOL_SIZE = 6;
  Schoolyard TheSchool(YARD_SIZE,SCHOOL_SIZE);

  cout << "\n\nThe yard is " << TheSchool.GetYardSize_X() << "x" 
        << TheSchool.GetYardSize_Y() << " in dimensions." << endl;
  cout << "The school building is " << TheSchool.GetSchoolSize_X() << "x" 
        << TheSchool.GetSchoolSize_Y() << " in dimensions." << endl << endl;
  cout << Ralph << endl;
  Ralph.Move(YARD_SIZE);
  cout << Ralph << endl;
	
  return 0;
}