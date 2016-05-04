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
//	string eq_name = eq.get_lhs().str();
//	auto dependencies = eq.get_rhs();


//	vector<string>::const_iterator itr, end;
//	for(itr = eq.begin(), end = _equations.end(); itr != end; ++itr)
//	_equations.insert( {eq_name , eq} );
}

vector<equation> solution::get_solved() {
//	vector<equation> solutions(_equations.size());
//	unordered_map<string, equation>::const_iterator itr, end;
//	for(itr = _equations.begin(), end = _equations.end(); itr != end; ++itr) {
//		solutions.push_back(itr->second);
//	}
	return vector<equation>();
}