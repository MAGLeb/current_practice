#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <vector>

using namespace std;

struct Date {
  Date(string date) : date_(date) {}

  string date_;
  int year = 1900;
  int month = 11;
  int day = 24;
};

int main() {
  set<pair<Date, string>> s;
  const Date d("2024-12-24");
  const string st = "event";
  auto p = make_pair(d, st);
  s.insert(make_pair(d, st));

//  s.insert(pair<Date, string>("2024-12-24", "event")));
}