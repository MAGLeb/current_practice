#include <iostream>
#include <string>

using namespace std;

int main() {
    int number, r;
    string result;
    cin >> number;

    while (number != 0) {
        r = number % 2;
        result.insert(0, to_string(r));
        number = int(number / 2);
    }
    cout << result;

    return 0;
}
