#include "callConsensusCpp.h"
#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::cout;
using std::vector;


PolishParams* construct_call_consensus_parameters(string paramsPath) {
    return getConsensusParameters(const_cast<char*>(paramsPath.c_str()));
}
void destruct_call_consensus_parameters(PolishParams *params) {
    destroyConsensusParameters(params);
}

RleString* call_consensus(vector<string> sequences, vector<vector<uint8_t>> runLengths, vector<uint8_t > strands, PolishParams *params) {
    int64_t read_no = sequences.size();
    char* c_sequences[read_no];
    uint8_t* c_runLengths[read_no];
    uint8_t c_strands[read_no];
    RleString* consensus;

    // do vector to array conversion
    for (unsigned i = 0; i < read_no; i++) {
        c_sequences[i] = const_cast<char*>(sequences.at(i).c_str());
        c_runLengths[i] = &runLengths.at(i).front();
        c_strands[i] = strands.at(i);
    }

    // invoke c function
    consensus = callConsensus(read_no, c_sequences, c_runLengths, c_strands, params);

    return consensus;
}

