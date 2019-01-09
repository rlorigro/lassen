#include <string>
#include <iostream>
#include <fstream>
#include "FastaReader.h"

using std::string;
using std::cout;
using std::ifstream;


FastaReader::FastaReader(string file_path){
    this->fasta_file = ifstream(file_path);
    this->header_1_symbol = '>';
    this->file_end = false;
    this->index = 0;

    if (!this->fasta_file.good()){
        cout << "ERROR: file read error: " << file_path << '\n';
        exit(1);
    }

    getline(this->fasta_file, this->line);

    // Skip to first header in file
    while (this->line[0] != '>'){
        this->next();
    }
}


//Iterate file
string FastaReader::next(){
    // Copy currently cached line in file
    string output_line = this->line;

    // Cache next line if it exists, or else toggle "file_end" attribute
    if (!getline(this->fasta_file, this->line)){
        this->file_end = true;
    }

    // Track line number
    this->index++;

    return output_line;
}


fasta_element FastaReader::next_element(){
    this->element = {};

    // Header 1
    this->parse_header_1();
    this->next();

    // Sequence
    this->parse_sequence();
    this->next();

//    // Space
//    this->parse_header_2();
//    this->next();

    return this->element;
}


//Parse header 1
void FastaReader::parse_header_1(){
    if ( !(this->line[0] == this->header_1_symbol) ){
        cout << "ERROR: non fastq header symbol at line: " << this->index+1 << " with symbol: " << this->line[0] << '\n';
        exit(1);
    }

    int length = line.length();
    string header = this->line.substr(1, length);
    this->element.header = header;
}


//Parse sequence
void FastaReader::parse_sequence(){
    this->element.sequence = this->line;
}
