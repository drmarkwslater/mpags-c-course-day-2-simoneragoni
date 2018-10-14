#ifndef MPAGSCIPHER_TRANSFORMCHAR_HPP
#define MPAGSCIPHER_TRANSFORMCHAR_HPP

// Standard Library includes
#include <iostream>
#include <string>
#include <vector>

// For std::isalpha and std::isupper
#include <cctype>

// Add a typedef that assigns another name for the given type for clarity
typedef std::vector<std::string>::size_type size_type;

std::string transformChar( const char in_char );

#endif
