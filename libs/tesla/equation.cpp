//
// Created by Francisco Aguilera on 5/3/16.
//

#include "equation.h"

using namespace std;
using namespace tesla;

equation::equation(const string &str) : _lhs("") {
}

variable_name equation::get_name() const {
	return _lhs;
}

ostream & operator<< (ostream & out, const equation & eqn)
{
	out << eqn.str();
	return out;
}

std::string equation::str() const {
	return _lhs.str() + " = ";
}




