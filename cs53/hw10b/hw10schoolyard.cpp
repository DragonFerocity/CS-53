//Name: Brendan Wright & Ryan Andrews
//Date: 28 April 2014
//Class: CS53 Section B
//////////////////////////////////////
#include "hw10schoolyard.h"

Schoolyard::Schoolyard(const int yardSize, const int schoolSize)
{
  const int DEFAULT_SCHOOL_SIZE = 5;
  const int DEFAULT_YARD_SIZE = 20;
  m_NumTrash_Left = 0;
  
  if(yardSize > MAX)
    m_Yard_size = DEFAULT_YARD_SIZE;
  else
    m_Yard_size = yardSize;
   
  for (int i = 0; i < m_Yard_size; i++)
  {
    for (int j = 0; j < m_Yard_size; j++)
    {
      m_schoolPlot[i][j] = 'A';
    }
  }
   
  if(schoolSize >= m_Yard_size)
    m_School_size = DEFAULT_SCHOOL_SIZE; 
  else
    m_School_size = schoolSize;
  
  m_hooverX = rand()%schoolSize;
  m_hooverY = rand()%schoolSize;
  
  m_schoolPlot[m_hooverY][m_hooverX] = 'H';
  
  buildSchool();
}
///////////////////////////////////////////////////////////////////////////////
ostream& operator<<(ostream& os, Schoolyard& Yard)
{
  //const int FENCE_HOLE_CHANCE = 20;
  int Field = Yard.m_Yard_size-Yard.m_School_size; //Column = 1, ;
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
      os << Yard.m_schoolPlot[i][j] << " ";
    os << "|";
    for (int j = 0; j < Field; j++)
      os << Yard.m_schoolPlot[i][j+Yard.m_School_size] << " ";
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
      os << Yard.m_schoolPlot[i][j] << " ";
    os << " ";
    for (int j = 0; j < Field; j++)
      os << Yard.m_schoolPlot[i][j+Yard.m_School_size] << " ";
    os << "\b|" << endl;
  }
  os << "|";
  for (int i = 0; i < Yard.m_Yard_size; i++)
    os << "--";
  os << "|" << endl;
  return os;
}
///////////////////////////////////////////////////////////////////////////////
void Schoolyard::buildSchool()
{ 
  const int TRASH_CHANCE = 20; // 1/20 or 5% chance of trash appearing
  int ChestX, ChestY;
  for (int i = 0; i < m_Yard_size; i++)
  {
    for (int j = 0; j < m_Yard_size; j++)
    {
      if (m_schoolPlot[i][j] != 'H' && m_schoolPlot[i][j] != 'C')
        m_schoolPlot[i][j] = ' ';
      if (j < m_School_size && i < m_School_size && m_schoolPlot[i][j] != 'H')
        m_schoolPlot[i][j] = 'S';
      if (j == m_School_size-1 && i == m_School_size-1)
        m_schoolPlot[i][j] = 'D';
      if (!(rand()%(TRASH_CHANCE)) && m_schoolPlot[i][j] != 'C' 
          && m_schoolPlot[i][j] != 'S' && m_schoolPlot[i][j] != 'D'
          && m_schoolPlot[i][j] != 'H')
      {
        m_schoolPlot[i][j] = 'T';
        //m_NumTrash_Left++;
      }
    }
  }
  do
  {
    ChestX = rand()%m_Yard_size;
    ChestY = rand()%m_Yard_size;
  }while((ChestX < m_School_size && ChestY < m_School_size)
          || m_schoolPlot[ChestY][ChestX] == 'H' 
          || m_schoolPlot[ChestY][ChestX] == 'C' 
          || m_schoolPlot[ChestY][ChestX] == 'D' 
          || m_schoolPlot[ChestY][ChestX] == 'S' 
          || m_schoolPlot[ChestY][ChestX] == 'T');
  m_schoolPlot[ChestY][ChestX] = 'O';
  
  return;
}
/////////////////////////////////////////////////////////////////////////////// 
char Schoolyard::getPlot(const int num1, const int num2)const
{
  if(num1 >= 0 && num1 < MAX && num2 >= 0 && num2 < MAX)
    return m_schoolPlot[num1][num2];
  else
    return 'X';
}
///////////////////////////////////////////////////////////////////////////////
void Schoolyard::setPlot(const int num1, const int num2, const char Val)
{
  if(num1 >= 0 && num1 < MAX && num2 >= 0 && num2 < MAX)
    m_schoolPlot[num1][num2] = Val;
  else
    cout << "BOOOOO";
  return;
}