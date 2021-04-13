#include <iostream>
#include <string>
#include <set>

using namespace std;


int main() {
    set<string> unique_strings;
    int n;
    cin >> n;

    for(int i = 0; i < n; ++ i) {
        string new_string;
        cin >> new_string;
        unique_strings.insert(new_string);
    }

    cout << unique_strings.size();
    return 0;
}
