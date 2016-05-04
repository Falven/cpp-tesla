//
// Created by Francisco Aguilera on 5/3/16.
//

#include "equation.h"

using namespace std;
using namespace tesla;

equation::equation(const string & str)
		: _equation(str), _lhs(parse_lhs(_equation)), _rhs(parse_rhs(_equation)) { }

variable_name equation::get_lhs() const {
	return _lhs;
}

vector<string> equation::get_rhs() const {
	return _rhs;
}

bool equation::is_delimiter(const char & c) {
	return c == ' ' || c == '\t';
}

bool equation::is_separator(const char & c) {
	return c == '=';
}

string equation::parse_lhs(const std::string & input) {
	string lhs;
	char c;
	for(_itr = input.cbegin(), c = *_itr, _end = input.cend(); !is_separator(c); c = *(++_itr)) {
		if(!is_delimiter(c)) {
			lhs += c;
		}
	}
	return lhs;
}

vector<string> equation::parse_rhs(const std::string & input) {
	vector<string> rhs;
	string token;
	char c;
	for(c = *_itr; _itr != _end; c = *(++_itr)) {
		if(is_delimiter(c)) {
			if(!token.empty()) {
				rhs.push_back(token);
				token.clear();
			}
		} else {
			token += c;
		}
	}
	return rhs;
}

string equation::str() const {
	return _equation;
}