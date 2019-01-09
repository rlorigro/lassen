#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/complex.h>
#include <pybind11/functional.h>
#include <pybind11/chrono.h>
#include "callConsensus.h"
#include <vector>

using namespace std;

char* getConsensus(int readNo, vector<string> readVector) {
    char* sequences[readNo];
    char* consensus;

    int i = 0;
    for (auto& element: readVector){
        sequences[i] = const_cast<char*>(element.c_str());
        i++;
    }

    cout << readNo << endl;
    cout << sequences[0] << endl;

    consensus = callConsensus(readNo, sequences, sequences[0]);

    return consensus;
}

PYBIND11_MODULE(pyLassen, module) {
    module.def("getConsensus", &getConsensus, "A function which takes an array of characters and converts them");
}
