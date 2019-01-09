#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include "FastqReader.h"
#include "callConsensusCpp.h"
#include "split.h"

using std::sqrt;
using std::string;
using std::cout;
using std::cerr;
using std::vector;
using std::set;


int main(){
    string fastq_path = "/home/ryan/data/Nanopore/polarbear/subreads_umi1.fastq";

    FastqReader fastq_reader(fastq_path);
    fastq_element element;
    vector<string> header_tokens;

    string prev_amplicon_name;

    set<string> amplicon_name_set = {};
    vector<string> amplicon_sequences = {};

    int length = 0;
    int length_cutoff = sqrt(9999999);
    int max_observed_length = 0;

    string amplicon_name;
    char* consensus;

    int cutoff = 10;
    int i = 0;

    while (!fastq_reader.file_end){
        element = fastq_reader.next_element();
        header_tokens = split(element.header, '_');
        length = element.sequence.length();

        amplicon_name = header_tokens[0];

//        cout << amplicon_name << '\n';

        // If a new amplicon read group has been started
        if ((amplicon_name_set.count(amplicon_name) == 0) && (amplicon_sequences.size() > 0)){

            if (max_observed_length < length_cutoff) {
//                for (auto& item: amplicon_sequences){
//                    cout << item.substr(0,10) << " ";
//                }
//                cout << '\n';

                consensus = get_consensus(amplicon_sequences);
                cout << ">" << prev_amplicon_name << '\n';
                cout << consensus << "\n\n";

            }
//            else {
//                cout << "length too long " << max_observed_length << '\n';
//            }

            amplicon_sequences = {};
            amplicon_name_set = {};
            max_observed_length = 0;

            i++;
        };

        prev_amplicon_name = amplicon_name;
        amplicon_name_set.insert(header_tokens[0]);
        amplicon_sequences.push_back(element.sequence);

//        cout << length << " " << max_observed_length << '\n';

        if (length > max_observed_length){
            max_observed_length = length;
        }

        cerr << "\r" << i << "  ";

        if (i == cutoff - 1){
            break;
        }
    }

    return 0;
}
