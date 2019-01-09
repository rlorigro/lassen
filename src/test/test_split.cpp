#include <string>
#include <iostream>
#include "split.h"

using std::vector;
using std::string;
using std::cout;

int main(){
    vector <string> tokens;
    string s;

    s = "_a_bb_ccc_dddd__eeeee_";

    tokens = split(s, '_');

    for (auto& item: tokens){
        cout << item << '\n';
    }

    s = "a_bb";

    tokens = split(s, '_');

    for (auto& item: tokens){
        cout << item << '\n';
    }


    return 0;
}
