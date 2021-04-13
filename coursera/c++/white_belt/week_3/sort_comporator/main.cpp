#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool comparator(int x, int y) {
    return abs(x) < abs(y);
}

int main() {
    int n;
    cin >> n;
    vector<int> container(n);

    for(auto& num : container) {
        cin >> num;
    }

    sort(container.begin(), container.end(), comparator);

    for(const auto& num : container) {
        cout << num << ' ';
    }

    return 0;
}
