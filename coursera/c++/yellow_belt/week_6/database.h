#pragma once

#include <iostream>
#include <map>

#include "date.h"

using namespace std;

class DataBase {
public:
  void Add(const Date &date, const string &event);
  void Print(const ostream &os) const;
  void RemoveIf();
  void FindIf();
  void Last(const Date &date);

private:
  map<string, string> date_event_mapper;
};