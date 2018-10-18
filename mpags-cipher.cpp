// Standard Library includes
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "MPAGSCipher/processCommandLine.hpp"
#include "MPAGSCipher/TransformChar.hpp"
#include "MPAGSCipher/runCaesarCipher.hpp"

// For std::isalpha and std::isupper
#include <cctype>

// Add a typedef that assigns another name for the given type for clarity
typedef std::vector<std::string>::size_type size_type;

// Main function of the mpags-cipher program
int main(int argc, char* argv[])
{
  // Convert the command-line arguments into a more easily usable form
  const std::vector<std::string> cmdLineArgs {argv, argv+argc};

  // Options that might be set by the command-line arguments
  bool helpRequested {false};
  bool versionRequested {false};
  std::string inputFile {""};
  std::string outputFile {""};

  if (!processCommandLine(cmdLineArgs, helpRequested, versionRequested, inputFile, outputFile))
    {
      std::cout << "Problem processing command line." << std::endl;
      return 1;
    }

  // Handle help, if requested
  if (helpRequested) {
    // Line splitting for readability
    std::cout
      << "Usage: mpags-cipher [-i <file>] [-o <file>]\n\n"
      << "Encrypts/Decrypts input alphanumeric text using classical ciphers\n\n"
      << "Available options:\n\n"
      << "  -h|--help        Print this help message and exit\n\n"
      << "  --version        Print version information\n\n"
      << "  -i FILE          Read text to be processed from FILE\n"
      << "                   Stdin will be used if not supplied\n\n"
      << "  -o FILE          Write processed text to FILE\n"
      << "                   Stdout will be used if not supplied\n\n";
    // Help requires no further action, so return from main
    // with 0 used to indicate success
    return 0;
  }

  // Handle version, if requested
  // Like help, requires no further action,
  // so return from main with zero to indicate success
  if (versionRequested) {
    std::cout << "0.1.0" << std::endl;
    return 0;
  }

  // Initialise variables for processing input text
  char inputChar {'x'};
  std::string inputText {""};

  // Read in user input from stdin/file
  // Warn that input file option not yet implemented
  if (!inputFile.empty()) 
  {
    std::ifstream in_file{inputFile};
    if(in_file.good())
		{
		while(in_file >> inputChar)
	  		{
			inputText += transformChar(inputChar);    
	   		}
		}
	else{
		while(std::cin >> inputChar)
		  {
		    inputText += transformChar(inputChar);    
		   }
  		}
   }
  // Loop over each character from user input
  // (until Return then CTRL-D (EOF) pressed)
  else  {
		while(std::cin >> inputChar)
		  {
		inputText += transformChar(inputChar);    
		  }


    // If the character isn't alphabetic or numeric, DONT add it.
    // Our ciphers can only operate on alphabetic characters.
  }


  // should be done as a command line argument
  std::cout << "Please input Caesar's key. Later decide if you want to encrypt or decrypt" << std::endl;
  int key;
  std::cin >> key;
  std::string exitText = runCaesarCipher(inputText, key, true); 



  // Output the transliterated text
  // Warn that output file option not yet implemented
  if (!outputFile.empty()) {
	std::ofstream out_file{outputFile};
	if(out_file.good())	out_file << exitText << std::endl;
	else {std::cout << exitText << std::endl;}
  }
  else {std::cout << exitText << std::endl;}

  // No requirement to return from main, but we do so for clarity
  // and for consistency with other functions
  return 0;
}


