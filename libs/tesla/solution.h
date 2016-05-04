//
// Created by Francisco Aguilera on 5/3/16.
//

#ifndef CPP_TESLA_SOLUTION_H
#define CPP_TESLA_SOLUTION_H

#include <string>
#include <unordered_map>
#include <vector>
#include <map>
#include "equation.h"

namespace tesla {

	// For sorting variable_names in our map.
	struct variable_name_comparator {
		bool operator()(const tesla::variable & a, const tesla::variable & b) const;
	};

	class solution {
	public:
		solution();

		void add_equation(const equation & eq);

		void add_equation(const std::string & eq);

		std::map<variable, unsigned int, variable_name_comparator> get_solved() const;

		void resolve_equations();

	private:
		std::map<variable, equation, variable_name_comparator> _equations;

		std::map<variable, unsigned int, variable_name_comparator> _solutions;

		unsigned int _total;

		bool resolve_equation(equation & eq);

		bool resolve_from_solutions(equation & eq);

		bool resolve_from_dependencies(equation & eq);

		void add_solution(const equation & eq);
	};
}

#endif //CPP_TESLA_SOLUTION_H
