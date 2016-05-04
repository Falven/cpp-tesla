//
// Created by Francisco Aguilera on 5/4/16.
//

#ifndef CPP_TESLA_EQUATION_SOLVER_H
#define CPP_TESLA_EQUATION_SOLVER_H

#include <string>
#include <vector>
#include <map>

namespace tesla {

	class equation_solver {

	public:

		equation_solver();

		void add_equation(const std::string & equation);

	private:

		std::map<std::string, std::vector<std::string>> _equations;

		std::string parse_lhs(const std::string & equation, std::string::const_iterator & citr);

		std::vector<std::string> parse_rhs(const std::string & equation, std::string::const_iterator & citr);

		bool is_delimiter(const char &c) const;

		bool is_separator(const char &c) const;

		bool is_operator(const char &c) const;
	};

}

#endif //CPP_TESLA_EQUATION_SOLVER_H