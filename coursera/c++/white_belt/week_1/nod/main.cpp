#include <iostream>
#include <vector>

using namespace std;

vector<int> find_max(int first, int second) {
    if(first < second) {
        return vector<int> {second, first};
    } else {
        return vector<int> {first, second};
    }
}

int main() {
    int a, b, first, second, r;
    cin >> a >> b;
    vector<int> result = find_max(a, b);
    first = result[0];
    second = result[1];

    do {
        r = first % second;
        if(r == 0) {
            cout << second;
            break;
        }
        first = second;
        second = r;
    } while (true);

    return 0;
}

