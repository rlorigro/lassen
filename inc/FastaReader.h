#ifndef LASSEN_FASTAREADER_H
#define LASSEN_FASTAREADER_H
#include <string>
#include <iostream>
#include <fstream>

using std::string;
using std::ifstream;


struct fasta_element{
    string header;
    string sequence;
    string quality;
};


class FastaReader{
    public:
        // Attributes
        char header_1_symbol;
        char header_2_symbol;
        fasta_element element;
        int start;
        int index;
        bool file_end;

        // Methods
        FastaReader(string file_path);
        string next();
        fasta_element next_element();
        void parse_header_1();
        void parse_sequence();
        void parse_header_2();
        void parse_quality();

    private:
        string line;
        string header;
        string sequence;
        string quality;

        ifstream fasta_file;
};


#endif //LASSEN_FASTAREADER_H
