//Ryan Andrews		Date: 4/23/14
//Class CS 53		Section: B

#include "Schoolyard.h"
using namespace std;

Schoolyard::Schoolyard(int YardSize, int SchoolSize)
{
  int HooverPos_X = 0, HooverPos_Y = 0;
  m_Yard_size = YardSize;
  m_School_size = SchoolSize;
  
  for (int i = 0; i < YardSize; i++)
  {
    for (int j = 0; j < YardSize; j++)
      m_Yard[i][j] = 'A';
  }
  
  do
  {
    HooverPos_X = rand()%SchoolSize;
    HooverPos_Y = rand()%SchoolSize;
  }while (HooverPos_X == SchoolSize && HooverPos_Y == SchoolSize);
  
  m_Yard[HooverPos_X][HooverPos_Y] = 'H';
  
  BuildSchool();
}

ostream& operator<<(ostream& os, Schoolyard& Yard)
{
  //const int FENCE_HOLE_CHANCE = 20;
  int Field = Yard.m_Yard_size-Yard.m_School_size; //Column = 1, 
  ////OUTPUT THE TOP OF THE YARD////
  /////Each cell is 2x1 in size/////
  os << "|";
  for (int i = 0; i < Yard.m_Yard_size; i++)
    os << "--";
  os << "|" << endl;
  ////OUTPUTS THE SCHOOL///
  for (int i = 0; i < Yard.m_School_size; i++)
  {
    os << "|";
    for (int j = 0; j < Yard.m_School_size; j++)
      os << Yard.m_Yard[i][j] << " ";
    os << "|";
    for (int j = 0; j < Field; j++)
      os << Yard.m_Yard[i][j+Yard.m_School_size] << " ";
    os << "\b|" << endl;
  }
  os << "|";
  for (int i = 0; i < Yard.m_School_size; i++)
    os << "--";
  os << "|";
  for (int i = 0; i < Field; i++)
    os << "  ";
  os << "\b|" << endl;
  ////OUTPUTS THE REST OF THE YARD///
  for (int i = Yard.m_School_size; i < Yard.m_Yard_size; i++)
  {
    os << "|";
    for (int j = 0; j < Yard.m_School_size; j++)
      os << Yard.m_Yard[i][j] << " ";
    os << " ";
    for (int j = 0; j < Field; j++)
      os << Yard.m_Yard[i][j+Yard.m_School_size] << " ";
    os << "\b|" << endl;
  }
  os << "|";
  for (int i = 0; i < Yard.m_Yard_size; i++)
    os << "--";
  os << "|" << endl;
  return os;
}

void Schoolyard::BuildSchool()
{
  const int TRASH_CHANCE = 20; // 1/10 or 10% chance of trash appearing
  for (int i = 0; i < m_Yard_size; i++)
  {
    for (int j = 0; j < m_Yard_size; j++)
    {
      if (m_Yard[i][j] != 'H')
        m_Yard[i][j] = ' ';
      if (!(rand()%(TRASH_CHANCE)))
        m_Yard[i][j] = 'T';
      if (j < m_School_size && i < m_School_size && m_Yard[i][j] != 'H')
        m_Yard[i][j] = 'S';
      if (j == m_School_size-1 && i == m_School_size-1)
        m_Yard[i][j] = 'D';
    }
  }
  cout << *this;
  return;
}

short Schoolyard::GetYardSize_X()
{
  return m_Yard_size;
}
short Schoolyard::GetSchoolSize_X()
{
  return m_School_size;
}

void Schoolyard::setPlot(const int num1, const int num2, const char Val)
{
  if(num1 >= 0 && num1 < m_Yard_size && num2 >= 0 && num2 < m_Yard_size)
    m_Yard[num1][num2] = Val;
  else
    cout << "BOOOOO";
  return;
}