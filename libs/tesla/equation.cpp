//
// Created by Francisco Aguilera on 5/3/16.
//

#include "equation.h"


tesla::equation::equation() : _lhs("") {

}

variable_name tesla::equation::get_name() const {
	return _lhs;
}


