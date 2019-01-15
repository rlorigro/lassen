//
// Created by tpesout on 1/11/19.
//
#include <string>
#include <vector>
#include "callConsensusCpp.h"

using std::sqrt;
using std::string;
using std::cout;
using std::cerr;
using std::vector;

/*
sequences->push_back("GATACA");
vector<uint8_t> *length = new vector<uint8_t>();
length->push_back(1);
length->push_back(1);
length->push_back(2);
length->push_back(1);
length->push_back(1);
length->push_back(1);
lengths->push_back(length);
strands->push_back(TRUE);
*/

int main() {
    vector<string> sequences;
    vector<vector<uint8_t>> lengths;
    vector<uint8_t> strands;

    sequences.emplace_back("GATACA");
    vector<uint8_t> length;
    length.push_back(1);
    length.push_back(1);
    length.push_back(2);
    length.push_back(1);
    length.push_back(1);
    length.push_back(1);
    lengths.push_back(length);
    strands.push_back(0);

    PolishParams *params = getConsensusParameters((char*)"../data/allParams.np.json");

    RleString* consensus = call_consensus(sequences, lengths, strands, params);
    cout << "Consensus: " << consensus->rleString << "\n";

    destroyConsensusParameters(params);
    destroyRleString(consensus);
    return 0;
}
