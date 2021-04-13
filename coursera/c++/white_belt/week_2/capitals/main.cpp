#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    map<string, string> countries;
    int n;
    cin >> n;

    for (int i = 0; i < n; ++ i) {
        string command;
        cin >> command;

        if (command == "CHANGE_CAPITAL") {
            string country, new_capital;
            cin >> country >> new_capital;

            if (countries.count(country)) {
                if (countries[country] == new_capital) {
                    cout << "Country " << country << " hasn't changed its capital" << endl;
                } else {
                    string old_capital = countries[country];
                    countries[country] = new_capital;
                    cout << "Country " << country << " has changed its capital from " << old_capital << " to " << new_capital << endl;
                }
            } else {
                countries[country] = new_capital;
                cout << "Introduce new country " << country << " with capital " << new_capital << endl;
            }
        } else if (command == "RENAME") {
            string old_country_name, new_country_name;
            cin >> old_country_name >> new_country_name;

            if (countries.count(old_country_name) == 0 || countries.count(new_country_name)) {
                cout << "Incorrect rename, skip" << endl;
            } else {
                string capital = countries[old_country_name];
                countries.erase(old_country_name);
                countries[new_country_name] = capital;
                cout << "Country " << old_country_name << " with capital " << capital << " has been renamed to " << new_country_name << endl;
            }
        } else if (command == "ABOUT") {
            string country;
            cin >> country;
            if (countries.count(country)) {
                cout << "Country " << country << " has capital " << countries[country] << endl;
            } else {
                cout << "Country " << country << " doesn't exist" << endl;
            }
        } else if (command == "DUMP") {
            if (countries.empty()) {
                cout << "There are no countries in the world" << endl;
            } else {
                for (auto [country, capital] : countries) {
                    cout << country << '/' << capital << ' ';
                }
                cout << endl;
            }
        }
    }
    return 0;
}
