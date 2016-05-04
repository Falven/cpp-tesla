#include <iostream>
#include <fstream>
#include <vector>

#include "tesla/solution.h"
#include "tesla/equation.h"

using namespace std;
using namespace tesla;

static void print_usage()
{
    cout << R"(Usage:
    invoke  info    option
    eval    [help]
    eval    [help]  download
    eval    [help]  version
    )" << endl;
}

int main(int argc, const char * argv []) {

    if(argc < 2) {
        print_usage();
        return -1;
    }

    solution solution;
    ifstream file(argv[1]);
    string line;
    if(file.is_open()) {
        while(file.good()) {
            getline(file, line);
            // Implicit conversion
            solution.add_equation(line);
        }
        solution.resolve_equations();
        auto solutions = solution.get_solved();
        for(auto & kv : solutions) {
            cout << kv.first.str() << " = " << kv.second << "\n";
        }
    }
    return 0;
}