//
// Created by Francisco Aguilera on 5/3/16.
//

#include <iostream>
#include <tesla/variable.h>

using namespace std;
using namespace tesla;

int main(int argc, const char * argv []) {
	int i, status = 0;

	cout << "Testing variable..." << endl;

	try {
		variable name("");
	} catch(const invalid_argument &) {
		status = 1;
	}

	try {
		variable name("offset");
	} catch (const invalid_argument &) {
		status = 1;
	}

	try {
		variable name("location");
	} catch (const invalid_argument &) {
		status = 1;
	}

	try {
		variable name("origin");
	} catch (const invalid_argument &) {
		status = 1;
	}

	try {
		variable name("random");
	} catch (const invalid_argument &) {
		status = 1;
	}

	// We could also write tests for Unicode character sets.
	// I think ascii suffices for now.
	// A-Z
	string alpha;
	for(i = 65; i <= 90; ++i) {
		alpha += char(i);
		try {
			variable name(alpha);
		} catch (const invalid_argument &) {
			status = 1;
		}
	}
	alpha.clear();
	// a-z
	for(i = 97; i <= 122; ++i) {
		alpha += char(i);
		try {
			variable name(alpha);
		} catch (const invalid_argument &) {
			status = 1;
		}
	}

	string dec;
	for(i = 0; i < 9; ++i) {
		dec += to_string(i);
		try {
			variable name(dec);
		} catch (const invalid_argument &) {
			status = 0;
		}
	}

	return status;
}