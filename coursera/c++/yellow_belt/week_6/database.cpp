#include <algorithm>
#include <iostream>
#include <set>

#include "database.h"
using namespace std;

template <class T> ostream &operator<<(ostream &os, const vector<T> &s) {
  os << "{";
  bool first = true;
  for (const auto &x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class T> ostream &operator<<(ostream &os, const set<T> &s) {
  os << "{";
  bool first = true;
  for (const auto &x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class K, class V>
ostream &operator<<(ostream &os, const map<K, V> &m) {
  os << "{";
  bool first = true;
  for (const auto &kv : m) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << kv.first << ": " << kv.second;
  }
  return os << "}";
}

void Database::Add(const Date &date, const string &event) {
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

void Database::Print(ostream &os) const {
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

pair<Date, string> Database::Last(const Date &date) const {
  auto it =
      find_if(begin(date_event_set), end(date_event_set),
              [date](const pair<Date, string> &p) { return date < p.first; });

  if (it-- == begin(date_event_set))
    throw invalid_argument("No dates before");

  return make_pair(it->first, date_event_mapper.at(it->first).back());
}

int Database::RemoveIf(function<bool(const Date &, const string &)> predicate) {
  vector<pair<Date, string>> v(begin(date_event_set), end(date_event_set));
  auto it = stable_partition(v.begin(), v.end(),
                             [predicate](const pair<Date, string> &p) {
                               return predicate(p.first, p.second);
                             });
  int result = distance(begin(v), it);
  date_event_set = set<pair<Date, string>, CustomCompare>(it, end(v));

  auto start = begin(v);
  while (start != it) {
    auto it_event = find(begin(date_event_mapper.at((*start).first)),
                         end(date_event_mapper.at((*start).first)), (*start).second);
    date_event_mapper.at((*start).first).erase(it_event);
    if (date_event_mapper.at(start->first).empty()) {
      date_event_mapper.erase(start->first);
    }
    start++;
  }

  return result;
}

vector<pair<Date, string>>
Database::FindIf(function<bool(const Date &, const string &)> predicate) const {
  vector<pair<Date, string>> result;
  for (auto p : date_event_set) {
    if (predicate(p.first, p.second))
      result.push_back(p);
  }
  return result;
}

bool CustomCompare::operator()(const pair<Date, string> &lhs,
                               const pair<Date, string> &rhs) const {
  if (lhs.first == rhs.first) {
    return lhs.second < rhs.second;
  } else {
    return lhs.first < rhs.first;
  }
}