//
// Created by Francisco Aguilera on 5/3/16.
//

#include <string>
#include <stdexcept>

#include "variable_name.h"

using namespace std;
using namespace tesla;

variable_name::variable_name() : _name() {}

variable_name::variable_name(const string & name) : _name(validate_name(name)) {}

string variable_name::validate_name(const string & str) {
	string::const_iterator itr, end;
	for(itr = str.cbegin(), end = str.cend(); itr != end; ++itr) {
		if(!isalpha(*itr)) {
			throw std::invalid_argument(" A variable name can only be composed"
					                            "of letters from the alphabet.");
		}
	}
	return str;
}

std::string variable_name::str() const {
	return _name;
}

bool variable_name::operator==(const string & str) {
	return _name == str;
}

bool variable_name::operator!=(const std::string & str) {
	return _name != str;
}

variable_name & variable_name::operator+=(const char & c) {
	_name += c;
	return *this; // return the result by reference
}

bool variable_name::operator==(const variable_name & varname) {
	return _name == varname.str();
}

bool variable_name::operator!=(const variable_name & varname) {
	return _name != varname.str();
}



