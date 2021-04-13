#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool IsPalindrom(string str) {
    int i = 0, j = str.size() - 1;

    while(i < j) {
        if(str[i] != str[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

vector<string> PalindromFilter(vector<string> array, int minLenght) {
    vector<string> result;

    for(auto str : array) {
        if(str.size() >= minLenght) {
            if(IsPalindrom(str)) {
                result.push_back(str);
            }
        }
    }
    return result;
}
