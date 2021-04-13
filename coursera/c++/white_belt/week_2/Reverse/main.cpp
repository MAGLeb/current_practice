#include <iostream>
#include <vector>

using namespace std;

void Reverse(vector<int>& v) {
    unsigned long middle = v.size() / 2, intermediate;

    for(int i = 0; i < middle; ++i) {
        intermediate = v[i];
        v[i] = v[v.size() - i - 1];
        v[v.size() - i - 1] = intermediate;
    }
}

vector<int> Reversed(const vector<int>& v) {
    vector<int> result;

    for(int i = v.size() - 1; i >= 0; --i) {
        result.push_back(v[i]);
    }

    return result;
}