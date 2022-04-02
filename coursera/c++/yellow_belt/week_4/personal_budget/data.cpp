#include <iostream>
#include <algorithm>
#include <chrono>

using namespace std;

#include "data.h"

int ConvertToInt(string str) {
  size_t pos;
  const int result = stoi(str, &pos);
  return result;
}

void Data::ParseDate(string date) {
  full_date = date;

  auto it = begin(date);
  auto next = find(begin(date), end(date), '-');
  year = ConvertToInt(string(it, next));

  it = next + 1;
  next = find(it, end(date), '-');
  month = ConvertToInt(string(it, next));

  it = next + 1;
  next = find(it, end(date), '-');
  day = ConvertToInt(string(it, next));
}

time_t Data::AsTimestamp() const {
  tm t;
  t.tm_sec  = 0;
  t.tm_min  = 0;
  t.tm_hour = 0;
  t.tm_mday = day;
  t.tm_mon  = month - 1;
  t.tm_year = year - 1900;
  t.tm_isdst = 0;
  return mktime(&t);
}

//int ComputeDiff(const Data &start, const Data &end) {
//  return (end.AsTimestamp() - start.AsTimestamp()) / 60 * 60 * 24;
//}

int ComputeDiff(const Data& start, const Data& end) {
  const time_t timestamp_to = start.AsTimestamp();
  const time_t timestamp_from = end.AsTimestamp();
  static constexpr int SECONDS_IN_DAY = 60 * 60 * 24;
  return (timestamp_from - timestamp_to) / SECONDS_IN_DAY;
}

istream &operator>>(istream &is, Data &d) {
  string s;
  is >> s;
  d.ParseDate(s);

  return is;
}