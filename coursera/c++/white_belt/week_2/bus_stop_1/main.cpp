#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

bool comparator(const pair<int, string>& a, const pair<int, string>& b) {
    return a.second < b.second;
}

vector<pair<int, string>> sortingMapByFirstElement(map<pair<int, string>, vector<string>>& m) {
    vector<pair<int, string>> v;

    for (auto& item : m) {
        v.push_back(item.first);
    }

    sort(v.begin(), v.end(), comparator);
    return v;
}

int main() {
    map<pair<int, string>, vector<string>> buses;
    int n;
    cin >> n;

    for (int i = 0; i < n; ++ i) {
        string command;
        cin >> command;

        if (command == "ALL_BUSES") {
            if (buses.empty()) {
                cout << "No buses" << endl;
            } else {
                vector<pair<int, string>> sorted_keys = sortingMapByFirstElement(buses);

                for (const auto& bus : sorted_keys) {
                    auto stops = buses[bus];
                    cout << "Bus " << bus.second << ":";
                    for (const auto& stop : stops) {
                        cout << ' ' << stop;
                    }
                    cout << endl;
                }

            }
        } else if (command == "BUSES_FOR_STOP") {
            string stop;
            bool contains = false;
            cin >> stop;

            for (const auto& [bus, stops] : buses) {
                string bus_name = bus.second;
                if (find(stops.begin(), stops.end(), stop) != stops.end()) {
                    cout << bus_name << ' ';
                    contains = true;
                }
            }
            if (!contains) {
                cout << "No stop";
            }
            cout << endl;
        } else if (command == "STOPS_FOR_BUS") {
            string bus_name;
            cin >> bus_name;
            bool contains_bus = false;

            for (const auto& [bus, stops] : buses) {
                if (bus.second == bus_name) {
                    contains_bus = true;
                    for (const auto& stop : stops) {
                        cout << "Stop " << stop << ": ";
                        bool contains = false;
                        for (const auto& [bus, stops] : buses) {
                            if (find(stops.begin(), stops.end(), stop) != stops.end() && bus.second != bus_name) {
                                cout << bus.second << ' ';
                                contains = true;
                            }
                        }
                        if (!contains) {
                            cout << "no interchange";
                        }
                        cout << endl;
                    }
                }
            }
            if (!contains_bus) {
                cout << "No bus" << endl;
            }
        } else if (command == "NEW_BUS") {
            string bus;
            int number_stops;
            vector<string> stops;
            cin >> bus;
            cin >> number_stops;

            for (int j = 0; j < number_stops; ++ j) {
                string stop;
                cin >> stop;
                stops.push_back(stop);
            }
            buses[{buses.size(), bus}] = stops;
        }
    }
    return 0;
}
