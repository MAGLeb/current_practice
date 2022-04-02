#pragma once

#include <iostream>
#include <string>

using namespace std;

class Data {
private:
  string full_date;
  int year;
  int month;
  int day;

public:
  void ParseDate(string date);
  time_t AsTimestamp() const;
};

int ComputeDiff(const Data &start, const Data &end);

istream &operator>>(istream &is, Data &d);
ostream &operator<<(ostream &os, const Data &d);