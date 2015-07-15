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
  m_GotGrade = false;
  m_Attack = false;
  for (int i = 0; i < MAXTRASH; i++)
  {
    strcpy(m_trash[i].m_name, "");
    m_trash[i].m_trashValue = 0;
  }
  m_numItems = 0;
  go_to_school(school);
}
///////////////////////////////////////////////////////////////////////////////
void Classmate::go_to_school(Schoolyard& school)
{
  do
  {
    m_x_coord = rand()%(school.getYard_size()-school.getBuild_size())
        +school.getBuild_size();
    m_y_coord = rand()%(school.getYard_size()-school.getBuild_size())
        +school.getBuild_size();
  }while(m_x_coord < school.getBuild_size() 
      && m_y_coord < school.getBuild_size());
  
  school.setPlot(m_y_coord,m_x_coord,'C');
  return;
}
///////////////////////////////////////////////////////////////////////////////
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
///////////////////////////////////////////////////////////////////////////////
void Classmate::move(Schoolyard& school)
{ 
  int Dir, mvX = 0, mvY = 0, Pos = 0;
  int LeastValue, ClosestTrash = 60, MvDir = 0;
  int numTrash = school.getNumTrash();
  
  for (int i = 0; i < school.getYard_size(); i++)
  {
    if ((school.getPlot(m_y_coord,i) == 'T' 
        || school.getPlot(m_y_coord,i) == 'O') 
        && abs(i-m_x_coord) < ClosestTrash)
    {
      ClosestTrash = abs(i-m_x_coord);
      if (i < m_x_coord) //Left
        MvDir = -1;
      if (i > m_x_coord)//Right
        MvDir = 1;
    }
    if ((school.getPlot(m_y_coord,i) == 'T' 
        || school.getPlot(m_y_coord,i) == 'O')
        && abs(i-m_y_coord) < ClosestTrash)
    {
      ClosestTrash = abs(i-m_y_coord);
      if (i < m_y_coord)//Up
        MvDir = -2;
      if (i > m_y_coord)//Down
        MvDir = 2;
    } 
  }
  
  school.setPlot(m_y_coord,m_x_coord,' ');
  
  if (ClosestTrash == 60)
  {
  do
  {
    mvX = 0;
    mvY = 0;
    Dir = rand()%(CHANCE*CHANCE);
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
  }while(Dir == m_LastMove || (m_x_coord+mvX < school.getBuild_size()
      && m_y_coord < school.getBuild_size())
      || m_x_coord+mvX > school.getYard_size()-1
      || (m_y_coord+mvY < school.getBuild_size()
      && m_x_coord < school.getBuild_size())
      || m_y_coord+mvY > school.getYard_size()-1
      || m_y_coord+mvY < 0 || m_x_coord+mvX < 0
      || school.getPlot(m_y_coord+mvY, m_x_coord+mvX) == 'C'
      || school.getPlot(m_y_coord+mvY, m_x_coord+mvX) == 'O');
  
  m_x_coord += mvX;
  m_y_coord += mvY;
  m_LastMove = abs(Dir - 2);  //Prevents classmate from moving in previous 
  }                           //direction
  else
  {
    switch (MvDir)
    {
      case -2:
        if (school.getPlot(m_y_coord-1,m_x_coord) != 'C')
          m_y_coord--;
        break;
      case -1:
        if (school.getPlot(m_y_coord,m_x_coord-1) != 'C')
          m_x_coord--;
        break;
      case 1:
        if (school.getPlot(m_y_coord,m_x_coord+1) != 'C')
          m_x_coord++;
        break;
      case 2:
        if (school.getPlot(m_y_coord+1,m_x_coord) != 'C')
          m_y_coord++;
        break;
      default:
        break;
    }
  }
  if (school.getPlot(m_y_coord,m_x_coord) == 'T')
  {
    Trash newTrash;
    //Create the trash object ONLY if the character finds trash on the ground.
    if(newTrash.m_trashValue != 17) //17 for glue, gets eaten
    {
      if (m_numItems == MAXTRASH)
      {
        LeastValue = m_trash[0].m_trashValue;
        for (int i = 0; i < m_numItems; i++)
        {
          if (m_trash[i].m_trashValue < LeastValue)
          {
            LeastValue = m_trash[i].m_trashValue;
            Pos = i;
          }
        }
        if (newTrash.m_trashValue > LeastValue)
        {
          m_trash[Pos].m_trashValue = newTrash.m_trashValue;
          strcpy(m_trash[Pos].m_name,newTrash.m_name);
        }
      }
      else
      {
        m_trash[m_numItems].m_trashValue = newTrash.m_trashValue;
        strcpy(m_trash[m_numItems].m_name,newTrash.m_name);
        m_numItems++;
      }
    }
    else
    {
      m_iq -= 2; //for eating glue...
    }
    numTrash--;
    school.setNumTrash(numTrash);
  }
  if (school.getPlot(m_y_coord,m_x_coord) == 'O')
  {
    Chest Weapon(true);
    cout << "Attention students: Someone has found a " << Weapon.m_name
         << "!!" << endl;
    m_numItems = 0;
    for (int i = 0; i < MAXTRASH; i++)
      strcpy(m_trash[i].m_name, " ");
    m_HasWeapon = true;
    m_Attack = true;
    Weapon.SpawnChests(school);
  }
  
  return;
}
///////////////////////////////////////////////////////////////////////////////
void Classmate::toDoor(Schoolyard& school)
{
  school.setPlot(m_y_coord,m_x_coord,' ');
  
  if(m_x_coord > school.getBuild_size() - 1
      && m_y_coord >= school.getBuild_size() - 1
      && school.getPlot(m_y_coord,m_x_coord-1) != 'C')
    m_x_coord --;
  else if(m_x_coord < school.getBuild_size() - 1
      && school.getPlot(m_y_coord,m_x_coord+1) != 'C')
    m_x_coord ++; 
  else if(m_y_coord > school.getBuild_size() - 1
      && school.getPlot(m_y_coord-1,m_x_coord) != 'C')
    m_y_coord --;
  else if(m_y_coord < school.getBuild_size() - 1
      && school.getPlot(m_y_coord+1,m_x_coord) != 'C')
    m_y_coord ++;
    
  school.setPlot(m_y_coord,m_x_coord,'C');
  return;
}
///////////////////////////////////////////////////////////////////////////////
void Classmate::toHoover(Schoolyard& school)
{
  school.setPlot(m_y_coord,m_x_coord,'S');
  
  if (m_y_coord != school.getBuild_size() - 1 
      || m_x_coord != school.getBuild_size() - 1)
    school.setPlot(school.getBuild_size() - 1,school.getBuild_size() - 1,'D');

  
  if(m_y_coord > school.getHooverY() + 1
      && school.getPlot(m_y_coord-1,m_x_coord) != 'C'
      && school.getPlot(m_y_coord-1,m_x_coord) != 'H')
    m_y_coord --;  
  else if(m_x_coord > school.getHooverX()
      && school.getPlot(m_y_coord,m_x_coord-1) != 'C'
      && school.getPlot(m_y_coord,m_x_coord-1) != 'H')
    m_x_coord --; 
  else
    HooverGrade(school); 
  school.setPlot(m_y_coord,m_x_coord,'C');
  return;
}
///////////////////////////////////////////////////////////////////////////////
void Classmate::HooverGrade(Schoolyard& school)
{
  cout << "Hoover: " << m_name << ", your score is ";
  m_totalVal = 0;
  for(int i = 0; i < m_numItems; i++)
  {
    m_totalVal += m_trash[i].m_trashValue;
  }
  m_totalVal /= m_iq;
  cout << m_totalVal << "." << endl;
  m_GotGrade = true;
  school.setPlot(m_y_coord,m_x_coord,'S');
  m_y_coord = MAX-1;
  m_x_coord = MAX-1;
  return;
}
///////////////////////////////////////////////////////////////////////////////
ostream& operator<<(ostream& os, const Classmate& classmate)
{
  os << classmate.m_name << " has iq " << classmate.m_iq << " and is at ("
    << classmate.m_x_coord << "," << classmate.m_y_coord << ")." << endl;
  return os;
}