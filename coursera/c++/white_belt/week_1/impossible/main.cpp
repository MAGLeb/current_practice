#include <iostream>

using namespace std;

int main() {
    double a, b;
    cin >> a >> b;
    if(b == 0) {
        cout << "Impossible";
        return 0;
    } else {
        cout << int(a / b);
    }
    return 0;
}
