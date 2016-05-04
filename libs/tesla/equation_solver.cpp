//
// Created by Francisco Aguilera on 5/4/16.
//

#include "equation_solver.h"

using namespace tesla;
using namespace std;

equation_solver::equation_solver() : _equations() {}

void equation_solver::add_equation(const std::string & equation) {
	auto citr = equation.begin();
	string lhs = parse_lhs(equation, citr);
	vector<string> rhs = parse_rhs(equation, citr);
}

std::string equation_solver::parse_lhs(const std::string & equation, std::string::const_iterator & citr) {
	char c;
	std::string lhs;
	for(c = *citr; !is_separator(c); c = *(++citr)) {
		if(!is_delimiter(c)) {
			lhs += c;
		}
	}
	++citr;
	return lhs;
}

vector<string> tesla::equation_solver::parse_rhs(const std::string & equation, string::const_iterator & citr) {
	vector<string> tokens;
	string token;
	char c;
	for(c = *citr; citr != equation.end(); c = *(++citr)) {
		if(is_delimiter(c)) {
			tokens.push_back(token);
			token.clear();
		} else {
			token += c;
		}
	}
	return tokens;
}

bool equation_solver::is_delimiter(const char & c) const {
	return c == ' ' || c == '\t';
}

bool equation_solver::is_separator(const char & c) const {
	return c == '=';
}

bool equation_solver::is_operator(const char &c) const {
	return c == '+';
}

