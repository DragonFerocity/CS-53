//Ryan Andrews		Date: 4/23/14
//Class CS 53		Section: B

#include "Classmate.h"
using namespace std;

Classmate::Classmate(Schoolyard& Yard, const string Name)
{
  m_IQ = rand()%(20)+50;
  m_Name = Name;
  Place(Yard);
}

ostream& operator<<(ostream& os, Classmate& Mate)
{
  os << Mate.m_Name << " has IQ " << Mate.m_IQ << " and is at ("
    << Mate.m_Posx << ", " << Mate.m_Posy << ")." << endl;
	
  return os;
}

void Classmate::Move(const int YardSize, Schoolyard& Yard)
{
  int Dir, mvX = 0, mvY = 0;
  int ClosestTrash = 60, MvDir = 0;
  
  //YardPos_X = Yard.getPlot(m_Posx
  /*for (int i = 0; i < Yard.GetYardSize_X(); i++)
  {
    if (Yard.getPlot(m_Posy,i) == 'T' && abs(i-m_Posx) < ClosestTrash)
    {
      ClosestTrash = abs(i-m_Posx);
      if (i < m_Posx) //Left
        MvDir = -1;
      if (i > m_Posx)//Right
        MvDir = 1;
    }
    if (Yard.getPlot(i,m_Posx) == 'T' && abs(i-m_Posy) < ClosestTrash)
    {
      ClosestTrash = abs(i-m_Posy);
      if (i < m_Posy)//Up
        MvDir = -2;
      if (i > m_Posy)//Down
        MvDir = 2;
    } 
  }
  
  */Yard.setPlot(m_Posy,m_Posx,':');
  
  /*if (ClosestTrash == 60)
  {*/
  do
  {
    mvX = 0;
    mvY = 0;
    Dir = rand()%(4);
      //FOR DIR:
      //0: Move Left
      //1: Move Up
      //2: Move Right
      //3: Move Down
    if (Dir == 0)
      mvX = -1;
    if (Dir == 1)
      mvY = -1;
    if (Dir == 2)
      mvX = 1;
    if (Dir == 3)
      mvY = 1;
  }while((m_Posx+mvX < Yard.GetSchoolSize_X()
      && m_Posy < Yard.GetSchoolSize_X())
      || m_Posx+mvX > Yard.GetYardSize_X()-1
      || (m_Posy+mvY < Yard.GetSchoolSize_X()
      && m_Posx < Yard.GetSchoolSize_X())
      || m_Posy+mvY > Yard.GetYardSize_X()-1
      || m_Posy+mvY < 0 || m_Posx+mvX < 0);
  m_Posx += mvX;
  m_Posy += mvY;
  /*}
  else
  {
    switch (MvDir)
    {
      case -2:
        m_Posy--;
        break;
      case -1:
        m_Posx--;
        break;
      case 1:
        m_Posx++;
        break;
      case 2:
        m_Posy++;
        break;
      default:
        break;
    }
  }*/
  
  Yard.setPlot(m_Posy,m_Posx,'C');
  
  return;
}

void Classmate::SetIQ(const int IQ)
{
  m_IQ = IQ;
}
void Classmate::Place(Schoolyard& Yard)
{
  const int YARD_SIZE = 25; //Maximum yard size that can be created
  //Used to place ralphy in the yard.
  m_Posx = rand()%(YARD_SIZE);
  m_Posy = rand()%(YARD_SIZE);
  
  Yard.setPlot(m_Posx,m_Posy,'C');
	
  return;
}

int Classmate::GetIQ()
{
  return m_IQ;
}