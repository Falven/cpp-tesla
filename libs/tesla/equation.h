//
// Created by Francisco Aguilera on 5/3/16.
//

#ifndef CPP_TESLA_EQUATION_H
#define CPP_TESLA_EQUATION_H


#include "variable_name.h"

namespace tesla {

	class equation {
	public:
		equation(const std::string & str);

		variable_name get_name() const;

		std::string str() const;

		friend std::ostream & operator<< (std::ostream & out, const equation & eqn);

	private:
		variable_name _lhs;

	};

}

#endif //CPP_TESLA_EQUATION_H
