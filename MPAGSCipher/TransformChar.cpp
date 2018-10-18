// Standard Library includes
#include <iostream>
#include <string>
#include <vector>
#include "TransformChar.hpp"

// For std::isalpha and std::isupper
#include <cctype>

// Add a typedef that assigns another name for the given type for clarity
typedef std::vector<std::string>::size_type size_type;


//translating function: gives inputs to "inputText"
std::string transformChar( const char in_char ){
    // Transliterate digits to English words

  std::string out_text{""};

  // Uppercase alphabetic characters
  if (std::isalpha(in_char)) {
    out_text += std::toupper(in_char);
    return out_text;
  }

    switch (in_char) {
      case '0':
	return "ZERO";
	//break;
      case '1':
	return "ONE";
	//break;
      case '2':
	return "TWO";
	//break;
      case '3':
	return "THREE";
	//break;
      case '4':
	return "FOUR";
	//break;
      case '5':
	return "FIVE";
	//break;
      case '6':
	return "SIX";
	//break;
      case '7':
	return "SEVEN";
	//break;
      case '8':
	return "EIGHT";
	//break;
      case '9':
	return "NINE";
	break;
			}
return "";
}


