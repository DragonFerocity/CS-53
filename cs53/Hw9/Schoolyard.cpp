//Ryan Andrews		Date: 4/23/14
//Class CS 53		Section: B

#include "Schoolyard.h"
using namespace std;

Schoolyard::Schoolyard(int YardSize, int SchoolSize)
{
  m_YardSize_X = YardSize;
  m_YardSize_Y = YardSize;
  m_SchoolSize_X = SchoolSize;
  m_SchoolSize_Y = SchoolSize;
  BuildSchool();
}

ostream& operator<<(ostream& os, Schoolyard& Yard)
{
  bool HorizBorder = false, VertBorder = false;
  //HorizBorder is if there is a horizontal border on the current line
  //VertBorder is if there is an extra pipe in the current line
  for (int i = 0; i < Yard.m_YardSize_X; i++)
    os << "--";
  os << "--\n";
  for (int j = 0; j < Yard.m_YardSize_Y; j++)
  {
    HorizBorder = false;
    VertBorder = false;
    os << "|";
    for (int k = 0; k < Yard.m_YardSize_X; k++)
    {
      os << " " << Yard.m_Yard[j][k] << "";
      if ((Yard.m_Yard[j][k] == 'S' || Yard.m_Yard[j][k] == 'D')
          && Yard.m_Yard[j][k+1] != 'S' && Yard.m_Yard[j][k+1] != 'D')
        {
          os << "|";
          VertBorder = true;
        }
      else
        os << "";
    }
    if (!VertBorder)
      os << " ";
    os << "\b|" << endl;
    for (int i = 0; i < Yard.m_YardSize_X; i++)
      if ((Yard.m_Yard[j][i] == 'S' || Yard.m_Yard[j][i] == 'D')
          && Yard.m_Yard[j+1][i] != 'S' && Yard.m_Yard[j+1][i] != 'D')
        {
          os << "--";
          HorizBorder = true;
        }
    if (HorizBorder)
    {
      os << "\b--|";
      for (int i = 0; i < Yard.m_YardSize_X-Yard.m_SchoolSize_X-1; i++)
        os << "  ";
      os << " |" << endl;
    }
  }
  for (int i = 0; i < Yard.m_YardSize_X; i++)
    os << "--";
  os << "--\n";

  return os;
}

void Schoolyard::BuildSchool()
{
  const int TRASH_MAX_CHANCE = 10; // 1/10 or 10% chance of trash appearing
  for (int i = 0; i < m_YardSize_Y; i++)
  {
    for (int j = 0; j < m_YardSize_X; j++)
    {
      m_Yard[i][j] = ' ';
      if (rand()%(TRASH_MAX_CHANCE) == 0)
        m_Yard[i][j] = 'T';
      if (j < m_SchoolSize_X && i < m_SchoolSize_Y)
        m_Yard[i][j] = 'S';
      if (j == m_SchoolSize_X-1 && i == m_SchoolSize_Y-1)
        m_Yard[i][j] = 'D';
    }
  }
  cout << *this;
  return;
}

short Schoolyard::GetYardSize_X()
{
  return m_YardSize_X;
}
short Schoolyard::GetYardSize_Y()
{
  return m_YardSize_Y;
}

short Schoolyard::GetSchoolSize_X()
{
  return m_SchoolSize_X;
}
short Schoolyard::GetSchoolSize_Y()
{
  return m_SchoolSize_Y;
}