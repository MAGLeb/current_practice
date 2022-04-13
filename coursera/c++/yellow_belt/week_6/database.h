#pragma once

#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <vector>

#include "date.h"

using namespace std;

struct CustomCompare {
  bool operator()(const pair<Date, string> &lhs, const pair<Date, string> &rhs);
};

class DataBase {
public:
  void Add(const Date &date, const string &event);
  void Print(ostream &os) const;
  void RemoveIf();
  void FindIf();
  Date Last(const Date &date);

private:
  map<Date, vector<string>> date_event_mapper;
  set<pair<Date, string>, CustomCompare> date_event_set;
};