//
// Created by Francisco Aguilera on 5/3/16.
//

#include "solution.h"

using namespace std;
using namespace tesla;

solution::solution()
		: _total(0), _equations(), _solutions() {
}

void solution::add_equation(const equation & eq) {
	auto equation_variables = eq.get_variables();
	if(equation_variables.empty()) {
		add_solution(eq);
	} else {
		_equations.insert({ eq.get_variable_name(), eq });
	}
}

void solution::resolve_equations() {
	for (auto itr = _equations.begin(); itr != _equations.end(); ++itr) {
		resolve_equation(itr->second);
	}
}

std::map<variable, unsigned int, variable_name_comparator> solution::get_solved() const {
	return _solutions;
}

void solution::add_equation(const std::string & eq) {
	add_equation(equation(eq));
}

bool solution::resolve_equation(equation & eq) {
	if(resolve_from_solutions(eq)) {
		add_solution(eq);
		return true;
	} else {
		return resolve_from_dependencies(eq);
	}
}

bool solution::resolve_from_solutions(equation & eq) {
	// Check solutions.
	for (auto sol_itr = _solutions.begin(); sol_itr != _solutions.end(); ++sol_itr) {
		if(eq.remove_variable(sol_itr->first)) {
			eq.add_constant(sol_itr->second);
		}
	}
	return eq.get_variables().empty();
}

void solution::add_solution(const equation & eq) {
	auto equation_constants = eq.get_constants();
	unsigned int total = 0u;
	for (auto & variable : equation_constants) {
		total += variable;
	}
	_solutions.insert( {eq.get_variable_name(), total } );
}

bool solution::resolve_from_dependencies(equation & eq) {
	// Check equations for dependencies.
	for (auto eq_itr = _equations.begin(); eq_itr != _equations.end(); ++eq_itr) {
		auto dependency = eq_itr->second;
		if(eq != dependency) {
			auto dependency_vars = dependency.get_variables();
			auto dependency_match = std::find(dependency_vars.begin(), dependency_vars.end(), eq_itr->first);
			if (dependency_match != dependency_vars.end()) {
				resolve_equation(dependency);
				return true;
			}
		}
	}
	return false;
}

bool variable_name_comparator::operator()(const tesla::variable &a, const tesla::variable &b) const {
	return a.str() < b.str();
}