#include <iostream>

using namespace std;

int main() {
    int a, b, i;
    cin >> a >> b;
    i = a;

    if (a == b) {
        if(a % 2 == 0)
            cout << a;
    } else {
        while(i <= b) {
            if(i % 2 != 0) {
                i += 1;
            }

            cout << i << ' ';
            i += 2;
        }
    }

    return 0;
}
