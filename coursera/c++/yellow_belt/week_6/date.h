#pragma once

#include <iostream>

using namespace std;

class Date {
public:
  Date(string &date);
  Date(int year, int month, int day);
  string GetDate() const;
  time_t AsTimestamp() const;

private:
  string date_;
  int year_;
  int month_;
  int day_;
};

const Date ParseDate(istream &is);
bool operator<(const Date &lhs, const Date &rhs);
bool operator>(const Date &lhs, const Date &rhs);
bool operator>=(const Date &lhs, const Date &rhs);
bool operator<=(const Date &lhs, const Date &rhs);
bool operator==(const Date &lhs, const Date &rhs);
bool operator!=(const Date &lhs, const Date &rhs);