#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    char const f = 'f';
    int counter = 0, index = 0;
    cin >> str;

    for(auto letter : str) {
        if(letter == f) {
            counter += 1;
            if(counter == 2) {
                break;
            }
        }
        index += 1;
    }

    if(counter == 0) {
        cout << -2;
    } else if(counter == 1) {
        cout << -1;
    } else {
        cout << index;
    }

    return 0;
}
