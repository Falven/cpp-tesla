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

	class solution {
	public:
		solution();

		void add_equation(const equation & eq);

		void resolve_equations();

		std::map<variable_name, unsigned int> get_solved() const;

	private:
		std::map<variable_name, equation> _equations;

		std::map<variable_name, unsigned int> _solutions;

		unsigned int _total;
	};

}

#endif //CPP_TESLA_SOLUTION_H
