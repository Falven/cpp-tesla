//
// Created by Francisco Aguilera on 5/3/16.
//

#ifndef CPP_TESLA_EQUATION_H
#define CPP_TESLA_EQUATION_H

#include <string>
#include <vector>
#include "variable.h"

namespace tesla {

	class equation {
	public:

		equation(const std::string & str);

		variable get_variable_name() const;

		std::vector<std::string> get_rhs() const;

		std::vector<variable> get_variables() const;

		bool remove_variable(const variable & varname);

		std::vector<unsigned int> get_constants() const;

		void add_constant(const unsigned int & constant);

		bool operator==(const equation & other);

		bool operator!=(const equation & other);

		std::string str() const;

	private:

		std::string _equation;

		std::vector<variable> _variables;

		std::vector<unsigned int> _constants;

		variable _lhs;

		std::vector<std::string> _rhs;

		std::string::const_iterator parse_lhs();

		void parse_rhs(std::string::const_iterator itr);

		bool is_delimiter(const char & c) const;

		bool is_separator(const char &c) const;

		bool is_operator(const char &c) const;

		void store_token(const std::string & token);
	};

}

#endif //CPP_TESLA_EQUATION_H
