#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

string lowercase(string x) {
    for(auto& letter : x) {
        letter = tolower(letter);
    }
    return x;
}

bool comparator(string x, string y) {
    return lowercase(x) < lowercase(y);
}

int main() {
    int n;
    cin >> n;
    vector<string> vector(n);

    for(auto& item : vector) {
        cin >> item;
    }

    sort(vector.begin(), vector.end(), comparator);

    for(const auto& item : vector) {
        cout << item << ' ';
    }
    return 0;
}
