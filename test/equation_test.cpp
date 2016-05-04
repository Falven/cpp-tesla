//
// Created by Francisco Aguilera on 5/4/16.
//

#include <iostream>
#include <tesla/variable.h>
#include <tesla/equation.h>

using namespace std;
using namespace tesla;

int main(int argc, const char * argv []) {
	int status = 0;

	cout << "Testing equation..." << endl;

	equation offset("offset = 4 + random + 1");
	if(offset.get_variable_name() != "offset") {
		status = 1;
	}
	equation location("location = 1 + origin + offset");
	if(location.get_variable_name() != "location") {
		status = 1;
	}
	equation origin("origin = 3 +     5");
	if(origin.get_variable_name() != "origin") {
		status = 1;
	}
	equation random("random =   2");
	if(random.get_variable_name() != "random") {
		status = 1;
	}

	return status;
}