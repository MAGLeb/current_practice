#include <algorithm>
#include <iostream>
#include <set>

#include "database.h"
#include "utils.h"
using namespace std;

pair<string, string> ParseStringDateEvent(const string &val) {
  auto it = begin(val);
  for (; it != end(val); it++) {
    if (*it == ' ')
      break;
  }
  return make_pair(string(begin(val), it), string(++it, end(val)));
}

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
  auto p = date_event_set.insert(date.GetDate() + ' ' + event);

  if (p.second) {
    auto it = p.first;

    if (date_event_set.size() == 1) {
      date_event_mapper.insert({date, {event}});
    } else {
      auto left = it;
      auto right = it;
      if (it++ == begin(date_event_set)) {
        right++;
        left++;
      } else if (it == end(date_event_set)) {
        left--;
        right--;
      } else {
        left--;
        right++;
      }

      string date_1 = GetDateFromString(*left);
      string date_2 = GetDateFromString(*right);
      if (date.GetDate() == date_1 || date.GetDate() == date_2)
        date_event_mapper.at(date).push_back(event);
      else
        date_event_mapper.insert({date, {event}});
    }
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

  if (it == end(date_event_set) && it == begin(date_event_set))
    throw invalid_argument("No dates before");
  else if (it == end(date_event_set))
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
    auto p = ParseStringDateEvent(*it);
    string date = p.first;
    string event = p.second;
    Date key_(date);

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