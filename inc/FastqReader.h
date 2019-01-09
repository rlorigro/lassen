#ifndef LASSEN_FASTQREADER_H
#define LASSEN_FASTQREADER_H
#include <string>
#include <iostream>
#include <fstream>

using std::string;
using std::ifstream;


struct fastq_element{
    string header;
    string sequence;
    string quality;
};


class FastqReader{
    public:
        // Attributes
        char header_1_symbol;
        char header_2_symbol;
        fastq_element element;
        int start;
        int index;
        bool file_end;

        // Methods
        FastqReader(string file_path);
        string next();
        fastq_element next_element();
        void parse_header_1();
        void parse_sequence();
        void parse_header_2();
        void parse_quality();

    private:
        string line;
        string header;
        string sequence;
        string quality;

        ifstream fastq_file;
};

//FastqReader::FastqReader(string file_path);
//string FastqReader::next();

#endif //LASSEN_FASTQREADER_H
