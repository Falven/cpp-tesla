//
// Created by Francisco Aguilera on 5/3/16.
//

#ifndef CPP_TESLA_SOLUTION_H
#define CPP_TESLA_SOLUTION_H

#include <unordered_map>
#include <vector>
#include "equation.h"

namespace tesla {

	class solution {
	public:
		solution();

		void add_equation(const equation & eq);

		std::vector<equation> get_solved();

	private:
		std::unordered_map<std::string, equation> _equations;

		std::unordered_map<std::string, equation> _solutions;

		unsigned int _total;
	};

}

#endif //CPP_TESLA_SOLUTION_H
