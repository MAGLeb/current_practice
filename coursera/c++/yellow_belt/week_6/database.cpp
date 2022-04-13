#include <algorithm>
#include <stdexcept>
#include <iostream>

#include "database.h"
using namespace std;

void DataBase::Add(const Date &date, const string &event) {
  auto it = find_if(begin(date_event_set), end(date_event_set),
                    [date, event](const pair<Date, string> &p) {
                      return p.first == date && p.second == event;
                    });
  if (it == end(date_event_set)) {
    date_event_set.insert(make_pair(date, event));
    auto it_mapper = find_if(begin(date_event_mapper), end(date_event_mapper),
                             [date](const pair<Date, vector<string>> &p) {
                               return date == p.first;
                             });

    if (it_mapper == end(date_event_mapper))
      date_event_mapper.insert({date, {event}});
    else
      (*it_mapper).second.push_back(event);
  } else
    cerr << "Event: " << event << ", dated: " << date
         << ", was not added to date_event_mapper." << endl;
}

void DataBase::Print(ostream &os) const {
  string s = "0-0-0";
  Date date(s);
  bool first = true;

  for (auto p : date_event_set) {
    if (first || date != p.first) {
      date = p.first;
      first = false;
    } else
      continue;

    for (auto event : date_event_mapper.at(date)) {
      os << date << ' ' << event << endl;
    }
  }
}

Date DataBase::Last(const Date &date) {
  auto it = find_if(begin(date_event_set), end(date_event_set),
                    [date](const pair<Date, string> &p) {
                      return date < p.first;
                    });

  if (it == begin(date_event_set))
    throw invalid_argument("No dates before");

  return (*it--).first;
}

bool CustomCompare::operator()(const pair<Date, string> &lhs,
                               const pair<Date, string> &rhs) {
  return lhs.first < rhs.first;
}