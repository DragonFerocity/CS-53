//Name: Brendan Wright & Ryan Andrews
//Date: 28 April 2014
//Class: CS53 Section B
//////////////////////////////////////
#include "hw10classmate.h"
//#include "hw10schoolyard.h"

Classmate::Classmate(Schoolyard& school, const string name)
                    : m_name(name), m_numItems(0)
{
  m_iq = rand()%IQRANGE + MINIQ;
  go_to_school(school);
}

void Classmate::go_to_school(Schoolyard& school)
{
  int rand_placeX = rand()%(school.getYard_size() - school.getBuild_size())
                    + school.getBuild_size();
  int rand_placeY = rand()%(school.getYard_size() - school.getBuild_size())
                    + school.getBuild_size();
  
  m_x_coord = rand_placeX;
  m_y_coord = rand_placeY;
  school.setPlot(m_x_coord,m_y_coord,'C');
  return;
}

bool Classmate::setIq(const int iq)
{
  bool iqNum = false;
  if(iq >= MINIQ && iq <= MAXIQ)
  {
    m_iq = iq;
    iqNum = true;
  }
  return iqNum;
}

int Classmate::getIq()
{
  return m_iq;
}
////////////////////////////////////////////////////////////////////
void Classmate::move(Schoolyard& school)
{ 
  int Dir, mvX = 0, mvY = 0;
  do
  {
    Dir = rand()%(CHANCE*CHANCE);
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
  }while(school.getPlot(m_x_coord+mvX, m_y_coord+mvY) != 'S'
      && school.getPlot(m_x_coord+mvX, m_y_coord+mvY) != 'D'
      && m_x_coord+mvX < school.getYard_size()
      && m_y_coord+mvY < school.getYard_size()
      && m_x_coord+mvX > 0
      && m_y_coord+mvY > 0);
  
  return;
}
//////////////////////////////////////////////////////////////////////////
ostream& operator<<(ostream& os, const Classmate& classmate)
{
  os << classmate.m_name << " has iq " << classmate.m_iq << " and is at ("
    << classmate.m_x_coord << "," << classmate.m_y_coord << ")." << endl;
  return os;
}