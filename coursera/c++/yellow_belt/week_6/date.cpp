#pragma once

#include "date.h"
#include <algorithm>
#include <iostream>

using namespace std;

Date::Date(string &date) {
  auto it_first = begin(date);
  auto it_second = find(it_first, end(date), '-');
  year_ = stoi(string(it_first, it_second));

  it_first = it_second + 1;
  auto it_second = find(it_first, end(date), '-');
  month_ = stoi(string(it_first, it_second));

  it_first = it_second + 1;
  day_ = stoi(string(it_first, end(date)));

  date_ = to_string(year_) + '-' + to_string(month_) + '-' + to_string(day_);
}

const string &Date::GetDate() {
  return date_;
}

const Date ParseDate(istream &is) {
  string s;
  is >> s;
  Date date(s);
  return date;
}

time_t Data::AsTimestamp() const {
  tm t;
  t.tm_sec = 0;
  t.tm_min = 0;
  t.tm_hour = 0;
  t.tm_mday = day;
  t.tm_mon = month - 1;
  t.tm_year = year - 1900;
  t.tm_isdst = 0;
  return mktime(&t);
}