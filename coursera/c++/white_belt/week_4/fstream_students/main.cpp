#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Date {
public:
    Date(int new_day, int new_month, int new_year) {
        day = new_day;
        month = new_month;
        year = new_year;
    }

    string FullDate() {
       return to_string(day) + '.' + to_string(month) + '.' + to_string(year);
    };

private:
    int day;
    int month;
    int year;
};

struct Student {
    string name;
    string last_name;
    Date date;
};

int main() {
    vector<Student> students;
    int n;
    cin >> n;

    for(int i = 0; i < n; ++ i) {
        string name;
        string last_name;
        int day;
        int month;
        int year;

        cin >> name >> last_name >> day >> month >> year;
        students.push_back({name, last_name, {day, month, year}});
    }
    int query;
    cin >> query;

    for(int i = 0; i < query; ++ i) {
        string command;
        cin >> command;
        int k;
        cin >> k;
        if(k > students.size() or k == 0) {
            cout << "bad request" << endl;
            continue;
        }
        Student current_student = students[k - 1];

        if(command == "name") {
            cout << current_student.name << ' ' << current_student.last_name << endl;
        } else if(command == "date") {
            cout << current_student.date.FullDate() << endl;
        } else {
            cout << "bad request" << endl;
        }

    }

    return 0;
}
