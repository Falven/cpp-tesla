//
// Created by Francisco Aguilera on 5/3/16.
//

#ifndef CPP_TESLA_EQUATION_H
#define CPP_TESLA_EQUATION_H

#include <string>
#include <vector>
#include "variable_name.h"

namespace tesla {

	class equation {
	public:

		equation(const std::string & str);

		variable_name get_lhs() const;

		std::vector<std::string> get_rhs() const;

		std::string str() const;

	private:

		std::string _equation;

		std::string::const_iterator _itr;

		std::string::const_iterator _end;

		variable_name _lhs;

		std::vector<std::string> _rhs;

		std::string parse_lhs(const std::string & input);

		std::vector<std::string> parse_rhs(const std::string & input);

		bool is_delimiter(const char & c);

		bool is_separator(const char &c);
	};

}

#endif //CPP_TESLA_EQUATION_H
