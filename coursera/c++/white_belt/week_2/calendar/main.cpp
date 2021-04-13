#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<int> number_day = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int month = 0;
    vector<vector<string>> current_month(number_day[month]);
    int n;
    cin >> n;

    for (int i = 0; i < n; ++ i) {
        string command;
        cin >> command;

        if (command == "ADD") {
            int index;
            string task;
            cin >> index >> task;

            current_month[index - 1].push_back(task);
        } else if (command == "NEXT") {
            int prev_number_days = number_day[month];
            month = month == 11 ? 0 : month + 1;
            if (prev_number_days > number_day[month]) {
                vector<string> missed_tasks;
                for (int j = number_day[month]; j < prev_number_days; ++ j) {
                    missed_tasks.insert(missed_tasks.end(), begin(current_month[j]), end(current_month[j]));
                }
                current_month.resize(number_day[month]);
                current_month[current_month.size() - 1].insert(end(current_month[current_month.size() - 1]), begin(missed_tasks), end(missed_tasks));
            } else {
                current_month.resize(number_day[month]);
            }

        } else if (command == "DUMP") {
            int index;
            cin >> index;
            cout << current_month[index - 1].size();
            for (const auto& task : current_month[index - 1]) {
                cout << ' ' << task;
            }
            cout << endl;
        }
//        for (int i = 0; i < current_month.size(); ++ i) {
//            cout << "day: " << i + 1 << endl;
//            cout << "tasks: ";
//            for (const auto& task : current_month[i]) {
//                cout << task << ' ';
//            }
//            cout << endl;
//        }
    }

    return 0;
}

//12
//ADD 5 Salary
//ADD 31 Walk
//ADD 30 WalkPreparations
//NEXT
//DUMP 5
//DUMP 28
//NEXT
//DUMP 31
//DUMP 30
//DUMP 28
//ADD 28 Payment
//DUMP 28
