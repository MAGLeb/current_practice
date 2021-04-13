#include <iostream>
#include <vector>
#include <string>

using namespace std;

void MoveStrings(vector<string>& source, vector<string>& distination) {
    for(auto str : source) {
        distination.push_back(str);
    }
    source.clear();
}