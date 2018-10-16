// Standard Library includes
#include <iostream>
#include <string>
#include <vector>
//#include "runCaesarCipher.hpp"

// For std::isalpha and std::isupper
//#include <cctype>

using namespace std;
// Add a typedef that assigns another name for the given type for clarity
typedef std::vector<std::string>::size_type size_type;


//translating function: gives inputs to "inputText"
std::string runCaesarCipher(	const std::string& inputText,
				const size_t key)//, 
				//const bool encrypt  )
{

int help;
const size_t dekey = key;
std::cout << "Would you like to encrypt or decrypt?" << std::endl;
std::cout << "Press  0(1)  for encrypt(decrypt)" << std::endl;
std::cin >> help;
std::string outputText = inputText;
if(help == 0) 
{
std::cout << help << std::endl;
std::vector<char> alphabet = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
for (std::string::size_type i = 0; i < outputText.length(); i++)
{
	const char helppppp = outputText[i];
/*	std::vector<char>::iterator it = std::find(alphabet.begin(), alphabet.end(), helppppp);
	if (it != alphabet.end()) std::cout << "Element Found" << std::endl;
	else std::cout << "Element Not Found" << std::endl;	
	// Get index of element from iterator
	int index = std::distance(alphabet.begin(), it);*/

	int index = 0;
	int indice = 0;
/*	// Iterate over all elements in Vector
	for (auto & elem : alphabet)
	{
		
		if (elem == helppppp) break;
		indice++;
	}*/
	// Iterate over all elements in Vector
	for (int j = 0; j < 25; j++)
	{
		
		if (helppppp == alphabet.at(j)) break;
		indice++;
	}


	index = indice;
	if(index + dekey < 25)	outputText[i] = alphabet.at(index + dekey);
	else outputText[i] = alphabet.at(index + dekey - 25);
}

}
else if(help == 1)
{
std::vector<char> alphabet = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
for (std::string::size_type i = 0; i < outputText.length(); i++)
{
	const char helppppp = outputText[i];
	int index = 0;
	int indice = 0;
	// Iterate over all elements in Vector
	for (int j = 0; j < 25; j++)
	{
		
		if (helppppp == alphabet.at(j)) break;
		indice++;
	}


	index = indice;
	if(index - dekey < 0)	outputText[i] = alphabet.at(index - dekey + 25);
	else outputText[i] = alphabet.at(index - dekey);
}
}
else{std::cout << "error: you chose neither encrypt or decrypt" << std::endl; return "SPACE";}


return outputText;
/* BLOCK for CAESAR CIPHER
std::vector<char> alphabet = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
std::string outputText = inputText;
for (string::size_type i = 0; i < outputText.length(); i++)
{
	std::vector<int>::iterator it = std::find(alphabet.begin(), alphabet.end(), outputText[i]);
	if (it != alphabet.end()) std::cout << "Element Found" << std::endl;
	else std::cout << "Element Not Found" << std::endl;	
	// Get index of element from iterator
	int index = std::distance(alphabet.begin(), it);
	if(index + dekey < 25)	outputText[i] = alphabet.at(index + dekey);
	else outputText[i] = alphabet.at(index + dekey - 25);
}
*/

}
