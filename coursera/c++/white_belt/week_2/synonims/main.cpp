#include <iostream>
#include <map>
#include <set>

using namespace std;

int main() {
    int n;
    map<string, set<string>> container;

    cin >> n;

    for(int i = 0; i < n; ++ i) {
        string command, f_word, s_word;
        cin >> command;

        if(command == "ADD") {
            cin >> f_word >> s_word;
            if(container.count(f_word)) {
                container[f_word].insert(s_word);
            } else {
                set<string> unique;
                unique.insert(s_word);
                container[f_word] = unique;
            }
            if(container.count(s_word)) {
                container[s_word].insert(f_word);
            } else {
                set<string> unique;
                unique.insert(f_word);
                container[s_word] = unique;
            }
        } else if(command == "COUNT") {
            cin >> f_word;
            cout << container[f_word].size() << endl;
        } else if(command == "CHECK") {
            cin >> f_word >> s_word;
            if(container[f_word].count(s_word)) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }

    }
    return 0;
}
