#include <iostream>
#include <string>

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

int main() {
    string str;
    cin >> str;
    if(IsPalindrom(str)) {
        cout << "true";
    } else {
        cout << "false";
    }
    return 0;
}
