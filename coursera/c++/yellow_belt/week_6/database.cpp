#include <algorithm>
#include <iostream>
#include <set>

#include "database.h"
#include "utils.h"
using namespace std;

string GetDateFromString(const string &val) {
  auto it = begin(val);
  for (; it != end(val); it++) {
    if (*it == ' ')
      break;
  }
  return string(begin(val), it);
}

string GetEventFromString(const string &val) {
  auto it = begin(val);
  for (; it != end(val); it++) {
    if (*it == ' ')
      break;
  }
  return string(++it, end(val));
}

void Database::Add(const Date &date, const string &event) {
  int prev_size = date_event_set.size();
  date_event_set.insert(date.GetDate() + ' ' + event);

  if (prev_size != date_event_set.size()) {
    if (date_event_mapper.count(date) == 0)
      date_event_mapper.insert({date, {event}});
    else
      date_event_mapper.at(date).push_back(event);
  }
}

void Database::Print(ostream &os) const {
  string date = "0000-00-00";

  for (auto val : date_event_set) {
    string val_ = GetDateFromString(val);
    if (date == "0000-00-00" || date != val_) {
      date = val_;
    } else
      continue;

    for (auto event : date_event_mapper.at(Date(date))) {
      os << date << ' ' << event << endl;
    }
  }
}

pair<Date, string> Database::Last(const Date &date) const {
  auto it = date_event_set.lower_bound(date.GetDate());
  string val;

  if (it == end(date_event_set))
    it--;
  else {
    val = GetDateFromString(*it);

    if (Date(val) != date) {
      if (it == begin(date_event_set))
        throw invalid_argument("No dates before");
      else
        --it;
    }
  }

  val = GetDateFromString(*it);
  Date key(val);
  return make_pair(key, date_event_mapper.at(key).back());
}

int Database::RemoveIf(function<bool(const Date &, const string &)> predicate) {
  int result = date_event_set.size();
  auto it = date_event_set.begin();
  Date key(0, 0, 0);

  while (it != date_event_set.end()) {
    string date = GetDateFromString(*it);
    string event = GetEventFromString(*it);
    Date key_(date);

    //    cout << "SET: " << date_event_set << endl;
    //    cout << "MAP: " << date_event_mapper << endl;

    if (predicate(key_, event))
      it = date_event_set.erase(it);
    else {
      it++;
      continue;
    }

    if (key != key_) {
      key = key_;

      auto &map_vec = date_event_mapper.at(key);
      auto it_m = stable_partition(
          begin(map_vec), end(map_vec),
          [key, predicate](const string &s) { return predicate(key, s); });
      if (it_m == end(map_vec))
        date_event_mapper.erase(key);
      else
        map_vec.erase(begin(map_vec), it_m);
    }
  }

  result -= date_event_set.size();
  return result;

  //  vector<pair<Date, string>> v(begin(date_event_set), end(date_event_set));
  //  auto it = stable_partition(v.begin(), v.end(),
  //                             [predicate](const pair<Date, string> &p) {
  //                               return predicate(p.first, p.second);
  //                             });
  //  int result = distance(begin(v), it);
  //  date_event_set = set<pair<Date, string>>(it, end(v));
  //
  //  for (auto it_mapper = date_event_mapper.cbegin(), next_it = it_mapper;
  //       it_mapper != date_event_mapper.cend(); it_mapper = next_it) {
  //    ++next_it;
  //    auto &map_vec = date_event_mapper.at(it_mapper->first);
  //    auto it_m = stable_partition(begin(map_vec), end(map_vec),
  //                                 [it_mapper, predicate](const string &s) {
  //                                   return predicate(it_mapper->first, s);
  //                                 });
  //    if (it_m == end(map_vec))
  //      date_event_mapper.erase(it_mapper);
  //    else
  //      map_vec.erase(begin(map_vec), it_m);
  //  }
  //
  //  return result;
}

vector<string>
Database::FindIf(function<bool(const Date &, const string &)> predicate) const {
  vector<string> result;
  string date = "0000-00-00";

  for (auto val : date_event_set) {
    string val_ = GetDateFromString(val);
    if (date == "0000-00-00" || date != val_) {
      date = val_;
    } else
      continue;

    for (auto event : date_event_mapper.at(Date(date))) {
      if (predicate(Date(date), event))
        result.push_back(date + ' ' + event);
    }
  }
  return result;
}