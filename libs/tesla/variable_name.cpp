//
// Created by Francisco Aguilera on 5/3/16.
//

#include <string>
#include <stdexcept>

#include "variable_name.h"

using namespace std;

tesla::variable_name::variable_name(const string & name)
		: _name(validate_name(name)) {
}

string tesla::variable_name::validate_name(const string & str) {
	string::const_iterator itr, end;
	for(itr = str.cbegin(), end = str.cend(); itr != end; ++itr) {
		if(!isalpha(*itr)) {
			throw std::invalid_argument(" A variable name can only be composed"
					                            "of letters from the alphabet");
		}
	}
	return str;
}

std::string tesla::variable_name::str() const {
	return _name;
}

