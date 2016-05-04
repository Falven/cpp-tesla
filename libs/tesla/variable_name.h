//
// Created by Francisco Aguilera on 5/3/16.
//

#ifndef CPP_TESLA_VARIABLE_H
#define CPP_TESLA_VARIABLE_H


#include <string>

namespace tesla {

	class variable_name {
	public:
		variable_name();

		variable_name(const std::string & name);

		std::string str() const;

		bool operator==(const std::string & str);

		bool operator==(const variable_name & varname);

		bool operator!=(const std::string & str);

		bool operator!=(const variable_name & varname);

		variable_name & operator+=(const char & c);

	private:
		std::string _name;

		std::string validate_name(const std::string &basic_string);
	};
}


#endif //CPP_TESLA_VARIABLE_H
