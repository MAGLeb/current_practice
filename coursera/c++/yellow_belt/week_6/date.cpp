#include "date.h"
#include <algorithm>
#include <iostream>

using namespace std;

string AddLeadingZeroes(int &number, const int max_zeroes) {
  string s = to_string(number);
  return string(abs((int)s.size() - max_zeroes), '0') + s;
}

Date::Date(int year, int month, int day) {
  year_ = year;
  month_ = month;
  day_ = day;
  date_ = AddLeadingZeroes(year_, 4) + '-' + AddLeadingZeroes(month_, 2) + '-' +
          AddLeadingZeroes(day_, 2);
}

Date::Date(string &date) {
  auto it_first = begin(date);
  auto it_second = find(it_first, end(date), '-');
  year_ = stoi(string(it_first, it_second));

  it_first = it_second + 1;
  it_second = find(it_first, end(date), '-');
  month_ = stoi(string(it_first, it_second));

  it_first = it_second + 1;
  day_ = stoi(string(it_first, end(date)));

  date_ = AddLeadingZeroes(year_, 4) + '-' + AddLeadingZeroes(month_, 2) + '-' +
          AddLeadingZeroes(day_, 2);
}

string Date::GetDate() const { return date_; }

const Date ParseDate(istream &is) {
  string s;
  is >> s;
  Date date(s);
  return date;
}

bool operator<(const Date &lhs, const Date &rhs) {
  return lhs.GetDate() < rhs.GetDate();
}

bool operator>(const Date &lhs, const Date &rhs) {
  return lhs.GetDate() > rhs.GetDate();
}

bool operator>=(const Date &lhs, const Date &rhs) {
  return lhs.GetDate() >= rhs.GetDate();
}

bool operator<=(const Date &lhs, const Date &rhs) {
  return lhs.GetDate() <= rhs.GetDate();
}

bool operator==(const Date &lhs, const Date &rhs) {
  return lhs.GetDate() == rhs.GetDate();
}

bool operator!=(const Date &lhs, const Date &rhs) {
  return lhs.GetDate() != rhs.GetDate();
}