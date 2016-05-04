//
// Created by Francisco Aguilera on 5/3/16.
//

#ifndef CPP_TESLA_EQUATION_H
#define CPP_TESLA_EQUATION_H


#include "variable_name.h"

namespace tesla {

	class equation {
	public:
		equation();
	private:
		variable_name _lhs;
		variable_name _rhs;
	};

}

#endif //CPP_TESLA_EQUATION_H
