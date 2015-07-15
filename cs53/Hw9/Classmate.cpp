//Ryan Andrews		Date: 4/23/14
//Class CS 53		Section: B

#include "Classmate.h"
using namespace std;

ostream& operator<<(ostream& os, Classmate& Mate)
{
  os << Mate.m_Name << " has IQ " << Mate.m_IQ << " and is at ("
    << Mate.m_Posx << ", " << Mate.m_Posy << ")." << endl;
	
  return os;
}

void Classmate::Move(const int YardSize)
{
  const int MOVE_DIR = rand()%2; //0: Move up/left, 1: Move down/right
  const int MOVE_POS = rand()%2; //0: Move y, 1: Move x
	
  int DirMax = 0; 
  //DirMax: the maximum distance the Mate can move
	
  if (MOVE_POS) //If moving Horizontal
  {
    if (!MOVE_DIR) //If moving Left
    {
      DirMax = m_Posx;
      m_Posx -= rand()%(DirMax+1);
    }
    else //If moving Right
    {
      DirMax = YardSize-m_Posx;
      m_Posx += rand()%(DirMax+1);
    }
  }
  else //If moving Vertical
  {
    if (!MOVE_DIR) //If moving Up
    {
      DirMax = m_Posy;
      m_Posy -= rand()%(DirMax+1);
    }
    else //If moving Down
    {
      DirMax = YardSize-m_Posy;
      m_Posy += rand()%(DirMax+1);
    }
  }
  return;
}

void Classmate::SetIQ(const int IQ)
{
  m_IQ = IQ;
}
void Classmate::Place()
{
  const int YARD_SIZE = 25; //Maximum yard size that can be created
  //Used to place ralphy in the yard.
  m_Posx = rand()%(YARD_SIZE);
  m_Posy = rand()%(YARD_SIZE);
	
  return;
}

int Classmate::GetIQ()
{
  return m_IQ;
}