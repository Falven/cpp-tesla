//
// Created by Francisco Aguilera on 5/3/16.
//

#include <string>
#include <stdexcept>

#include "variable.h"

using namespace std;
using namespace tesla;

variable::variable() : _name() {}

variable::variable(const string & name) : _name(validate_name(name)) {}

string variable::validate_name(const string & str) {
	string::const_iterator itr, end;
	for(auto & c : str) {
		if(!isalpha(c)) {
			throw std::invalid_argument(" A variable name can only be composed"
					                            "of letters from the alphabet.");
		}
	}
	return str;
}

std::string variable::get_name() const {
	return _name;
}

bool variable::operator==(const variable & varname) {
	return _name == varname._name;
}

bool variable::operator!=(const variable & varname) {
	return _name != varname._name;
}



