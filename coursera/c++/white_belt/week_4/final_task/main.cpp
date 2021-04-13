#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

class Date {
public:
    Date() {};
    Date(const int& new_year, const int& new_month, const int& new_day) {
        year = new_year;
        month = new_month;
        day = new_day;
    }

    int GetYear() const {
        return year;
    };

    int GetMonth() const {
        return month;
    };

    int GetDay() const {
        return day;
    };

private:
    int year = 2020;
    int month = 10;
    int day = 6;
};

void CheckForSeparator(char separator) {
    if(separator != '-') {
        string other_string;
        throw;
    }
};

void CheckForMonth(int month) {
    if(month > 12 or month < 1) {
        throw out_of_range("Month value is invalid: " + to_string(month));
    }
}

void CheckForDay(int day) {
    if(31 < day or day < 1) {
        throw out_of_range("Day value is invalid: " + to_string(day));
    }
}

istream& operator >> (istream& input, Date& date) {
    int year, month, day;
    char slash;
    string full_string;
    try {
        getline(input, full_string);

        stringstream ss;
        ss << full_string;
        ss >> year >> slash;
        if(ss.fail()) throw exception();
        CheckForSeparator(slash);
        ss >> month >> slash >> day;
        if(ss.fail()) throw exception();
        CheckForSeparator(slash);
        CheckForMonth(month);
        CheckForDay(day);
        date = {year, month, day};
        if(!ss.eof()) throw exception();
    } catch (out_of_range& e) {
        cout << e.what() << endl;
        exit(0);
    } catch (exception& e) {
        cout << "Wrong date format: " + full_string << endl;
        exit(0);
    }

    return input;
}

bool operator < (const Date& left, const Date& right) {
    if(left.GetYear() == right.GetYear()) {
        if(left.GetMonth() == right.GetMonth()) {
            return left.GetDay() < right.GetDay();
        }
        return left.GetMonth() < right.GetMonth();
    }
    return left.GetYear() < right.GetYear();
};

class Database {
public:
  void AddEvent(const Date& date, const string& event) {
      db[date].insert(event);
  };
  bool DeleteEvent(const Date& date, const string& event) {
      if(db.count(date) > 0) {
          auto current_set = db.at(date);
          for(auto it = current_set.begin(); it != current_set.end(); ++ it) {
              if(*it == event) {
                  current_set.erase(it);
                  if(current_set.empty()) {
                      db.erase(date);
                  } else {
                      db[date] = current_set;
                  }
                  return true;
              }
          }
      }
      return false;
  };
  int DeleteDate(const Date& date) {
      int events = 0;
      if(db.count(date) > 0) {
          events = db[date].size();
          db.erase(date);
      }
      return events;
  };

  void Find(const Date& date) const {
      if(db.count(date) > 0) {
          auto current_set = db.at(date);
          for(auto event : current_set) {
              cout << event << endl;
          }

      }
  };
  
  void Print() const {
      for(auto [key, events] : db) {
          for(auto event : events) {
              cout << setfill('0') << setw(4)  << to_string(key.GetYear()) << '-'
                   << setw(2) << setfill('0') << to_string(key.GetMonth()) << '-'
                   << setw(2) << setfill('0') << to_string(key.GetDay())
                   << ' ' << event << endl;
          }
      }
  };

private:
    map<Date, set<string>> db;
};

int main() {
    Database db;

    string command;
    while(cin >> command) {
        Date date;
        string event;
        if(command == "Add" or command == "Del" or command == "Find") {
            cin.ignore(1);
            string other_string;
            getline(cin, other_string);

            size_t found = other_string.find(' ');
            if(found != string::npos) {
                stringstream ss_date, ss_event;
                ss_date << other_string.substr(0,found);
                ss_event << other_string.substr(found + 1);
                ss_date >> date;
                ss_event >> event;
            } else {
                stringstream ss;
                ss << other_string;
                ss >> date;
            }
        }


        if(command == "Add") {
            db.AddEvent(date, event);
        } else if(command == "Del") {
            if(!event.empty()) {
                if(db.DeleteEvent(date, event)) {
                    cout << "Deleted successfully" << endl;
                } else {
                    cout << "Event not found" << endl;
                }
            } else {
                cout << "Deleted " << to_string(db.DeleteDate(date)) << " events" << endl;
            }

        } else if(command == "Find") {
            db.Find(date);
        } else if(command == "Print") {
            db.Print();
        } else {
            cout << "Unknown command: " << command << endl;
            exit(0);
        }
    }

    return 0;
}