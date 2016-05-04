//
// Created by Francisco Aguilera on 5/3/16.
//

#ifndef CPP_TESLA_VARIABLE_H
#define CPP_TESLA_VARIABLE_H


#include <string>

namespace tesla {

	class variable {
	public:
		variable();

		variable(const std::string & name);

		std::string get_name() const;

		bool operator==(const variable & var);

		bool operator!=(const variable & var);

	private:
		std::string _name;

		std::string validate_name(const std::string &basic_string);
	};

}


#endif //CPP_TESLA_VARIABLE_H
