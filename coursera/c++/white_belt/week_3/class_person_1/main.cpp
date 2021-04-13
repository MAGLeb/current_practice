#include <map>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Person {
public:
    Person(const string& name, const string& surname, const int& year_of_birth) {
        history[year_of_birth] = {name, surname};
    }
    void ChangeFirstName(int year, const string& first_name) {
        if(year < history.begin()->first) {
            return;
        }
        string last_name = history[year].second;
        history[year] = {first_name, last_name};
    }
    void ChangeLastName(int year, const string& last_name) {
        if(year < history.begin()->first) {
            return;
        }
        string first_name = history[year].first;
        history[year] = {first_name, last_name};
    }
    string GetFullName(int year) const {
        if(year < history.begin()->first) {
            return "No person";
        }

        string current_name, current_last_name;

        for(const auto& [key, value] : history) {
            if(year >= key) {
                if(!value.first.empty()) {
                    current_name = value.first;
                }
                if(!value.second.empty()) {
                    current_last_name = value.second;
                }
            }
        }
        string result = "Incognito";
        if(!current_name.empty() and !current_last_name.empty()) {
            result = current_name + " " + current_last_name;
        } else if(!current_name.empty()) {
            result = current_name + " with unknown last name";
        } else if(!current_last_name.empty()) {
            result = current_last_name + " with unknown first name";
        }
        return result;
    }
    string GetFullNameWithHistory(int year) const {
        if(year < history.begin()->first) {
            return "No person";
        }

        vector<string> prev_last_name, prev_first_name;
        string current_first_name, current_last_name;

        for(const auto& [key, value] : history) {
            if(key <= year) {
                if(!value.first.empty()) {
                    if(!current_first_name.empty() and current_first_name != value.first) {
                        prev_first_name.push_back(current_first_name);
                    }
                    current_first_name = value.first;
                }
                if(!value.second.empty()) {
                    if(!current_last_name.empty() and current_last_name != value.second) {
                        prev_last_name.push_back(current_last_name);
                    }
                    current_last_name = value.second;
                }
            }
        }

        string result = "Incognito";
        string result_prev_first_names, result_prev_last_names;
        int counter_first = prev_first_name.size(), counter_last = prev_last_name.size();

        if(counter_last == 1) {
            result_prev_last_names = " (" + *--prev_last_name.end() + ")";
        } else {
            for(int i = 0; i < counter_last; ++ i) {
                auto element_iterator = --prev_last_name.end();
                if(i == 0) {
                    result_prev_last_names = " (" + *element_iterator;
                } else if(i == counter_last - 1) {
                    result_prev_last_names += ", " + *element_iterator + ")";
                } else {
                    result_prev_last_names += ", " + *element_iterator;
                }
                prev_last_name.erase(--prev_last_name.end());
            }
        }

        if(counter_first == 0) {
            result_prev_first_names = " ";
        } else if(counter_first == 1) {
            result_prev_first_names = " (" + *--prev_first_name.end() + ") ";
        } else {
            for(int i = 0; i < counter_first; ++ i) {
                auto element_iterator = --prev_first_name.end();
                if(i == 0) {
                    result_prev_first_names = " (" + *element_iterator;
                } else if(i == counter_first - 1) {
                    result_prev_first_names += ", " + *element_iterator + ") ";
                } else {
                    result_prev_first_names += ", " + *element_iterator;
                }
                prev_first_name.erase(--prev_first_name.end());
            }
        }

        if(!current_first_name.empty() and !current_last_name.empty()) {
            result = current_first_name + result_prev_first_names + current_last_name + result_prev_last_names;
        } else if(!current_first_name.empty()) {
            result = current_first_name + result_prev_first_names + "with unknown last name";
        } else if(!current_last_name.empty()) {
            result = current_last_name + result_prev_last_names + " with unknown first name";
        }
        return result;
    }
    void PrintHistory() {
        for(const auto& [key, value] : history) {
            cout << "key: " << key << ", first_name: " << value.first << ", second_name: " << value.second << endl;
        }
    }
private:
    map<int, pair<string, string>> history;
};

int main() {
    Person person("Polina", "Sergeeva", 1960);
    for (int year : {1959, 1960}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1965, "Appolinaria");
    person.ChangeLastName(1967, "Ivanova");
    for (int year : {1965, 1967}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    return 0;
}

//No person
//Polina Sergeeva
//Appolinaria (Polina) Sergeeva
//Appolinaria (Polina) Ivanova (Sergeeva)