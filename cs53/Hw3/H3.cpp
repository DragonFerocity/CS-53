//Ryan Andrews			Date: February 8, 2014
//Title: H3.cpp
//Section: 1B

#include <iostream>
using namespace std;

int main()
{
  const float TOXIC_CHEM_BAG = 2.0;
  //TOXIC_CHEM_BAG is the price of a 1 pound bag of Toxic Chemicals
  const float HS_F = 2.0, HS_D = 3.0, HS_C = 4.0, HS_B = 5.0, HS_A = 5.0;
  //TOXIC_CHEM_BAG is the price of a 1-pound bag sold by Bart.
  //HS is the Hoover Score. HS_F is the score needed to get an F...
  int NumBags; 
  //NumBags is the number of Toxic Chemical Bags Ralphy has.
  float Poundage, Money, Weight, Weight_Orig; 
  //Poundage is how many pounds of trash is picked up
  //Money is the money ralphy comes to school with.
  //Weight is the weight of Ralphy's science project.
  //Weight_Orig is the original weight of the bag before he eats some of it.
  bool Cry, Hungry, GlowingItem, Glue;
  //Cry is if Ralphy will cry after Ms Hoover grades his project.
  //Hungry is if Ralphy is hungry.
  //GlowingItem is if Ralphy has a glowing item in his bag.
  //Glue is if Ralphy has glue in his bag.'
  char Repeat = 'n';
  //Repeat is if the user wants to repeate the program.
  do
  {
    cout << "Hello Ralphy!" << endl;
    cout << "  How many pounds of stuff did you pick up?  ";
    cin >> Poundage;
    cout << "  How much money do you have?  $";
    cin >> Money;
    cout << "  Will you cry if you get a low grade? (1: yes. 0: no):  ";
    cin >> Cry;
    cout << "  Are you hungry? (1: yes. 0: no):  ";
    cin >> Hungry;
    cout << "  Does your bag contain a glowing item? (1: yes. 0: no):  ";
    cin >> GlowingItem;
    cout << "  Do you have a bottle of glue with you? (1: yes. 0: no):  ";
    cin >> Glue;
  
    NumBags = static_cast<int>(Money/TOXIC_CHEM_BAG);
    Weight_Orig = Poundage + NumBags;
    Weight = Weight_Orig;
  
    if (Hungry && Glue)
      Weight -= Weight_Orig/4;
    if (Hungry && Glue && GlowingItem)
    {
      Weight -= Weight_Orig/4;
      Weight += 1;
    }
    if (!Hungry && Glue)
      Weight += 0.5;
    if (Weight == 0)
      Weight = 1;
    if (Cry)
      Weight *= 3;

    cout << endl;
  
    if (Weight < HS_F)
      cout << "You will recieve an F on this project ";
    if (Weight < HS_D && Weight >= HS_F)
      cout << "You will recieve a D on this project ";
    if (Weight < HS_C && Weight >= HS_D)
      cout << "You will recieve a C on this project ";
    if (Weight < HS_B && Weight >= HS_C)
      cout << "You will recieve a B on this project ";
    if (Weight > HS_A)
      cout << "You will recieve an A on this project ";
  
    cout << "with a final grade of: " << Weight << " points." << endl;
    cout << endl << "Would you like to repeat this program (y/n)?  ";
    cin >> Repeat;
  }while (Repeat != 'n');
  
  return 0;
}
