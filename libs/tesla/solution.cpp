//
// Created by Francisco Aguilera on 5/3/16.
//

#include "solution.h"

void tesla::solution::add_equation(const tesla::equation &eq) {
	_equations.insert({ eq.get_name().str(), eq});
}

tesla::solution::solution() {

}

std::vector<tesla::equation> tesla::solution::get_solved() {
	return std::vector<tesla::equation>();
}