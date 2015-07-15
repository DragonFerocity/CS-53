//Ryan Andrews		Date: April 12, 2014
//Class: CS 53		Section: B

#ifndef H8FUNCTIONS_8
#define H8FUNCTIONS_8
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;

//Greets the user
//Pre: None
//Post: Outputs a greeting to the screen
void Greeting();
//Counts the number of words/entries in a file
//Pre: FileName must be the name of a .dat file
//Post: Returns the number of entries in the file
int CountFileEntries(const string FileName);
//Counts the number of entries in a file. 1 entry is everything before Delimiter
//Pre: FileName must be the name of a .dat file
//Post: Returns the number of entries in the file
int CountFileEntries(const string FileName, const char Delimiter);
//Prompts the user to ask a question
//Pre: None
//Post: Stores the question in an array
void GetUserQuestion(char UserQuestion[]);
//Generates a response to the asked question using 4 different files
//Pre: N1F, N2F, N3F, and VF, must be the names of data files
//Post: Generates a response to a question
void OutputOpt1Response(char Response[], const string N1F, const string N2F, 
		const string N3F, const string VF, const string ResponseFile);
//Finds the longest word in the asked question
//Pre: Filename must be a data file
//Post: Returns the word-position of the longest word
int FindLongestResponseWord(const string Filename);
//
//
//
void OutputOpt2Response(char Response[], const string RalphismsF);

#endif