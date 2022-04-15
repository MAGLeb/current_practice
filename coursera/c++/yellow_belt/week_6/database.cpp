#include <algorithm>
#include <iostream>
#include <set>

#include "database.h"
#include "utils.h"
using namespace std;

void Database::Add(const Date &date, const string &event) {
  int prev_size = date_event_set.size();
  date_event_set.insert(make_pair(date, event));

  if (prev_size != date_event_set.size()) {
    if (date_event_mapper.count(date) == 0)
      date_event_mapper.insert({date, {event}});
    else
      date_event_mapper.at(date).push_back(event);
  }
}

void Database::Print(ostream &os) const {
  Date date(0, 0, 0);
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
  vector<pair<Date, string>> v(begin(date_event_set), end(date_event_set));
  auto it = lower_bound(begin(v), end(v), date,
                        [](const pair<Date, string> &p, const Date &date_) {
                          return date_ >= p.first;
                        });

  if (it-- == begin(v))
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
  date_event_set = set<pair<Date, string>>(it, end(v));

  for (auto it_mapper = date_event_mapper.cbegin(), next_it = it_mapper;
       it_mapper != date_event_mapper.cend(); it_mapper = next_it) {
    ++next_it;
    auto &map_vec = date_event_mapper.at(it_mapper->first);
    auto it_m = stable_partition(begin(map_vec), end(map_vec),
                                 [it_mapper, predicate](const string &s) {
                                   return predicate(it_mapper->first, s);
                                 });
    if (it_m == end(map_vec))
      date_event_mapper.erase(it_mapper);
    else
      map_vec.erase(begin(map_vec), it_m);
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