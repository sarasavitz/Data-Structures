#include "Tokenizer.h"																	//Sara Savitz
#include <string>																		//U37713110
using namespace std;																	//COP4530.001F16

void tokenizer(const string input, const string delimitier, list<string> &tokenList)
{
	string modInput, token;
	int pos; 

	//Copy const string into modifiable variable
	modInput = input;

	//Find first appearance of delimiter
	pos = modInput.find(delimitier);
	
	//Check if delimiter appears at beginning of input
	if(pos == 0)
	{
		modInput = modInput.substr(pos + delimitier.length());
		pos =modInput.find(delimitier); 
	}

	while (pos != std::string::npos && modInput.length() > 0)
	{
		//Checks if delimiter appears at beginning of input
		if (pos == 0)
		{
			//Stores a blank space in the list 
			token = modInput.substr(0, pos);
			
			//Chops off delimiter and stores remaining input
			modInput = modInput.substr(delimitier.length());

			//Adds token to the list
			tokenList.push_back(token);
		}
		else
		{
			//Chops off token from input and stores it
			token = modInput.substr(0, pos);

			//Chops off delimiter and stores remaining input 
			modInput = modInput.substr(pos + delimitier.length());

			//Adds token to the list
			tokenList.push_back(token);
		}

		//Finds next appearance of delimiter
		pos = modInput.find(delimitier);

	}

	//Any leftover input will be stored in the last token
	if (modInput.length() > 0)
	{
		token = modInput;
		tokenList.push_back(token);
	}
	
	
}
