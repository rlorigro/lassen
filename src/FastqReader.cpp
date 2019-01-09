#include <string>
#include <iostream>
#include <fstream>
#include "FastqReader.h"

using std::string;
using std::cout;
using std::ifstream;


FastqReader::FastqReader(string file_path){
    this->fastq_file = ifstream(file_path);
    this->header_1_symbol = '@';
    this->header_2_symbol = '+';
    this->file_end = false;
    this->index = 0;

    if (!this->fastq_file.good()){
        cout << "ERROR: file read error: " << file_path << '\n';
        exit(1);
    }

    getline(this->fastq_file, this->line);

    // Skip to first header in file
    while (this->line[0] != '@'){
        this->next();
    }
}


//Iterate file
string FastqReader::next(){
    // Copy currently cached line in file
    string output_line = this->line;

    // Cache next line if it exists, or else toggle "file_end" attribute
    if (!getline(this->fastq_file, this->line)){
        this->file_end = true;
    }

    // Track line number
    this->index++;

    return output_line;
}


fastq_element FastqReader::next_element(){
    this->element = {};

    // Header 1
    this->parse_header_1();
    this->next();

    // Sequence
    this->parse_sequence();
    this->next();

    // Header 2
    this->parse_header_2();
    this->next();

    // Quality
    this->parse_quality();
    this->next();

    return this->element;
}


//Parse header 1
void FastqReader::parse_header_1(){
    if ( !(this->line[0] == this->header_1_symbol) ){
        cout << "ERROR: non fastq header symbol at line: " << this->index+1 << " with symbol: " << this->line[0] << '\n';
        exit(1);
    }

    int length = line.length();
    string header = this->line.substr(1, length);
    this->element.header = header;
}


//Parse sequence
void FastqReader::parse_sequence(){
    this->element.sequence = this->line;
}


//Parse header 2
void FastqReader::parse_header_2(){
    if ( !(this->line[0] == this->header_2_symbol) ){
        cout << "ERROR: non fastq header symbol at line: " << this->index+1 << " with symbol: " << this->line[0] << '\n';
        exit(1);
    }
}


//Parse quality
void FastqReader::parse_quality(){
    this->element.quality = this->line;
}
