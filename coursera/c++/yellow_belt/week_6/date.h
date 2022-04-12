#pragma once

#include <iostream>

using namespace std;

class Date {
public:
  Date(string &date);
  const string& GetDate();
  time_t AsTimestamp() const;

private:
  string date_;
  int year_;
  int month_;
  int day_;
};

Date ParseDate(istream &is);