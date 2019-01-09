#include "callConsensusCpp.h"
#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::cout;
using std::vector;


char* get_consensus(vector<string> sequences) {
    int read_no = sequences.size();
    char* c_sequences[read_no];
    char* consensus;

    // Convert to char* from string :(
    int i = 0;
    for (auto& element: sequences){
        c_sequences[i] = const_cast<char*>((element).c_str());
        i++;
    }

//    cout << read_no << '\n';
//    cout << sequences[0] << '\n';

    consensus = callConsensus(read_no, c_sequences, c_sequences[0]);

    return consensus;
}

