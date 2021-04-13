#include <iostream>
#include <set>
#include <map>

using namespace std;

int main() {
    int n;
    map<set<string>, int> buses;
    cin >> n;

    for(int i = 0; i < n; ++ i) {
        int n_stops;
        set<string> stops;
        cin >> n_stops;

        for(int j = 0; j < n_stops; ++ j) {
            string stop;
            cin >> stop;
            stops.insert(stop);
        }

        if(buses.count(stops)) {
            cout << "Already exists for " << buses[stops] << endl;
        } else {
            int new_index = buses.size() + 1;
            buses[stops] = new_index;
            cout << "New bus " << new_index << endl;
        }
    }
    return 0;
}
