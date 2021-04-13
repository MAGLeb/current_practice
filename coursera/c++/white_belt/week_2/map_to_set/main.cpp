#include <iostream>
#include <map>
#include <string>
#include <set>

using namespace std;

set<string> BuildMapValuesSet(const map<int, string>& m) {
    set<string> unique;

    for(const auto& [key, value] : m) {
        unique.insert(value);
    }
    return unique;
}
