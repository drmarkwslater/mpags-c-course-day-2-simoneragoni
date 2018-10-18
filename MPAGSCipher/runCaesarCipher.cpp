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
				const size_t key, 
				const bool encrypt  )
{

std::vector<char> alphabet = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

  std::string outputText = inputText;
  char processedChar{'x'};

for (std::string::size_type i = 0; i < inputText.length(); i++)
{
	// Iterate over all elements in Vector
  int j;
  for (j = 0; j < 25; j++)
	{
		
		if (inputText[i] == alphabet.at(j)) break;
	}

	if ( encrypt ) {
	  processedChar = alphabet[ (j + key) % alphabet.size() ];
	} else {
	  processedChar = alphabet[ (j + alphabet.size() - key) % alphabet.size() ];
	}
	outputText += processedChar;
}

return outputText;

}
