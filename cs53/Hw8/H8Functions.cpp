//Ryan Andrews		Date: April 12, 2014
//Class: CS 53		Section: B

#include "H8Functions.h"
using namespace std;

void Greeting()
{
	cout << endl << "Hello Ralphie!" << endl << endl;
	
	return;
}

int CountFileEntries(const string FileName)
{
	char Response[100] = {'\0'};
	int Count = 0;
	ifstream fin;
	
	fin.open(FileName.c_str());
	
	while (fin >> Response)
		Count++;
	
	fin.close();
	
	return Count;
}

int CountFileEntries(const string FileName, const char Delimiter)
{
	char Response[100] = {'\0'};
	int Count = 0;
	ifstream fin;
	
	fin.open(FileName.c_str());
	
	while (fin.getline(Response,100,Delimiter))
		Count++;
	
	fin.close();
	
	return Count;
}

void GetUserQuestion(char UserQuestion[])
{
	ofstream fout;
	const string RESPONSEF = "Response.dat";
	
	cout << "What would you like to ask ralphy? \nQ:  ";
	cin.ignore();
	cin.getline(UserQuestion,300,'\n');
	
	fout.open(RESPONSEF.c_str());
	fout << UserQuestion;
	
	return;
}

int FindLongestResponseWord(const string Filename)
{
	ifstream fin;
	const int NumWords = CountFileEntries(Filename);
	int Pos = 0, j = 0, Longest = 0;
	char Word[100] = {'\0'};
	
	fin.open(Filename.c_str());
	
	for (int i = 0; i < NumWords; i++)
	{
		fin >> Word;
		while (Word[j] != '\0')
			j++;
		if (j > Longest)
		{
			Pos = i;
			Longest = j;
		}
		j = 0;
		Word[0] = '\0';
	}
	
	fin.close();
	
	return Pos;
}
	

void OutputOpt1Response(char Response[], const string N1F, const string N2F, 
		const string N3F, const string VF, const string ResponseFile)
{
	const int NOUN1_NUM = CountFileEntries(N1F);
	const int NOUN2_NUM = CountFileEntries(N2F);
	const int NOUN3_NUM = CountFileEntries(N3F, '\n');
	const int VERB_NUM = CountFileEntries(VF);
	
	const int Noun1 = rand()%NOUN1_NUM;
	const int Noun2 = rand()%NOUN2_NUM;
	const int Noun3 = rand()%NOUN3_NUM;
	const int Verb = rand()%VERB_NUM;
	
	const int LONGEST_WORD = 4, REGULAR = 1;
	//LONGEST_WORD is the chance that Ralphy will use the longest word in the
	//question asked in his answer.
	//REGULAR is the chance that Ralphy won't use the longest word from the
	//question asked in his answer.
	const int LONG_WORD_N2 = 2, LONG_WORD_N3 = 3;
	//LONG_WORD_N2 is the chance that Ralphy will use the longest word as Noun 2
	//LONG_WORD_N3 is the chance that Ralphy will use the longest word as Noun 3
	bool UseLongest = false;
	//Use longest is if Ralphy will use the longest word.
	int NounUsed = 2;
	//The noun to replace with the longest word
	const int LongestWordPos = FindLongestResponseWord(ResponseFile);
	
	if (rand()%(LONGEST_WORD + REGULAR) < LONGEST_WORD)
		UseLongest = true;
	if (rand()%(LONG_WORD_N2 + LONG_WORD_N3) < LONG_WORD_N2)
		NounUsed = 2;
	else
		NounUsed = 3;
	
	ifstream fin;
	char Word[100] = {"\0"};
	
	strcat(Response,"My ");
	
	fin.open(N1F.c_str());
	fin >> Word;
	for (int i = 0; i < Noun1; i++)
		fin >> Word;
	fin.close();
	strcat(Response, Word);
	strcat(Response, "'s ");
	
	if (!UseLongest || NounUsed != 2)
	{
		fin.open(N2F.c_str());
		fin >> Word;
		for (int i = 0; i < Noun2; i++)
			fin >> Word;
		fin.close();
		strcat(Response, Word);
		strcat(Response, " ");
	}
	else if (UseLongest && NounUsed == 2)
	{
		fin.open(ResponseFile.c_str());
		fin >> Word;
		for (int i = 0; i < LongestWordPos; i++)
			fin >> Word;
		fin.close();
		strcat(Response, Word);
		strcat(Response, " ");
	}
	
	fin.open(VF.c_str());
	fin >> Word;
	for (int i = 0; i < Verb; i++)
		fin >> Word;
	fin.close();
	strcat(Response, Word);
	strcat(Response, " like ");
	
	if (!UseLongest || NounUsed != 3)
	{
		fin.open(N3F.c_str());
		fin.getline(Word,300,'\n');
		for (int i = 0; i < Noun3; i++)
			fin.getline(Word,300,'\n');
		fin.close();
		strcat(Response, Word);
		strcat(Response, ".");
	}
	else if (UseLongest && NounUsed == 3)
	{
		fin.open(ResponseFile.c_str());
		fin >> Word;
		for (int i = 0; i < LongestWordPos; i++)
			fin >> Word;
		fin.close();
		strcat(Response, Word);
		strcat(Response, ". ");
	}
	return;
}

void OutputOpt2Response(char Response[], const string RalphismsF)
{
	const int RALPHISMS_NUM = CountFileEntries(RalphismsF, '\n');
	const int PHRASE_POS = rand()%RALPHISMS_NUM;
	
	ifstream fin;
	
	fin.open(RalphismsF.c_str());
	fin.getline(Response,300,'\n');
	
	for (int i = 0; i < PHRASE_POS; i++)
		fin.getline(Response,300,'\n');
	
	fin.close();
	
	return;
}