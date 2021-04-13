#include <iostream>
#include <map>
#include <string>

using namespace std;

void doCommand(const string command, map<int, bool>& m, int n=0) {
    if(command == "COME") {
        if(n > 0) {
            while(n > 0) {
                m.insert({m.size(), false});
                -- n;
            }
        } else {
            while(n < 0) {
                m.erase(m.size() - 1);
                ++ n;
            }
        }
    } else if(command == "WORRY") {
        m[n] = true;
    } else if(command == "QUIET") {
        m[n] = false;
    } else if(command == "WORRY_COUNT") {
        int counter = 0;
        for(auto person : m) {
            if(person.second) {
                counter++;
            }
        }
        cout << counter << endl;
    }
}

int main() {
    int n, nC;
    string command;
    map<int, bool> worried_people;
    cin >> n;

    while(n > 0) {
        -- n;
        cin >> command;
        if(command == "WORRY_COUNT") {
            doCommand(command, worried_people);
        } else {
            cin >> nC;
            doCommand(command, worried_people, nC);
        }
    }

    return 0;
}
