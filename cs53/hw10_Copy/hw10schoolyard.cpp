//Name: Brendan Wright & Ryan Andrews
//Date: 28 April 2014
//Class: CS53 Section B
//////////////////////////////////////
#include "hw10schoolyard.h"

Schoolyard::Schoolyard(const int yardSize, const int schoolSize)
{
  const int BALANCE = 2; //fixes schoolbuild size if too large
  int HooverPos_X = 0, HooverPos_Y = 0;
  
  if(yardSize > MAX)
    m_Yard_size = MAX;
  else
    m_Yard_size = yardSize;
    
  if(schoolSize >= m_Yard_size)
    m_School_size = yardSize - BALANCE; 
  else
    m_School_size = schoolSize;
  
  do
  {
    HooverPos_X = rand()%schoolSize;
    HooverPos_Y = rand()%schoolSize;
  }while (HooverPos_X == schoolSize && HooverPos_Y == schoolSize);
  
  m_schoolPlot[HooverPos_X][HooverPos_Y] = 'H';
  
  buildSchool();
}

ostream& operator<<(ostream& o, Schoolyard& school)
{
  for(int i = 0; i < school.m_Yard_size; i++)
  {   
    o << "~~~~~";
  }
  o << endl << endl;
  
  ///////////////////////////////////////////////
  for(int j = 0; j < school.m_Yard_size; j++)
  {
    o << "|";
    for(int i = 0; i < school.m_Yard_size; i++)
    {
      o << "----";
    }
    o << "-|" << endl << "| ";
    for(int i = 0; i < school.m_Yard_size; i++)
    {
      o << school.m_schoolPlot[i][j] << "   ";
    }   
    o << "|" << endl;
  }
  o << "|";
  for(int i = 0; i < school.m_Yard_size; i++)
  {
    o << "----";
  }
  o << "-|" << endl << endl; 
  /////////////////////////////////////////////// 
    
 for(int i = 0; i < school.m_Yard_size; i++)
  {   
    o << "~~~~~";
  }
  o << endl;
  return o;
}

void Schoolyard::buildSchool()
{
  const int TRASH_CHANCE = 20; // 1/10 or 10% chance of trash appearing
  for (int i = 0; i < m_Yard_size; i++)
  {
    for (int j = 0; j < m_Yard_size; j++)
    {
      if (m_schoolPlot[i][j] != 'H')
        m_schoolPlot[i][j] = ' ';
      if (!(rand()%(TRASH_CHANCE)))
        m_schoolPlot[i][j] = 'T';
      if (j < m_School_size && i < m_School_size && m_schoolPlot[i][j] != 'H')
        m_schoolPlot[i][j] = 'S';
      if (j == m_School_size-1 && i == m_School_size-1)
        m_schoolPlot[i][j] = 'D';
    }
  }
  cout << *this;
  return;
}
  
char Schoolyard::getPlot(const int num1, const int num2)const
{
  if(num1 > 0 && num1 < MAX && num2 > 0 && num2 < MAX)
    return m_schoolPlot[num1][num2];
  else
    return 'X';
}
void Schoolyard::setPlot(const int num1, const int num2, const char Val)
{
  if(num1 > 0 && num1 < MAX && num2 > 0 && num2 < MAX)
    m_schoolPlot[num1][num2] = Val;
  return;
}