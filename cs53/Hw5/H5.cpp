//Ryan Andrews		Date: February 26, 2014
//Class: CS 53		Section: B

#include <iostream>
using namespace std;

//Displays a greeting to the user
//Pre: None
//Post: None
void Greeting();
//Displays a goodbye message to the user
//Pre: None
//Post: None
void Goodbye();
//Asks the user for two fruit names and their weights
//Pre: None
//Post: None
void GetFruits(string& Fruit1, float& Weight1, string& Fruit2, float& Weight2);
//Finds the fruit that weighs more, and outputs the name of that fruit
//Pre: None
//Post: None
void RaceWinner(string Fruit1, float Weight1, string Fruit2, float Weight2);

int main()
{
  string Fruit1 = "", Fruit2 = "";
  float Weight1 = 0, Weight2 = 0, WeightWinner = 0;
  
  Greeting();
  GetFruits(Fruit1, Weight1, Fruit2, Weight2);
  
  RaceWinner(Fruit1, Weight1, Fruit2, Weight2);
 
  return 0;
}

void Greeting()
{
  cout << "Hello Ralphy! Are you ready to GO BANANAS?\n" << endl;
  
  return;
}

void GetFruits(string& Fruit1, float& Weight1, string& Fruit2, float& Weight2)
{
  const int FruitMaxWeight = 2000;
  
  cout << "What are the names and weights of the fruits" 
       << "you would like to test today?" << endl;
  cout << "Fruit #1:  ";
  cin >> Fruit1;
  
  do
  {
    cout << "Weight:    ";
    cin >> Weight1;
    
    if (Weight1 > FruitMaxWeight)
      cout << "Please enter a valid weight, less than 2,000 lbs." << endl;
  }while (Weight1 > FruitMaxWeight);
  
  cout << "\nFruit #2  ";
  cin >> Fruit2;
  
  do
  {
    cout << "Weight:   ";
    cin >> Weight2;
    
    if (Weight2 > FruitMaxWeight)
      cout << "Please enter a valid weight, less than 2,000 lbs." << endl;
  }while (Weight2 > FruitMaxWeight);
  
  return;
}

void RaceWinner(string Fruit1, float Weight1, string Fruit2, float Weight2)
{
  string FruitWinner;
  
  if (Weight1 > Weight2)
    FruitWinner = Fruit1;
  else if (Weight1 < Weight2)
    FruitWinner = Fruit2;
  else
    FruitWinner = Fruit1;

  cout << endl << "\nGO " << FruitWinner << "!!!" << endl << endl;
  
  return;
}
