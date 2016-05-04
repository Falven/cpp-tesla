//
// Created by Francisco Aguilera on 5/3/16.
//

#include <iostream>
#include <tesla/variable_name.h>

using namespace std;
using namespace tesla;

int main(int argc, const char * argv []) {
	int i, status = 0;

	try {
		variable_name name("");
	} catch(const invalid_argument &) {
		status = 1;
	}

//	try {
//		variable_name name("offset");
//	} catch (const invalid_argument &) {
//		status = 1;
//	}
//
//	try {
//		variable_name name("location");
//	} catch (const invalid_argument &) {
//		status = 1;
//	}
//
//	try {
//		variable_name name("origin");
//	} catch (const invalid_argument &) {
//		status = 1;
//	}
//
//	try {
//		variable_name name("random");
//	} catch (const invalid_argument &) {
//		status = 1;
//	}
//
//	// We could also write tests for Unicode character sets.
//	// I think ascii suffices for now.
//	// A-Z
//	string alpha;
//	for(i = 65; i <= 90; ++i) {
//		alpha += char(i);
//		try {
//			variable_name name(alpha);
//		} catch (const invalid_argument &) {
//			status = 1;
//		}
//	}
//	alpha.clear();
//	// a-z
//	for(i = 97; i <= 122; ++i) {
//		alpha += char(i);
//		try {
//			variable_name name(alpha);
//		} catch (const invalid_argument &) {
//			status = 1;
//		}
//	}
//
//	string dec;
//	for(i = 0; i < 9; ++i) {
//		dec += to_string(i);
//		try {
//			variable_name name(dec);
//		} catch (const invalid_argument &) {
//			status = 0;
//		}
//	}

	return status;
}