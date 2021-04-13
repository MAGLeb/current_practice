#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    map<vector<string>, int> m;

    for(int i = 0; i < n; ++ i) {
        int n_stops;
        cin >> n_stops;
        vector<string> bus_stops(n_stops);
        for(string& stop : bus_stops) {
            cin >> stop;
        }
        if(m.count(bus_stops)) {
            cout << "Already exists for " << m[bus_stops] << endl;
        } else{
            int new_index = m.size() + 1;
            m[bus_stops] = new_index;
            cout << "New bus " << new_index << endl;
        }
    }

    return 0;
}