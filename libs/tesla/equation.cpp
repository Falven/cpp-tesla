//
// Created by Francisco Aguilera on 5/3/16.
//

#include "equation.h"

using namespace std;
using namespace tesla;

equation::equation(const string & str)
		: _equation(str),
		  _variables(),
		  _constants(),
		  _lhs(),
		  _rhs()
{
	parse_rhs(parse_lhs());
}

variable_name equation::get_variable_name() const {
	return _lhs;
}

vector<string> equation::get_rhs() const {
	return _rhs;
}

bool equation::is_delimiter(const char & c) const {
	return c == ' ' || c == '\t';
}

bool equation::is_separator(const char & c) const {
	return c == '=';
}

bool equation::is_operator(const char &c) const {
	return c == '+';
}

string::const_iterator equation::parse_lhs() {
	char c;
	string::const_iterator itr;
	for(itr = _equation.cbegin(), c = *itr; !is_separator(c); c = *(++itr)) {
		if(!is_delimiter(c)) {
			_lhs += c;
		}
	}
	return ++itr;
}

void equation::parse_rhs(std::string::const_iterator itr) {
	string token;
	char c;
	for(c = *itr; itr != _equation.cend(); c = *(++itr)) {
		if(is_delimiter(c)) {
			store_token(token);
			token.clear();
		} else {
			token += c;
		}
	}
	store_token(token);
}

string equation::str() const {
	return _equation;
}

std::vector<variable_name> equation::get_variables() const {
	return _variables;
}

std::vector<unsigned int> equation::get_constants() const {
	return _constants;
}

void equation::store_token(const std::string & token) {
	if(!token.empty()) {
		_rhs.push_back(token);
		if (isalpha(token[0])) {
			_variables.push_back(token);
		} else {
			if (isdigit(token[0])) {
				_constants.push_back(static_cast<unsigned int>(stoul(token)));
			}
		}
	}
}

bool equation::remove_variable(const variable_name & varname) {
	auto itr = std::find(_variables.begin(), _variables.end(), varname);
	if(itr != _variables.end()) {
		_variables.erase(itr);
		return true;
	}
	return false;
}

void equation::add_constant(const unsigned int & constant) {
	_constants.push_back(constant);
}

bool equation::operator!=(const equation &other) {
	return _equation != other._equation;
}

bool equation::operator==(const equation &other) {
	return _equation == other._equation;;
}
