#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include "FastaReader.h"
#include "callConsensusCpp.h"
#include "split.h"

using std::sqrt;
using std::string;
using std::cout;
using std::cerr;
using std::vector;
using std::set;


int main(){
    string sequences_fasta_path = "../data/test/ecoli_200_50bp_windows/gi_14451_14500.fasta";
    string reference_fasta_path = "../data/test/ecoli_200_50bp_windows/gi_14451_14500_ref.fasta";

    FastaReader sequences_fasta_reader(sequences_fasta_path);
    FastaReader reference_fasta_reader(reference_fasta_path);

    fasta_element element;
    string header;

    vector<string> window_sequences = {};
    char* consensus_sequence;

    int length = 0;
    int length_cutoff = sqrt(9999999);

    int i = 0;

    while (!sequences_fasta_reader.file_end) {
        element = sequences_fasta_reader.next_element();
        header = element.header;
        length = element.sequence.length();
        window_sequences.push_back(element.sequence);
        i++;

        cerr << "\r" << i << "  ";
    }

    string ref_sequence;

    while (!reference_fasta_reader.file_end) {
        element = reference_fasta_reader.next_element();
        header = element.header;
        length = element.sequence.length();
        ref_sequence = element.sequence;
        i++;

        cerr << "\n" << i << "  ";
    }

    consensus_sequence = get_consensus(window_sequences);

    cout << "\n" << ref_sequence << "\n";
    cout << consensus_sequence << "\n\n";

    return 0;
}
