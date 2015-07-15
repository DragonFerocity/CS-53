//Name: Brendan Wright & Ryan Andrews
//Date: 28 April 2014
//Class: CS53 Section B
//////////////////////////////////////


#ifndef HW10CHEST_H
#define HW10CHEST_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "hw10schoolyard.h"
using namespace std;


struct Chest
{
  Chest(bool isWeapon);
  void SpawnChests(Schoolyard& school);
  bool m_weapon;
  char m_name[100];
  int m_itemValue;
};  
  

#endif
