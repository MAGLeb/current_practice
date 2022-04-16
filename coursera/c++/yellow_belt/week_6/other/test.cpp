#include "../utils.h"
#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <vector>

using namespace std;

int main() {
  string s = "0000-00-00 event";
  auto it = begin(s);
  for (; it != end(s); it++) {
    if (*it == ' ')
      break;
  }
  string event = string(++it, end(s));
  cout << event << endl;

//  set<string> s;
//  s.insert("3021-08-02");
//  s.insert("2001-09-01");
//  s.insert("2021-08-02");
//  s.insert("2021-07-02");
//  s.insert("2021-08-31");
//  s.insert("0021-08-02");
//
//  cout << s << endl;
//  string predicate = "1000-01-01";
//
//  auto it = stable_partition(s.begin(), s.end(), [predicate](const string &item) {
//    return predicate < item;
//  });
//  s.erase(it, end(s));
//  cout << s << endl;
//
//  vector<string> v(begin(s), end(s));
//
//  cout << v << endl;
}