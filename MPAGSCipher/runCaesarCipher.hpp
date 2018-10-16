#ifndef MPAGSCIPHER_RUNCAESARCIPHER_HPP
#define MPAGSCIPHER_RUNCAESARCIPHER_HPP

// Standard Library includes
#include <iostream>
#include <string>
#include <vector>

// For std::isalpha and std::isupper
#include <cctype>

// Add a typedef that assigns another name for the given type for clarity
typedef std::vector<std::string>::size_type size_type;

std::string runCaesarCipher(	const std::string& inputText,
				const size_t key)//, 
				//const bool encrypt  );

#endif
