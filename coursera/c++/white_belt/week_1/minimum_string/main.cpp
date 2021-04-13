#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<string> array;
    string first, second, third, result_min;

    cin >> first >> second >> third;
    array.push_back(first);
    array.push_back(second);
    array.push_back(third);

    result_min = first;

    for(auto & str : array) {
        if(str < result_min) {
            result_min = str;
        }
    }

    cout << result_min;
}
