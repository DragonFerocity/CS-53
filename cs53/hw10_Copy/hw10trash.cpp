//Name: Brendan Wright & Ryan Andrews
//Date: 28 April 2014
//Class: CS53 Section B
//////////////////////////////////////

#include "hw10trash.h"
using namespace std;


Trash::Trash()
{
  int numItems = 0;
  int randTrash;
  ifstream fin;
  
  fin.open("trash.dat");
  
  fin >> numItems;
  
  randTrash = rand()%numItems + OFFSET;
  for(int i = 0; i < randTrash; i++)
  {
    fin >> m_trashValue;
    fin.getline(m_name,100);
  }
}