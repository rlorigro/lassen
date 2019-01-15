#ifndef LASSEN_CALLCONSENSUSCPP_H
#define LASSEN_CALLCONSENSUSCPP_H

#include "marginPhase/callConsensus.h"
#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::cout;
using std::vector;

PolishParams* construct_call_consensus_parameters(string paramsPath);
void destruct_call_consensus_parameters(PolishParams *params);
RleString* call_consensus(vector<string> sequences, vector<vector<uint8_t>> runLengths, vector<uint8_t> strands, PolishParams *params);

#endif //LASSEN_CALLCONSENSUSCPP_H
