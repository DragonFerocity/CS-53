//Ryan Andrews		Date: April 12, 2014
//Class: CS 53		Section: B
 
#include "H8Functions.h"
using namespace std;

int main()
{
	srand(time('\0'));
	const string NOUN1F = "Noun1.dat", NOUN2F = "Noun2.dat";
	const string NOUN3F = "Noun3.dat", VERBF = "Verb.dat";
	const string RALPHISMSF = "Ralphisms.dat";
	const string RESPONSEF = "Response.dat";
	const int OPT1_CHANCE = 2, OPT2_CHANCE = 3;
	//int NOUN1_NUM = 0, NOUN2_NUM = 0, NOUN3_NUM = 0, VERB_NUM = 0;
	//int RALPHISMS_NUM = 0;
	char Continue = 'n';
	char UserQuestion[300] = {'\0'};
	char Response[300] = {'\0'};
	ifstream fin;
	ofstream fout;
	
	Greeting();
	do
	{
		GetUserQuestion(UserQuestion);
		if (rand()%(OPT1_CHANCE+OPT2_CHANCE) < OPT1_CHANCE)
			OutputOpt1Response(Response, NOUN1F, NOUN2F, NOUN3F, VERBF, RESPONSEF);
		else
			OutputOpt2Response(Response, RALPHISMSF);
	
		cout << Response << endl;
		
		cout << "\nWould you like to ask another question? (y/n): ";
		cin >> Continue;
		cout << endl;
		Response[0] = '\0';
	}while(Continue != 'n');

	return 0;
}