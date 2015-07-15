//Name: Brendan Wright & Ryan Andrews
//Date: 28 April 2014
//Class: CS53 Section B
//////////////////////////////////////

#include "hw10chest.h"
using namespace std;

const int OFFSET = 1;

Chest::Chest(bool isWeapon)
{
  int numItems = 0;
  int randCItem;
  m_weapon = isWeapon;
  ifstream fin;
  
  if(isWeapon)
    fin.open("weapons.dat");
  else
    fin.open("defenders.dat");
    
    fin >> numItems;
    
  randCItem = rand()%numItems + OFFSET;
  for(int i = 0; i < randCItem; i++)
  {
    fin >> m_itemValue;
    fin.getline(m_name,100);
  }
  
  fin.close();
}

void Chest::SpawnChests(Schoolyard& school)
{
  for (int i = 0; i < school.getYard_size(); i++)
  {
    for (int j = 0; j < school.getYard_size(); j++)
    {
      if (school.getPlot(i,j) == 'T')
      {
        school.setPlot(i,j,'O');
        cout << school.getPlot(i,j);
      }
    }
  }
  
  return;
}