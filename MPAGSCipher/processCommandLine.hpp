#ifndef MPAGSCIPHER_PROCESSCOMMANDLINE_HPP
#define MPAGSCIPHER_PROCESSCOMMANDLINE_HPP

// Standard Library includes
#include <iostream>
#include <string>
#include <vector>

// For std::isalpha and std::isupper
#include <cctype>

// Add a typedef that assigns another name for the given type for clarity
typedef std::vector<std::string>::size_type size_type;

bool processCommandLine(const std::vector<std::string>& args,
			bool& helpRequested,
			bool& versionRequested,
			std::string& inputFileName,
			std::string& outputFileName);
#endif
