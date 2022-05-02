#include <bits/stdc++.h>

using namespace std;

int sum_of_divisors(int n) {
  set<int> v({1});
  int divisor = 2;

  while (n != 1) {
    while (n % divisor != 0)
      divisor++;
    n /= divisor;
    set<int> b;
    for (int val : v)
      b.insert(val * divisor);
    v.insert(begin(b), end(b));
  }

  int res = 0;
  auto it = begin(v);
  while (it != prev(end(v)))
    res += *it++;
  return res;
}

int main() {
  vector<int> abundant;
  vector<int> s_of_t(28123, 0);

  for (int i = 1; i < 28123; i++) {
    if (sum_of_divisors(i) > i) {
      abundant.push_back(i);
      for (int val : abundant) {
        if (i + val < 28123)
          s_of_t[i + val] = 1;
      }
    }
  }

  uint64_t res = 0;
  for (int i = 0; i < s_of_t.size(); i++) {
    if (s_of_t[i] == 0)
      res += i;
  }
  cout << res << endl;
}