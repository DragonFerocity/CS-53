//Name: Brendan Wright & Ryan Andrews
//Date: 28 April 2014
//Class: CS53 Section B
//////////////////////////////////////

#include "hw10schoolyard.h"
#include "hw10classmate.h"
#include "hw10trash.h"
//#include "hw10chest.h"
using namespace std;

int main()
{
  srand(time('\0'));
  
  const int Iterations = 500, Spaces = 38, PosOffset = 22;
  const int ItOffset = 13, NmOffset = 9;
  int Offset = 0, NmOffset2 = 0;
  const int YARD_SIZE = 20;
  const int SCHOOL_SIZE = 5;
  int i = 0; //Counts the number of iterations
  char g; //Used with cin.get()
  int TrashCount = 0; //Counts trash in the yard
  Schoolyard TheSchool(YARD_SIZE,SCHOOL_SIZE);
  
  Classmate Ralph(TheSchool, "Ralph");
  Classmate Possum(TheSchool, "Possum");
  
  for (int i = 0; i < TheSchool.getYard_size(); i++)
  {
    for (int j = 0; j < TheSchool.getYard_size(); j++)
      if (TheSchool.getPlot(i,j) == 'T')
        TrashCount++;
  }
  TheSchool.setNumTrash(TrashCount);
  
  while(i < Iterations && (!Ralph.Graded() || !Possum.Graded()))
  {
    cout << "\n";
    cout << "----" << Ralph.getName() << "----\t\t\t" 
         << "----" << Possum.getName() << "----" << endl;
    //////////////Output the position of each character////////////////////////
    Offset = 0;
    if (Ralph.getX() > 9)
      Offset++;
    if (Ralph.getY() > 9)
      Offset++;
    cout << "Position: (" << Ralph.getX() << ", " << Ralph.getY() << ")";
    for (int j = 0; j < Spaces-PosOffset-Offset; j++)
      cout << " ";
    cout << "Position: (" << Possum.getX() << ", " << Possum.getY() << ")";
    cout << endl;
    //////////////Output the trash each character has//////////////////////////
    cout << "Items: ";
    for (int j = 0; j < Spaces-ItOffset; j++)
      cout << " ";
    cout << "Items: ";
    cout << endl;
    for (int j = 0; j < MAXTRASH; j++)
    {
      cout << "  " << j + 1 << ". " << Ralph.getTrash(j).m_name;
      NmOffset2 = strlen(Ralph.getTrash(j).m_name);
      for (int k = 0; k < Spaces-NmOffset2-NmOffset; k++) 
        cout << " ";
      if (j > 8)
        cout << "\b";
      cout << j + 1 << ". " << Possum.getTrash(j).m_name << endl;
    }
    if(TheSchool.getNumTrash() != 0)
    {
      Ralph.move(TheSchool);
      Possum.move(TheSchool);
    }
    if((Ralph.getX() > 4 || Ralph.getY() > 4) && TheSchool.getNumTrash() == 0)
      Ralph.toDoor(TheSchool);
    else if(TheSchool.getNumTrash() == 0 
        && Ralph.getX() <= 4 && Ralph.getY() <= 4)
      Ralph.toHoover(TheSchool);    
    if((Possum.getX() > 4 || Possum.getY() > 4)
        && TheSchool.getNumTrash() == 0)
      Possum.toDoor(TheSchool);   
    else if(Possum.getX() <= 4 && Possum.getY() <= 4 
        && TheSchool.getNumTrash() == 0)
      Possum.toHoover(TheSchool);     
    cout << TheSchool;

    cout << TheSchool.getHooverY() << ":" << TheSchool.getHooverX() << endl;
    cout << TheSchool.getNumTrash() << endl;
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
    cin.get(g);  //pause for individual steps of classmates
    i++;
  }
  cout << "Ralph's Total Score:  " << Ralph.getTotalVal() << endl
       << "Possum's Total Score:  " << Possum.getTotalVal() << endl;
  if(Ralph.getTotalVal() > Possum.getTotalVal())
  {
    cout << "Ralph has won the most intelligent student award!!";
    cout << "\n\tCONGRATULATIONS!!!!  Maybe next time, Possum!!";
  }
  else if(Possum.getTotalVal() > Ralph.getTotalVal())
  {
    cout << "Possum has won the most intelligent student award!!";
    cout << "\n\tCONGRATULATIONS!!!!  Maybe next time, Ralph!!";
  }
  else
  {
    cout << "Hmmm...it seems as if there has been a tie..." << endl
         << "Homer Simpson has won the most intelligent student award!!"
         << "\n\tCONGRATULATIONS!!!!  Maybe next time, students!!";
  }
	cout <<endl << endl << endl;
  return 0;
}