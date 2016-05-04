//
// Created by Francisco Aguilera on 5/4/16.
//

#include <iostream>
#include "tesla/variable.h"
#include "tesla/equation.h"
#include "tesla/solution.h"

using namespace std;
using namespace tesla;

int main(int argc, const char * argv []) {
	int status = 0;

	cout << "Testing solution..." << endl;

	solution solution;

	solution.add_equation("offset = 4 + random + 1");
	solution.add_equation("location = 1 + origin + offset");
	solution.add_equation("origin = 3 + 5");
	solution.add_equation("random = 2");
	solution.resolve_equations();
	auto solved = solution.get_solved();

	std::map<variable, unsigned int, variable_name_comparator> solutions;
	solutions.insert({ variable("location"), 16});
	solutions.insert({ variable("offset"), 7});
	solutions.insert({ variable("origin"), 8});
	solutions.insert({ variable("random"), 2});



	return status;
}