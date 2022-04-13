#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
#include <iostream>
#include <string>

using namespace std;

template <typename T> ostream &operator<<(ostream &os, vector<T> &container) {
  for (auto val : container) {
    os << val << ' ';
  }
  os << endl;
  return os;
}

int main() {
  vector<int> v({1, 2, 3, 4, 5, 6, 9, 1, 2, 3});
  int val = 1;

  function<bool(const int &f, const int &s)> p(
      [](const int &f, const int &s) { return f > s; });

  function<bool(const int &f, const int &s)> predicate =
      [](const int &f, const int &s) { return f > s; };

  struct combat {
    bool operator()(const int &f, const int &s) { return f > s; }
  };

  cout << v;
  sort(begin(v), end(v), p);
  cout << v;
}