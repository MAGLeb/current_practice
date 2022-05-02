#include <bits/stdc++.h>

using namespace std;

int sum_of_divisors(int n) {
  set<int> v({1});
  int divisor = 2;

  while(n != 1) {
    while(n % divisor != 0)
      divisor++;
    n /= divisor;
    set<int> b;
    for(int val : v)
      b.insert(val * divisor);
    v.insert(begin(b), end(b));
  }

  int res = 0;
  auto it = begin(v);
  while(it != prev(end(v)))
    res += *it++;
  return res;
}

int main() {
  int res = 0;
  map<int, int> mapper;

  for(int i = 1; i < 10000; i++) {
    int sm = sum_of_divisors(i);
    mapper[i] = sm;
    if (sm <= i && mapper[sm] == i) {
      if (i != sm) {
        res += i + sm;
        cout << i << ' ' << sm << endl;
      }
    }
  }

  cout << res << endl;
}