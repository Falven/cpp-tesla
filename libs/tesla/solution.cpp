//
// Created by Francisco Aguilera on 5/3/16.
//

#include "solution.h"

using namespace std;
using namespace tesla;

solution::solution()
		: _total(0), _equations() {
}

void solution::add_equation(const equation & eq) {
	_equations.insert( { eq.get_lhs(), eq } );
}

void solution::resolve_equations() {
	for (auto & kv : _equations) {
		auto equation_name = kv.first;
		auto equation = kv.second;
		auto equation_variables = equation.get_variables();
		auto equation_constants = equation.get_constants();
		std::vector<variable_name>::iterator var_itr;
		std::map<variable_name, unsigned int>::iterator sol_itr;
		for (var_itr = equation_variables.begin();
		     var_itr != equation_variables.end();) {
			if((sol_itr = _solutions.find(*var_itr)) >= _solutions.end()) {
				break;
			}
			equation_variables.erase(var_itr);
			equation_constants.push_back(sol_itr->second);
		}
		if(equation_variables.empty()) {
			unsigned int total;
			for (auto & variable : equation_constants) {
				total += variable;
			}
			_solutions.insert( { equation_name, total } );
		}
	}
}

std::map<variable_name, unsigned int> solution::get_solved() const {
	return _solutions;
}

