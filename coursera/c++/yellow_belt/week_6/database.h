#pragma once

#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <vector>

#include "date.h"

using namespace std;

class Database {
public:
  void Add(const Date &date, const string &event);
  void Print(ostream &os) const;
  int RemoveIf(function<bool(const Date &date, const string &event)> predicate);
  vector<pair<Date, string>>
  FindIf(function<bool(const Date &date, const string &event)> predicate) const;
  pair<Date, string> Last(const Date &date) const;

private:
  map<Date, vector<string>> date_event_mapper;
  set<pair<Date, string>> date_event_set;
};

ostream &operator<<(ostream &os, const pair<Date, string> &p);