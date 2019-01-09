#include <string>
#include <iostream>
#include <vector>

using std::vector;
using std::string;

vector<string> split(string s, char delimiter){
    vector<string> tokens;
    int start_index = 0;
    int length = 0;

    for (int i=0; i<s.length(); i++){
        // Test each position for a delimiter
        if (s[i] == delimiter){
            // Only store token if there are characters between 2 delimiters
            if (length > 0) {
                tokens.push_back(s.substr(start_index, length));
            }
            length = 0;
            start_index = i + 1;
        }
        else{
            // If not a delimiter, increment length of the current token
            length++;
        }
    }

    // Append final token if exists
    if (length > 0) {
        tokens.push_back(s.substr(start_index, length));
    }

    return tokens;
}

