#include <string>
#include <iostream>
#include "FastqReader.h"

using std::string;
using std::cout;

int main(){
    string file_path = "/home/ryan/code/polarbear_assembly_cpp/src/test/test.fastq";

    FastqReader fastq_reader(file_path);

    string line;
    fastq_element element;

    while (!fastq_reader.file_end) {
        element = fastq_reader.next_element();
        cout << element.header << "\n";
        cout << element.sequence << "\n";
        cout << element.quality << "\n\n";
    }

    return 0;
}
